#pragma once
#include "common.h"
#include <SDL2/SDL.h>
class Tile
{
private:
    SDL_Texture* _texture;
    SDL_Rect _src_rect;
    Tile();
public:
    Tile(SDL_Texture* texture, int x, int y, int w, int h);
    void Render(SDL_Renderer* renderer, int x, int y, const SDL_Color& color);
};