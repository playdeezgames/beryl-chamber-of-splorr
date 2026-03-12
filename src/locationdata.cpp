#include "locationdata.h"
LocationData::LocationData(LocationType locationType)
    : _locationType(locationType)
    , _characterIndex(std::nullopt)
    , _inventoryIndex(std::nullopt)
{

}
void LocationData::SetLocationType(LocationType locationType)
{
    _locationType = locationType;
}
LocationType LocationData::GetLocationType() const
{
    return _locationType;
}
std::optional<size_t> LocationData::GetCharacterIndex() const
{   
    return _characterIndex;
}
void LocationData::SetCharacterIndex(std::optional<size_t> characterIndex)
{
    _characterIndex = characterIndex;
}
std::optional<size_t> LocationData::GetInventoryIndex() const
{
    return _inventoryIndex;
}
void LocationData::SetInventoryIndex(std::optional<size_t> inventoryIndex)
{
    _inventoryIndex = inventoryIndex;
}   
