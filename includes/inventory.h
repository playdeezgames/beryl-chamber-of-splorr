#pragma once
#include "worlddata.h"
class Inventory
{
private:
    WorldData& _worldData;
    size_t _index;
    Inventory();
public:
    Inventory(WorldData& worldData, size_t index):_worldData(worldData),_index(index){}
    size_t GetIndex() const {return _index;}
};