#pragma once
#include <iostream>
#include "Item.h"
#include <vector>
#include <map>

class Store
{
private:
	Item* smallHpPotion;
	Item* middleHpPotion;
	Item* bigHpPotion;
	Item* smallMpPotion;
	Item* middleMpPotion;
	Item* bigMpPotion;
	std::vector<Item*> itemVec;
public:
	std::vector<Item*> GetItemVec() { return itemVec; }
	void VectorPush();
	void PrintName(int x, int y, int count);
	void PrintPrice(int x, int y, int count);
	void PrintFeature(int x, int y, Item* item);
	void gotoxy(int x, int y);
	void DeleteItem();

	Store();
	~Store();
};

