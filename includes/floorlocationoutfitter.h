#pragma once
#include "locationoutfitter.h"
class FloorLocationOutfitter: public LocationOutfitter
{
public:
    FloorLocationOutfitter();
    void Initialize(Location location) const override;
};