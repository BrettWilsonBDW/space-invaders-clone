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

    // playerPosX = (static_cast<float>(GetScreenWidth() / 2) - (ship.width * scale) / 2);
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

void Player::UpdatePlayer()
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

        shootCtr++;

        if (shootCtr >= maxBullets)
        {
            shootCtr = 0;
        }
    }
    Shoot();

    screenPos = playerPosX;

    screenPos = (screenPos * gameUtils->GetScale());

    shipRect = {0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
    shipDestRect = {static_cast<float>(screenPos), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};
}

void Player::updatePlayerPersistance()
{
    // TODO reimplement scale

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

void Player::Shoot()
{
    int speed{500};
    for (auto &bullet : bullets)
    {
        if (bullet.y < 0)
        {
            // bullet.canShootAgain = true;
            bullet.canShootAgain = false;
            bullet.hasShot = false;
        }
        else
        {
            // bullet.canShootAgain = false;
            bullet.canShootAgain = true;
        }

        if (bullet.canShootAgain)
        {
            bullet.y -= speed * gameUtils->GetDeltaTime();
            bullet.rect = {static_cast<float>(bullet.x), static_cast<float>(bullet.y), 2 * scale, 5 * scale};
        }
    }
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
        if (bullet.hasShot)
        {
            DrawRectangle(bullet.x, bullet.y, 2 * scale, 5 * scale, RED);
        }
    }

    // TODO fix jitter comes from the player is being drawn

    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);
}