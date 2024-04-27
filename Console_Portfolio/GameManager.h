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


class GameManager
{
private:
	static std::vector<Character*> chracterCount;
	static int characterNum;
public:
	NinJa* nj;
	Archer* ah;
	EnemyNinJa* e_nj;
	EnemyArcher* e_ah;
	IntermediateNInJa* e_inj;
	IntermediateArcher* e_iah;
	BossNinJa* e_bnj;
	BossArcher* e_bah;
	BattleMapDot bmd;
	std::vector<Character*> GetCharacterCount() { return chracterCount; }
	void AddCharacter(Character* ch) { chracterCount.push_back(ch); }
	int GetCharacter() { return characterNum; }
	void SetCharacter(int num) { characterNum = num; }

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

