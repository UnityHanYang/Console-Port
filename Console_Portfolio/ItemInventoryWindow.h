#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>
#include "MapManager.h"
#include "ItemInventory.h"
#include "CharacterInfo.h"
#include "GameManager.h"
#include "CharacterChoice.h"
#include "ItemSell.h"
#include "Item.h"
#include "Player.h"

class ItemInventoryWindow : public PrintSetting
{
private:
	int count;
	int option;
	ItemInventory* iit;
	Player player;
	bool isEnter;

public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintItemAndCancelTool(int x, int y);
	void PrintMoneyTool(int x, int y);
	void PrintItemTool(int x, int y);
	void PrintItemDetailTool(int x, int y);
	void PrintMoneyText(int x, int y);
	void ShowItem(int x, int y, int num);
	void ChoiceUse();
	void ClearText(int x, int y);
	void ChoiceHealChar(int x, int y, Item* item);
	void LeftRightInput();
	void PrintOptionText(int x, int y, int num);
	void UseItemYesOrNo(int x, int y, Item* item);
	void ClearSection(int x, int y);
	void SettingInfo(int x, int y, int num);
	void ClearSection2(int x, int y);
	void HpMpHeal(Character* charcater, Item* item, int x, int y);

	void InventoryTool();

	ItemInventoryWindow();
	~ItemInventoryWindow();
};