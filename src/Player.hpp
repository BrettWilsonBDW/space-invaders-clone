#pragma once

#include "raylib.h"
#include "raymath.h"
#include "AssetManager.hpp"
#include "GameUtils.hpp"

class Player
{
public:
    Player();
    void SetAssetManager(AssetManager *assetManagerPass)
    {
        assetManager = assetManagerPass;
    }
    void SetGameUtils(GameUtils *gameUtilsPass)
    {
        gameUtils = gameUtilsPass;
    }
    Rectangle GetPlayerRect() { return playerRect; };
    int GetplayerPosX() { return playerPosX; }

    void Init();
    void Unload();
    void updatePlayerPersistance();
    void UpdatePlayer();
    void playerControls();
    void CheckPlayerBounds();
    void Shoot();
    void DrawPlayer();


private:
    void CalcScale();

    AssetManager *assetManager;
    GameUtils *gameUtils;
    Texture2D ship;

    int windowWidth{};
    int windowHeight{};
    float scale{};
    int playerSize{};

    Rectangle playerRect{};
    Rectangle shipDestRect{};
    Rectangle shipRect{};

    Vector2 playerMove{};
    bool hitBoundsLeft{};
    bool hitBoundsRight{};

    int playerSpeed{};
    int playerVelocity{};
    int playerPosX{};

    float sScale{};

    bool hasShot{};
    bool canShootAgain{true};

    Vector2 bulletVelocity{100, 100};
};
