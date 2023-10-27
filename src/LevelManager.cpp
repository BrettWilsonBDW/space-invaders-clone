#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    enemiesArraySize = 5;
    enemiesArray = new Enemies[enemiesArraySize];

    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].SetPlayer(player);
        enemiesArray[i].SetAssetManager(assetManager);
        enemiesArray[i].SetGameUtils(gameUtils);

        enemiesArray[i].Init();

        // TODO adjust placement logic
        enemiesArray[i].PostionPlacement(300 + i * 200, 100);
    }
}

void LevelManager::Unload()
{
    delete[] enemiesArray;
}

void LevelManager::Update(float dt)
{
    // float timePassed{};
    timePassed += dt;
    // int ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize + 1);
    for (int i = 0; i < enemiesArraySize; i++)
    {
        // gameUtils->GetRandomNumber(0, enemiesArraySize + 1);
        // enemiesArray[i].PostionPlacement(300 + i * 300, 300);
        enemiesArray[i].SetDeltaTime(dt);
        // if (timePassed > 0.50 && !enemiesArray[i].enemyBullet.hasShot)
        // {
        //     enemiesArray[gameUtils->GetRandomNumber(0, enemiesArraySize + 1)].Shoot(true);
        //     // enemiesArray[ranNum].Shoot(true);
        //     timePassed = 0;
        // }

        //TODO fix below to have random shots from random enemy
        enemiesArray[i].Shoot(true);
        enemiesArray[i].Movement();
        enemiesArray[i].Update();
    }
}

void LevelManager::Draw()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].Draw();
    }
}
