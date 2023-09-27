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

void Player::updatePlayerPersistance()
{
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
}

void Player::DrawPlayer()
{
    int scale = (gameUtils->GetScale() * 20);


    Rectangle shipRect{0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};

    Rectangle shipDestRect{static_cast<float>(windowWidth) / 2 - ship.width * scale / 2, static_cast<float>(windowHeight) / 2 - ship.height * scale / 2, static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

    DrawTexturePro(ship, shipRect, shipDestRect, Vector2{static_cast<float>(ship.width / 2), static_cast<float>(ship.height / 2)}, 0, WHITE);
}