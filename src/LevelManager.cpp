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
    timePassed += dt;
    // threshold = 10.0f / 60.0f;
    threshold = 0.1f;

    // TODO skip dead enemies
    if (timePassed >= threshold && !enemiesArray[ranNum].enemyBullet.hasShot)
    // if (timePassed >= threshold && !enemiesArray[ranNum].enemyBullet.canShootAgain)
    {
        ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize - 1);
        timePassed = 0;
    }

    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].SetDeltaTime(dt);
        enemiesArray[i].Movement();
        enemiesArray[i].Update();

        if (enemiesArray[i].GetAliveState() == false)
        {
            enemyAliveArray[i] = 0;
        }
    }

    // std::cout << ranNum << std::endl;

    if (enemyAliveArray[ranNum] == 1)
    {
        enemiesArray[ranNum].Shoot(true);
    }
    else
    {
        // enemiesArray[ranNum].Shoot(false);
        ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize - 1);
    }

    // for (int i = 0; i < enemiesArraySize; i++)
    // {
    //     std::cout << i << ": " << enemyAliveArray[i] << " ";
    // }
    // std::cout << std::endl;
}

void LevelManager::Draw()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].Draw();
    }
}
