#include "ItemSell.h"


#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter 13
#define ESC 27

#pragma region 아이템 자세히 보기
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
				gotoxy(x + 37, y + this_count);
				std::cout << "       " << std::endl;
				gotoxy(x + 37, y + this_count);
				std::cout << (*iter)->GetPrice() << " ◀" << std::endl;

				if (isEnter)
				{
					UseItemYesOrNo(x, y, *iter);
				}
			}
			else
			{
				std::cout << "                        " << std::endl;
				gotoxy(x, y + this_count);
				std::cout << (*iter)->GetName() << std::endl;

				gotoxy(x + 37, y + this_count);
				std::cout << "       " << std::endl;
				gotoxy(x + 37, y + this_count);
				std::cout << (*iter)->GetPrice() << std::endl;
			}
			index++;
			this_count += 2;
		}
	}
}
#pragma endregion

#pragma region 아이템 판매 여부
void ItemSell::UseItemYesOrNo(int x, int y, Item* item)
{
	StoreMap storeM;
	ItemInventoryWindow iiw;
	Player player;
	SetColor(15, 0);
	gotoxy(x + 58, y + 27);
	std::cout << "                                   ";
	gotoxy(x + 58, y + 27);
	std::cout << item->GetName() << "을 판매하시겠습까? ";
	gotoxy(x + 70, y + 29);
	std::cout << "               ";
	gotoxy(x + 70, y + 29);
	std::cout << "예 / 아니오";
	int choice = 0;
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
					SetColor(15, 0);
					gotoxy(x + 70, y + 29);
					std::cout << "               ";
					gotoxy(x + 70, y + 29);
					SetColor(15, 0);
					std::cout << "예 / ";
					gotoxy(x + 75, y + 29);
					SetColor(12, 0);
					std::cout << "아니오";
					choice = 1;
					break;
				case LEFT_ARROW:
					SetColor(15, 0);
					gotoxy(x + 70, y + 29);
					std::cout << "               ";
					gotoxy(x + 70, y + 29);
					SetColor(12, 0);
					std::cout << "예";
					gotoxy(x + 72, y + 29);
					SetColor(15, 0);
					std::cout << " / 아니오";
					choice = 2;
					break;
				}
			}
			else if (input == Enter)
			{
				if (choice == 1)
				{
					iiw.ClearText(16, 14);
					ClearRightSection(66, 9);
					ChocieSell();
					break;
				}
				else if (choice == 2)
				{
					item->MinusCount();
					player.SetMoney(item->GetPrice());
					iiw.ClearSection(16, 14);
					if (item->GetCount() > 0)
					{
						ClearRightSection(66, 9);
						PrintInventory(x, y, count);
					}
					else
					{
						ClearRightSection(66, 9);
						inven->FindInventory(item);
						iiw.ClearSection2(16, 14);
						ChocieSell();
					}
					if (inven->GetInventory().empty())
					{
						ClearRightSection(66, 9);
						inven->GetInventory().clear();
						ClearOption(15, 5);
						storeM.PrintBuyAndSellText(15, 5, 2);
						storeM.LeftRightInput();
					}
					break;
				}
			}
			else
			{
				SetColor(15, 0);
				gotoxy(x + 70, y + 29);
				std::cout << "               ";
				gotoxy(x + 70, y + 29);
				std::cout << "예 / 아니오";
			}
		}
	}
}
#pragma endregion

#pragma region 텍스트 세팅
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
#pragma endregion

#pragma region 아이템 선택
void ItemSell::ChocieSell()
{
	StoreMap storeM;
	isEnter = false;
	ItemInventoryWindow iiw;
	PrintInventory(16, 14, 0);
	iiw.PrintMoneyText(89, 5);
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
					isEnter = true;
					PrintInventory(16, 14, count);
					break;
				}
				else if (input == ESC)
				{
					count = 0;
					storeM.ClearText(16, 14);
					ClearRightSection(58, 14);
					storeM.PrintBuyAndSellText(15, 5, storeM.GetBuySellNum());
					storeM.LeftRightInput();
					break;
				}
			}
		}
	}
}
#pragma endregion

#pragma region 부분 삭제(더블 버퍼링)
void ItemSell::ClearOption(int x, int y)
{
	gotoxy(x, y);
	std::cout << "                                                                ";
}
void ItemSell::ClearRightSection(int x, int y)
{
	for (int i = 0; i < 37; i++)
	{
		gotoxy(x, y + i);
		std::cout << "                                                    ";
	}
}
#pragma endregion

ItemSell::ItemSell()
{
	inven = new ItemInventory;
	count = 0;
	isEnter = false;
}

ItemSell::~ItemSell()
{
	delete inven;
}

