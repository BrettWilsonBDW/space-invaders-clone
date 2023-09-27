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

private:
    void PackAllAssets();
    void LoadAllAssets();
    GameUtils* gameUtils;
    // GameUtils gameUtils;

    Font font;
    Texture2D logo;
    Texture2D ship;
};
