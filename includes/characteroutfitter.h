#pragma once
#include "character.h"
class CharacterOutfitter
{
public:
    virtual void Initialize(Character character) const = 0;
    virtual void DoTurn(Character character) const = 0;
    virtual ~CharacterOutfitter() = default;
};