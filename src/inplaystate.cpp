#include "inplaystate.h"
InPlayState::InPlayState(
    World& world, 
    FrameBuffer& frameBuffer)
    : GameState(world, frameBuffer)
{
    
}
std::optional<GameStateType> InPlayState::HandleCommand(CommandType command)
{
    if(command == CommandType::RED) return std::nullopt;
    return GameStateType::IN_PLAY;
}
void InPlayState::Draw()
{
    auto board = _world.GetAvatar()->GetBoard();
    for(size_t row : std::views::iota(size_t{0}, board.GetRows()))
    {
        for(size_t column: std::views::iota(size_t{0}, board.GetColumns()))
        {
            auto location = board.GetLocation(column, row);
            auto character = location.GetCharacter();
            unsigned char cellCharacter = '?';
            FrameBufferCellColor foreground = FrameBufferCellColor::BLACK;
            FrameBufferCellColor background = FrameBufferCellColor::RED;
            if(character)
            {
                switch(character->GetCharacterType())
                {
                    case CharacterType::N00B:
                        cellCharacter = '@';
                        foreground = FrameBufferCellColor::LIGHT_GRAY;
                        background = FrameBufferCellColor::BLACK;
                        break;
                    default:
                        break;
                }
            }
            else
            {
                switch(location.GetLocationType())
                {
                    case LocationType::BLUE_WALL:
                        cellCharacter = 219;
                        foreground = FrameBufferCellColor::BLUE;
                        background = FrameBufferCellColor::BLACK;
                        break;
                    case LocationType::FLOOR:
                        cellCharacter = 0;
                        foreground = FrameBufferCellColor::BLACK;
                        background = FrameBufferCellColor::BLACK;
                        break;
                    default:
                        break;
                }   
            }
            _frameBuffer.SetCell(column, row, cellCharacter, foreground, background);
        }
    }
}
