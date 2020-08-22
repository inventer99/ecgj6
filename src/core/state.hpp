#pragma once

#include "common.hpp"

class GAME_API State {
public:
    State() = default;
    virtual ~State() = default;

public:
    virtual void onEnter() = 0;
    virtual void onLeave() = 0;
    virtual void onUpdate() = 0;
    virtual void onDrawGui() {}
};
