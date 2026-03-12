#include "neutral.h"
std::optional<GameStateType> Neutral::DetermineState(const World& world)
{
    auto avatar = world.GetAvatar();
    if(*avatar->GetStatistic(StatisticType::HEALTH) <= avatar->GetStatisticMinimum(StatisticType::HEALTH))
    {
        return GameStateType::GAME_OVER;
    }
    return GameStateType::IN_PLAY;
}
