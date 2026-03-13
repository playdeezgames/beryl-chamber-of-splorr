#include "character.h"
#include "board.h"
#include "location.h"
#include "verbs.h"
#include "characters.h"
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
void Character::AttemptVerb(VerbType verbType)
{
    Verbs::GetVerb(verbType).Attempt(*this);
}
void Character::SetLocation(Location location)
{
    GetCharacterData().SetLocationIndices(location.GetBoardIndex(), location.GetLocationIndex());
}
std::optional<int> Character::GetStatistic(StatisticType statisticType) const
{
    return GetCharacterData().GetStatistic(statisticType);
}
void Character::Initialize()
{
    Characters::GetOutfitter(GetCharacterType()).Initialize(*this);
}
std::optional<int> Character::SetStatistic(StatisticType statisticType, std::optional<int> statisticValue)
{
    GetCharacterData().SetStatistic(statisticType, statisticValue);
    return GetStatistic(statisticType);
}
int Character::GetStatisticMaximum(StatisticType statisticType) const
{
    return GetCharacterData().GetStatisticMaximum(statisticType);
}
int Character::GetStatisticMinimum(StatisticType statisticType) const
{
    return GetCharacterData().GetStatisticMinimum(statisticType);
}
void Character::SetStatisticMaximum(StatisticType statisticType, int maximum)
{
    GetCharacterData().SetStatisticMaximum(statisticType, maximum);
}
void Character::SetStatisticMinimum(StatisticType statisticType, int minimum)
{
    GetCharacterData().SetStatisticMinimum(statisticType, minimum);
}
void Character::DoTurn()
{
    Characters::GetOutfitter(GetCharacterType()).DoTurn(*this);
}
int Character::ChangeStatistic(StatisticType statisticType, int delta)
{
    return *SetStatistic(statisticType, *GetStatistic(statisticType) + delta);
}
unsigned char Character::GetFrameCharacter() const
{
    return Characters::GetOutfitter(GetCharacterType()).GetFrameCharacter();
}
FrameBufferCellColor Character::GetFrameForeground() const
{
    return Characters::GetOutfitter(GetCharacterType()).GetFrameForeground();
}

