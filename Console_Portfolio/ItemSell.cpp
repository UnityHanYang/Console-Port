#include "ItemSell.h"


#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter 13
#define ESC 27

void ItemSell::PrintInventory(int x, int y, int num)
{
	int this_count = 0;
	int index = 1;
	SetColor(15, 0);
	gotoxy(x, y - 4);
	std::cout << "-포션-";
	gotoxy(x, y - 2);
	std::cout << "     이름                           가격";
	if (!inven->GetInventory().empty())
	{
		SetColor(15, 0);
		for (std::vector<Item*>::iterator iter = inven->GetInventory().begin(); iter != inven->GetInventory().end(); ++iter)
		{
			gotoxy(x, y + this_count);
			if (index == num)
			{
				std::cout << "                        " << std::endl;
				gotoxy(x, y + this_count);
				std::cout << "▶ " << (*iter)->GetName() << std::endl;

				gotoxy(x + 54, y - 3);
				std::cout << "                             ";
				gotoxy(x + 54, y - 3);
				std::cout << "수량: " << (*iter)->GetCount() << std::endl;
				gotoxy(x + 54, y - 1);
				std::cout << "                             ";
				gotoxy(x + 54, y - 1);
				std::cout << (*iter)->GetFeature() << std::endl;

				/*if (isEnter)
				{
					UseItemYesOrNo(x, y, *iter);
					isEnter = false;
				}*/
			}
			else
			{
				std::cout << "                        " << std::endl;
				gotoxy(x, y + this_count);
				std::cout << (*iter)->GetName() << std::endl;
			}
			index++;
			this_count += 2;
		}
	}
}

void ItemSell::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void ItemSell::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ItemSell::ChocieSell()
{
	StoreMap storeM;
	PrintInventory(16, 14, 0);
	if (!inven->GetInventory().empty())
	{

		int input;
		while (true)
		{
			if (_kbhit())
			{
				input = _getch();
				if (input == ARROW)
				{
					input = _getch();
					switch (input)
					{
					case DOWN_ARROW:
						count = (count > inven->GetInventory().size() - 1) ? count : count += 1;
						PrintInventory(16, 14, count);
						break;
					case UP_ARROW:
						count = (count < 2) ? count : count -= 1;
						PrintInventory(16, 14, count);
						break;
					}
				}
				else if (input == Enter)
				{
					PrintInventory(16, 14, count);
					break;
				}
				else if (input == ESC)
				{
					count = 0;
					storeM.ClearText(16, 14);
					storeM.LeftRightInput();
					break;
				}
			}
		}
	}
}

ItemSell::ItemSell()
{
	inven = new ItemInventory;
	count = 0;
}

ItemSell::~ItemSell()
{
	delete inven;
}
