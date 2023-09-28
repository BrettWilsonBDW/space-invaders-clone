#include "GameUtils.hpp"

GameUtils::GameUtils()
{
}

/**
 * Calculates the scale factor for a game based on the window width and height.
 *
 * @param windowWidth The width of the game window.
 * @param windowHeight The height of the game window.
 *
 * @return void
 *
 * @throws None
 */
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

/**
 * Load an image from a file and return a Texture2D object.
 *
 * @param DATA the data of the image
 * @param WIDTH the width of the image
 * @param HEIGHT the height of the image
 * @param FORMAT the format of the image
 *
 * @return the loaded Texture2D object
 *
 * @throws ErrorType if there is an error loading the image
 */
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
 * Loads a font from a file.
 *
 * @return The loaded font.
 *
 * @throws ErrorType A description of the error that can occur during font loading.
 */
Font GameUtils::LoadFontFromFile()
{
#include "../assets/fonts/Roboto.h"
    Font font = {0};

    font.baseSize = 32;
    font.glyphCount = 95;
    font.glyphPadding = 4;

    // Custom font loading
    // NOTE: Compressed font image data (DEFLATE), it requires DecompressData() function
    int fontDataSize_Roboto = 0;
    unsigned char *data = DecompressData(fontData_Roboto, COMPRESSED_DATA_SIZE_FONT_ROBOTO, &fontDataSize_Roboto);
    Image imFont = {data, 512, 256, 1, 2};

    // Load texture from image
    font.texture = LoadTextureFromImage(imFont);
    UnloadImage(imFont); // Uncompressed data can be unloaded from memory

    // Assign glyph recs and info data directly
    // WARNING: This font data must not be unloaded
    font.recs = const_cast<Rectangle *>(fontRecs_Roboto);
    font.glyphs = const_cast<GlyphInfo *>(fontGlyphs_Roboto);

    return font;
}

/**
 * Packs a texture by loading an image, exporting it as code, and then unloading the image.
 *
 * @param filePath the path to the image file
 * @param outputFilename the name of the output file and path
 *
 * @throws ErrorType if there is an error in loading, exporting, or unloading the image
 */
void GameUtils::packTexture(const std::string &filePath, const std::string &outputFilename)
{
    // Load image
    Image image = LoadImage(filePath.c_str());

    // // Export image as code
    ExportImageAsCode(image, outputFilename.c_str());

    // Unload image
    UnloadImage(image);
}

/**
 * Packs a font file into a code file.
 *
 * @param filePath the path to the font file
 * @param outputFilename the name of the output code file
 *
 * @throws ErrorType if there is an error packing the font
 */
void GameUtils::packFont(const std::string &filePath, const std::string &outputFilename)
{
    Font font = LoadFont(filePath.c_str());

    // // Export image as code
    ExportFontAsCode(font, outputFilename.c_str());

    // Unload image
    UnloadFont(font);
}

/**
 * Updates the delta time of the game.
 *
 * @return void
 */
void GameUtils::UpdateDeltaTime()
{
    dt = GetFrameTime();
}

/**
 * Updates the window position.
 *
 * @return void
 */
void GameUtils::UpdateWindowPos()
{
    windowSizeW = GetScreenWidth();
    windowSizeH = GetScreenHeight();
}