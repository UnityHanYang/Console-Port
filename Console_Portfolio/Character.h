#pragma once
#include <iostream>
#include "Item.h"

class Character
{
protected:
#pragma region ĳ���� �Ӽ�
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
	virtual void NorMalAttack(Character* target); // �Ϲݰ��� �Լ�
	virtual void SkillAttack(Character* target); // ��ų���� �Լ�
    Character(const char* r_name, const char* r_job, int r_level, int r_currentExp, int r_maxExp, int r_currentHp, int r_maxHp, int r_currentMp, int r_maxMp, int r_def, int r_atk) : 
		name(r_name), job(r_job), level(r_level), currentExp(r_currentExp), maxExp(r_maxExp), currentHp(r_currentHp), maxHp(r_maxHp), currentMp(r_currentMp), maxMp(r_maxMp), def(r_def), atk(r_atk) {};

	int GetLevel() { return level; } // ���� ���� ��ȯ
	int GetCurrentExp() { return currentExp; } // ���� ������ ����ġ ��ȯ
	int GetMaxExp() { return maxExp; } // ���� ������ �Ǳ� ���� ��ƾ� �� ����ġ ��ȯ
	int GetCurrentHp() { return currentHp; } // ���� ü�� ��ȯ
	int GetMaxHp() { return maxHp; } // �ִ� ü�� ��ȯ
	int GetCurrentMp() { return currentMp; }; // ���� ���� ��ȯ
	int GetMaxMp() { return maxMp; } // �ִ� ���� ��ȯ
	int GetAtk() { return atk; } // ���ݷ� ��ȯ
	int GetDef() { return def; } // ���� ��ȯ
	const char* GetName() { return name; } // �̸� ��ȯ
	const char* GetOccupation() { return job; } // ���� ��ȯ


	void SetLevel(int level) { this->level += level; } // ���� ����
	void SetCurrentExp(int exp) { this->currentExp += exp; } // ���� ü�� ����
	void SetMaxExp(int exp) { this->maxExp += exp; } // ���� ������ �Ǳ� ���� ��ƾ� �� ����ġ ����
	void SetCurrentHp(int hp) { this->currentHp += hp; } // ���� ü�� ����
	void SetMaxHp(int hp) { this->maxHp += hp; } // �ִ� ü�� ����
	void SetCurrentMp(int mp) { this->currentMp += mp; } // ���� ���� ����
	void SetMaxMp(int mp) { this->maxMp += mp; } // �ִ� ���� ����
	void SetAtk(int atk) { this->atk += atk; } // ���ݷ� ����
	void SetDef(int def) { this->def += def; } // ���� ����
};

