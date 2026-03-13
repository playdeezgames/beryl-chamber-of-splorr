#pragma once
#include "worlddata.h"
#include "itemdata.h"
class Item
{
private:
    WorldData& _worldData;
    size_t _index;
    Item();
    ItemData& GetItemData();
    const ItemData& GetItemData() const;
public:
    Item(WorldData& worldData, size_t index):_worldData(worldData), _index(index){}
    void Initialize();
    ItemType GetItemType() const;
};