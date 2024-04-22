#pragma once
#include <iostream>

class Character
{
protected:
    const char* name;
    static int hp;
    int mp;
    int def;
    int atk;
public:
    Character(const char* f_name, int f_mp, int f_def, int f_atk) : name(f_name),  mp(f_mp), def(f_def), atk(f_atk) {};

    void SetHp(int a) { hp = a; }
};

