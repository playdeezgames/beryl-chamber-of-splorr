#pragma once
#include "common.h"
#include "locationdata.h"
#include "worlddata.h"
class Character;
class Board;
class Location
{
private:
    WorldData& _worldData;
    size_t _boardIndex;
    size_t _locationIndex;
    Location();
    LocationData& GetLocationData();
    const LocationData& GetLocationData() const;
public:
    Location(WorldData& worldData, size_t boardIndex, size_t locationIndex);
    void SetLocationType(LocationType locationType);
    LocationType GetLocationType() const;
    size_t GetBoardIndex() const;
    size_t GetLocationIndex() const;
    void SetCharacter(std::optional<Character> character);
    std::optional<Character> GetCharacter() const;
    Board GetBoard() const;
};