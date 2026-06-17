#pragma once
#include "locationoutfitter.h"
class SignLocationOutfitter: public LocationOutfitter
{
public:
    SignLocationOutfitter();
    void Initialize(Location location) const override;
};