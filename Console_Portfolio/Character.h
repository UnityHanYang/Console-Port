#pragma once
#include <iostream>
#include "ICharacter.h"

class Character : public ICharacter
{
protected:
    const char* name;
    const char* job;
    static int currentHp;
	int maxHp;
	int currentMp;
	int maxMp;
    int def;
    int atk;
    int critical;
public:

    Character(const char* r_name, const char* r_job, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk, int r_critical) : name(r_name), job(r_job), maxHp(r_maxHp), currentMp(r_currentMp), maxMp(r_maxMp), def(r_def), atk(r_atk), critical(r_critical) {};

	int GetCurrentHp() { return currentHp; }
	int GetMaxHp() { return maxHp; }
	int GetCurrentMp() { return currentMp; };
	int GetMaxMp() { return maxMp; }
	int GetAtk() { return atk; }
	int GetDef() { return def; }
	int GetCritical() { return critical; }
	const char* GetName() { return name; }
	const char* GetOccupation() { return job; }

	void SetCurrentHp(int hp) { this->currentHp += hp; }
	void SetMaxHp(int hp) { this->maxHp += hp; }
	void SetCurrentMp(int mp) { this->currentMp += mp; }
	void SetMaxMp(int mp) { this->maxMp += mp; }
	void SetAtk(int atk) { this->atk += atk; }
	void SetDef(int def) { this->def += def; }
	void SetCritical(int critical) { this->critical += critical; }
};

