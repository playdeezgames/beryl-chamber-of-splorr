#include "items.h"
#include "pieitemoutfitter.h"
std::map<ItemType, std::unique_ptr<ItemOutfitter>> Items::_outfitters;
void Items::Initialize()
{
    if(_outfitters.empty())
    {
        _outfitters.emplace(ItemType::PIE, std::make_unique<PieItemOutfitter>());
    }
}
const ItemOutfitter& Items::GetOutfitter(ItemType itemType)
{
    return *_outfitters.find(itemType)->second;
}
