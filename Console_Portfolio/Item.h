#pragma once
#include <iostream>
#include <Windows.h>

enum ItemType
{
	weapon,
	armor,
	hpPotion,
	mpPotion
};

class Item
{
private:
	const char* name;
	int price;
	const char* feature;
	int heal;
	int count;
	ItemType itemType;
public:
	Item(const char* c_Name, int c_Price, const char* c_Feature, int c_Count, int c_Heal, ItemType c_ItemType) : name(c_Name), price(c_Price), feature(c_Feature), count(c_Count), heal(c_Heal), itemType(c_ItemType) {}
	Item();

	const char* GetName() { return name; }
	int GetPrice() { return price; }
	const char* GetFeature() { return feature; }
	int GetCount() { return count; }
	void SetCount() { count += 1; }
	void MinusCount() { count -= 1; }
	ItemType GetItemType() { return itemType; }
	int GetHeal() { return heal; }
};