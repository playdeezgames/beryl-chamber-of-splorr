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
