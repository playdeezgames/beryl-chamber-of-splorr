#include "board.h"
#include "character.h"
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
void Board::DoTurn()
{
    for(size_t column : std::views::iota(size_t{0}, GetColumns()))
    {
        for(size_t row : std::views::iota(size_t{0}, GetRows()))
        {
            auto character = GetLocation(column, row).GetCharacter();
            if(character)
            {
                character->DoTurn();
            }
        }
    }
}
