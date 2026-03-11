#include "confirmabandonstate.h"
#include "neutral.h"
std::optional<GameStateType> ConfirmAbandonState::OnConfirm()
{
    _world.Abandon();
    return GameStateType::MAIN_MENU;
}
std::optional<GameStateType> ConfirmAbandonState::OnCancel()
{
    return Neutral::DetermineState(_world);
}
