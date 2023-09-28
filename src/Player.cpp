#include "Player.hpp"

Player::Player()
{
}

void Player::Init()
{
    ship = assetManager->GetShip();
}

void Player::Unload()
{
    UnloadTexture(ship);
}

void Player::UpdatePlayer()
{
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
        // playerVector.x -= 5 * scale / 5 * gameUtils->GetDeltaTime();
        playerVector.x -= (75 * gameUtils->GetDeltaTime()) * scale;

    }

    if (IsKeyDown(KEY_D))
    {
        // playerVector.x += 5 * scale / 5 * gameUtils->GetDeltaTime();
        playerVector.x += (75 * gameUtils->GetDeltaTime()) * scale;
    }
}

void Player::DrawPlayer()
{
    Rectangle shipRect{0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
    Rectangle shipDestRect{playerScreenPos.x + playerVector.x, playerScreenPos.y, static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>((ship.width / 2) / scale), static_cast<float>((ship.height / 2) / scale)}, 0, WHITE);

    int margin = 30;
    playerRect = {shipDestRect.x + margin, shipDestRect.y + margin, shipDestRect.width - (margin + 20), shipDestRect.height - margin};
}