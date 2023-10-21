#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    // Enemies *enemiesArray = new Enemies[5];
    enemiesArraySize = 5;
    enemiesArray = new Enemies[enemiesArraySize];

    // for (auto &enemy : enemiesArray)
    // {
    //     enemy.Init();
    // }

    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].SetPlayer(player);
        enemiesArray[i].SetAssetManager(assetManager);
        enemiesArray[i].SetGameUtils(gameUtils);

        // sceneManager->SetEnemies(&enemiesArray[i]);
        enemiesArray[i].Init();

        // enemiesArray[i].Update();
        // enemiesArray[i].Draw();
    }
}

void LevelManager::Unload()
{
    delete[] enemiesArray;
}

void LevelManager::Update()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        //TODO adjust placement logic
        enemiesArray[i].PostionPlacement(300 + i * 300, 300);
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
