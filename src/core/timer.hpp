#pragma once

#include <rxcpp/rx.hpp>

#include "common.hpp"


class GAME_API Timer {
    float elapsed = 0;
    float limit;

    bool playing = false;

    rxcpp::rxsub::subject<void*> done_;

public:
    explicit Timer(float time, bool completeOnEnd);
    virtual ~Timer();

public:
    void start();
    void pause();
    void reset();
    void update();

public:
    inline float getElapsed() { return elapsed; }
    inline rxcpp::observable<void*> getDone_() { return done_.get_observable(); }
};
