#pragma once
#include "ItemInventory.h"
#include <iostream>
#include <conio.h>
#include "Character.h"
#include "Battle.h"
#include "PrintSetting.h"
#include "BattleMapDot.h"
#include "SkillManager.h"

class BattleSkill : public PrintSetting
{
private:
	ItemInventory* iit;
	BattleMapDot bmd;
	int count;
	bool isEnter;

public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);

	void NinJaSkillChoice();
	void ArcherSkillChoice();
	void ClearOption(int x, int y);
	void ShowSkill(int x, int y, int num);
	void NinjaSkillInfo(int x, int y, int num);
	void ArcherkillInfo(int x, int y, int num);

	BattleSkill();
	~BattleSkill();
};

