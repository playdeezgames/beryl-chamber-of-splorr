#pragma once
#include "worlddata.h"
#include "framebuffercellcolor.h"
class Item;
class Inventory
{
private:
    WorldData& _worldData;
    size_t _index;
    Inventory();
    InventoryData& GetInventoryData();
    const InventoryData& GetInventoryData() const;
public:
    Inventory(WorldData& worldData, size_t index):_worldData(worldData),_index(index){}
    size_t GetIndex() const {return _index;}
    unsigned char GetFrameCharacter() const;
    FrameBufferCellColor GetFrameForeground() const;
    void AddItem(Item item);
    void RemoveItem(Item item);
    bool HasItems() const;
};