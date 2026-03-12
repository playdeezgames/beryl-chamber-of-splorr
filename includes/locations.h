#pragma once
#include "common.h"
#include "locationtype.h"
#include "locationoutfitter.h"
class Locations
{
private:
    static std::map<LocationType, std::unique_ptr<LocationOutfitter>> _outfitters;
public:
    static void Initialize();
    static const LocationOutfitter& GetOutfitter(LocationType locationType);
};