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
    void PackAllAssets();

    //set data
    Texture2D Getlogo()
    {
        return logo;
    }
    Font GetFont()
    {
        return font;
    }

private:
    void LoadAllAssets();
    GameUtils* gameUtils;
    // GameUtils gameUtils;

    Texture2D logo;
    Font font;
};
