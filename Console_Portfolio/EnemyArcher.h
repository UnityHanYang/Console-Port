#pragma once
#include "Character.h"

class EnemyArcher : public Character
{
public:
    EnemyArcher(const char* r_name, const char* r_job)
        : Character(r_name, r_job)
    {
    }
};

class IntermediateArcher : public Character
{
public:
    IntermediateArcher(const char* r_name, const char* r_job)
        : Character(r_name, r_job)
    {
    }
};

class BossArcher : public Character
{
public:
    BossArcher(const char* r_name, const char* r_job)
        : Character(r_name, r_job)
    {
    }
};