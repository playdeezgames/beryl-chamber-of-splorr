#include "inplaystate.h"
#include "neutral.h"
InPlayState::InPlayState(
    World& world, 
    FrameBuffer& frameBuffer)
    : GameState(world, frameBuffer)
{
    
}
std::optional<GameStateType> InPlayState::HandleCommand(CommandType command)
{
    auto avatar = *_world.GetAvatar();
    switch(command)
    {
        case CommandType::UP:
            avatar.AttemptVerb(VerbType::MOVE_UP);
            break;
        case CommandType::DOWN:
            avatar.AttemptVerb(VerbType::MOVE_DOWN);
            break;
        case CommandType::LEFT:
            avatar.AttemptVerb(VerbType::MOVE_LEFT);
            break;
        case CommandType::RIGHT:
            avatar.AttemptVerb(VerbType::MOVE_RIGHT);
            break;
        case CommandType::RED:
            return GameStateType::MAIN_MENU;
        default:
            break;
    }
    return Neutral::DetermineState(_world);
}
static void DrawBoard(size_t offsetX, size_t offsetY, World& world, FrameBuffer& frameBuffer)
{
    auto board = world.GetAvatar()->GetBoard();
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
            frameBuffer.SetCell(offsetX + column, offsetY + row, cellCharacter, foreground, background);
        }
    }
}
void DrawStats(size_t offsetX, size_t offsetY, World& world, FrameBuffer& frameBuffer)
{
    auto avatar = *world.GetAvatar();
    frameBuffer.WriteText(
        offsetX, 
        offsetY++, 
        std::format("SAT: {}/{}", avatar.GetStatistic(StatisticType::SATIETY).value_or(0), avatar.GetStatisticMaximum(StatisticType::SATIETY)), 
        FrameBufferCellColor::MAGENTA, 
        std::nullopt);
}
void InPlayState::Draw()
{
    DrawBoard(0,0,_world, _frameBuffer);
    DrawStats(25,0,_world, _frameBuffer);
}
