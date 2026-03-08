#pragma once
#include "common.h"
#include "framebuffercellcolor.h"
#include <SDL2/SDL.h>
class Palette
{
private:
    std::map<FrameBufferCellColor, SDL_Color> _colors;
public:
    void SetColor(FrameBufferCellColor index, const SDL_Color& hue)
    {
        _colors.insert_or_assign(index, hue);
    }
    const SDL_Color& GetColor(FrameBufferCellColor index) const
    {
        return _colors.find(index)->second;
    }
};