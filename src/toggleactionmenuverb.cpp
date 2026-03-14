#include "toggleactionmenuverb.h"
std::string ToggleActionMenuVerb::GetText(Character character) const
{
    return "Never Mind";
}
void ToggleActionMenuVerb::Attempt(Character character) const
{
    character.ToggleFlag(FlagType::ACTION_MENU);
}
