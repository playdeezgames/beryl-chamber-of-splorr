#include "confirmabandonstate.h"
#include "neutral.h"
std::optional<GameStateType> ConfirmAbandonState::OnConfirm()
{
    ClearMenuItems();
    _world.Abandon();
    return GameStateType::MAIN_MENU;
}
std::optional<GameStateType> ConfirmAbandonState::OnCancel()
{
    ClearMenuItems();
    return Neutral::DetermineState(_world);
}
