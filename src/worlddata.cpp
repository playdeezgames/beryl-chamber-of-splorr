#include "worlddata.h"
void WorldData::Clear()
{
    _boards.clear();
    _recycledBoards.clear();
}
size_t WorldData::CreateBoard(
    size_t columns, 
    size_t rows, 
    LocationType locationType)
{
    size_t result;
    if(_recycledBoards.empty())
    {
        result = _boards.size();
        _boards.emplace_back(columns, rows, locationType);
    }
    else
    {
        result = *_recycledBoards.begin();
        _recycledBoards.erase(result);
        _boards[result] = BoardData(columns, rows, locationType);
    }
    return result;
}
BoardData& WorldData::GetBoardData(size_t boardIndex)
{
    return _boards[boardIndex];
}
const BoardData& WorldData::GetBoardData(size_t boardIndex) const
{
    return _boards[boardIndex];
}
