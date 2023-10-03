#include "Player.hpp"
// #include "iostream"

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

    // CalcScale();
    playerSize = 8;
    // scale = (sScale * playerSize);
    // gameUtils->CalcScale(GetScreenWidth(), GetScreenHeight());

    scale = (gameUtils->GetScale() * playerSize);

    // start the player in the middle of the screen
    //  playerPosX = static_cast<float>(GetScreenWidth() / 2) - (ship.width * scale) / 2;
    //  playerPosX = static_cast<float>(GetScreenWidth() / 2) - (ship.width * scale) / 2;
    //  playerPosX = static_cast<float>(GetScreenWidth() / 2) - (ship.width * scale) / 2;

    playerPosX = static_cast<float>(GetScreenWidth() / 2) - (ship.width * scale) / 2;
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

// void Player::CalcScale()
// {
//     int targetWidth = 1920;
//     int targetHeight = 1080;

//     int screenWidth = GetScreenWidth();
//     int screenHeight = GetScreenHeight();

//     float scaleX = (float)screenWidth / targetWidth;
//     float scaleY = (float)screenHeight / targetHeight;

//     sScale = std::min(scaleX, scaleY);
// }

void Player::UpdatePlayer()
{
    playerControls();
    shipRect = {0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
    shipDestRect = {static_cast<float>(playerPosX), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

    // CalcScale();

    // playerPosX = static_cast<float>(GetScreenWidth() / 2) - (ship.width * scale) / 2;

    // playerPosX = static_cast<float>(windowWidth) / 2 - ship.width * scale / 2;
    // playerScreenPos.y = static_cast<float>(windowHeight) - ship.height * scale;
}

void Player::updatePlayerPersistance()
{
    // TODO reimplement scale

    // int playerSize = 8;
    // scale = (gameUtils->GetScale() * playerSize);
    // int playerSize = 8;
    // scale = (sScale * playerSize);

    scale = (gameUtils->GetScale() * playerSize);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    // playerPosX = static_cast<float>(GetScreenWidth() / 2) - (ship.width * scale) / 2;

    int margin = 15;

    playerRect = {
        shipDestRect.x + margin,            // x coordinate: shift shipDestRect.x to the left by margin units - left
        shipDestRect.y + margin,            // y coordinate: shift shipDestRect.y up by margin units - top
        shipDestRect.width - (margin + 20), // width: decrease shipDestRect.width by (margin - 20) units - right
        shipDestRect.height - (margin + 5)  // height: decrease shipDestRect.height by margin units - bottom
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

    // if (IsKeyDown(KEY_D) && playerPosX <= windowWidth - ship.width * scale)
    if (IsKeyDown(KEY_D))
    {
        if (playerPosX <= windowWidth - ship.width * scale)
        {
            velocity.x = speed * dt;
        }
        else
        {
            velocity.x = 0;
        }
    }

    // Calculate the target position based on velocity
    Vector2 targetPosition = {playerPosX + velocity.x, 100}; // Assuming constant y position

    // Use lerp to smoothly interpolate the position
    float smoothingFactor = 0.1f; // Adjust as needed for desired smoothing
    playerPosX = Lerp(playerPosX, targetPosition.x, smoothingFactor);
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
    // DrawTexturePro(ship, shipRect, shipDestRect, Vector2{ship}, 0, WHITE);
    // DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);
    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);
    // DrawTextureEx(ship, Vector2{static_cast<float>(playerPosX), 100}, 0, scale, WHITE);
}