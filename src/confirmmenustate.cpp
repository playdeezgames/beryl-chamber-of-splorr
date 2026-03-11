#include "confirmmenustate.h"
std::optional<GameStateType> ConfirmMenuState::HandleMenuItem(ConfirmMenuItem menuItem)
{
    switch(menuItem)
    {
    case ConfirmMenuItem::NO:
        return OnCancel();
    case ConfirmMenuItem::YES:
        return OnConfirm();
    }
    throw "shouldnt get here";
}
void ConfirmMenuState::InitializeMenuItems()
{
    AddMenuItem(ConfirmMenuItem::NO, "No");
    AddMenuItem(ConfirmMenuItem::YES, "Yes");
}
