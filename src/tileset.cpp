#include "tileset.h"
void TileSet::Add(SDL_Texture* texture, int tileWidth, int tileHeight)
{
    int textureWidth;
    int textureHeight;
    SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);
    for(auto row : std::views::iota(0, textureHeight / tileHeight))
    {
        for(auto column: std::views::iota(0, textureWidth / tileWidth))
        {
            _tiles.emplace_back(texture,column * tileWidth, row * tileHeight, tileWidth, tileHeight);
        }
    }
}
Tile& TileSet::GetTile(int index)
{
    return _tiles[index];
}
