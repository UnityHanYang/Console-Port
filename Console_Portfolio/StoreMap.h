#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>
#include "Store.h"
#include <conio.h>
#include "Item.h"

class StoreMap : public PrintSetting
{
private:
	Store* store;
	static int count;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintBuyAndSellTool(int x, int y);
	void PrintMoneyTool(int x, int y);
	void PrintItemTool(int x, int y);
	void PrintItemDetailTool(int x, int y);
	void PrintBuyAndSellText(int x, int y);
	void PrintMoneyText(int x, int y);
	void ShowItem(int x, int y);
	void PrintDetailText(int x, int y);
	void PrintStoreMap();
	int Getcount() { return count; }

	StoreMap();
	~StoreMap();
};

