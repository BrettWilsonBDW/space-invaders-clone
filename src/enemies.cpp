#include "Enemies.hpp"
#include <iostream>

Enemies::Enemies()
{
}

void Enemies::Init()
{
    scale = gameUtils->GetScale();
}

void Enemies::Update()
{
    scale = gameUtils->GetScale();
}

void Enemies::Draw()
{
    int factor = 10;
    for (int i = 0; i < 5; i++)
    {
        // Rectangle enemiesRect = {(300 * scale) + i * factor, (300 * scale), (50 * scale) + i * factor, (50 * scale) + i * factor};
        // DrawRectangleRec(enemiesRect, RED);
    }

    // Rectangle enemiesRect = {300 * scale, 300 * scale, 50 * scale, 50 * scale};
    // DrawRectangleRec(enemiesRect, RED);
}
