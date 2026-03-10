#pragma once
#include "common.h"
#include "gamestatetype.h"
#include "world.h"
class Neutral
{
public:
    static GameStateType DetermineState(const World&);
};