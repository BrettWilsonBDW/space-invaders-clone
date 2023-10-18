#include "Enemies.hpp"

Enemies::Enemies()
{
}

void Enemies::Init()
{
    enemy1 = assetManager->GetEnemy1();

    scale = gameUtils->GetScale();
    bullets = player->GetBullets();
    maxBullets = player->GetMaxBullets();
}

void Enemies::Update()
{
    scale = gameUtils->GetScale();

    int factor = 0;
    float shipScale{scale * 6};
    sourceRect = {0, 0, static_cast<float>(enemy1.width), static_cast<float>(enemy1.height)};
    enemiesDestRect = {static_cast<float>((300 * scale) + factor), static_cast<float>((300 * scale)), static_cast<float>((50 * scale) * shipScale), static_cast<float>((50 * scale) * shipScale)};

    int margin = 10;
    // collision rect
    enemiesRect = {
        enemiesDestRect.x + margin,            // - left
        enemiesDestRect.y + margin,            // - top
        enemiesDestRect.width - (margin + 7), // - right
        enemiesDestRect.height - (margin)  // - bottom
    };
}

void Enemies::Draw()
{
    // for (int i = 0; i < maxBullets; i++)
    // {
    //     std::cout << i << " : [" << bullets[i].y << "] ";
    // }

    // std::cout << " info: " << bullets->rect.x << " " << bullets->rect.y << " " << bullets->rect.width << " " << bullets->rect.height << std::endl;

    // float shipScale{scale * 6};

    // // int factor = 100 * scale;
    // int factor = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     // Rectangle enemiesRect = {(300 * scale) + i * factor, (300 * scale), (50 * scale) + i * factor, (50 * scale) + i * factor};
    //     // DrawRectangleRec(enemiesRect, RED);

    //     // shipRect = {0, 0, static_cast<float>(ship.width), static_cast<float>(ship.height)};
    //     // shipDestRect = {static_cast<float>(screenPos), static_cast<float>(GetScreenHeight() - ship.height * scale), static_cast<float>(ship.width * scale), static_cast<float>(ship.height * scale)};

    //     Rectangle sourceRect = {0, 0, static_cast<float>(enemy1.width), static_cast<float>(enemy1.height)};
    //     Rectangle enemiesDestRect = {static_cast<float>((300 * scale) + factor), static_cast<float>((300 * scale)), static_cast<float>((50 * scale) * shipScale), static_cast<float>((50 * scale) * shipScale)};
    //     // DrawRectangleRec(enemiesRect, RED);

    //     // DrawTexture(enemy1, (300 * scale) + factor, (300 * scale), WHITE);
    //     DrawTexturePro(enemy1, sourceRect, enemiesDestRect, Vector2{0, 0}, 0, WHITE);
    //     // factor += 100 * scale;
    //     factor += 100;
    // }

    // Rectangle enemiesRect = {300 * scale, 300 * scale, 50 * scale, 50 * scale};
    // DrawRectangleRec(enemiesRect, RED);

    // int factor = 0;
    // float shipScale{scale * 6};
    // Rectangle sourceRect = {0, 0, static_cast<float>(enemy1.width), static_cast<float>(enemy1.height)};
    // Rectangle enemiesDestRect = {static_cast<float>((300 * scale) + factor), static_cast<float>((300 * scale)), static_cast<float>((50 * scale) * shipScale), static_cast<float>((50 * scale) * shipScale)};
    DrawTexturePro(enemy1, sourceRect, enemiesDestRect, Vector2{0, 0}, 0, WHITE);
    DrawRectangleLines(enemiesRect.x, enemiesRect.y, enemiesRect.width, enemiesRect.height, RED);
}
