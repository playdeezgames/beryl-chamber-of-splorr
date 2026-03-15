#include "n00bcharacteroutfitter.h"
void N00bCharacterOutfitter::Initialize(Character character) const
{
    character.SetStatistic(StatisticType::SATIETY, 100);
    character.SetStatisticMaximum(StatisticType::SATIETY, 100);
    character.SetStatisticMinimum(StatisticType::SATIETY, 0);
    character.SetStatistic(StatisticType::HEALTH, 100);
    character.SetStatisticMaximum(StatisticType::HEALTH, 100);
    character.SetStatisticMinimum(StatisticType::HEALTH, 0);
    character.SetStatistic(StatisticType::STOMACH, 0);
    character.SetStatisticMinimum(StatisticType::STOMACH, 0);
}
void N00bCharacterOutfitter::DoTurn(Character character) const
{
    auto stomach = *character.GetStatistic(StatisticType::STOMACH);
    character.ChangeStatistic(StatisticType::STOMACH, -1);
    if(stomach <= character.GetStatisticMinimum(StatisticType::STOMACH))
    {
        auto satiety = *character.GetStatistic(StatisticType::SATIETY);
        if(satiety > character.GetStatisticMinimum(StatisticType::SATIETY))
        {
            character.ChangeStatistic(StatisticType::SATIETY, -1);
        }
        else
        {
            character.ChangeStatistic(StatisticType::HEALTH, -1);
        }
    }
    else
    {
        auto satiety = *character.GetStatistic(StatisticType::SATIETY);
        if(satiety < character.GetStatisticMaximum(StatisticType::SATIETY))
        {
            character.ChangeStatistic(StatisticType::SATIETY, 1);
        }
        else
        {
            character.ChangeStatistic(StatisticType::HEALTH, 1);
        }
    }
}
N00bCharacterOutfitter::N00bCharacterOutfitter()
    : CharacterOutfitter(2, FrameBufferCellColor::LIGHT_GRAY)
{

}
