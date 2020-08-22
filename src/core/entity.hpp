#pragma once

#include <raymath.h>

#include "common.hpp"

class GAME_API Entity {
protected:
    Vector2 position { 0, 0 };
    Matrix rotation;

public:
    Entity() = default;
    virtual ~Entity() = default;

public:
    virtual void onStart() = 0;
    virtual void onStop() = 0;
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
};
