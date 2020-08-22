#pragma once

#include "common.hpp"

class Game;

struct GAME_API GameStatics {
    static int width;
    static int height;

    static Game* game;
};