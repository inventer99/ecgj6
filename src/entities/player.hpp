#pragma once

#include "common.hpp"
#include "core/entity.hpp"

class GAME_API Player : public Entity {


public:
    Player() = default;
    virtual ~Player() = default;

public:
    void onStart() override;
    void onStop() override;
    void onUpdate() override;
    void onDraw() override;
};
