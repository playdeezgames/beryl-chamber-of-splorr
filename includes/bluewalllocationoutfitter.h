#pragma once
#include "locationoutfitter.h"
class BlueWallLocationOutfitter: public LocationOutfitter
{
public:
    BlueWallLocationOutfitter();
    void Initialize(Location location) const override;
};