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
    threshold = 10.0f / 60.0f;

    // int ranNum{};
    
    //TODO skip dead enemies
    if (timePassed >= threshold && !enemiesArray[ranNum].enemyBullet.hasShot)
    {
        ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize + 1);
        timePassed = 0;
    }

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

        // enemiesArray[ranNum].Shoot(true);
        // enemiesArray[0 + i].Shoot(true);
        // TODO fix below to have random shots from random enemy
        // enemiesArray[i].Shoot(true);
        enemiesArray[i].Movement();
        enemiesArray[i].Update();
    }

    // if (enemiesArray->enemyBullet.canShootAgain)
    // {
    //     enemiesArray[ranNum].Shoot(true);
    //     enemiesArray->enemyBullet.canShootAgain = false;
    // }

    // if (enemiesArray->enemyBullet.y > GetScreenHeight())
    // {
    enemiesArray[ranNum].Shoot(true);
    // enemiesArray->enemyBullet.canShootAgain = false;
    // }
}

void LevelManager::Draw()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].Draw();
    }
}
