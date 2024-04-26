#pragma once
#include "Character.h"
class Archer : public Character
{
public:
    Archer(const char* r_name, const char* r_job)
        : Character(r_name, r_job)
    {
    }
};

