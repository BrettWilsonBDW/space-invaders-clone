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
        enemiesArray[i].Update();
        // enemiesArray[i].Draw();
    }
}

void LevelManager::Draw()
{
    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].Draw();
    }
}

// TODO implement this

// IDEA: Build an array of enemies and pass in information about their placement. Handle the passing of the instances from GameLoop as seen below.

// MyClass *arr; // Declare a pointer to MyClass

// int size;
// std::cout << "Enter the size of the array: ";
// std::cin >> size;

// arr = new MyClass[size]; // Allocate memory for the array

// // Use the array as needed

// delete[] arr; // Deallocate the memory when done
