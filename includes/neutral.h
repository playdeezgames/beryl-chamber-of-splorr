#pragma once
#include "common.h"
#include "gamestatetype.h"
#include "world.h"
class Neutral
{
public:
    static std::optional<GameStateType> DetermineState(const World&);
};