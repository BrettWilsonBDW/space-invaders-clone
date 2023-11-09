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

    enemyBullet.x = enemyX;
    enemyBullet.y = enemyY;
    enemyBullet.width = 0;
    enemyBullet.height = 0;
    enemyBullet.ctr = 0;
    enemyBullet.hasShot = false;
    enemyBullet.canShootAgain = true;
    enemyBullet.collided = false;
}

void Enemies::Shoot(bool shoot)
{

    int speed{500};
    if (!enemyBullet.hasShot)
    {
        enemyBullet.x = (enemyX + (enemy1.width * 2)) * scale;
        enemyBullet.y = (enemiesDestRect.y) + 110 * scale;
    }

    enemyBullet.hasShot = true;
    // enemyBullet.canShootAgain = true;
    enemyBullet.y += speed * dt;

    if (enemyBullet.y > GetScreenHeight())
    {
        enemyBullet.hasShot = false;
        enemyBullet.canShootAgain = false;
        toggleShootState = false;
    }

    if (player->GetBulletCollisionState())
    {
        enemyBullet.hasShot = false;
    }
    

    enemyBullet.rect = {static_cast<float>(enemyBullet.x), static_cast<float>(enemyBullet.y), static_cast<float>(enemyBullet.width), static_cast<float>(enemyBullet.height)};

    if (CheckCollisionRecs(player->GetPlayerRect(), enemyBullet.rect))
    {
        // std::cout << "collided" << std::endl;
        player->SetPlayerCollisionState(true);
    }
}

void Enemies::CheckCollision()
{
    for (int i = 0; i < maxBullets; i++)
    {
        if (enemyIsActive && bullets[i].collided == false)
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

    
    if (toggleShootState)
    {
        Shoot(true);
        // toggleShootState = false;
    }
}

void Enemies::Draw()
{
    if (!enemyBullet.x == 0 || !enemyBullet.y == 0)
    {
        DrawRectangle(enemyBullet.x, enemyBullet.y, (10 * scale) * 2, (20 * scale) * 2, RED);
    }

    if (enemyIsActive)
    {
        DrawTexturePro(enemy1, sourceRect, enemiesDestRect, Vector2{0, 0}, 0, WHITE);
        // DrawRectangleLines(enemiesRect.x, enemiesRect.y, enemiesRect.width, enemiesRect.height, RED);
    }

    // DrawRectangle(enemyBullet.x, 300, 10, 20, RED);
    // DrawRectangle(enemyBullet.x, enemyBullet.y, (10 * scale) * 2, (20 * scale) * 2, RED);
}
