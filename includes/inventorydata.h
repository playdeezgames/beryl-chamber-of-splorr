#pragma once
#include "common.h"
class InventoryData
{
private:
    std::set<size_t> _itemIndices;
public:
    InventoryData():_itemIndices(){}
    bool HasItemIndices() const{return !_itemIndices.empty();}
    void AddItemIndex(size_t itemIndex){_itemIndices.insert(itemIndex);}
    void RemoveItemIndex(size_t itemIndex){_itemIndices.erase(itemIndex);}
    const std::set<size_t>& GetItemIndices() const{return _itemIndices;}
};