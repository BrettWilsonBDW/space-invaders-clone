#include "Enemies.hpp"
#include <iostream>

Enemies::Enemies()
{
}

void Enemies::Init()
{
    scale = gameUtils->GetScale();
    bullets = player->GetBullets();
}

void Enemies::Update()
{
    scale = gameUtils->GetScale();
}

void Enemies::Draw()
{
    // Player player;

    // Player::Bullets *bullets = player->GetBullets();

    // Bullets *bullets = player->GetBullets();

    std::cout << bullets[1].y << std::endl;
    


    int factor = 100 * scale;
    for (int i = 0; i < 10; i++)
    {
        // Rectangle enemiesRect = {(300 * scale) + i * factor, (300 * scale), (50 * scale) + i * factor, (50 * scale) + i * factor};
        // DrawRectangleRec(enemiesRect, RED);

        Rectangle enemiesRect = {(300 * scale) + factor, (300 * scale), (50 * scale), (50 * scale)};
        DrawRectangleRec(enemiesRect, RED);
        factor += 100 * scale;
    }



    // Rectangle enemiesRect = {300 * scale, 300 * scale, 50 * scale, 50 * scale};
    // DrawRectangleRec(enemiesRect, RED);
}
