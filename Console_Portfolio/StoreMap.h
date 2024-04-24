#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>
#include "Store.h"
#include <conio.h>
#include "Item.h"
#include "Player.h"
#include "Village.h"

class StoreMap : public PrintSetting
{
private:
	Store* store;
	int count;
	int buyCellNum;
public:
	Player* player;
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintBuyAndSellTool(int x, int y);
	void PrintMoneyTool(int x, int y);
	void PrintItemTool(int x, int y);
	void PrintItemDetailTool(int x, int y);
	void PrintBuyAndSellText(int x, int y, int num);
	void PrintMoneyText(int x, int y);
	void ShowItem(int x, int y, int num);
	void ChoiceBuy();
	void PrintStoreMap();
	void ClearText(int x, int y);
	void LeftRightInput();

	StoreMap();
	~StoreMap();
};

