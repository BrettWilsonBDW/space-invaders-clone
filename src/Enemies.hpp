#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Player.hpp"
#include "AssetManager.hpp"
#include "GameUtils.hpp"
// #include "SceneManager.hpp"

class Enemies
{
public:
    Enemies();
    void SetPlayer(Player *playerPass)
    {
        player = playerPass;
    }
    void SetAssetManager(AssetManager *assetManagerPass)
    {
        assetManager = assetManagerPass;
    }
    void SetGameUtils(GameUtils *gameUtilsPass)
    {
        gameUtils = gameUtilsPass;
    }

    // void SetSceneManager(SceneManager *sceneManagerPass)
    // {
    //     sceneManager = sceneManagerPass;
    // }

    void Init();
    void CheckCollision();
    void PostionPlacement();
    void Update();
    void Draw();

private:
    Player *player;
    AssetManager *assetManager;
    GameUtils *gameUtils;
    Bullets *bullets;
    // SceneManager *sceneManager;

    Texture2D enemy1{};

    Rectangle enemiesRect{};

    Rectangle sourceRect{};
    Rectangle enemiesDestRect{};

    bool enemyIsActive{true};

    int maxBullets{};

    float scale{};
};
