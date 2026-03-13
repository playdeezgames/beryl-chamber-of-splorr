#include "location.h"
#include "character.h"
#include "board.h"
#include "inventory.h"
#include "locations.h"
Location::Location(
    WorldData& worldData, 
    size_t boardIndex, 
    size_t locationIndex)
    : _worldData(worldData)
    , _boardIndex(boardIndex)
    , _locationIndex(locationIndex)
{

}
void Location::SetLocationType(LocationType locationType)
{
    GetLocationData().SetLocationType(locationType);
    Initialize();
}
LocationType Location::GetLocationType() const
{
    return GetLocationData().GetLocationType();
}
LocationData& Location::GetLocationData()
{
    return _worldData.GetBoardData(_boardIndex).GetLocationData(_locationIndex);
}
const LocationData& Location::GetLocationData() const
{
    return _worldData.GetBoardData(_boardIndex).GetLocationData(_locationIndex);
}
size_t Location::GetBoardIndex() const
{
    return _boardIndex;
}
size_t Location::GetLocationIndex() const
{
    return _locationIndex;
}
void Location::SetCharacter(std::optional<Character> character)
{
    if(character)
    {
        GetLocationData().SetCharacterIndex(character->GetIndex());
    }
    else
    {
        GetLocationData().SetCharacterIndex(std::nullopt);
    }
}
std::optional<Character> Location::GetCharacter() const
{
    auto characterIndex = GetLocationData().GetCharacterIndex();
    if(characterIndex)
    {
        return Character(_worldData, *characterIndex);
    }
    return std::nullopt;
}
Board Location::GetBoard() const
{
    return Board(_worldData, GetBoardIndex());
}
size_t Location::GetColumn() const
{
    return GetLocationIndex() % GetBoard().GetColumns();
}
size_t Location::GetRow() const
{
    return GetLocationIndex() / GetBoard().GetColumns();
}
Inventory Location::GetInventory()
{
    std::optional<size_t> inventoryIndex = GetLocationData().GetInventoryIndex();
    if(!inventoryIndex)
    {
        inventoryIndex = _worldData.CreateInventory();
        GetLocationData().SetInventoryIndex(*inventoryIndex);
    }
    return Inventory(_worldData, *inventoryIndex);
}
void Location::Initialize()
{
    Locations::GetOutfitter(GetLocationType()).Initialize(*this);
}
unsigned char Location::GetFrameCharacter() const
{
    auto character = GetCharacter();
    if(character)
    {
        return character->GetFrameCharacter();
    }
    return Locations::GetOutfitter(GetLocationType()).GetFrameCharacter();
}
FrameBufferCellColor Location::GetFrameForeground() const
{
    auto character = GetCharacter();
    if(character)
    {
        return character->GetFrameForeground();
    }
    return Locations::GetOutfitter(GetLocationType()).GetFrameForeground();
}
FrameBufferCellColor Location::GetFrameBackground() const
{
    return Locations::GetOutfitter(GetLocationType()).GetFrameBackground();
}
