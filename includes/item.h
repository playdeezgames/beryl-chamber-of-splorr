#pragma once
#include "worlddata.h"
#include "itemdata.h"
#include "framebuffercellcolor.h"
class Inventory;
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
    size_t GetIndex() const {return _index;}
    unsigned char GetFrameCharacter() const;
    FrameBufferCellColor GetFrameForeground() const;
    void SetInventory(Inventory inventory);
    Inventory GetInventory() const;
};