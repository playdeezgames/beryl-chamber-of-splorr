#pragma once
#include "character.h"
class CharacterOutfitter
{
public:
    virtual void Initialize(Character character) const = 0;
};