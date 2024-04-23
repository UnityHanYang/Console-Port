#pragma once
#include "Character.h"

class NinJa : public Character
{
public:
    NinJa(const char* r_name, const char* r_job, int r_hp, int r_mp, int r_def, int r_atk, int r_critical)
        : Character(r_name, r_job, r_hp, r_mp, r_def, r_atk, r_critical)
    {
    }
    int GetHp() { return hp; }
};

