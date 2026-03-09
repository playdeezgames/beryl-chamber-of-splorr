#pragma once
#include "common.h"
#include "charactertype.h"
class CharacterData
{
private:
    CharacterType _characterType;
    size_t _boardIndex;
    size_t _locationIndex;
    CharacterData();
public:
    CharacterData(CharacterType characterType, size_t boardIndex, size_t locationIndex);
    void SetCharacterType(CharacterType characterType);
    void SetLocationIndices(size_t boardIndex, size_t locationIndex);
    CharacterType GetCharacterType() const;
    size_t GetBoardIndex() const;
    size_t GetLocationIndex() const;
};