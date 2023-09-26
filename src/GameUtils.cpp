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

Texture2D GameUtils::LoadImgFromFile(void *DATA, int WIDTH, int HEIGHT, int FORMAT)
{
    Image texture = {
        .data = DATA,
        .width = WIDTH,
        .height = HEIGHT,
        .mipmaps = 1,
        .format = FORMAT};

    Texture2D img = LoadTextureFromImage(texture);

    return img;
}

/**
 * Packs a texture by loading an image, exporting it as code, and then unloading the image.
 *
 * @param filePath the path to the image file
 * @param outputFilename the name of the output file and path
 *
 * @throws ErrorType if there is an error in loading, exporting, or unloading the image
 */
void GameUtils::packTexture(const std::string &filePath, const std::string& outputFilename)
{
    // Load image
    Image image = LoadImage(filePath.c_str());

    // // Export image as code
    ExportImageAsCode(image, outputFilename.c_str());

    // Unload image
    UnloadImage(image);
}