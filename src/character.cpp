#include "character.h"
#include "board.h"
#include "location.h"
Character::Character(
    WorldData& worldData, 
    size_t index)
    : _worldData(worldData)
    , _index(index)
{

}
size_t Character::GetIndex() const
{
    return _index;
}
Board Character::GetBoard() const
{
    return Board(_worldData, GetCharacterData().GetBoardIndex());
}
Location Character::GetLocation() const
{
    auto characterData = GetCharacterData();
    return Location(_worldData, characterData.GetBoardIndex(), characterData.GetLocationIndex());
}
CharacterData& Character::GetCharacterData()
{
    return _worldData.GetCharacterData(GetIndex());
}
const CharacterData& Character::GetCharacterData() const
{
    return _worldData.GetCharacterData(GetIndex());
}
CharacterType Character::GetCharacterType() const
{
    return GetCharacterData().GetCharacterType();
}
