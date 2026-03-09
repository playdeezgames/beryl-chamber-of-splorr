#pragma once
#include "common.h"
#include "worlddata.h"
#include "location.h"
class Board
{
private:
    WorldData& _worldData;
    size_t _index;
    Board();
    BoardData& GetBoardData();
    const BoardData& GetBoardData() const;
public:
    Board(WorldData& worldData, size_t index);
    Location GetLocation(size_t column, size_t row);
    size_t GetColumns() const;
    size_t GetRows() const;
};