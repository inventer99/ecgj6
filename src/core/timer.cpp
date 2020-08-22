#include "timer.hpp"

#include <raylib.h>

#include "gamestatics.hpp"
#include "game.hpp"


Timer::Timer(float time, bool completeOnEnd = false) : limit(time) {
    if(completeOnEnd) {
        done_.get_observable().subscribe([this](auto) {
            GameStatics::game->removeTimer(this);
        });
    }
}

Timer::~Timer() {
    done_.get_subscriber().on_completed();
}

void Timer::start() {
    playing = true;
}

void Timer::pause() {
    playing = false;
}

void Timer::reset() {
    elapsed = 0;
    playing = false;
}

void Timer::update() {
    if(playing) {
        elapsed += GetFrameTime();

        if (elapsed >= limit) {
            playing = false;
            done_.get_subscriber().on_next(nullptr);
        }
    }
}
