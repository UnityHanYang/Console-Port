#include "Store.h"


void Store::VectorPush()
{
	itemVec.push_back(smallHpPotion);
	itemVec.push_back(middleHpPotion);
	itemVec.push_back(bigHpPotion);
	itemVec.push_back(smallMpPotion);
	itemVec.push_back(middleMpPotion);
	itemVec.push_back(bigMpPotion);

}

void Store::PrintName(int x, int y, int count)
{
	int this_count = 0;
	int index = 1;
	for (std::vector<Item*>::iterator it = itemVec.begin(); it != itemVec.end(); ++it)
	{
		gotoxy(x, y + this_count);
		if (index == count)
		{
			std::cout << "                      " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << "▶ " << (*it)->GetName() << std::endl;
			PrintFeature(x+54, y- 3, *it);
			currentItem = *it;
		}
		else
		{
			std::cout << "                      " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << (*it)->GetName() << std::endl;
		}
		index++;
		this_count += 2;
	}
}

void Store::PrintPrice(int x, int y, int count)
{
	int this_count = 0;
	int index = 1;
	for (std::vector<Item*>::iterator it = itemVec.begin(); it != itemVec.end(); ++it)
	{
		gotoxy(x, y + this_count);
		if (index == count)
		{
			std::cout << "       " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << (*it)->GetPrice() << " ◀" << std::endl;
			currentItemPrice = (*it)->GetPrice();
		}
		else
		{
			std::cout << "       " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << (*it)->GetPrice() << std::endl;
		}
		index++;
		this_count += 2;
	}
}

void Store::PrintFeature(int x, int y, Item* item)
{
	gotoxy(x, y);
	std::cout << "                             ";
	gotoxy(x, y);
	std::cout << (item)->GetFeature() << std::endl;
}

void Store::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Store::Store()
{
	hpType = ItemType::hpPotion;
	mpType = ItemType::mpPotion;

	currentItemPrice = 0;
	smallHpPotion = new Item("Hp회복포션(소)", 100, "Hp를 10 회복한다.", 1, 10, hpType);
	middleHpPotion = new Item("Hp회복포션(중)", 400, "Hp를 30 회복한다.", 1, 30, hpType);
	bigHpPotion = new Item("Hp회복포션(대)", 800, "Hp를 60 회복한다.", 1, 60, hpType);
	smallMpPotion = new Item("Mp회복포션(소)", 100, "Mp를 5 회복한다.", 1, 5, mpType);
	middleMpPotion = new Item("Mp회복포션(중)", 400, "Mp를 10 회복한다.", 1, 10, mpType);
	bigMpPotion = new Item("Mp회복포션(대)", 800, "Mp를 20 회복한다.", 1, 20, mpType);
	currentItem = new Item;
}

Store::~Store()
{
	delete smallHpPotion;
	delete middleHpPotion;
	delete bigHpPotion;
	delete smallMpPotion;
	delete middleMpPotion;
	delete bigMpPotion;
	delete currentItem;
}

