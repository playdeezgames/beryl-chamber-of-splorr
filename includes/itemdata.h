#pragma once
#include "itemtype.h"
class ItemData
{
private:
    ItemType _itemType;
    size_t _inventoryIndex;
    ItemData();
public:
    ItemData(ItemType itemType, size_t inventoryIndex):_itemType(itemType), _inventoryIndex(inventoryIndex){}
    ItemType GetItemType() const{return _itemType;}
    void SetInventoryIndex(size_t inventoryIndex){_inventoryIndex = inventoryIndex;}
    size_t GetInventoryIndex() const{return _inventoryIndex;}
};