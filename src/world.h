#pragma once
#include "common.h"
#include "worlddata.h"
#include "board.h"
class World
{
private:
    WorldData& _worldData;
    World();
public:
    World(WorldData& worldData);
    void Initialize();
    Board CreateBoard(size_t columns, size_t rows, LocationType locationType);
};