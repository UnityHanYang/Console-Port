#include "ItemInventory.h"

std::vector<Item*> ItemInventory::inventory = {};

#pragma region 백터 삭제, 삽입, 수정, 검색
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
	delete itemToFind;
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
#pragma endregion


