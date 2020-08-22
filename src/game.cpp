#include "game.hpp"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raygui.h>

#include <iostream>
#include <rxcpp/rx.hpp>

#include "entities/player.hpp"
#include "states/menustate.hpp"
#include "gamestatics.hpp"
#include "entities/plant.hpp"

Game::Game() {
    GameStatics::game = this;
}

int Game::run() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(GameStatics::width, GameStatics::height, "RayLib Basics");

    SetTargetFPS(60);

    auto player = new Player();
    entities.emplace_back(player);

    auto menuState = new MenuState();
    state = menuState;

    auto plant = new Plant();
    entities.emplace_back(plant);

    for(auto entity : entities) {
        entity->onStart();
    }

    while (!WindowShouldClose() && running) {
        for(auto entity : entities) {
            entity->onUpdate();
        }

        for(auto timer : timers) {
            timer->update();
        }

        BeginDrawing();

        ClearBackground(MAGENTA);
        
        for(auto entity : entities) {
            entity->onDraw();
        }

        drawGui();

        EndDrawing();
    }

    for(auto entity : entities) {
        entity->onStop();
        delete entity;
    }

    for(auto timer : timers) {
        delete timer;
    }

    CloseWindow();

    return 0;
}

void Game::stop() {
    running = false;
}

void Game::addTimer(Timer *timer) {
    timers.emplace_back(timer);
}

void Game::removeTimer(Timer *timer) {
    std::remove(timers.begin(), timers.end(), timer);
}

void Game::drawGui() {
    state->onDrawGui();
}

int game_main() {
    Game game;
    return game.run();
}