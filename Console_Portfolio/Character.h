#pragma once
#include <iostream>

class Character
{
protected:
    const char* name;
    const char* job;
    static int currentHp;
	static int maxHp;
	static int currentMp;
	static int maxMp;
	static int def;
	static int atk;
	static int critical;
public:

    Character(const char* r_name, const char* r_job) : name(r_name), job(r_job) {};

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

