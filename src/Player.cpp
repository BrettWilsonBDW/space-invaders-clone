#include "Player.hpp"
#include "iostream"

Player::Player()
{
}

/**
 * Initializes the Player object.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Player::Init()
{
    ship = assetManager->GetShip();

    // playerSize = 8;
    scale = (gameUtils->GetScale() * playerSize);

    playerPosX = ((static_cast<float>(GetScreenWidth() / 2)) - (ship.width * scale) / 2);

    playerPosX = playerPosX / gameUtils->GetScale();
}

/**
 * Unloads the player texture.
 *
 * @throws ErrorType description of error
 */
void Player::Unload()
{
    UnloadTexture(ship);
}

void Player::playerControls()
{
    // int speed = 1300 * 6;
    int speed = 1000;
    // speed = static_cast<int>(scale * speed);

    float dt = GetFrameTime();

    // Calculate the velocity based on input
    Vector2 velocity = {0.0f, 0.0f};

    if (IsKeyDown(KEY_A))
    {
        if (playerPosX > 0 + 15)
        {
            velocity.x = -speed * dt;
        }
        else
        {
            velocity.x = 0;
        }
    }

    if (IsKeyDown(KEY_D))
    {
        if (playerPosX * gameUtils->GetScale() < windowWidth - ship.width * scale)
        {
            velocity.x = speed * dt;
        }
        else
        {
            velocity.x = 0;
        }
    }

    playerPosX = static_cast<int>(playerPosX + static_cast<int>(velocity.x));
}

void Player::Shoot(float dt)
{
    int speed{700};
    for (auto &bullet : bullets)
    {
        //bullet bounds check
        if (bullet.y < 0)
        {
            bullet.canShootAgain = false;
            bullet.hasShot = false;
        }
        else
        {
            bullet.canShootAgain = true;
        }

        if (bullet.canShootAgain)
        {
            bullet.y -= speed * dt;
            bullet.rect = {static_cast<float>(bullet.x), static_cast<float>(bullet.y), 2 * scale, 5 * scale};
        }
    }
}

void Player::CheckPlayerCollision()
{
    if (playerCollision)
    {
        bulletCollisionState = true;
        playerCollision = false;
        TrackPlayerLives();
    }
    else
    {
        bulletCollisionState = false;
    }
}

void Player::TrackPlayerLives()
{
    lifeCtr++;

    // for some reason collision increments are in 2, the below is to combat this
    if (lifeCtr >= 2)
    {
        lifeCtrDown--;
        lifeCtr = 0;
    }

    if (lifeCtrDown == 0)
    {
        playerIsAlive = false;
    }
}

void Player::Update(float dt, bool canShoot)
{
    playerCanMove = canShoot;

    //prevent the player from shooting "ghost bullets from previous levels into the next during pause"
    if (!playerCanMove)
    {
        for (auto &bullet : bullets)
        {
            bullet.hasShot = true;
            bullet.x = (shipDestRect.x + shipDestRect.width / 2) * 1000; // move the bullets of the screen this way there is no collision
            bullet.y = shipDestRect.y;
        }
    }

    //playerCanMove prevents the player shoot and move controls during pause events
    if (playerIsAlive && playerCanMove)
    {
        playerControls();

        if (IsKeyPressed(KEY_SPACE))
        {
            if (!bullets[shootCtr].canShootAgain)
            {
                bullets[shootCtr].hasShot = true;
                bullets[shootCtr].x = shipDestRect.x + shipDestRect.width / 2;
                bullets[shootCtr].y = shipDestRect.y;
            }

            if (bullets[shootCtr].collided)
            {
                bullets[shootCtr].collided = false;
            }

            shootCtr++;

            if (shootCtr >= maxBullets)
            {
                shootCtr = 0;
            }
        }
        //part of shoot logic in the above
        Shoot(dt);

        screenPos = playerPosX;

        screenPos = (screenPos * gameUtils->GetScale());

        shipRect = {0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
        shipDestRect = {static_cast<float>(screenPos), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

        CheckPlayerCollision();
    }

    if (IsKeyDown(KEY_R) && IsKeyDown(KEY_P))
    {
        playerIsAlive = true;
        lifeCtrDown = 3;
    }
}

void Player::updatePlayerPersistance()
{
    // TODO reimplement scale to be only called once not every frame same for calcScale (on window change)

    scale = (gameUtils->GetScale() * playerSize);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    // rest player if its off the screen
    if (playerPosX * gameUtils->GetScale() > windowWidth)
    {
        // playerPosX = windowWidth - (ship.width * scale) + 10;
        screenPos = windowWidth - (ship.width * scale) + 10;
    }

    int margin = 15;

    // collision rect
    playerRect = {
        shipDestRect.x + margin,            // - left
        shipDestRect.y + margin,            // - top
        shipDestRect.width - (margin + 20), // - right
        shipDestRect.height - (margin + 5)  // - bottom
    };
}

/**
 * Draws the player on the screen.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Player::DrawPlayer()
{
    for (auto &bullet : bullets)
    {
        if (bullet.hasShot && !bullet.collided && playerCanMove)
        {
            DrawRectangle(bullet.x, bullet.y, 2 * scale, 5 * scale, RED);
        }
    }

    // TODO fix jitter comes from the player is being drawn something to do with sub pixels aka the sprite is too small
    // or multi thread look at the debugger

    if (playerIsAlive)
    {
        // draw player
        DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);

        // draw player lives
        DrawText(("Player Lives: " + std::to_string(lifeCtrDown)).c_str(), (GetScreenWidth() - 165), 10, 20, WHITE);
    }

    if (!playerIsAlive)
    {
        DrawText("You are dead", (GetScreenWidth() / 2) - 100, GetScreenHeight() / 2, 30, RED);
    }
}
