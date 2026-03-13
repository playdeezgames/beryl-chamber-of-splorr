#pragma once
#include "menustate.h"
enum class MainMenuItem
{
    EMBARK,
    CONTINUE,
    ABANDON,
    QUIT
};
class MainMenuState: public MenuState<MainMenuItem>
{
protected:
    std::optional<GameStateType> HandleMenuItem(MainMenuItem menuItem);
    void InitializeMenuItems();
    std::optional<GameStateType> HandleCancel() override;
public:
    MainMenuState(
        World& world, 
        FrameBuffer& frameBuffer)
        : MenuState(
            world, 
            frameBuffer, 
            "Main Menu:", 
            FrameBufferCellColor::BROWN, 
            FrameBufferCellColor::BLACK, 
            GameStateType::MAIN_MENU)
        {
        }
};