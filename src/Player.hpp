#pragma once

#include "raylib.h"
#include "raymath.h"
#include "AssetManager.hpp"
#include "GameUtils.hpp"

// struct Bullets
// {
//     int x{};
//     int y{};
//     int width{};
//     int height{};
//     int ctr{};
//     bool hasShot{};
//     bool canShootAgain{};
//     Rectangle rect;
// };

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
    int GetplayerPosX() { return playerPosX * gameUtils->GetScale(); }
    int GetBulletCount() { return shootCtr; }
    // Bullets GetBullets() { return bullets; }

    // Return a pointer to the Bullets array in GetBullets()
    Bullets *GetBullets()
    {
        return bullets;
    }

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

    // TODO clean up unused

    AssetManager *assetManager;
    GameUtils *gameUtils;
    Texture2D ship;

    int windowWidth{};
    int windowHeight{};
    float scale{};
    int playerSize{8};

    Rectangle playerRect{};
    Rectangle shipDestRect{};
    Rectangle shipRect{};

    int playerSpeed{};
    int playerVelocity{};
    int playerPosX{};
    int screenPos{};

    bool hasShot{};
    bool canShootAgain{true};

    // set  max amount of bullets allowed to be on the screen at once
    static const int maxBullets{3};

    int shootCtr{};

    Bullets bullets[maxBullets];
};
