#pragma once
#include <iostream>
#include "Character.h"

class Player : public Character
{
public:
    Player(const char* f_name, int f_mp, int f_def, int f_atk) : Character(f_name, f_mp, f_def, f_atk) {};

    const char* GetName() { return name; }
    int GetHp() { return hp; }
};

