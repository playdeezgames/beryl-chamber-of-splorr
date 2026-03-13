#include "items.h"
#include "bakedscallopsitemoutfitter.h"
std::map<ItemType, std::unique_ptr<ItemOutfitter>> Items::_outfitters;
void Items::Initialize()
{
    if(_outfitters.empty())
    {
        _outfitters.emplace(ItemType::BAKED_SCALLOPS, std::make_unique<BakedScallopsItemOutfitter>());
    }
}
const ItemOutfitter& Items::GetOutfitter(ItemType itemType)
{
    return *_outfitters.find(itemType)->second;
}
