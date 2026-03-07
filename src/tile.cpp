#include "tile.h"
Tile::Tile(SDL_Texture* texture, int x, int y, int w, int h)
    : _texture(texture)
    , _src_rect{x,y,w,h}
{

}
void Tile::Render(SDL_Renderer* renderer, int x, int y, const SDL_Color& color)
{
    SDL_Rect dst_rect{x,y,_src_rect.w,_src_rect.h};
    SDL_SetTextureColorMod(_texture, color.r, color.g, color.b);
    SDL_RenderCopy(renderer, _texture, &_src_rect, &dst_rect);
}
