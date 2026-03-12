#pragma once
#include "common.h"
#include "charactertype.h"
#include "statistictype.h"
class CharacterData
{
private:
    CharacterType _characterType;
    size_t _boardIndex;
    size_t _locationIndex;
    std::map<StatisticType, int> _statistics;
    std::map<StatisticType, int> _statisticMaximums;
    std::map<StatisticType, int> _statisticMinimums;
    CharacterData();
public:
    CharacterData(CharacterType characterType, size_t boardIndex, size_t locationIndex);
    void SetCharacterType(CharacterType characterType);
    void SetLocationIndices(size_t boardIndex, size_t locationIndex);
    CharacterType GetCharacterType() const;
    size_t GetBoardIndex() const;
    size_t GetLocationIndex() const;
    std::optional<int> GetStatistic(StatisticType statisticType) const;
    void SetStatistic(StatisticType statisticType, std::optional<int> statisticValue);
    int GetStatisticMaximum(StatisticType statisticType) const;
    int GetStatisticMinimum(StatisticType statisticType) const;
    void SetStatisticMaximum(StatisticType statisticType, int maximum);
    void SetStatisticMinimum(StatisticType statisticType, int minimum);
};