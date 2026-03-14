#include "actionmenustate.h"
#include "neutral.h"
#include "verbs.h"
std::optional<GameStateType> ActionMenuState::HandleMenuItem(VerbType menuItem)
{
    _world.GetAvatar()->AttemptVerb(menuItem);
    return Neutral::DetermineState(_world);
}
std::optional<GameStateType> ActionMenuState::HandleCancel()
{
    _world.GetAvatar()->AttemptVerb(VerbType::TOGGLE_ACTION_MENU);
    return Neutral::DetermineState(_world);
}
void ActionMenuState::ActionMenuState::InitializeMenuItems()
{
    for(auto menuitem : Verbs::GetActionMenu(*_world.GetAvatar()))
    {
        AddMenuItem(std::get<0>(menuitem), std::get<1>(menuitem));
    }
}
ActionMenuState::ActionMenuState(
    World& world, 
    FrameBuffer& frameBuffer)
    : MenuState(
        world, 
        frameBuffer, 
        "Action Menu:", 
        FrameBufferCellColor::BROWN, 
        FrameBufferCellColor::BLACK, 
        GameStateType::ACTION_MENU)
{

}
