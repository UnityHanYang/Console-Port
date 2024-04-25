#include "ItemInventory.h"

std::vector<Item*> ItemInventory::inventory = {};

bool ItemInventory::FindInventory(int index, Item* item)
{
	Item* itemToFind = new Item;
	if (!inventory.empty())
	{
		/*if (std::find(inventory.begin(), inventory.end(), index) != item)
		{
			return true;
		}*/
		auto it = std::find_if(inventory.begin(), inventory.end(), [itemToFind](const Item* item) {
			return item == itemToFind;
			});
		return it != inventory.end();
	}


	return false;
}

void ItemInventory::AddInventory(Item* item)
{
	inventory.push_back(item);
}

void ItemInventory::RemoveInventory(int index, Item* item)
{
	//inventory.erase(std::remove(inventory.begin(), inventory.end(), index), inventory.end());	
	if (FindInventory(index, item))
	{
		inventory.erase(inventory.begin() + index);
	}
}

void ItemInventory::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
