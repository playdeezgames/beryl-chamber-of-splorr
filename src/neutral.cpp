#include "neutral.h"
std::optional<GameStateType> Neutral::DetermineState(const World&)
{
    return GameStateType::IN_PLAY;
}
