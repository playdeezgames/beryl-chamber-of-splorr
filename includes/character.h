#pragma once
#include "common.h"
#include "worlddata.h"
#include "verbtype.h"
#include "statistictype.h"
#include "framebuffercellcolor.h"
class Board;
class Location;
class Inventory;
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
    void AttemptVerb(VerbType verbType);
    void SetLocation(Location location);
    std::optional<int> GetStatistic(StatisticType statisticType) const;
    std::optional<int> SetStatistic(StatisticType statisticType, std::optional<int> statisticValue);
    void Initialize();
    int GetStatisticMaximum(StatisticType statisticType) const;
    int GetStatisticMinimum(StatisticType statisticType) const;
    void SetStatisticMaximum(StatisticType statisticType, int maximum);
    void SetStatisticMinimum(StatisticType statisticType, int minimum);
    void DoTurn();
    int ChangeStatistic(StatisticType statisticType, int delta);
    unsigned char GetFrameCharacter() const;
    FrameBufferCellColor GetFrameForeground() const;
    Inventory GetInventory();
    bool HasInventory() const;
    Inventory GetInventory() const;
};