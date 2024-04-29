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
	void FindInventory(Item* item);
	void AddInventory(Item* item);
	void AddItemCountInventory(Item* item, int count);
	void RemoveInventory(int index, Item* item);
	std::vector<Item*>& GetInventory() { return inventory; }
};

