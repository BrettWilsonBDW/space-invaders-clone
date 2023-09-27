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
    width = GetScreenWidth();
    height = GetScreenHeight();
}

void Player::DrawPlayer()
{
    DrawTexture(ship, width / 2, height / 2, WHITE);
}