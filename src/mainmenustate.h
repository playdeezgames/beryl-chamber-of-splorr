#pragma once
#include "gamestate.h"
enum class MainMenuItem
{
    EMBARK,
    CONTINUE,
    ABANDON,
    QUIT
};
class MainMenuState: public GameState
{
private:
    std::vector<std::tuple<MainMenuItem, std::string>> _menuItems;
    size_t _menuItemIndex;
    void InitializeMenuItems();
    void ClearMenuItems();
    std::optional<GameStateType> HandleMenuItem(MainMenuItem menuItem);
public:
    MainMenuState(
        World& world, 
        FrameBuffer& frameBuffer)
        : GameState(world, frameBuffer)
        , _menuItems()
        , _menuItemIndex(0)
        {
        }
    std::optional<GameStateType> HandleCommand(CommandType command) override;
    void Draw() override;
};