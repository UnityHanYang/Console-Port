#include "ItemInventoryWindow.h"


#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter 13
#define ESC 27

void ItemInventoryWindow::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void ItemInventoryWindow::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void ItemInventoryWindow::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ItemInventoryWindow::PrintItemAndCancelTool(int x, int y)
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

void ItemInventoryWindow::PrintMoneyTool(int x, int y)
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

void ItemInventoryWindow::PrintItemTool(int x, int y)
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

void ItemInventoryWindow::PrintItemDetailTool(int x, int y)
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


void ItemInventoryWindow::PrintMoneyText(int x, int y)
{
	gotoxy(x, y);
	//std::cout << "소지금: " << player->GetMoney();
}

void ItemInventoryWindow::ShowItem(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x, y - 4);
	std::cout << "-포션-";
	gotoxy(x, y - 2);
	std::cout << "     이름                           가격";

	//store->PrintName(x, y, num);

	//store->PrintPrice(x + 37, y, num);

}

void ItemInventoryWindow::ChoiceUse()
{
	ShowItem(16, 14, 0);

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
					ShowItem(16, 14, count);
					break;
				case UP_ARROW:
					count = (count < 2) ? count : count -= 1;
					ShowItem(16, 14, count);
					break;
				}
			}
			else if (input == ESC)
			{
				count = 0;
				ClearText(16, 14);
				LeftRightInput();
				break;
			}
		}
	}
}

void ItemInventoryWindow::ClearText(int x, int y)
{
	SetColor(0, 0);
	for (int i = 0; i < 16; i++)
	{
		gotoxy(x, y - 4 + i);
		std::cout << "                                          ";
	}

	gotoxy(x + 53, y - 3);
	std::cout << "                                       ";
}

void ItemInventoryWindow::PrintOptionText(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x, y);
	switch (num)
	{
	case 1:
		std::cout << "                                            ";
		gotoxy(x, y);
		std::cout << " ▶ 아이템 ◀                        취소";
		break;
	case 2:
		std::cout << "                                            ";
		gotoxy(x, y);
		std::cout << "   아이템                        ▶ 취소 ◀";
		break;
	default:
		std::cout << "                                            ";
		gotoxy(x, y);
		std::cout << "아이템                          취소 ";
		break;
	}
}

void ItemInventoryWindow::LeftRightInput()
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
				case RIGHT_ARROW:
					option = 2;
					PrintOptionText(27, 5, option);
					break;
				case LEFT_ARROW:
					option = 1;
					PrintOptionText(27, 5, option);
					break;
				}
			}
			else if (input == Enter)
			{
				switch (option)
				{
				case 1:
					ChoiceUse();
					break;
				case 2:
					system("cls");
					break;
				}
			}
		}
	}
}

void ItemInventoryWindow::InventoryTool()
{
	PrintItemAndCancelTool(10, 3);
	PrintMoneyTool(86, 3);
	PrintItemTool(10, 8);
	PrintItemDetailTool(65, 8);
	PrintOptionText(30, 5, option);

	LeftRightInput();
}

ItemInventoryWindow::ItemInventoryWindow()
{
	iit = new ItemInventory;
	count = 0;
	option = 0;
}

ItemInventoryWindow::~ItemInventoryWindow()
{
	delete iit;
}
