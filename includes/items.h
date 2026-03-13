#pragma once
#include "common.h"
#include "itemtype.h"
#include "itemoutfitter.h"
class Items
{
private:
    static std::map<ItemType, std::unique_ptr<ItemOutfitter>> _outfitters;
public:
    static void Initialize();
    static const ItemOutfitter& GetOutfitter(ItemType itemType);
};