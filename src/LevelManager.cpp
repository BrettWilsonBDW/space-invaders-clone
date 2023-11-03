#include "LevelManager.hpp"

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    levelOne.SetPlayer(player);
    levelOne.SetAssetManager(assetManager);
    levelOne.SetGameUtils(gameUtils);

    levelOne.Init();
}

void LevelManager::Unload()
{
    levelOne.Unload();
}

void LevelManager::Update(float dt)
{
    levelOne.update(dt);
}

void LevelManager::Draw()
{
    levelOne.draw();
}
