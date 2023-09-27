#include "SceneManager.hpp"

SceneManager::SceneManager()
{
}

void SceneManager::InitScenes()
{
    // dont forget to set new imgs here
    font = assetManager->GetFont();
    logo = assetManager->Getlogo();
}

void SceneManager::Unload()
{
    UnloadFont(font);
    UnloadTexture(logo);
}

void SceneManager::SplashScreen()
{
    float logoSacle = gameUtils->GetScale() / 3;
    Vector2 logoCenter{(static_cast<float>(windowWidth) / 2) - (logo.width * logoSacle / 2), (static_cast<float>(windowHeight) / 2) - (logo.height * logoSacle / 2)};
    DrawTextureEx(logo, logoCenter, 0, logoSacle, WHITE);

    std::string text = u8"   2023 | Made by Brett Wilson";
    Vector2 logoTextCenter{(static_cast<float>(windowWidth) / 2) - (logo.width * logoSacle / 2), (((static_cast<float>(windowHeight) / 2) - (logo.height * logoSacle / 2)) + logo.height * logoSacle) + 20};
    float centerX = logoTextCenter.x + (logo.width * logoSacle / 2);
    logoTextCenter.x = centerX - MeasureTextEx(font, text.c_str(), 16, 2).x / 2;
    DrawText(u8"\u00A9", logoTextCenter.x, logoTextCenter.y, 16, WHITE); // for the copyright symbol
    DrawTextEx(font, text.c_str(), logoTextCenter, 16, 2, WHITE);
}

void SceneManager::PauseMenu()
{
    DrawTextEx(font, "Paused", Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2}, 16, 2, WHITE);
    DrawTextEx(font, "Press ESC to resume", Vector2{static_cast<float>(windowWidth) / 2, static_cast<float>(windowHeight) / 2 + 20}, 16, 2, WHITE);
}

void SceneManager::GameScreen()
{
    player->DrawPlayer();
}