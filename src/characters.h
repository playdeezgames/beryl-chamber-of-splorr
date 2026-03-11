#pragma once
#include "common.h"
#include "charactertype.h"
#include "characteroutfitter.h"
class Characters
{
private:
    static std::map<CharacterType, std::unique_ptr<CharacterOutfitter>> _outfitters;
public:
    static void Initialize();
    static const CharacterOutfitter& GetOutfitter(CharacterType characterType);
};