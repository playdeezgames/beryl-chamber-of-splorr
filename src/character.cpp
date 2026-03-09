#include "character.h"
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
