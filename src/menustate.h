#pragma once
#include "gamestate.h"
template<typename TItem>
class MenuState: public GameState
{
private:
    std::string _title;
    GameStateType _state;
    std::vector<std::tuple<TItem, std::string>> _menuItems;
    size_t _menuItemIndex;
protected:
    void AddMenuItem(const TItem item, const std::string& text)
    {
        _menuItems.emplace_back(item, text);
    }
    virtual std::optional<GameStateType> HandleMenuItem(TItem menuItem) = 0;
    virtual void InitializeMenuItems() = 0;
public:
    MenuState(
        World& world, 
        FrameBuffer& frameBuffer,
        const std::string& title,
        GameStateType state)
        : GameState(world, frameBuffer)
        , _title(title)
        , _state(state)
        , _menuItems()
        , _menuItemIndex(0)
        {
        }
    void Start() override
    {
        _menuItems.clear();
        _menuItemIndex = 0;
    }
    void Stop() override {}
    std::optional<GameStateType> HandleCommand(CommandType command) override
    {
        if(_menuItems.empty())
        {
            return _state;
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
        return _state;
    }
    void Draw() override
    {
        if(_menuItems.empty())
        {
            InitializeMenuItems();
        }
        _frameBuffer.Fill(0,0,_frameBuffer.GetColumns(),_frameBuffer.GetRows(),0,FrameBufferCellColor::BLACK,FrameBufferCellColor::BLACK);
        _frameBuffer.WriteText(0,0,_title,FrameBufferCellColor::WHITE, std::nullopt);

        size_t row = 2;
        for(size_t index : std::views::iota(size_t{0}, _menuItems.size()))
        {
            FrameBufferCellColor foreground = (index == _menuItemIndex) ? (FrameBufferCellColor::BLACK) : (FrameBufferCellColor::WHITE);
            FrameBufferCellColor background = (index == _menuItemIndex) ? (FrameBufferCellColor::WHITE) : (FrameBufferCellColor::BLACK);
            _frameBuffer.WriteText(0, row++, std::get<1>(_menuItems[index]), foreground, background);
        }
    }
};