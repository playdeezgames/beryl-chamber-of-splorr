#include "verbs.h"
#include "moveverb.h"
std::map<VerbType, std::unique_ptr<Verb>> Verbs::_verbs;
void Verbs::Initialize()
{
    if(_verbs.empty())
    {
        _verbs.emplace(VerbType::MOVE_UP, std::make_unique<MoveVerb>(0,-1));
        _verbs.emplace(VerbType::MOVE_DOWN, std::make_unique<MoveVerb>(0,1));
        _verbs.emplace(VerbType::MOVE_LEFT, std::make_unique<MoveVerb>(-1,0));
        _verbs.emplace(VerbType::MOVE_RIGHT, std::make_unique<MoveVerb>(1,0));
    }
}
const Verb& Verbs::GetVerb(VerbType verbType)
{
    return *_verbs.find(verbType)->second;
}
