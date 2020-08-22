#pragma once

#include "common.hpp"
#include "core/state.hpp"

class GAME_API GameState : public State {
public:
    GameState() = default;
    virtual ~GameState() = default;

public:
    void onEnter() override;
    void onLeave() override;
    void onUpdate() override;
    void onDrawGui() override;
};
