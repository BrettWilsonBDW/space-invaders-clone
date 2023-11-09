#include "LevelManager.hpp"
#include <iostream>

LevelManager::LevelManager()
{
}

void LevelManager::Init()
{
    // TODO improve this code

    // levelOne.SetPlayer(player);
    // levelOne.SetAssetManager(assetManager);
    // levelOne.SetGameUtils(gameUtils);

    // levelOne.SetEnemyAmt(5);
    // levelOne.Init();

    // levelTwo.SetPlayer(player);
    // levelTwo.SetAssetManager(assetManager);
    // levelTwo.SetGameUtils(gameUtils);

    // levelTwo.SetEnemyAmt(8);
    // levelTwo.Init();

    // levelThree.SetPlayer(player);
    // levelThree.SetAssetManager(assetManager);
    // levelThree.SetGameUtils(gameUtils);

    // levelThree.SetEnemyAmt(5);
    // levelThree.Init();

    // levelThreeHalf.SetPlayer(player);
    // levelThreeHalf.SetAssetManager(assetManager);
    // levelThreeHalf.SetGameUtils(gameUtils);

    // levelThreeHalf.SetEnemyAmt(5);
    // levelThreeHalf.Init(300, 300);

    // Set common properties for all levels
    // LevelOne *levels[] = {&levelOne, &levelTwo, &levelThree, &levelThreeHalf};

    // levels = new LevelOne[4];

    // for (auto level : levels)
    // {
    //     level->SetPlayer(player);
    //     level->SetAssetManager(assetManager);
    //     level->SetGameUtils(gameUtils);
    // }
    // // Initialize each level with specific properties
    // levelOne.SetEnemyAmt(5);
    // levelOne.Init();
    // levelTwo.SetEnemyAmt(8);
    // levelTwo.Init();
    // levelThree.SetEnemyAmt(5);
    // levelThree.Init();
    // levelThreeHalf.SetEnemyAmt(5);
    // levelThreeHalf.Init(300, 300);

    // int lvlCtr{};
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

    levels[2].SetEnemyAmt(5);
    levels[2].Init();

    levels[3].SetEnemyAmt(5);
    levels[3].Init(300, 300);
}

void LevelManager::Unload()
{
    // levelOne.Unload();
    // levelTwo.Unload();
    // levelThree.Unload();
    // levelThreeHalf.Unload();

    for (auto &level : levels)
    {
        level.Unload();
    }
}

void LevelManager::Update(float dt)
{
    // if (publicToggle)
    // {
    //     nextLevelNum = nextLevelNumPublic;
    // }

    // if (levelOne.gameWinState || levelTwo.gameWinState || (levelThree.gameWinState && levelThreeHalf.gameWinState))
    // {
    //     nextLevelNum++;
    //     levelOne.gameWinState = false;
    //     levelTwo.gameWinState = false;
    //     levelThree.gameWinState = false;
    // }

    // switch (nextLevelNum)
    // {
    // case 0:
    //     levelOne.update(dt);
    //     break;

    // case 1:
    //     levelTwo.update(dt);
    //     levelOne.unloadToggle = true;
    //     break;

    // case 2:
    //     levelThree.update(dt);
    //     levelThreeHalf.update(dt);
    //     levelTwo.unloadToggle = true;
    //     break;

    // case 3:
    //     levelThree.unloadToggle = true;
    //     levelThreeHalf.unloadToggle = true;
    //     break;

    // case 4:
    //     break;

    // default:
    //     std::cout << "error in logic the level with number: " << nextLevelNum << " is not found" << std::endl;
    //     break;
    // }

    if (publicToggle)
    {
        nextLevelNum = nextLevelNumPublic;
    }

    // for (auto level : levels)
    // {
    //     if (level.gameWinState || (levels[2].gameWinState && levels[3].gameWinState))
    //     {
    //         nextLevelNum++;
    //         level.gameWinState = false;
    //     }
    // }

    // bool anyGameWinState = false;
    // bool levelThreeCombinedGameWinState = levels[2].gameWinState && levels[3].gameWinState;

    // for (auto& level : levels)
    // {
    //     if (level.gameWinState)
    //     {
    //         anyGameWinState = true;
    //         level.gameWinState = false;
    //     }
    // }

    // if (anyGameWinState || levelThreeCombinedGameWinState)
    // {
    //     nextLevelNum++;
    // }

    if (levels[0].gameWinState || levels[1].gameWinState || (levels[2].gameWinState && levels[3].gameWinState))
    {
        nextLevelNum++;
        levels[0].gameWinState = false;
        levels[1].gameWinState = false;
        levels[2].gameWinState = false;
        levels[3].gameWinState = false;
    }

    switch (nextLevelNum)
    {
    case 0:
        levels[nextLevelNum].update(dt);
        break;

    case 1:
        levels[nextLevelNum].update(dt);
        // be mindful that this code unloads the previous level not the current one soo in this case level num 0 is the previous level
        levels[nextLevelNum - 1].unloadToggle = true;
        break;

    case 2:
        levels[nextLevelNum].update(dt);
        levels[nextLevelNum + 1].update(dt);
        levels[nextLevelNum - 1].unloadToggle = true;
        break;

    case 3:
        levels[nextLevelNum - 1].unloadToggle = true;
        levels[nextLevelNum].unloadToggle = true;
        break;

    case 4:
        break;

    default:
        std::cout << "error in logic the level with number: " << nextLevelNum << " is not found" << std::endl;
        break;
    }
}

void LevelManager::Draw()
{
    // levelOne.draw();
    // levelTwo.draw();
    // levelThree.draw();
    // levelThreeHalf.draw();

    for (auto &level : levels)
    {
        level.draw();
    }
}
