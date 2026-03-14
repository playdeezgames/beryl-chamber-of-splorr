#pragma once
#include "menustate.h"
#include "verbtype.h"
class ActionMenuState : public MenuState<VerbType>
{
protected:
    std::optional<GameStateType> HandleMenuItem(VerbType menuItem) override;
    std::optional<GameStateType> HandleCancel() override;
    void InitializeMenuItems() override;
public:
    ActionMenuState(
        World& world, 
        FrameBuffer& frameBuffer);
};