#pragma once
#include <iostream>
#include "Item.h"

class Character
{
protected:
    const char* name;
    const char* job;
	int level;
	int currentExp;
	int maxExp;
    int currentHp;
	int maxHp;
	int currentMp;
	int maxMp;
	int def;
	int atk;
	int critical;
public:
	virtual void NorMalAttack(Character* target);
	virtual void ItemUse(Item* item);
	virtual void SkillAttack(Character* target);
    Character(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk, int r_critical) : 
		name(r_name), job(r_job), level(r_level), currentExp(r_currentExp), maxExp(r_maxExp), currentHp(r_currentHp), maxHp(r_maxHp), currentMp(r_currentMp), maxMp(r_maxMp), def(r_def), atk(r_atk), critical(r_critical) {};

	int GetLevel() { return level; }
	int GetCurrentExp() { return currentExp; }
	int GetMaxExp() { return maxExp; }
	int GetCurrentHp() { return currentHp; }
	int GetMaxHp() { return maxHp; }
	int GetCurrentMp() { return currentMp; };
	int GetMaxMp() { return maxMp; }
	int GetAtk() { return atk; }
	int GetDef() { return def; }
	int GetCritical() { return critical; }
	const char* GetName() { return name; }
	const char* GetOccupation() { return job; }


	void SetLevel(int level) { this->level += level; }
	void SetCurrentExp(int exp) { this->currentExp += exp; }
	void SetMaxExp(int exp) { this->maxExp += exp; }
	void SetCurrentHp(int hp) { this->currentHp += hp; }
	void SetMaxHp(int hp) { this->maxHp += hp; }
	void SetCurrentMp(int mp) { this->currentMp += mp; }
	void SetMaxMp(int mp) { this->maxMp += mp; }
	void SetAtk(int atk) { this->atk += atk; }
	void SetDef(int def) { this->def += def; }
	void SetCritical(int critical) { this->critical += critical; }
};

