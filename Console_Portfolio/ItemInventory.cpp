#include "ItemInventory.h"

std::vector<Item*> ItemInventory::inventory = {};

void ItemInventory::FindInventory(Item* item)
{
	Item* itemToFind = new Item;
	if (!inventory.empty())
	{
		if (std::find(inventory.begin(), inventory.end(), item) != inventory.end())
		{
			RemoveInventory(std::find(inventory.begin(), inventory.end(), item) - inventory.begin(), item);
		}
	}
}

void ItemInventory::AddInventory(Item* item)
{
	inventory.push_back(item);
}

void ItemInventory::AddItemCountInventory(Item* item, int count)
{
	item->SetCount();
	inventory.at(count) = item;
}

void ItemInventory::RemoveInventory(int index, Item* item)
{
	inventory.erase(inventory.begin() + index);
}

void ItemInventory::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
