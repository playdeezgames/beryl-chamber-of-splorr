#pragma once
#include "menustate.h"
enum class ConfirmMenuItem
{
    YES,
    NO
};
class ConfirmQuitState : public MenuState<ConfirmMenuItem>
{
protected:
    std::optional<GameStateType> HandleMenuItem(ConfirmMenuItem menuItem) override;
    void InitializeMenuItems() override;
public:
    ConfirmQuitState(
        World& world, 
        FrameBuffer& frameBuffer)
        : MenuState(world, frameBuffer, "Are you sure you want to quit?", GameStateType::CONFIRM_QUIT)
    {
    }
};