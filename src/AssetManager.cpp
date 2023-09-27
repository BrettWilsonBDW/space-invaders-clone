#include "AssetManager.hpp"

// asset headers
#include "../assets/testAssets/logo.h"

AssetManager::AssetManager()
{
    PackAllAssets();
    LoadAllAssets();
}

void AssetManager::PackAllAssets()
{
    // pack assets
    // gameUtils->packTexture("assets/testAssets/logo.png", "../assets/testAssets/logo.h");
    // gameUtils->packFont("assets/testAssets/Roboto.ttf", "../assets/testAssets/Roboto.h");
}

void AssetManager::LoadAllAssets()
{
#if defined(PLATFORM_WEB)
    font = LoadFont("assets/fonts/Roboto.ttf");
#else
    font = gameUtils->LoadFontFromFile();
#endif

    logo = gameUtils->LoadImgFromFile(LOGO_DATA, LOGO_WIDTH, LOGO_HEIGHT, LOGO_FORMAT);
}
