#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Item.h"
#include <algorithm>

class ItemInventory
{
private:
	static std::vector<Item*> inventory;

public:
	bool FindInventory(int index, Item* item);
	void AddInventory(Item* item);
	void RemoveInventory(int index, Item* item);
	void gotoxy(int x, int y);
	std::vector<Item*>& GetInventory() { return inventory; }
};

