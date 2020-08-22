#include "plant.hpp"

#include <raylib.h>

#include "core/timer.hpp"
#include "gamestatics.hpp"
#include "game.hpp"

const float SAPLING_TO_GROWN_TIME = 5.f;

void Plant::onStart() {
    auto t = new Timer(SAPLING_TO_GROWN_TIME, true);
    t->getDone_().subscribe([this](auto) { onSeedComplete(); });
    t->start();
    GameStatics::game->addTimer(t);
}

void Plant::onStop() {

}

void Plant::onUpdate() {

}

void Plant::onDraw() {

}

void Plant::onSeedComplete() {
    std::cout << "On Seed Complete" << std::endl;
}