#pragma once
#include "itemoutfitter.h"
class BakedScallopsItemOutfitter: public ItemOutfitter
{
public:
    void Initialize(Item item) const override;
    BakedScallopsItemOutfitter();
};