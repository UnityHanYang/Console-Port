#pragma once
#include "ItemInventory.h"
#include <iostream>
#include <conio.h>
#include "Character.h"
#include "Battle.h"
#include "PrintSetting.h"
#include "BattleMapDot.h"


class BattleInventory : public PrintSetting
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
	void ItemChoice();
	void ShowItem(int x, int y, int num);
	void SettingInfo(int x, int y, int num);
	void ChoiceHealChar(int x, int y, Item* item);
	void HpMpHeal(Character& character, Item* item, int x, int y);
	void ClearOption(int x, int y);
	void CharacterHpMpBar(Character* ch); 

	BattleInventory();
	~BattleInventory();
};

