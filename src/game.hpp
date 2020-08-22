#pragma once

#include <vector>

#include "common.hpp"
#include "core/entity.hpp"
#include "core/state.hpp"
#include "core/timer.hpp"
#include "gamestate.hpp"


class GAME_API Game {
private:
    bool running = true;

    std::vector<Entity*> entities;
    std::vector<Timer*> timers;

    State* state = nullptr;

public:
    Game();

public:
    int run();
    void stop();

    void addTimer(Timer* timer);
    void removeTimer(Timer* timer);

private:
    void drawGui();

public:
    inline State* getState() { return state; }
};