#include "neutral.h"
GameStateType Neutral::DetermineState(const World&)
{
    return GameStateType::IN_PLAY;
}
