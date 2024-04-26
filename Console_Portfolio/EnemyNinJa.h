#pragma once
#include "Character.h"

class EnemyNinJa : public Character
{
public:
    EnemyNinJa(const char* r_name, const char* r_job)
        : Character(r_name, r_job)
    {
    }
};

class IntermediateNInJa : public Character
{
public:
    IntermediateNInJa(const char* r_name, const char* r_job)
        : Character(r_name, r_job)
    {
    }
};

class BossNinJa : public Character
{
public:
    BossNinJa(const char* r_name, const char* r_job)
        : Character(r_name, r_job)
    {
    }
};