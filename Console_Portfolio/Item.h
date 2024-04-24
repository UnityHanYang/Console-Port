#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

struct ItemElement
{
	const char* name;
	int price;
	const char* feature;
	int count;
};

class Item
{
private:
	std::vector<ItemElement> itemVec;
public:
	std::vector<ItemElement> GetItemVec() { return itemVec; }
	void PushItemVec(ItemElement ie) { itemVec.push_back(ie); }

	Item() : itemVec{ 0 } {};
};

