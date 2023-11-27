#include "LevelManager.hpp"
// #include <iostream>

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    for (auto &level : levels)
    {
        level.SetPlayer(player);
        level.SetAssetManager(assetManager);
        level.SetGameUtils(gameUtils);
    }

    levels[0].SetEnemyAmt(5);
    levels[0].Init();

    levels[1].SetEnemyAmt(8);
    levels[1].Init();

    //TODO make the two levels below below

    //part of a double stacked level
    levels[2].SetEnemyAmt(5);
    levels[2].Init();
    levels[2].ignoreSpecialAbilities = true;

    // part of the above stack 
    levels[3].SetEnemyAmt(5);
    levels[3].Init(300, 300);
    levels[3].ignoreSpecialAbilities = true;

    levels[4].SetEnemyAmt(7);
    levels[4].Init();

    levels[5].SetEnemyAmt(3);
    levels[5].Init();

    levels[6].SetEnemyAmt(5);
    levels[6].Init();
}

void LevelManager::Unload()
{
    for (auto &level : levels)
    {
        level.Unload();
    }
}

void LevelManager::DisplayControls(float dt)
{
    playerCanMove = false;

    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        toggleDisplayControls = !toggleDisplayControls;
        playerCanMove = true;
    }
}

void LevelManager::handleStats()
{
    statsString = "Stats Menu\nbullets fired " + std::to_string(shootCtr) + "\nLevels finished " + std::to_string(nextLevelNum) + "\nTime completed in: " + std::to_string(timePassed) + " seconds\nPress enter to continue";
}

void LevelManager::HandleStatsMenu(bool toggle)
{
    if (toggle)
    {
        toggleStatsMenu = true;
    }

    if ((IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) && handleStatsToggle)
    {
        toggleStatsMenu = false;
        handleStatsToggle = false;
        shootCtr = 0;
        timePassed = 0.0f;
    }
}

void LevelManager::Update(float dt)
{
    if (IsKeyPressed(KEY_SPACE) && !toggleStatsMenu)
    {
        shootCtr++;
    }

    if (!toggleStatsMenu)
    {
        timePassed += dt;
    }

    playerCanMove = !toggleStatsMenu;

    if (publicToggle)
    {
        // increments in game loop
        nextLevelNum = nextLevelNumPublic;
    }

    if (levels[0].gameWinState || levels[1].gameWinState || (levels[2].gameWinState && levels[3].gameWinState) || levels[4].gameWinState || levels[5].gameWinState || levels[6].gameWinState)
    {
        nextLevelNum++;
        handleStatsToggle = true;

        for (auto &level : levels)
        {
            level.gameWinState = false;
        }
    }

    switch (nextLevelNum)
    {
    case 0:
        if (!toggleDisplayControls)
        {
            DisplayControls(dt);
        }
        else
        {
            levels[0].update(dt);
        }

        break;

    case 1:
        // be mindful that this code unloads the previous level not the current one soo in this case level num 0 is the previous level
        levels[0].unloadToggle = true;

        HandleStatsMenu(handleStatsToggle);

        if (!toggleStatsMenu)
        {
            levels[1].update(dt);
        }
        break;

    case 2:
        levels[1].unloadToggle = true;

        HandleStatsMenu(handleStatsToggle);

        if (!toggleStatsMenu)
        {
            levels[2].update(dt);
            levels[3].update(dt);
        }
        break;

    case 3:
        levels[2].unloadToggle = true;
        levels[3].unloadToggle = true;

        HandleStatsMenu(handleStatsToggle);

        if (!toggleStatsMenu)
        {
            levels[4].update(dt, 15);
        }
        break;

    case 4:
        levels[4].unloadToggle = true;

        HandleStatsMenu(handleStatsToggle);

        if (!toggleStatsMenu)
        {
            levels[5].update(dt, 10, 1000);
        }
        break;

    case 5:
        levels[5].unloadToggle = true;

        HandleStatsMenu(handleStatsToggle);

        if (!toggleStatsMenu)
        {
            levels[6].update(dt, 15, 750);
        }
        break;

    case 6:
        levels[6].unloadToggle = true;

        HandleStatsMenu(handleStatsToggle);

        // levels[7].update(dt, 15, 750);
        break;

    default:
        std::cout << "error in logic the level with number: " << nextLevelNum << " is not found" << std::endl;
        break;
    }
}

void LevelManager::Reset()
{
    nextLevelNum = 0;
    toggleStatsMenu = false;
    timePassed = 0.0f;
    shootCtr = 0;
    handleStatsToggle = false;

    // reset all levels
    Unload();
    Init();
    for (auto &level : levels)
    {
        level.Reset();
    }
}

void LevelManager::Draw()
{
    for (auto &level : levels)
    {
        level.draw();
    }

    if (toggleStatsMenu)
    {
        handleStats();

        int textWidth = MeasureText(statsString.c_str(), 20);

        int x = (GetScreenWidth() - textWidth) / 2;
        int y = 100;

        // TODO scale screen size text
        DrawText(statsString.c_str(), x, y, 20, WHITE);
    }

    if (!toggleDisplayControls)
    {
        std::string text = "\nControls: a d space\npress enter to start game";
        int textWidth = MeasureText(text.c_str(), 20);

        int x = (GetScreenWidth() - textWidth) / 2;
        int y = (GetScreenHeight() - 200) * gameUtils->GetScale();

        // TODO scale screen size text
        DrawText(text.c_str(), x, y, 20, WHITE);
    }
}
