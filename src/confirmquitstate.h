#pragma once
#include "confirmmenustate.h"
class ConfirmQuitState : public ConfirmMenuState
{
protected:
    std::optional<GameStateType> OnConfirm() override;
    std::optional<GameStateType> OnCancel() override;
public:
    ConfirmQuitState(
        World& world, 
        FrameBuffer& frameBuffer)
        : ConfirmMenuState(world, frameBuffer, "Are you sure you want to quit?", GameStateType::CONFIRM_QUIT)
    {
    }
};