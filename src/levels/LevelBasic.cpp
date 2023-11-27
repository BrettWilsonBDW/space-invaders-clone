#include "LevelBasic.hpp"

LevelBasic::LevelBasic()
{
}

void LevelBasic::Init(int x, int y)
{
    enemiesArraySize = enemyAmt;
    enemiesArray = new Enemies[enemiesArraySize];
    enemyAliveArray = new int[enemiesArraySize];

    for (int i = 0; i < enemiesArraySize; i++)
    {
        enemiesArray[i].SetPlayer(player);
        enemiesArray[i].SetAssetManager(assetManager);
        enemiesArray[i].SetGameUtils(gameUtils);

        enemiesArray[i].Init();

        // TODO adjust placement logic
        enemiesArray[i].PostionPlacement(x + i * 200, y);
        // enemiesArray[i].PostionPlacement(300 + i * 200, 100);

        enemyAliveArray[i] = 1;
    }
}

int LevelBasic::findLastEnemyArrayPos(int* array, int size)
{
    int target = 1;

    auto position = std::find(array, array + size, target);

    if (position != array + size)
    {
        return position - array;
    }
    else
    {
        std::cout << "error " << target << " is not found in the array." << std::endl;
        return -1;
    }
}

void LevelBasic::Unload()
{
    delete[] enemiesArray;
    delete[] enemyAliveArray;
}

void LevelBasic::update(float dt, int speed, int bulletSpeed)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    timePassed += dt;
    timeWaited += dt;
    threshold = 10.0f / 60.0f;

    if (!enemiesArray[ranNum].enemyBullet.hasShot)
    {
        ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize - 1);
    }

    for (int i = 0; i < enemiesArraySize; i++)
    {
        // enemiesArray[i].SetDeltaTime(dt);
        enemiesArray[i].Movement(speed);
        enemiesArray[i].bulletSpeed = bulletSpeed;
        enemiesArray[i].Update(dt);

        if (!enemiesArray[i].GetAliveState())
        {
            enemyAliveArray[i] = 0;
        }
    }

    // wait a set time before giving enemy a chance to shoot
    if (timeWaited >= 1.0f)
    {
        if (enemyAliveArray[ranNum] == 1 && timePassed >= threshold)
        {
            enemiesArray[ranNum].SetShootState(true);
            timePassed = 0;
        }
        else
        {
            // attempt to skip dead enemies
            ranNum = gameUtils->GetRandomNumber(0, enemiesArraySize - 1);
        }
    }

    // count amt of dead enemies if all dead set win condition
    amtDead = 0;
    for (int i = 0; i < enemiesArraySize; i++)
    {
        if (enemyAliveArray[i] == 0)
        {
            amtDead++;
        }
    }

    //handle enemy win condition
    if (amtDead == enemiesArraySize && toggleWinCondition)
    {
        gameWinState = true;
        toggleWinCondition = false;
    }

    // handle last enemy standing condition
    if (amtDead == enemiesArraySize - 1 && !ignoreSpecialAbilities)
    {
        // set last enemy
        enemiesArray[findLastEnemyArrayPos(enemyAliveArray, enemiesArraySize)].lastEnemy = true;
    }
}

void LevelBasic::Reset()
{
    toggleWinCondition = true;
    gameWinState = false;
    unloadToggle = false;
    timeWaited = 0;
}

void LevelBasic::draw()
{
    if (!unloadToggle)
    {
        for (int i = 0; i < enemiesArraySize; i++)
        {
            enemiesArray[i].Draw();
        }
    }
}