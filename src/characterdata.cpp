#include "characterdata.h"
#include <limits>
#include <algorithm>
CharacterData::CharacterData(
    CharacterType characterType, 
    size_t boardIndex, 
    size_t locationIndex)
    : _characterType(characterType)
    , _boardIndex(boardIndex)
    , _locationIndex(locationIndex)
    , _statistics()
    , _statisticMaximums()
    , _statisticMinimums()
    , _inventoryIndex(std::nullopt)
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
        return std::clamp(
            iter->second, 
            GetStatisticMinimum(statisticType), 
            GetStatisticMaximum(statisticType));        
    }
    return std::nullopt;
}
void CharacterData::SetStatistic(StatisticType statisticType, std::optional<int> statisticValue)
{
    if(statisticValue)
    {
        _statistics.insert_or_assign(
            statisticType, 
            std::clamp(
                *statisticValue, 
                GetStatisticMinimum(statisticType), 
                GetStatisticMaximum(statisticType)));
    }
    else
    {
        _statistics.erase(statisticType);
    }
}
int CharacterData::GetStatisticMaximum(StatisticType statisticType) const
{
    auto iter = _statisticMaximums.find(statisticType);
    if(iter!=_statisticMaximums.end())
    {
        return iter->second;
    }
    return std::numeric_limits<int>::max();
}
int CharacterData::GetStatisticMinimum(StatisticType statisticType) const
{
    auto iter = _statisticMinimums.find(statisticType);
    if(iter!=_statisticMinimums.end())
    {
        return iter->second;
    }
    return std::numeric_limits<int>::min();
}
void CharacterData::SetStatisticMaximum(StatisticType statisticType, int maximum)
{
    _statisticMaximums.insert_or_assign(statisticType, maximum);
}
void CharacterData::SetStatisticMinimum(StatisticType statisticType, int minimum)
{
    _statisticMinimums.insert_or_assign(statisticType, minimum);
}
void CharacterData::SetInventoryIndex(std::optional<size_t> inventoryIndex)
{
    _inventoryIndex = inventoryIndex;
}
std::optional<size_t> CharacterData::GetInventoryIndex() const
{
    return _inventoryIndex;
}
