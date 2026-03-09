#include "locationdata.h"
LocationData::LocationData(LocationType locationType)
    : _locationType(locationType)
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
