#include "neutral.h"
std::optional<GameStateType> Neutral::DetermineState(const World& world)
{
    auto avatar = world.GetAvatar();
    if(*avatar->GetStatistic(StatisticType::HEALTH) <= avatar->GetStatisticMinimum(StatisticType::HEALTH))
    {
        return GameStateType::GAME_OVER;
    }
    if(avatar->HasFlag(FlagType::ACTION_MENU))
    {
        return GameStateType::ACTION_MENU;
    }
    return GameStateType::IN_PLAY;
}
