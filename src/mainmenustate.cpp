#include "mainmenustate.h"
#include "neutral.h"
void MainMenuState::InitializeMenuItems()
{
    auto avatar = _world.GetAvatar();
    if(avatar)
    {
        AddMenuItem(MainMenuItem::CONTINUE, "Continue");
        AddMenuItem(MainMenuItem::ABANDON, "Abandon");
    }
    else
    {
        AddMenuItem(MainMenuItem::EMBARK, "Embark!");
        AddMenuItem(MainMenuItem::QUIT, "Quit");
    }
}
std::optional<GameStateType> MainMenuState::HandleMenuItem(MainMenuItem menuItem)
{
    switch(menuItem)
    {
        case MainMenuItem::EMBARK:
            _world.Initialize();
            return Neutral::DetermineState(_world);
        case MainMenuItem::CONTINUE:
            return Neutral::DetermineState(_world);
        case MainMenuItem::ABANDON:
            return GameStateType::CONFIRM_ABANDON;
        case MainMenuItem::QUIT:
            return GameStateType::CONFIRM_QUIT;
        default:
            return GameStateType::MAIN_MENU;
    }
}
std::optional<GameStateType> MainMenuState::HandleCancel()
{
    if(_world.GetAvatar())
    {
        return HandleMenuItem(MainMenuItem::CONTINUE);
    }
    else
    {
        return HandleMenuItem(MainMenuItem::QUIT);
    }
}

