#pragma once
#include "character.h"
class Verb
{
public:
    virtual std::string GetText(Character character) const = 0;
    virtual void Attempt(Character character) const = 0;
    virtual ~Verb() = default;
};