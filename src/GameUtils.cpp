#include "GameUtils.hpp"

GameUtils::GameUtils()
{
}

void GameUtils::CalcScale(int windowWidth, int windowHeight)
{
    targetWidth = windowWidth;
    targetHeight = windowHeight;

    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    scaleX = (float)screenWidth / targetWidth;
    scaleY = (float)screenHeight / targetHeight;

    scale = std::min(scaleX, scaleY);
}