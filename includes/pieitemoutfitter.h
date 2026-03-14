#pragma once
#include "itemoutfitter.h"
class PieItemOutfitter: public ItemOutfitter
{
public:
    void Initialize(Item item) const override;
    PieItemOutfitter();
};