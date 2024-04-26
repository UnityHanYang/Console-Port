#include "StoreMap.h"

int StoreMap::buySellNum = 0;
#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter 13
#define ESC 27

#pragma region 상속 메서드
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
#pragma endregion

#pragma region 테두리
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
#pragma endregion

#pragma region 아이템 자세히 보기
void StoreMap::PrintMoneyText(int x, int y)
{
	gotoxy(x, y);
	std::cout << "                      ";
	gotoxy(x, y);
	std::cout << "소지금: " << player.GetMoney();
}

void StoreMap::ShowItem(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x, y - 4);
	std::cout << "-포션-";
	gotoxy(x, y - 2);
	std::cout << "     이름                           가격";

	store->PrintName(x, y, num);

	store->PrintPrice(x + 37, y, num);

}
#pragma endregion

#pragma region 부분 제거(더블 버퍼링)
void StoreMap::ClearText(int x, int y)
{
	SetColor(0, 0);
	for (int i = 0; i < 35; i++)
	{
		gotoxy(x - 2, y - 4 + i);
		std::cout << "                                                ";

	}

	gotoxy(x + 53, y - 3);
	std::cout << "                                       ";

}
#pragma endregion

#pragma region 아이템 구매
bool StoreMap::CheckBuy()
{
	if (player.GetMoney() >= store->GetCurrentItemPrice())
		return true;

	return false;
}

void StoreMap::ChoiceBuy()
{
	ShowItem(16, 14, 0);
	ItemSell itemS;
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
					itemS.ClearRightSection(66, 9, 37);
					ShowItem(16, 14, count);
					break;
				case UP_ARROW:
					count = (count < 2) ? count : count -= 1;
					itemS.ClearRightSection(66, 9, 37);
					ShowItem(16, 14, count);
					break;
				}
			}
			else if (input == Enter)
			{
				if (CheckBuy())
				{
					if (std::find(iit->GetInventory().begin(), iit->GetInventory().end(), store->GetCurrentItem()) == iit->GetInventory().end())
					{
						if (store->GetCurrentItem()->GetCount() == 0)
						{
							store->GetCurrentItem()->SetCount();
						}
						iit->AddInventory(store->GetCurrentItem());
					}
					else
					{
						int index = std::find(iit->GetInventory().begin(), iit->GetInventory().end(), store->GetCurrentItem()) - iit->GetInventory().begin();
						iit->AddItemCountInventory(store->GetCurrentItem(), index);
					}
					player.SetMoney(-store->GetCurrentItemPrice());

					PrintMoneyText(89, 5);
				}
			}
			else if (input == ESC)
			{
				count = 0;
				itemS.ClearRightSection(66, 9, 37);
				itemS.ClearRightSection(11, 13, 30);
				ClearText(16, 14);
				LeftRightInput();
				break;
			}
		}
	}
}
#pragma endregion

#pragma region 옵션 선택
void StoreMap::LeftRightInput()
{
	int input;
	ItemSell itemS;
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
					buySellNum = (buySellNum > 2) ? buySellNum : buySellNum += 1;
					itemS.ClearRightSection(11, 10, 30);
					PrintBuyAndSellText(15, 5, buySellNum);
					break;
				case LEFT_ARROW:
					buySellNum = (buySellNum < 2) ? buySellNum : buySellNum -= 1;
					itemS.ClearRightSection(11, 10, 30);
					PrintBuyAndSellText(15, 5, buySellNum);
					break;
				}
			}
			else if (input == Enter)
			{
				switch (buySellNum)
				{
				case 1:
					ClearText(16, 14);
					ChoiceBuy();
					break;
				case 2:
					ClearText(16, 14);
					itemS.ChocieSell();
					break;
				case 3:
					system("cls");
					Village vg;
					vg.PrintMapAndCharMove(vg.GetCurrentX(), vg.GetCurrentY());
					break;
				}
			}
		}
	}
}

void StoreMap::PrintBuyAndSellText(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x, y);
	switch (num)
	{
	case 1:
		std::cout << "                                                                ";
		gotoxy(x, y);
		std::cout << "     ▶ 구입 ◀                  판매                    취소";
		break;
	case 2:
		std::cout << "                                                                ";
		gotoxy(x, y);
		std::cout << "       구입                  ▶ 판매 ◀                  취소";
		break;
	case 3:
		std::cout << "                                                                ";
		gotoxy(x, y);
		std::cout << "       구입                    판매                  ▶ 취소 ◀";
		break;
	default:
		std::cout << "                                                                ";
		gotoxy(x, y);
		std::cout << "       구입                    판매                    취소";
		break;
	}
}
#pragma endregion

#pragma region 화면 출력
void StoreMap::PrintStoreMap()
{
	//Store store;
	store->VectorPush();
	PrintBuyAndSellTool(10, 3);
	PrintMoneyTool(86, 3);
	PrintItemTool(10, 8);
	PrintItemDetailTool(65, 8);
	PrintMoneyText(89, 5);
	PrintBuyAndSellText(15, 5, buySellNum);

	LeftRightInput();
}
#pragma endregion


StoreMap::StoreMap()
{
	iit = new ItemInventory;
	store = new Store;
	count = 0;
}

StoreMap::~StoreMap()
{
	delete iit;
	delete store;
}

