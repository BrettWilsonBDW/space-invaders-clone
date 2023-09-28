#include "Player.hpp"

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

/**
 * Updates the player's screen position based on the window size and ship dimensions.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Player::UpdatePlayer()
{
    playerScreenPos = {static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) - ship.height * scale};
}

/**
 * Updates the player's persistence.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Player::updatePlayerPersistance()
{
    int playerSize = 10;
    scale = (gameUtils->GetScale() * playerSize);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
}


// Linear interpolation function
float lerp(float start, float end, float t)
{
    return start + t * (end - start);
}

/**
 * Updates the player's position based on user input, using interpolation for smooth movement.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void Player::playerControls()
{
    int speed = 1000;
    float interpolationFactor = 0.1f; // Adjust this value to control the smoothness of the movement

    // Calculate the target position
    float targetX = playerVector.x;
    if (IsKeyDown(KEY_A))
    {
        targetX -= speed * gameUtils->GetDeltaTime() * scale;
    }
    if (IsKeyDown(KEY_D))
    {
        targetX += speed * gameUtils->GetDeltaTime() * scale;
    }

    // Apply interpolation
    playerVector.x = lerp(playerVector.x, targetX, interpolationFactor);
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
    Rectangle shipRect{0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
    Rectangle shipDestRect{playerScreenPos.x + playerVector.x, playerScreenPos.y, static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);

    int margin = 15;

    // Create a rectangle representing the position and size of the player on the screen
    // The playerRect is defined using the shipDestRect and margin variables
    playerRect = {
        shipDestRect.x + margin,            // x coordinate: shift shipDestRect.x to the left by margin units - left
        shipDestRect.y + margin,            // y coordinate: shift shipDestRect.y up by margin units - top
        shipDestRect.width - (margin + 20), // width: decrease shipDestRect.width by (margin - 20) units - right
        shipDestRect.height - (margin + 5)  // height: decrease shipDestRect.height by margin units - bottom
    };
}