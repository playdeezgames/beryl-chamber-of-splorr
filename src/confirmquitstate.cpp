#include "confirmquitstate.h"
std::optional<GameStateType> ConfirmQuitState::OnConfirm()
{
    return std::nullopt;
}
std::optional<GameStateType> ConfirmQuitState::OnCancel()
{
    ClearMenuItems();
    return GameStateType::MAIN_MENU;
}
