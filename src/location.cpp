#include "location.h"
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
