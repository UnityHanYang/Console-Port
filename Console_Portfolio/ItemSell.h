#pragma once
#include <iostream>
#include <Windows.h>
#include "ItemInventory.h"
#include "StoreMap.h"
#include <conio.h>

class ItemSell
{
private:
	ItemInventory* inven;
	int count;

public:
	void PrintInventory(int x, int y, int num);
	void SetColor(int fontColor, int backgroundColor);
	void gotoxy(int x, int y);
	void ChocieSell();

	ItemSell();
	~ItemSell();
};

