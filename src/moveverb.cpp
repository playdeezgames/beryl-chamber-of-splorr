#include "moveverb.h"
#include "board.h"
#include "location.h"
#include "inventory.h"
#include "item.h"
MoveVerb::MoveVerb(int deltaX, int deltaY)
    : _deltaX(deltaX)
    , _deltaY(deltaY)
{

}
void MoveVerb::Attempt(Character character) const
{
    auto board = character.GetBoard();
    auto location = character.GetLocation();
    int column = location.GetColumn();
    int row = location.GetRow();
    int nextColumn = column + _deltaX;
    int nextRow = row + _deltaY;
    if(nextColumn < 0 || nextRow < 0 || nextColumn > (int)board.GetColumns() - 1 || nextRow > (int)board.GetRows() - 1)
    {
        return;
    }
    auto nextLocation = board.GetLocation(nextColumn, nextRow);
    if(nextLocation.GetLocationType() == LocationType::BLUE_WALL || nextLocation.GetCharacter())
    {
        return;
    }
    nextLocation.SetCharacter(character);
    location.SetCharacter(std::nullopt);
    character.SetLocation(nextLocation);
    if(location.HasInventory())
    {
        auto locationInventory = location.GetInventory();
        auto characterInventory = character.GetInventory();
        for(auto item : locationInventory.GetItems())
        {
            characterInventory.AddItem(item);
            locationInventory.RemoveItem(item);
        }
    }
}
