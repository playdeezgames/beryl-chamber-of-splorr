#pragma once
#include "common.h"
#include "worlddata.h"
class Character
{
private:
    WorldData& _worldData;
    size_t _index;
    Character();
public:
    Character(WorldData& worldData, size_t index);
    size_t GetIndex() const;
};