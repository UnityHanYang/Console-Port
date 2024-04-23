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

	int GetHp() { return hp; }
	int GetMp() { return mp; };
	int GetAtk() { return atk; }
	int GetDef() { return def; }
	int GetCritical() { return critical; }
	const char* GetName() { return name; }
	const char* GetOccupation() { return job; }

	void SetHp(int hp) { this->hp += hp; }
	void SetMp(int mp) { this->mp += mp; }
	void SetAtk(int atk) { this->atk += atk; }
	void SetDef(int def) { this->def += def; }
	void SetCritical(int critical) { this->critical += critical; }
};

