#pragma once
#include "worlddata.h"
#include "itemdata.h"
class Item
{
private:
    WorldData& _worldData;
    size_t _index;
    Item();
public:
    Item(WorldData& worldData, size_t index):_worldData(worldData), _index(index){}
};