#pragma once
#include "Character.h"

class EnemyNinJa : public Character
{
public:
    EnemyNinJa(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk, int r_critical) :
        Character(r_name, r_job, r_level, r_currentExp, r_maxExp, r_currentHp, r_maxHp, r_currentMp, r_maxMp, r_def, r_atk, r_critical) {};
};

class IntermediateNInJa : public Character
{
public:
    IntermediateNInJa(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk, int r_critical) :
        Character(r_name, r_job, r_level, r_currentExp, r_maxExp, r_currentHp, r_maxHp, r_currentMp, r_maxMp, r_def, r_atk, r_critical) {};
};

class BossNinJa : public Character
{
public:
    BossNinJa(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk, int r_critical) :
        Character(r_name, r_job, r_level, r_currentExp, r_maxExp, r_currentHp, r_maxHp, r_currentMp, r_maxMp, r_def, r_atk, r_critical) {};
};