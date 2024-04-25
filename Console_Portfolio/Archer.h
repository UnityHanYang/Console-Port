#pragma once
#include "Character.h"
class Archer : public Character
{
public:
    Archer(const char* r_name, const char* r_job, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk, int r_critical)
        : Character(r_name, r_job, r_maxHp, r_currentMp, r_maxMp, r_def, r_atk, r_critical)
    {
    }
};

