#pragma once
#include <iostream>
#include <Windows.h>
#include "ItemInventory.h"
#include "ItemInventoryWindow.h"
#include "StoreMap.h"
#include "Store.h"
#include <conio.h>

class ItemSell
{
private:
	ItemInventory* inven;
	int count;
	bool isEnter;

public:
	void PrintInventory(int x, int y, int num);
	void SetColor(int fontColor, int backgroundColor);
	void gotoxy(int x, int y);
	void ChocieSell();
	void UseItemYesOrNo(int x, int y, Item* item);
	void ClearOption(int x, int y); 
	void ClearRightSection(int x, int y, int loopNum);

	ItemSell();
	~ItemSell();
};

