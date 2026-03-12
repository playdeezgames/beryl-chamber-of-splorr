#pragma once
#include "common.h"
#include "worlddata.h"
#include "board.h"
#include "charactertype.h"
#include "character.h"
class World
{
private:
    WorldData& _worldData;
    World();
public:
    World(WorldData& worldData);
    void Initialize();
    void Abandon();
    Board CreateBoard(size_t columns, size_t rows, LocationType locationType);
    Character CreateCharacter(CharacterType characterType, Location location);
    void SetAvatar(std::optional<Character> avatar);
    std::optional<Character> GetAvatar() const;
};