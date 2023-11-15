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
    int GetMaxBullets() { return maxBulletCtr; }
    void SetPlayerCollisionState(bool collision) { playerCollision = collision; }
    // void SetPlayerCollisionState(bool collision) { playerCollision = collision; }
    bool GetBulletCollisionState() { return bulletCollisionState; }

    // Return a pointer to the Bullets array in GetBullets()
    Bullets *GetBullets() { return bullets; }

    void Init();
    void Unload();
    void playerControls();
    void CheckPlayerBounds();
    void Shoot(float dt);
    void CheckPlayerCollision();
    void TrackPlayerLives();
    void Update(float dt, bool canShoot = true);
    void Reset();
    void updatePlayerPersistance();
    void DrawPlayer();
    void GetPlayerCanMove(bool canShoot)
    {
        playerCanMove = canShoot;
    }


    int playerCollisionCtr{};
    bool playerIsDead{};

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

    int maxBulletCtr{maxBullets};

    int shootCtr{};

    Bullets bullets[maxBullets];

    bool playerCollision{};

    int lifeCtr{};
    int maxLives{3};
    int lifeCtrDown{maxLives};

    bool bulletCollisionState{};
    bool playerIsAlive{true};

    bool playerCanMove{true};
};
