#pragma once
#include <iostream>
#include "Item.h"

class Character
{
protected:
#pragma region 캐릭터 속성
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
#pragma endregion

public:
	virtual void NorMalAttack(Character* target); // 일반공격 함수
	virtual void SkillAttack(Character* target); // 스킬공격 함수
    Character(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk) : 
		name(r_name), job(r_job), level(r_level), currentExp(r_currentExp), maxExp(r_maxExp), currentHp(r_currentHp), maxHp(r_maxHp), currentMp(r_currentMp), maxMp(r_maxMp), def(r_def), atk(r_atk) {};

	int GetLevel() { return level; } // 현재 레벨 반환
	int GetCurrentExp() { return currentExp; } // 현재 보유한 경험치 반환
	int GetMaxExp() { return maxExp; } // 다음 레벨이 되기 위해 모아야 할 경험치 반환
	int GetCurrentHp() { return currentHp; } // 현재 체력 반환
	int GetMaxHp() { return maxHp; } // 최대 체력 반환
	int GetCurrentMp() { return currentMp; }; // 현재 마나 반환
	int GetMaxMp() { return maxMp; } // 최대 마나 반환
	int GetAtk() { return atk; } // 공격력 반환
	int GetDef() { return def; } // 방어력 반환
	const char* GetName() { return name; } // 이름 반환
	const char* GetOccupation() { return job; } // 직업 반환


	void SetLevel(int level) { this->level += level; } // 레벨 수정
	void SetCurrentExp(int exp) { this->currentExp += exp; } // 현재 체력 수정
	void SetMaxExp(int exp) { this->maxExp += exp; } // 다음 레벨이 되기 위해 모아야 할 경험치 수정
	void SetCurrentHp(int hp) { this->currentHp += hp; } // 현재 체력 수정
	void SetMaxHp(int hp) { this->maxHp += hp; } // 최대 체력 수정
	void SetCurrentMp(int mp) { this->currentMp += mp; } // 현재 마나 수정
	void SetMaxMp(int mp) { this->maxMp += mp; } // 최대 마나 수정
	void SetAtk(int atk) { this->atk += atk; } // 공격력 수정
	void SetDef(int def) { this->def += def; } // 방어력 수정
};

