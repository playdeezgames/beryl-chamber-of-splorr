#pragma once
#include "common.h"
#include "worlddata.h"
class Board;
class Location;
class Character
{
private:
    WorldData& _worldData;
    size_t _index;
    Character();
    CharacterData& GetCharacterData();
    const CharacterData& GetCharacterData() const;
public:
    Character(WorldData& worldData, size_t index);
    size_t GetIndex() const;
    Board GetBoard() const;
    Location GetLocation() const;
    CharacterType GetCharacterType() const;
};