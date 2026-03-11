#pragma once
#include "confirmmenustate.h"
class ConfirmAbandonState : public ConfirmMenuState
{
protected:
    std::optional<GameStateType> OnConfirm() override;
    std::optional<GameStateType> OnCancel() override;
public:
    ConfirmAbandonState(
        World& world, 
        FrameBuffer& frameBuffer)
        : ConfirmMenuState(world, frameBuffer, "Are you sure you want to abandon?", GameStateType::CONFIRM_ABANDON)
    {
    }
};