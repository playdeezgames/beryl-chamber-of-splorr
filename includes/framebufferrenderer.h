#pragma once
#include "framebuffer.h"
#include "tileset.h"
#include "plotter.h"
#include "palette.h"
class FrameBufferRenderer
{
private:
    const FrameBuffer& _frameBuffer;
    TileSet& _tileSet;
    const Plotter& _plotter;
    const Palette& _palette;
    FrameBufferRenderer();
public:
    FrameBufferRenderer(
        const FrameBuffer& frameBuffer,
        TileSet& tileSet,
        const Plotter& plotter,
        const Palette& palette)
        : _frameBuffer(frameBuffer)
        , _tileSet(tileSet)
        , _plotter(plotter)
        , _palette(palette)
    {
    }
    void Render(SDL_Renderer* renderer);
};