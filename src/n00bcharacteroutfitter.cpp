#include "n00bcharacteroutfitter.h"
void N00bCharacterOutfitter::Initialize(Character character) const
{
    character.SetStatistic(StatisticType::SATIETY, 100);
    character.SetStatisticMaximum(StatisticType::SATIETY, 100);
    character.SetStatisticMinimum(StatisticType::SATIETY, 0);
    character.SetStatistic(StatisticType::HEALTH, 100);
    character.SetStatisticMaximum(StatisticType::HEALTH, 100);
    character.SetStatisticMinimum(StatisticType::HEALTH, 0);
}
void N00bCharacterOutfitter::DoTurn(Character character) const
{
    auto satiety = *character.GetStatistic(StatisticType::SATIETY);
    if(satiety > 0)
    {
        character.ChangeStatistic(StatisticType::SATIETY, -1);
    }
    else
    {
        character.ChangeStatistic(StatisticType::HEALTH, -1);
    }
}
