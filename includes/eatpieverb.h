#pragma once
#include "verb.h"
class EatPieVerb: public Verb
{
public:
    std::string GetText(Character character) const override;
    void Attempt(Character character) const override;
};