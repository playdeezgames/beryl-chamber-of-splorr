#include "characters.h"
#include "n00bcharacteroutfitter.h"
std::map<CharacterType, std::unique_ptr<CharacterOutfitter>> Characters::_outfitters;
void Characters::Initialize()
{
    if(_outfitters.empty())
    {
        _outfitters.emplace(CharacterType::N00B, std::make_unique<N00bCharacterOutfitter>());
    }
}
const CharacterOutfitter& Characters::GetOutfitter(CharacterType characterType)
{
    return *_outfitters.find(characterType)->second;
}
