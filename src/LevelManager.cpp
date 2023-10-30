#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    enemiesArraySize = 5;
    enemiesArray = new Enemies[enemiesArraySize];
    enemyAliveArray = new int[enemiesArraySize];

    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].SetPlayer(player);
        enemiesArray[i].SetAssetManager(assetManager);
        enemiesArray[i].SetGameUtils(gameUtils);

        enemiesArray[i].Init();

        // TODO adjust placement logic
        enemiesArray[i].PostionPlacement(300 + i * 200, 100);

        enemyAliveArray[i] = 1;
    }
}

void LevelManager::Unload()
{
    delete[] enemiesArray;
    delete[] enemyAliveArray;
}

void LevelManager::Update(float dt)
{
    // TODO gain more control over how many bullets are on the screen
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    timePassed += dt;
    threshold = 10.0f / 60.0f;

    if (!enemiesArray[ranNum].enemyBullet.hasShot)
    {
        ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize - 1);
    }

    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].SetDeltaTime(dt);
        enemiesArray[i].Movement();
        enemiesArray[i].Update();

        if (!enemiesArray[i].GetAliveState())
        {
            enemyAliveArray[i] = 0;
        }
    }

    if (enemyAliveArray[ranNum] == 1 && timePassed >= threshold)
    {
        enemiesArray[ranNum].SetShootState(true);
        timePassed = 0;
    }
    else
    {
        ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize - 1);
    }

    amtDead = 0;
    for (int i = 0; i < enemiesArraySize; i++)
    {
        if (enemyAliveArray[i] == 0)
        {
            amtDead++;
        }
    }

    if (amtDead == enemiesArraySize)
    {
        gameWinState = true;
    }
}

void LevelManager::Draw()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].Draw();
    }

    if (gameWinState)
    {
        DrawText("You Have Won!", (GetScreenWidth() / 2) - 100, GetScreenHeight() / 2, 30, RED);
    }
}
