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

    CalcScale();
    playerSize = 8;
    scale = (sScale * playerSize);

    //start the player in the middle of the screen
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

void Player::CalcScale()
{

    int targetWidth = 1920;
    int targetHeight = 1080;

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    float scaleX = (float)screenWidth / targetWidth;
    float scaleY = (float)screenHeight / targetHeight;

    sScale = std::min(scaleX, scaleY);
}

void Player::UpdatePlayer()
{
    shipRect = {0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
    shipDestRect = {static_cast<float>(playerPosX), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

    CalcScale();
    playerControls();

    // playerPosX = static_cast<float>(windowWidth) / 2 - ship.width * scale / 2;
    // playerScreenPos.y = static_cast<float>(windowHeight) - ship.height * scale;
}

void Player::updatePlayerPersistance()
{
    // TODO reimplement scale

    // int playerSize = 8;
    // scale = (gameUtils->GetScale() * playerSize);
    // int playerSize = 8;
    scale = (sScale * playerSize);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

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
    int speed = 150;
    speed = scale * speed;

    float dt = gameUtils->GetDeltaTime();

    if (IsKeyDown(KEY_A))
    {
        float newPosition = playerPosX - static_cast<int>(speed * dt);

        if (newPosition >= 0)
        {
            playerPosX = newPosition;
        }
    }

    if (IsKeyDown(KEY_D))
    {
        float newPosition = playerPosX + static_cast<int>(speed * dt);

        if (newPosition <= windowWidth - ship.width * scale)
        {
            playerPosX = newPosition;
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
    // DrawTexturePro(ship, shipRect, shipDestRect, Vector2{ship}, 0, WHITE);
    // DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);
    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);
}