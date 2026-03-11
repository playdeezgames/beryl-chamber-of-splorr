#include "mainmenustate.h"
#include "neutral.h"
std::optional<GameStateType> MainMenuState::HandleCommand(CommandType command)
{
    if(_menuItems.empty())
    {
        return GameStateType::MAIN_MENU;
    }
    switch(command)
    {
        case CommandType::GREEN:
            return HandleMenuItem(std::get<0>(_menuItems[_menuItemIndex]));
        case CommandType::UP:
            _menuItemIndex = (_menuItemIndex + _menuItems.size() - 1) % _menuItems.size();
            break;
        case CommandType::DOWN:
            _menuItemIndex = (_menuItemIndex + 1) % _menuItems.size();
            break;
        default:
            break;
    }
    return GameStateType::MAIN_MENU;
}
void MainMenuState::InitializeMenuItems()
{
    if(!_menuItems.empty())
    {
        return;
    }
    auto avatar = _world.GetAvatar();
    if(avatar)
    {
        _menuItems.emplace_back(MainMenuItem::CONTINUE, "Continue");
        _menuItems.emplace_back(MainMenuItem::ABANDON, "Abandon");
    }
    else
    {
        _menuItems.emplace_back(MainMenuItem::EMBARK, "Embark!");
        _menuItems.emplace_back(MainMenuItem::QUIT, "Quit");
    }
    _menuItemIndex = 0;
}
void MainMenuState::ClearMenuItems()
{
    _menuItems.clear();
}
void MainMenuState::Draw()
{
    InitializeMenuItems();
    _frameBuffer.Fill(0,0,_frameBuffer.GetColumns(),_frameBuffer.GetRows(),0,FrameBufferCellColor::BLACK,FrameBufferCellColor::BLACK);
    _frameBuffer.WriteText(0,0,"Main Menu:",FrameBufferCellColor::WHITE, std::nullopt);

    size_t row = 2;
    for(size_t index : std::views::iota(size_t{0}, _menuItems.size()))
    {
        FrameBufferCellColor foreground = (index == _menuItemIndex) ? (FrameBufferCellColor::BLACK) : (FrameBufferCellColor::WHITE);
        FrameBufferCellColor background = (index == _menuItemIndex) ? (FrameBufferCellColor::WHITE) : (FrameBufferCellColor::BLACK);
        _frameBuffer.WriteText(0, row++, std::get<1>(_menuItems[index]), foreground, background);
    }
}
std::optional<GameStateType> MainMenuState::HandleMenuItem(MainMenuItem menuItem)
{
    switch(menuItem)
    {
        case MainMenuItem::EMBARK:
            _world.Initialize();
            ClearMenuItems();
            return Neutral::DetermineState(_world);
        case MainMenuItem::CONTINUE:
            ClearMenuItems();
            return Neutral::DetermineState(_world);
        case MainMenuItem::ABANDON:
            _world.Abandon();
            ClearMenuItems();
            return GameStateType::MAIN_MENU;
        case MainMenuItem::QUIT:
            ClearMenuItems();
            return GameStateType::CONFIRM_QUIT;
        default:
            return GameStateType::MAIN_MENU;
    }
}
