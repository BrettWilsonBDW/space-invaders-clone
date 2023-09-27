#include "AssetManager.hpp"

// asset headers
#include "../assets/logo.h"
#include "../assets/playership.h"
#include "../assets/spaceBackground.h"


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
    // gameUtils->packTexture("assets/playership.png", "../assets/playership.h");
    // gameUtils->packTexture("assets/spaceBackground.png", "../assets/spaceBackground.h");
}

void AssetManager::LoadAllAssets()
{
#if defined(PLATFORM_WEB)
    font = LoadFont("assets/fonts/Roboto.ttf");
#else
    font = gameUtils->LoadFontFromFile();
#endif

    logo = gameUtils->LoadImgFromFile(LOGO_DATA, LOGO_WIDTH, LOGO_HEIGHT, LOGO_FORMAT);
    ship = gameUtils->LoadImgFromFile(PLAYERSHIP_DATA, PLAYERSHIP_WIDTH, PLAYERSHIP_HEIGHT, PLAYERSHIP_FORMAT);
    background = gameUtils->LoadImgFromFile(SPACEBACKGROUND_DATA, SPACEBACKGROUND_WIDTH, SPACEBACKGROUND_HEIGHT, SPACEBACKGROUND_FORMAT);
}
