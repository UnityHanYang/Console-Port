#include "StoreMap.h"

int StoreMap::count = 0;

#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13

void StoreMap::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void StoreMap::PrintS(int count, int font, int background, bool isEndl, int x, int y)
{
	SetColor(font, background);
	gotoxy(x, y);

	for (int i = 0; i < count; i++)
	{
		std::cout << "ㅁ";
	}

	if (isEndl)
	{
		std::cout << std::endl;
	}
}

void StoreMap::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void StoreMap::PrintBuyAndSellTool(int x, int y)
{
	SetColor(15, 0);
	gotoxy(x, y);
	std::cout << "┌─────────────────────────────────────────────────────────────────────────┐";
	gotoxy(x, y + 1);
	std::cout << "│                                                                         │";
	gotoxy(x, y + 2);
	std::cout << "│                                                                         │";
	gotoxy(x, y + 3);
	std::cout << "│                                                                         │";
	gotoxy(x, y + 4);
	std::cout << "└─────────────────────────────────────────────────────────────────────────┘";
}

void StoreMap::PrintMoneyTool(int x, int y)
{
	SetColor(15, 0);
	gotoxy(x, y);
	std::cout << "┌───────────────────────────────┐";
	gotoxy(x, y + 1);
	std::cout << "│                               │";
	gotoxy(x, y + 2);
	std::cout << "│                               │";
	gotoxy(x, y + 3);
	std::cout << "│                               │";
	gotoxy(x, y + 4);
	std::cout << "└───────────────────────────────┘";
}

void StoreMap::PrintItemTool(int x, int y)
{
	SetColor(15, 0);
	gotoxy(x, y);
	std::cout << "┌────────────────────────────────────────────────────┐";
	gotoxy(x, y + 1);
	std::cout << "│                                                    │";
	gotoxy(x, y + 2);
	std::cout << "│                                                    │";
	gotoxy(x, y + 3);
	std::cout << "│                                                    │";
	gotoxy(x, y + 4);
	std::cout << "│                                                    │";
	gotoxy(x, y + 5);
	std::cout << "│                                                    │";
	gotoxy(x, y + 6);
	std::cout << "│                                                    │";
	gotoxy(x, y + 7);
	std::cout << "│                                                    │";
	gotoxy(x, y + 8);
	std::cout << "│                                                    │";
	gotoxy(x, y + 9);
	std::cout << "│                                                    │";
	gotoxy(x, y + 10);
	std::cout << "│                                                    │";
	gotoxy(x, y + 11);
	std::cout << "│                                                    │";
	gotoxy(x, y +12);
	std::cout << "│                                                    │";
	gotoxy(x, y + 13);
	std::cout << "│                                                    │";
	gotoxy(x, y + 14);
	std::cout << "│                                                    │";
	gotoxy(x, y + 15);
	std::cout << "│                                                    │";
	gotoxy(x, y + 16);
	std::cout << "│                                                    │";
	gotoxy(x, y + 17);
	std::cout << "│                                                    │";
	gotoxy(x, y + 18);
	std::cout << "│                                                    │";
	gotoxy(x, y + 19);
	std::cout << "│                                                    │";
	gotoxy(x, y + 20);
	std::cout << "│                                                    │";
	gotoxy(x, y + 21);
	std::cout << "│                                                    │";
	gotoxy(x, y + 22);
	std::cout << "│                                                    │";
	gotoxy(x, y + 23);
	std::cout << "│                                                    │";
	gotoxy(x, y + 24);
	std::cout << "│                                                    │";
	gotoxy(x, y + 25);
	std::cout << "│                                                    │";
	gotoxy(x, y + 26);
	std::cout << "│                                                    │";
	gotoxy(x, y + 27);
	std::cout << "│                                                    │";
	gotoxy(x, y + 28);
	std::cout << "│                                                    │";
	gotoxy(x, y + 29);
	std::cout << "│                                                    │";
	gotoxy(x, y + 30);
	std::cout << "│                                                    │";
	gotoxy(x, y + 31);
	std::cout << "│                                                    │";
	gotoxy(x, y + 32);
	std::cout << "│                                                    │";
	gotoxy(x, y + 33);
	std::cout << "│                                                    │";
	gotoxy(x, y + 34);
	std::cout << "│                                                    │";
	gotoxy(x, y + 35);
	std::cout << "│                                                    │";
	gotoxy(x, y + 36);
	std::cout << "│                                                    │";
	gotoxy(x, y + 37);
	std::cout << "│                                                    │";
	gotoxy(x, y + 38);
	std::cout << "└────────────────────────────────────────────────────┘";
}

void StoreMap::PrintItemDetailTool(int x, int y)
{
	SetColor(15, 0);
	gotoxy(x, y);
	std::cout << "┌────────────────────────────────────────────────────┐";
	gotoxy(x, y + 1);
	std::cout << "│                                                    │";
	gotoxy(x, y + 2);
	std::cout << "│                                                    │";
	gotoxy(x, y + 3);
	std::cout << "│                                                    │";
	gotoxy(x, y + 4);
	std::cout << "│                                                    │";
	gotoxy(x, y + 5);
	std::cout << "│                                                    │";
	gotoxy(x, y + 6);
	std::cout << "│                                                    │";
	gotoxy(x, y + 7);
	std::cout << "│                                                    │";
	gotoxy(x, y + 8);
	std::cout << "│                                                    │";
	gotoxy(x, y + 9);
	std::cout << "│                                                    │";
	gotoxy(x, y + 10);
	std::cout << "│                                                    │";
	gotoxy(x, y + 11);
	std::cout << "│                                                    │";
	gotoxy(x, y + 12);
	std::cout << "│                                                    │";
	gotoxy(x, y + 13);
	std::cout << "│                                                    │";
	gotoxy(x, y + 14);
	std::cout << "│                                                    │";
	gotoxy(x, y + 15);
	std::cout << "│                                                    │";
	gotoxy(x, y + 16);
	std::cout << "│                                                    │";
	gotoxy(x, y + 17);
	std::cout << "│                                                    │";
	gotoxy(x, y + 18);
	std::cout << "│                                                    │";
	gotoxy(x, y + 19);
	std::cout << "│                                                    │";
	gotoxy(x, y + 20);
	std::cout << "│                                                    │";
	gotoxy(x, y + 21);
	std::cout << "│                                                    │";
	gotoxy(x, y + 22);
	std::cout << "│                                                    │";
	gotoxy(x, y + 23);
	std::cout << "│                                                    │";
	gotoxy(x, y + 24);
	std::cout << "│                                                    │";
	gotoxy(x, y + 25);
	std::cout << "│                                                    │";
	gotoxy(x, y + 26);
	std::cout << "│                                                    │";
	gotoxy(x, y + 27);
	std::cout << "│                                                    │";
	gotoxy(x, y + 28);
	std::cout << "│                                                    │";
	gotoxy(x, y + 29);
	std::cout << "│                                                    │";
	gotoxy(x, y + 30);
	std::cout << "│                                                    │";
	gotoxy(x, y + 31);
	std::cout << "│                                                    │";
	gotoxy(x, y + 32);
	std::cout << "│                                                    │";
	gotoxy(x, y + 33);
	std::cout << "│                                                    │";
	gotoxy(x, y + 34);
	std::cout << "│                                                    │";
	gotoxy(x, y + 35);
	std::cout << "│                                                    │";
	gotoxy(x, y + 36);
	std::cout << "│                                                    │";
	gotoxy(x, y + 37);
	std::cout << "│                                                    │";
	gotoxy(x, y + 38);
	std::cout << "└────────────────────────────────────────────────────┘";
}

void StoreMap::PrintBuyAndSellText(int x, int y)
{
	SetColor(15, 0);
	gotoxy(x, y);
	std::cout << "       구입                    판매                    취소";
}

void StoreMap::PrintMoneyText(int x, int y)
{
	gotoxy(x, y);
	std::cout << "소지금: ";
}

void StoreMap::ShowItem(int x, int y)
{
	SetColor(15, 0);
	gotoxy(x, y-4);
	std::cout << "-포션-";
	gotoxy(x, y-2);
	std::cout << "     이름                           가격";

	store->PrintName(x, y, count);

	store->PrintPrice(x+37, y, count);

}

void StoreMap::PrintDetailText(int x, int y)
{
	SetColor(15, 0);

	//store->PrintFeature(x, y, );
}

void StoreMap::PrintStoreMap()
{
	store->ItemInit();
	store->VectorPush();
	PrintBuyAndSellTool(10, 3);
	PrintMoneyTool(86, 3);
	PrintItemTool(10, 8);
	PrintItemDetailTool(65, 8);
	PrintBuyAndSellText(15, 5);
	PrintMoneyText(89, 5);
	ShowItem(16, 14);
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
					count = (count > 5) ? count : count += 1;
					ShowItem(16, 14);
					break;
				case UP_ARROW:
					count = (count < 2) ? count : count -= 1;
					ShowItem(16, 14);
					break;
				}
			}
		}
	}
}

StoreMap::StoreMap()
{
	store = new Store;
}

StoreMap::~StoreMap()
{
	delete store;
}

