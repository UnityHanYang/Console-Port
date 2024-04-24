#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Item.h"

class ItemInventory
{
private:
	static std::vector<Item*> inventory;

public:
	void PrintName(int x, int y, int num);
};

