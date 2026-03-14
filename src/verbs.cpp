#include "verbs.h"
#include "moveverb.h"
#include "toggleactionmenuverb.h"
#include "eatpieverb.h"
std::map<VerbType, std::unique_ptr<Verb>> Verbs::_verbs;
void Verbs::Initialize()
{
    if(_verbs.empty())
    {
        _verbs.emplace(VerbType::MOVE_UP, std::make_unique<MoveVerb>(0,-1));
        _verbs.emplace(VerbType::MOVE_DOWN, std::make_unique<MoveVerb>(0,1));
        _verbs.emplace(VerbType::MOVE_LEFT, std::make_unique<MoveVerb>(-1,0));
        _verbs.emplace(VerbType::MOVE_RIGHT, std::make_unique<MoveVerb>(1,0));
        _verbs.emplace(VerbType::TOGGLE_ACTION_MENU, std::make_unique<ToggleActionMenuVerb>());
        _verbs.emplace(VerbType::EAT_PIE, std::make_unique<EatPieVerb>());
    }
}
const Verb& Verbs::GetVerb(VerbType verbType)
{
    return *_verbs.find(verbType)->second;
}
std::vector<std::tuple<VerbType, std::string>> Verbs::GetActionMenu(Character character)
{
    std::vector<std::tuple<VerbType, std::string>> result;
    for(const auto& verb : _verbs)
    {
        auto text = verb.second->GetText(character);
        if(!text.empty())
        {
            result.emplace_back(verb.first, text);
        }
    }
    return result;
}
