#pragma once
#include "gamestate.h"
class GameOverState: public GameState
{
private:
    GameOverState();
public:
    GameOverState(
        World& world, 
        FrameBuffer& frameBuffer)
        : GameState(world, frameBuffer)
        {
        }
    std::optional<GameStateType> HandleCommand(CommandType command) override;
    void Draw() override;
    void Start() override;
    void Stop() override;
};