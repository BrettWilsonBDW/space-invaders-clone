#include "Player.hpp"

Player::Player()
{
    // playerPos = {static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2};
    // playerPos = {static_cast<float>(windowWidth) / 2, 100};

    // playerScreenPos = {static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2};
}

void Player::Init()
{
    ship = assetManager->GetShip();
    // playerScreenPos = {static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2};

    // playerScreenPos = {static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2};

}

void Player::Unload()
{
    UnloadTexture(ship);
}

void Player::UpdatePlayer()
{
    // playerPos = {static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2};

    playerScreenPos = {static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) - ship.height * scale};
}

void Player::updatePlayerPersistance()
{
    scale = (gameUtils->GetScale() * 20);
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
}

void Player::playerControls()
{
    if (IsKeyDown(KEY_A))
    {
        playerVector.x -= 5;
    }

    if (IsKeyDown(KEY_D))
    {
        playerVector.x += 5;
    }
}

void Player::DrawPlayer()
{
    scale = (gameUtils->GetScale() * 20);
    // playerScreenPos = {static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2};

    Rectangle shipRect{0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};

    // Rectangle shipDestRect{static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2, static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};
    // Rectangle shipDestRect{(static_cast<float>(windowWidth) / 2 - ship.width * scale / 2) + playerPos.x, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2, static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};
    Rectangle shipDestRect{playerScreenPos.x + playerVector.x, playerScreenPos.y, static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};
    // Rectangle shipDestRect{playerPos.x, playerPos.y - ship.width * scale / 2, static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);

    DrawRectangleLines(shipDestRect.x, shipDestRect.y, shipDestRect.width, shipDestRect.height, WHITE);
}