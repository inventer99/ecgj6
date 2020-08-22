#pragma once

#include <raygui.h>

#include "gamestatics.hpp"


inline float centeredX(float width) {
    return ((float)GetScreenWidth() / 2.f) - (width / 2.f);
}

inline float centeredY(float height) {
    return ((float)GetScreenHeight() / 2.f) - (height / 2.f);
}

inline Rectangle centeredRect(float width, float height) {
    return {
        centeredX(width),
        centeredY(width),
        width,
        height
    };
}
