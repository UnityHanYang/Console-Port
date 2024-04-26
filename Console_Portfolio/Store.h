#pragma once
#include <iostream>
#include "Item.h"
#include <vector>
#include "ItemSell.h"

class Store
{
private:
	Item* smallHpPotion;
	Item* middleHpPotion;
	Item* bigHpPotion;
	Item* smallMpPotion;
	Item* middleMpPotion;
	Item* bigMpPotion;
	static std::vector<Item*> itemVec;
	int currentItemPrice;
	Item* currentItem;
	ItemType hpType;
	ItemType mpType;
public:
	std::vector<Item*>& GetItemVec() { return itemVec; }
	void VectorPush();
	void PrintName(int x, int y, int count);
	void PrintPrice(int x, int y, int count);
	void PrintFeature(int x, int y, Item* item);
	void gotoxy(int x, int y);
	int GetCurrentItemPrice() { return currentItemPrice; }
	Item* GetCurrentItem() { return currentItem; }

	Store();
	~Store();
};

