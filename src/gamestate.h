#pragma once
#include "common.h"
#include "gamestatetype.h"
#include "commandtype.h"
#include "framebuffer.h"
#include "world.h"
class GameState
{
private:
    GameState();
protected:
    World& _world;
    FrameBuffer& _frameBuffer;
public:
    GameState(
        World& world, 
        FrameBuffer& frameBuffer)
        : _world(world)
        , _frameBuffer(frameBuffer)
        {
        }
    virtual std::optional<GameStateType> HandleCommand(CommandType command) = 0;
    virtual void Draw() = 0;
};