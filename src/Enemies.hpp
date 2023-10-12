#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Player.hpp"


class Enemies
{
public:
    Enemies();
    void SetPlayer(Player *playerPass)
    {
        player = playerPass;
    }

    void Draw();
private:
    Player *player;
};
