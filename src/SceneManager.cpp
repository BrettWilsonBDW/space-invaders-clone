#include "SceneManager.hpp"

#include <iostream>
#include <sstream>
#include <string>

SceneManager::SceneManager()
{
}

/**
 * Initializes the scenes for the SceneManager.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void SceneManager::InitScenes()
{
    // dont forget to set new imgs here
    font = assetManager->GetFont();
    logo = assetManager->Getlogo();
    background = assetManager->GetBackGround();
}

/**
 * Unloads the scene manager by unloading the font, logo, and background textures.
 *
 * @throws ErrorType description of error
 */
void SceneManager::Unload()
{
    UnloadFont(font);
    UnloadTexture(logo);
    UnloadTexture(background);
}

/**
 * Draw the background of the scene.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void SceneManager::DrawBackground()
{
    DrawTextureEx(background, Vector2{0, 0}, 0, (gameUtils->GetScale() * 1.5), WHITE);
    // DrawTextureEx(background, Vector2{0, 0}, 0, (0.5 * 1.5), WHITE);
}

/**
 * Displays the splash screen of the game.
 *
 * @throws ErrorType if there is an error while displaying the splash screen.
 */
void SceneManager::SplashScreen()
{
    // DrawBackground();

    float logoSacle = gameUtils->GetScale() / 3;
    Vector2 logoCenter{(static_cast<float>(windowWidth) / 2) - (logo.width * logoSacle / 2), (static_cast<float>(windowHeight) / 2) - (logo.height * logoSacle / 2)};
    DrawTextureEx(logo, logoCenter, 0, logoSacle, WHITE);

    std::string text = u8"   2023 | Made by Brett Wilson\n              with Raylib";
    Vector2 logoTextCenter{(static_cast<float>(windowWidth) / 2) - (logo.width * logoSacle / 2), (((static_cast<float>(windowHeight) / 2) - (logo.height * logoSacle / 2)) + logo.height * logoSacle) + 20};
    float centerX = logoTextCenter.x + (logo.width * logoSacle / 2);
    logoTextCenter.x = centerX - MeasureTextEx(font, text.c_str(), 16, 2).x / 2;
    DrawText(u8"\u00A9", logoTextCenter.x, logoTextCenter.y, 16, WHITE); // for the copyright symbol
    DrawTextEx(font, text.c_str(), logoTextCenter, 16, 2, WHITE);
}

/**
 * Pause the menu and display a paused message on the screen.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void SceneManager::PauseMenu()
{
    DrawBackground();

    int windowSizes[][2] = {
        {800, 400},   // KEY_ONE
        {1920 / 2, 1080 / 2}, // KEY_TWO
        {1440, 2560}, // KEY_THREE
        {600, 1024},  // KEY_FOUR
        {768, 1366},  // KEY_FIVE
        {1024, 2048}, // KEY_SIX
        {1280, 720},  // KEY_SEVEN
        {1920, 1080}, // KEY_EIGHT
        {2560, 1440}  // KEY_NINE
    };

    for (int key = KEY_ONE; key <= KEY_NINE; key++)
    {
        if (IsKeyPressed(key))
        {
            int width = windowSizes[key - KEY_ONE][0];
            int height = windowSizes[key - KEY_ONE][1];
            SetWindowSize(width, height);
            SetWindowPosition(0, 5);
        }
    }


    DrawTextEx(font, "Paused", Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2}, 16, 2, WHITE);
    DrawTextEx(font, "Press ESC to resume", Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 + 20}, 16, 2, WHITE);

    DrawTextEx(font, "\n\n1: 360x720\n\n2: 960x540\n\n3: 1440x2560\n\n4: 600x1024\n\n5: 768x1366\n\n6: 1024x2048\n\n7: 1280x720\n\n8: 1920x1080\n\n9: 2560x1440\n", Vector2{static_cast<float>(windowWidth) / 4, static_cast<float>(windowHeight) / 4}, 16, 2, WHITE);
    // DrawTextEx(font, windowSizesString.str(), Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 + 20}, 16, 2, WHITE);
}

/**
 * GameScreen function of SceneManager class.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void SceneManager::GameScreen()
{
    // DrawBackground();
    player->DrawPlayer();
}

void SceneManager::DrawScenes()
{
    DrawBackground();

    runningTime += gameUtils->GetDeltaTime();

    if (runningTime > (2.f))
    {
        splashScreen = false;
    }

    if (splashScreen)
    {
        SplashScreen();
    }

    // SplashScreen();

    GameScreen();
}