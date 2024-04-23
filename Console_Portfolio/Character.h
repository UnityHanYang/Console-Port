#pragma once
#include <iostream>
#include "ICharacter.h"

class Character : public ICharacter
{
protected:
    const char* name;
    const char* job;
    int hp;
    int mp;
    int def;
    int atk;
    int critical;
public:

    Character(const char* r_name, const char* r_job, int r_hp, int r_mp, int r_def, int r_atk, int r_critical) : name(r_name), job(r_job), hp(r_hp),  mp(r_mp), def(r_def), atk(r_atk), critical(r_critical) {};
};

