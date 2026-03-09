#pragma once
#include "common.h"
#include "locationdata.h"
#include "worlddata.h"
class Location
{
private:
    WorldData& _worldData;
    size_t _boardIndex;
    size_t _locationIndex;
    Location();
    LocationData& GetLocationData();
    const LocationData& GetLocationData() const;
public:
    Location(WorldData& worldData, size_t boardIndex, size_t locationIndex);
    void SetLocationType(LocationType locationType);
    LocationType GetLocationType() const;
};