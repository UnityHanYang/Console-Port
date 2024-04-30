#pragma once
#include "Character.h"

class EnemyArcher : public Character
{
public:
    EnemyArcher(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk) :
        Character(r_name, r_job, r_level, r_currentExp, r_maxExp, r_currentHp, r_maxHp, r_currentMp, r_maxMp, r_def, r_atk) {};

    void NorMalAttack(Character* target) override; //일반공격 함수
    void SkillAttack(Character* target) override; //스킬공격 함수
};

class IntermediateArcher : public Character
{
public:
    IntermediateArcher(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk) :
        Character(r_name, r_job, r_level, r_currentExp, r_maxExp, r_currentHp, r_maxHp, r_currentMp, r_maxMp, r_def, r_atk) {};

    void NorMalAttack(Character* target) override; //일반공격 함수
    void SkillAttack(Character* target) override; //스킬공격 함수
};