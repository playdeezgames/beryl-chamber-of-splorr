#pragma once
#include "common.h"
#include "verbtype.h"
#include "verb.h"
class Verbs
{
private:
    static std::map<VerbType, std::unique_ptr<Verb>> _verbs;
public:
    static void Initialize();
    static const Verb& GetVerb(VerbType verbType);
};