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
    playerPosX = (( static_cast<float>(GetScreenWidth() / 2)) - (ship.width * scale) / 2);

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

    if (hasShot)
    {
        Shoot();
    }

    // int temp = playerPosX;
    // screenPos = temp * gameUtils->GetScale();
    screenPos = playerPosX;

    screenPos = screenPos * gameUtils->GetScale();

    shipRect = {0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
    // shipDestRect = {static_cast<float>(playerPosX), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};
    shipDestRect = {static_cast<float>(screenPos), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};
    // shipDestRect = {static_cast<float>(playerPosX * gameUtils->GetScale()), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};
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
        playerPosX = windowWidth - (ship.width * scale) + 10;
        // screenPos = windowWidth - (ship.width * scale) + 10;
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
    int speed = 1300;
    speed = static_cast<int>(scale * speed);

    float dt = GetFrameTime();

    // Calculate the velocity based on input
    Vector2 velocity = {0.0f, 0.0f};

    if (IsKeyDown(KEY_A))
    {
        if (playerPosX > 0)
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

    // Calculate the target position based on velocity
    Vector2 targetPosition = {(playerPosX + velocity.x), 100};

    // Use lerp to smoothly interpolate the position
    float smoothingFactor = 0.1f; // Adjust as needed for desired smoothing
    playerPosX = Lerp(playerPosX, targetPosition.x, smoothingFactor);

    // playerPosX = playerPosX * gameUtils->GetScale();

    if (canShootAgain)
    {
        hasShot = false;
        if (IsKeyPressed(KEY_SPACE))
        {
            // hasShot = !hasShot;
            hasShot = true;

            // hasShot = !hasShot;

            bulletVelocity.x = shipDestRect.x + (shipDestRect.width / 2) - (2 * scale / 2);
            bulletVelocity.y = shipDestRect.y + (shipDestRect.height / 2) - (30 * scale / 2);

            // Shoot();
        }
    }
}


void Player::Shoot()
{
    bulletVelocity.y -= 500 * gameUtils->GetDeltaTime();

    if (bulletVelocity.y > 0)
    {
        canShootAgain = false;
    }
    else
    {
        canShootAgain = true;
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
    if (hasShot)
    {
        DrawRectangle(bulletVelocity.x, bulletVelocity.y, 2 * scale, 5 * scale, RED);
    }

    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);
}