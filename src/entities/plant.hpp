#pragma once

#include "common.hpp"
#include "core/entity.hpp"
#include "plantgrowthstate.hpp"

class GAME_API Plant : public Entity {
    PlantGrowthState growthState = PlantGrowthState::Sapling;

public:
    Plant() = default;
    virtual ~Plant() = default;

public:
    void onStart() override;
    void onStop() override;
    void onUpdate() override;
    void onDraw() override;

private:
    void onSeedComplete();
};
