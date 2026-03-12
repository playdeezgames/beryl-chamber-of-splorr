#pragma once
#include "character.h"
class Verb
{
public:
    virtual void Attempt(Character character) const = 0;
    virtual ~Verb() = default;
};