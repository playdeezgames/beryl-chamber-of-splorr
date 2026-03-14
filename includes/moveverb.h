#pragma once
#include "verb.h"
class MoveVerb: public Verb
{
private:
    int _deltaX;
    int _deltaY;
    MoveVerb();
public:
    MoveVerb(int deltaX, int deltaY);
    void Attempt(Character character) const override;
    std::string GetText(Character character) const override {return "";}
};