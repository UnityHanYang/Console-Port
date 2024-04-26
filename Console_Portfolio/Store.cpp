#include "Store.h"

std::vector<Item*> Store::itemVec = {};
//Item* Store::currentItem = new Item;

#pragma region ���� ����
void Store::VectorPush()
{
	itemVec.push_back(smallHpPotion);
	itemVec.push_back(middleHpPotion);
	itemVec.push_back(bigHpPotion);
	itemVec.push_back(smallMpPotion);
	itemVec.push_back(middleMpPotion);
	itemVec.push_back(bigMpPotion);

}
#pragma endregion

#pragma region ������ �̸�, �ݾ�, ����
void Store::PrintName(int x, int y, int count)
{
	ItemSell itemS;
	int this_count = 0;
	int index = 1;
	itemS.ClearRightSection(66, 9, 37);
	itemS.ClearRightSection(11, 13, 30);
	std::vector<Item*>::iterator iter;
	for (iter = itemVec.begin(); iter != itemVec.end(); ++iter)
	{
		gotoxy(x, y + this_count);
		if (index == count)
		{
			std::cout << "                      " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << "�� " << (*iter)->GetName() << std::endl;
			PrintFeature(x + 54, y - 3, *iter);
			currentItem = *iter;
		}
		else
		{
			std::cout << "                      " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << (*iter)->GetName() << std::endl;
		}
		index++;
		this_count += 2;
	}
}

void Store::PrintPrice(int x, int y, int count)
{
	int this_count = 0;
	int index = 1;
	std::vector<Item*>::iterator iter;
	for (iter = itemVec.begin(); iter != itemVec.end(); ++iter)
	{
		gotoxy(x, y + this_count);
		if (index == count)
		{
			std::cout << "       " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << (*iter)->GetPrice() << " ��" << std::endl;
			currentItemPrice = (*iter)->GetPrice();
		}
		else
		{
			std::cout << "       " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << (*iter)->GetPrice() << std::endl;
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
#pragma endregion

#pragma region ��ġ �̵�
void Store::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#pragma endregion

Store::Store()
{
	hpType = ItemType::hpPotion;
	mpType = ItemType::mpPotion;

	currentItemPrice = 0;
	smallHpPotion = new Item("Hpȸ������(��)", 100, "Hp�� 10 ȸ���Ѵ�.", 1, 10, hpType);
	middleHpPotion = new Item("Hpȸ������(��)", 400, "Hp�� 30 ȸ���Ѵ�.", 1, 30, hpType);
	bigHpPotion = new Item("Hpȸ������(��)", 800, "Hp�� 60 ȸ���Ѵ�.", 1, 60, hpType);
	smallMpPotion = new Item("Mpȸ������(��)", 100, "Mp�� 5 ȸ���Ѵ�.", 1, 5, mpType);
	middleMpPotion = new Item("Mpȸ������(��)", 400, "Mp�� 10 ȸ���Ѵ�.", 1, 10, mpType);
	bigMpPotion = new Item("Mpȸ������(��)", 800, "Mp�� 20 ȸ���Ѵ�.", 1, 20, mpType);
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

