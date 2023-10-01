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

    void Init();
    void Unload();
    Rectangle GetPlayerRect() { return playerRect; };
    void updatePlayerPersistance();
    void UpdatePlayer();
    void playerControls();
    void CheckPlayerBounds();
    void DrawPlayer();

    int GetplayerPosX()
    {
        // return playerMove;
        // return shipDestRect;

        return playerPosX;
    }

private:
    void CalcScale();

    AssetManager *assetManager;
    GameUtils *gameUtils;
    Texture2D ship;

    int windowWidth{};
    int windowHeight{};
    int scale{};
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
};
