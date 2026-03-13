#pragma once
#include "menustate.h"
enum class ConfirmMenuItem
{
    YES,
    NO
};
class ConfirmMenuState: public MenuState<ConfirmMenuItem>
{
protected:
    std::optional<GameStateType> HandleMenuItem(ConfirmMenuItem menuItem) override;
    void InitializeMenuItems() override;
    virtual std::optional<GameStateType> OnConfirm() = 0;
    virtual std::optional<GameStateType> OnCancel() = 0;
    std::optional<GameStateType> HandleCancel() override;
public:
    ConfirmMenuState(
        World& world, 
        FrameBuffer& frameBuffer,
        const std::string title,
        FrameBufferCellColor foreground,
        FrameBufferCellColor background,
        GameStateType state)
        : MenuState(
            world, 
            frameBuffer, 
            title, 
            foreground, 
            background, 
            state)
    {
    }
};