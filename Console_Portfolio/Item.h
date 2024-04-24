#pragma once
#include <iostream>
#include <Windows.h>

class Item
{
private:
	const char* name;
	int price;
	const char* feature;
	int count;
public:
	Item(const char* c_Name, int c_Price, const char* c_Feature, int c_Count = 0) : name(c_Name), price(c_Price), feature(c_Feature), count(c_Count) {}

	const char* GetName() { return name; }
	int GetPrice() { return price; }
	const char* GetFeature() { return feature; }
};