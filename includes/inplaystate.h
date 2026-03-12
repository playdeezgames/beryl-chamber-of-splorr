#pragma once
#include "gamestate.h"
class InPlayState: public GameState
{
private:
    InPlayState();
public:
    InPlayState(
        World& world, 
        FrameBuffer& frameBuffer);
    std::optional<GameStateType> HandleCommand(CommandType command) override;
    void Draw() override;
    void Start() override{}
    void Stop() override{}
};