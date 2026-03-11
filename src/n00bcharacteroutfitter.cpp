#include "n00bcharacteroutfitter.h"
void N00bCharacterOutfitter::Initialize(Character character) const
{
    character.SetStatistic(StatisticType::SATIETY, 100);
    character.SetStatisticMaximum(StatisticType::SATIETY, 100);
    character.SetStatisticMinimum(StatisticType::SATIETY, 0);
}
