#pragma once
#include "tile.h"
#include "common.h"
class TileSet
{
private:
    std::vector<Tile> _tiles;
public:
    void Add(SDL_Texture* texture, int tileWidth, int tileHeight);
    Tile& GetTile(int index);
};