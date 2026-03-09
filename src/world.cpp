#include "world.h"
World::World(WorldData& worldData)
    : _worldData(worldData)
{

}
constexpr size_t BOARD_COLUMNS = 25;
constexpr size_t BOARD_ROWS = 25;
void World::Initialize()
{
    _worldData.Clear();
    auto board = CreateBoard(BOARD_COLUMNS, BOARD_ROWS, LocationType::FLOOR);
    for(size_t column : std::views::iota(size_t{0}, BOARD_COLUMNS))
    {
        board.GetLocation(column, 0).SetLocationType(LocationType::BLUE_WALL);
        board.GetLocation(column, BOARD_ROWS - 1).SetLocationType(LocationType::BLUE_WALL);
    }
    for(size_t row : std::views::iota(size_t{1}, BOARD_ROWS - 1))
    {
        board.GetLocation(0, row).SetLocationType(LocationType::BLUE_WALL);
        board.GetLocation(BOARD_COLUMNS - 1, row).SetLocationType(LocationType::BLUE_WALL);
    }
}
Board World::CreateBoard(size_t columns, size_t rows, LocationType locationType)
{
    auto index = _worldData.CreateBoard(columns, rows, locationType);
    return Board(_worldData, index);
}
