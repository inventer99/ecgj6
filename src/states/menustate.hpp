#pragma once

#include "common.hpp"
#include "core/state.hpp"

class GAME_API MenuState : public State {
public:
    MenuState() = default;
    virtual ~MenuState() = default;

protected:
    void onEnter() override;
    void onLeave() override;
    void onUpdate() override;
    void onDrawGui() override;
};
