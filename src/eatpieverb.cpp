#include "eatpieverb.h"
#include "inventory.h"
#include "item.h"
std::string EatPieVerb::GetText(Character character) const
{
    if(character.GetInventory().HasItemOfType(ItemType::PIE))
    {
        return "Eat Pie";
    }
    return "";
}
void EatPieVerb::Attempt(Character character) const
{
    auto inventory = character.GetInventory();
    auto item = inventory.GetItemOfType(ItemType::PIE);
    if(!item)
    {
        return;
    }
    inventory.RemoveItem(*item);
    item->Recycle();
    character.ChangeStatistic(StatisticType::STOMACH, 50);
}
