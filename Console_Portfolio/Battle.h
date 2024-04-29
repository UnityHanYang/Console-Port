#pragma once
#include "BattleMapDot.h"
#include "GameManager.h"
#include <conio.h>
#include "PrintSetting.h"
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "Character.h"
#include "MapDot.h"
#include "MapManager.h"
#include <time.h>
#include "ItemInventory.h"
#include "BattleInventory.h"
#include <vector>
#include "Player.h"
#include "BattleSkill.h"

class Battle : public PrintSetting
{
private:
	BattleMapDot bmd;
	NinjaDot nd;
	ArcherDot ad;
	Character* chr;
	Character* target;
	MapDot md;
	Player player;
	int count = 0;
	int hpBar = 0;
	int mpBar = 0;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintBattleMap();
	void PrintOption(int num, int x, int y);
	void ClearOption(int x, int y);
	void EnemyTurn();
	void PlayerDie(std::vector<Character*> characterVec);
	void EnemyDie();
	bool CheckPlayerDie(std::vector<Character*> characterVec);
	void CheckExpLevel(std::vector<Character*> characterVec, int exp);
	void SpecUp(Character* ch);
	void DownUpInput();
	void CharacterTarget();
};

