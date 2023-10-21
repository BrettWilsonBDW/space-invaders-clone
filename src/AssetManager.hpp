#pragma once

#include "raylib.h"
#include "GameUtils.hpp"

class AssetManager
{
public:
    AssetManager();

    void SetGameUtils(GameUtils *gameUtilsPass)
    {
        gameUtils = gameUtilsPass;
    }

    //set data
    Texture2D& Getlogo()
    {
        return logo;
    }
    Font& GetFont()
    {
        return font;
    }
    Texture2D& GetShip()
    {
        return ship;
    }
    Texture2D& GetBackGround()
    {
        return background;
    }
    Texture2D& GetEnemy1()
    {
        return enemy1;
    }

private:
    void PackAllAssets();
    void LoadAllAssets();
    GameUtils* gameUtils;
    // GameUtils gameUtils;

    Font font;
    Texture2D logo;
    Texture2D ship;
    Texture2D background;
    Texture2D enemy1;
};
