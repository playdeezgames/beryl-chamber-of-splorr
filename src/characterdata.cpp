#include "characterdata.h"
CharacterData::CharacterData(
    CharacterType characterType, 
    size_t boardIndex, 
    size_t locationIndex)
    : _characterType(characterType)
    , _boardIndex(boardIndex)
    , _locationIndex(locationIndex)
    , _statistics()
{

}
void CharacterData::SetCharacterType(CharacterType characterType)
{
    _characterType = characterType;
}
void CharacterData::SetLocationIndices(size_t boardIndex, size_t locationIndex)
{
    _boardIndex = boardIndex;
    _locationIndex = locationIndex;
}
CharacterType CharacterData::GetCharacterType() const
{
    return _characterType;
}
size_t CharacterData::GetBoardIndex() const
{
    return _boardIndex;
}
size_t CharacterData::GetLocationIndex() const
{
    return _locationIndex;
}
std::optional<int> CharacterData::GetStatistic(StatisticType statisticType) const
{
    auto iter = _statistics.find(statisticType);
    if(iter != _statistics.end())
    {
        return iter->second;        
    }
    return std::nullopt;
}
