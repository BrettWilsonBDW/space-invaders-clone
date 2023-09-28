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

/**
 * Packs all the assets.
 *
 * This function packs the assets by calling specific functions to pack each asset individually.
 * The packed assets are saved in a different file format.
 *
 * @throws ErrorType If there is an error while packing the assets.
 */
void AssetManager::PackAllAssets()
{
    // pack assets
    // gameUtils->packTexture("assets/testAssets/logo.png", "../assets/testAssets/logo.h");
    // gameUtils->packFont("assets/testAssets/Roboto.ttf", "../assets/testAssets/Roboto.h");
    // gameUtils->packTexture("assets/playership.png", "../assets/playership.h");
    // gameUtils->packTexture("assets/spaceBackground.png", "../assets/spaceBackground.h");
}

/**
 * Loads all the assets required for the game.
 *
 * @throws ErrorType description of error
 */
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
