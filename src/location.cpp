#include "location.h"
#include "character.h"
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
