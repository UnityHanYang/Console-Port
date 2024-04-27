#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>
#include "Store.h"
#include <conio.h>
#include "Item.h"
#include "Player.h"
#include "ItemInventory.h"
#include "Village.h"
#include "ItemSell.h"
#include <algorithm>
#include "GameManager.h"

class Store;

class StoreMap : public PrintSetting
{
private:
	Player player;
	ItemInventory* iit;
	Store* store;
	int count;
	static int buySellNum;
public:
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
	bool CheckBuy();
	void LeftRightInput();
	int GetBuySellNum() { return buySellNum; }

	StoreMap();
	~StoreMap();
};

