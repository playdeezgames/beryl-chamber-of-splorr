#include "board.h"
Board::Board(
    WorldData& worldData, 
    size_t index)
    : _worldData(worldData)
    , _index(index)
{

}
Location Board::GetLocation(
    size_t column, 
    size_t row)
{
    return Location(
        _worldData, 
        _index, 
        column + row * GetColumns());
}
BoardData& Board::GetBoardData()
{
    return _worldData.GetBoardData(_index);
}
const BoardData& Board::GetBoardData() const
{
    return _worldData.GetBoardData(_index);
}
size_t Board::GetColumns() const
{
    return GetBoardData().GetColumns();
}
size_t Board::GetRows() const
{
    return GetBoardData().GetRows();
}
