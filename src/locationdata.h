#pragma once
#include "common.h"
#include "locationtype.h"
class LocationData
{
private:
    LocationType _locationType;
    LocationData();
public:
    LocationData(LocationType locationType);
    void SetLocationType(LocationType locationType);
    LocationType GetLocationType() const;
};