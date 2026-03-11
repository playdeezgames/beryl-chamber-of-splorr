#include "confirmquitstate.h"
std::optional<GameStateType> ConfirmQuitState::HandleMenuItem(ConfirmMenuItem menuItem)
{
    switch(menuItem)
    {
    case ConfirmMenuItem::NO:
        return GameStateType::MAIN_MENU;
    case ConfirmMenuItem::YES:
        return std::nullopt;
    }
    throw "shouldnt get here";
}
void ConfirmQuitState::InitializeMenuItems()
{
    AddMenuItem(ConfirmMenuItem::NO, "No");
    AddMenuItem(ConfirmMenuItem::YES, "Yes");
}
