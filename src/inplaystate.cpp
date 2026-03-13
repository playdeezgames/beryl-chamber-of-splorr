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
            avatar.GetBoard().DoTurn();
            break;
        case CommandType::DOWN:
            avatar.AttemptVerb(VerbType::MOVE_DOWN);
            avatar.GetBoard().DoTurn();
            break;
        case CommandType::LEFT:
            avatar.AttemptVerb(VerbType::MOVE_LEFT);
            avatar.GetBoard().DoTurn();
            break;
        case CommandType::RIGHT:
            avatar.AttemptVerb(VerbType::MOVE_RIGHT);
            avatar.GetBoard().DoTurn();
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
            unsigned char cellCharacter = location.GetFrameCharacter();
            FrameBufferCellColor foreground = location.GetFrameForeground();
            FrameBufferCellColor background = location.GetFrameBackground();
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
        std::format("SAT:{:>3}/{:>3}    ", avatar.GetStatistic(StatisticType::SATIETY).value_or(0), avatar.GetStatisticMaximum(StatisticType::SATIETY)), 
        FrameBufferCellColor::MAGENTA, 
        std::nullopt);
    frameBuffer.WriteText(
        offsetX, 
        offsetY++, 
        std::format("HLT:{:>3}/{:>3}    ", avatar.GetStatistic(StatisticType::HEALTH).value_or(0), avatar.GetStatisticMaximum(StatisticType::HEALTH)), 
        FrameBufferCellColor::RED, 
        std::nullopt);
}
void InPlayState::Draw()
{
    DrawBoard(0,0,_world, _frameBuffer);
    DrawStats(20,0,_world, _frameBuffer);
}
