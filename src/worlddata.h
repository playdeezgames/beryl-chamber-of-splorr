#pragma once
#include "common.h"
#include "boarddata.h"
#include "characterdata.h"
class WorldData
{
private:
    std::vector<BoardData> _boards;
    std::set<size_t> _recycledBoards;
    std::vector<CharacterData> _characters;
    std::set<size_t> _recycledCharacters;
    std::optional<size_t> _avatar;
public:
    void Clear();
    size_t CreateBoard(size_t columns, size_t rows, LocationType locationType);
    BoardData& GetBoardData(size_t boardIndex);
    const BoardData& GetBoardData(size_t boardIndex) const;
    size_t CreateCharacter(CharacterType characterType, size_t boardIndex, size_t locationIndex);
    CharacterData& GetCharacterData(size_t characterIndex);
    const CharacterData& GetCharacterData(size_t characterIndex) const;
    void SetAvatar(std::optional<size_t> avatar);
    std::optional<size_t> GetAvatar() const;
};