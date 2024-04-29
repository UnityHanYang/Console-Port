#pragma once
#include "PrintSetting.h"
#include "NinJa.h"
#include "Archer.h"
#include "EnemyNinJa.h"
#include "EnemyArcher.h"
#include <iostream>
#include "NinjaDot.h"
#include "ArcherDot.h"
#include <time.h>
#include "BattleMapDot.h"
#include <vector>
#include "Character.h"
#include "Battle.h"
#include "Skill.h"


class GameManager
{
private:
	static std::vector<Character*> chracterCount;
	static int characterNum;
	static int enemyLevelNum;
	static int randomNum;
public:
	NinJa* nj;
	Archer* ah;
	EnemyNinJa* e_nj;
	EnemyArcher* e_ah;
	IntermediateNInJa* e_inj;
	IntermediateArcher* e_iah;
	BossNinJa* e_bnj;
	BattleMapDot bmd;
	Skill* skill;
	std::vector<Character*> GetCharacterCount() { return chracterCount; }
	void AddCharacter(Character* ch) { chracterCount.push_back(ch); }
	int GetCharacter() { return characterNum; }
	void SetCharacter(int num) { characterNum = num; }
	int GetEnemyLevelNum() { return enemyLevelNum; }
	int GetRandomNum() { return randomNum; }
	void SkillInit();

	static GameManager* instance;

	void RandomEnemyUnit(int enemyLevel);

	static GameManager* GetInstance() {
		if (instance == nullptr)
		{
			instance = new GameManager();
		}
		return instance;
	}

	GameManager();
	~GameManager();
};

