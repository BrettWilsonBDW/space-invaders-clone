#include "Enemies.hpp"

Enemies::Enemies()
{
}

void Enemies::Init()
{
    enemy1 = assetManager->GetEnemy1();

    scale = gameUtils->GetScale();

    // get bullets data from the player class
    bullets = player->GetBullets();
    maxBullets = player->GetMaxBullets();
}

void Enemies::CheckCollision()
{
    for (int i = 0; i < maxBullets; i++)
    {
        if (enemyIsActive)
        {
            if (CheckCollisionRecs(enemiesRect, bullets[i].rect))
            {
                enemyIsActive = false;
                // bullets[i].collided = true;
                bullets[i].canShootAgain = false;
                bullets[i].collided = true;
            }
        }
    }
}

void Enemies::PostionPlacement(int x, int y)
{
    enemyX = x;
    enemyY = y;
}

void Enemies::Movement()
{
    if ((enemyX * scale) > GetScreenWidth() - enemiesDestRect.width)
    {
        directionLR = true;
    }

    if (enemyX * scale < 0)
    {
        directionLR = false;
    }

    if (directionLR)
    {
        enemyX -= 10;
    }
    else
    {
        enemyX += 10;
    }
}

void Enemies::Update()
{

    scale = gameUtils->GetScale();

    float shipScale{scale * 5};
    sourceRect = {0, 0, static_cast<float>(enemy1.width), static_cast<float>(enemy1.height)};
    enemiesDestRect = {static_cast<float>(enemyX) * scale, enemyY * scale, static_cast<float>(enemy1.width * shipScale), static_cast<float>(enemy1.height * shipScale)};

    int margin = 10;
    // collision rect
    enemiesRect = {
        enemiesDestRect.x + margin,           // - left
        enemiesDestRect.y + margin,           // - top
        enemiesDestRect.width - (margin + 7), // - right
        enemiesDestRect.height - (margin)     // - bottom
    };

    CheckCollision();
}

void Enemies::Draw()
{
    if (enemyIsActive)
    {
        DrawTexturePro(enemy1, sourceRect, enemiesDestRect, Vector2{0, 0}, 0, WHITE);
        DrawRectangleLines(enemiesRect.x, enemiesRect.y, enemiesRect.width, enemiesRect.height, RED);
    }
}