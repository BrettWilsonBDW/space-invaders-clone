#include "SceneManager.hpp"

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

    if (IsKeyPressed(KEY_ONE))
    {
        int width = 360;
        int height = 720;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_TWO))
    {
        int width = 1080;
        int height = 1920;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_THREE))
    {
        int width = 1440;
        int height = 2560;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_FOUR))
    {
        int width = 600;
        int height = 1024;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_FIVE))
    {
        int width = 768;
        int height = 1366;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_SIX))
    {
        int width = 1024;
        int height = 2048;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_SEVEN))
    {
        int width = 1280;
        int height = 720;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_EIGHT))
    {
        int width = 1920;
        int height = 1080;
        SetWindowSize(width, height);
    }

    if (IsKeyPressed(KEY_NINE))
    {
        int width = 2560;
        int height = 1440;
        SetWindowSize(width, height);
    }

    DrawTextEx(font, "Paused", Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2}, 16, 2, WHITE);
    DrawTextEx(font, "Press ESC to resume", Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 + 20}, 16, 2, WHITE);

    DrawTextEx(font, "\n\n360x720\n\n1080x1920\n\n1440x2560\n\n600x1024\n\n768x1366\n\n1024x2048\n\n1280x720\n\n1920x1080\n\n2560x1440\n", Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 + 20}, 16, 2, WHITE);
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