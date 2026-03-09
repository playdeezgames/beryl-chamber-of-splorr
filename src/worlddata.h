#pragma once
#include "common.h"
#include "boarddata.h"
class WorldData
{
private:
    std::vector<BoardData> _boards;
    std::set<size_t> _recycledBoards;
public:
    void Clear();
    size_t CreateBoard(size_t columns, size_t rows, LocationType locationType);
    BoardData& GetBoardData(size_t boardIndex);
    const BoardData& GetBoardData(size_t boardIndex) const;
};