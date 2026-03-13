#pragma once
#include "characteroutfitter.h"
class N00bCharacterOutfitter : public CharacterOutfitter
{
public:
    void Initialize(Character character) const override;
    void DoTurn(Character character) const override;
    N00bCharacterOutfitter();
};