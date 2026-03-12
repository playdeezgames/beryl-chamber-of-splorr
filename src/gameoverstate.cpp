#include "gameoverstate.h"
std::optional<GameStateType> GameOverState::HandleCommand(CommandType command)
{
    if(command == CommandType::RED)
    {
        return GameStateType::MAIN_MENU;
    }
    return GameStateType::GAME_OVER;
}
void GameOverState::Draw()
{
    _frameBuffer.Fill(0,0,_frameBuffer.GetColumns(),_frameBuffer.GetRows(),0,FrameBufferCellColor::BLACK, FrameBufferCellColor::BLACK);
    _frameBuffer.WriteText(0,0,"Yer dead!",FrameBufferCellColor::RED, std::nullopt);
}
void GameOverState::Start()
{

}
void GameOverState::Stop()
{

}
