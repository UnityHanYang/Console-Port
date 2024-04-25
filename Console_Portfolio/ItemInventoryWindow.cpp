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
	std::cout << "소지금: " << player.GetMoney();
}

void ItemInventoryWindow::ShowItem(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x, y - 4);
	std::cout << "-포션-";
	gotoxy(x, y - 2);
	std::cout << "     이름                          ";


	SettingInfo(x, y, num);

}


void ItemInventoryWindow::UseItemYesOrNo(int x, int y, Item* item)
{
	SetColor(15, 0);
	gotoxy(x + 58, y + 27);
	std::cout << "                                   ";
	gotoxy(x + 58, y + 27);
	std::cout << item->GetName() << "을 사용하시겠습니까? ";
	gotoxy(x + 70, y + 29);
	std::cout << "               ";
	gotoxy(x + 70, y + 29);
	std::cout << "예 / 아니오";
	int choiceNum = 0;
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
					choiceNum = 1;
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
					choiceNum = 2;
					break;
				}
			}
			else if (input == Enter)
			{
				if (choiceNum == 1)
				{
					ClearText(x, y);
					ChoiceUse();
					break;
				}
				else if (choiceNum == 2)
				{
					ClearSection(x, y);
					ChoiceHealChar(x, y, item);
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

void ItemInventoryWindow::ChoiceHealChar(int x, int y, Item* item)
{
	GameManager gm;
	CharacterChoice cc;
	CharacterInfo ci;
	int characterNum = 0;
	SetColor(15, 0);
	gotoxy(x + 65, y + 27);
	std::cout << "                     ";
	gotoxy(x + 65, y + 27);

	if (ci.GetJoinWhether())
	{

	}
	else
	{
		if (cc.GetCharacter() == 1)
		{
			std::cout << "▶ " << gm.nj->GetName() << ":  ";
			if (item->GetItemType() == ItemType::hpPotion)
			{
				std::cout << gm.nj->GetCurrentHp() << " / " << gm.nj->GetMaxHp();
			}
			else if (item->GetItemType() == ItemType::mpPotion)
			{
				std::cout << gm.nj->GetCurrentMp() << " / " << gm.nj->GetMaxMp();
			}
			characterNum = 1;
		}
		else if (cc.GetCharacter() == 2)
		{
			std::cout << "▶ " << gm.ah->GetName() << ":  ";
			if (item->GetItemType() == ItemType::hpPotion)
			{
				std::cout << gm.ah->GetCurrentHp() << " / " << gm.ah->GetMaxHp();
			}
			else if (item->GetItemType() == ItemType::mpPotion)
			{
				std::cout << gm.ah->GetCurrentMp() << " / " << gm.ah->GetMaxMp();
			}
			characterNum = 2;
		}
	}
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
					break;
				case UP_ARROW:
					break;
				}
			}
			else if (input == Enter)
			{
				if (characterNum == 1)
				{
					HpMpHeal(*gm.nj, item, x, y);
					break;
				}
				else if (characterNum == 2)
				{

				}
			}
		}
	}
}
void ItemInventoryWindow::HpMpHeal(Character& character, Item* item, int x, int y)
{
	if (item->GetItemType() == ItemType::hpPotion)
	{
		if (character.GetCurrentHp() < character.GetMaxHp())
		{
			(character.GetCurrentHp() + item->GetHeal() <= character.GetMaxHp()) ? character.SetCurrentHp(item->GetHeal()) : character.SetCurrentHp((character.GetCurrentHp() + item->GetHeal()) - character.GetMaxHp());
			item->MinusCount();
			gotoxy(x + 65, y + 27);
			std::cout << "                         ";
			gotoxy(x + 65, y + 27);
			std::cout << character.GetName() << ":  " << character.GetCurrentHp() << " / " << character.GetMaxHp();;
			Sleep(1500);
			ClearSection(x, y);
			if (item->GetCount() > 0)
			{
				SettingInfo(x, y, count);
			}
			else
			{
				ItemInventory iit;
				iit.FindInventory(item);
				ClearSection2(16, 14);
				ChoiceUse();
			}
		}
		else
		{
			ClearSection2(16, 14);
			ClearSection(x, y);
			ChoiceUse();
		}
	}
	else if (item->GetItemType() == ItemType::mpPotion)
	{
		if (character.GetCurrentMp() < character.GetMaxMp())
		{
			(character.GetCurrentMp() + item->GetHeal() <= character.GetMaxMp()) ? character.SetCurrentMp(item->GetHeal()) : character.SetCurrentMp((character.GetCurrentMp() + item->GetHeal()) - character.GetMaxMp());
			item->MinusCount();
			gotoxy(x + 65, y + 27);
			std::cout << "                         ";
			gotoxy(x + 65, y + 27);
			std::cout << character.GetName() << ":  " << character.GetCurrentMp() << " / " << character.GetMaxMp();
			Sleep(1500);
			ClearSection(x, y);
			if (item->GetCount() > 0)
			{
				SettingInfo(x, y, count);
			}
			else
			{
				ItemInventory iit;
				iit.FindInventory(item);
				ClearSection2(16, 14);
				ChoiceUse();
			}
		}
		else
		{
			ClearSection2(16, 14);
			ClearSection(x, y);
			ChoiceUse();
		}
	}
	if (iit->GetInventory().empty())
	{
		LeftRightInput();
	}
}


void ItemInventoryWindow::ClearSection2(int x, int y)
{
	SetColor(0, 0);
	for (int i = 0; i < 16; i++)
	{
		gotoxy(x, y + i);
		std::cout << "                                          ";
	}
}


void ItemInventoryWindow::ClearSection(int x, int y)
{
	gotoxy(x + 53, y - 3);
	std::cout << "                                       ";
	gotoxy(x + 53, y - 1);
	std::cout << "                                       ";
	gotoxy(x + 58, y + 27);
	std::cout << "                                       ";
	gotoxy(x + 70, y + 29);
	std::cout << "               ";
}

void ItemInventoryWindow::SettingInfo(int x, int y, int num)
{
	int this_count = 0;
	int index = 1;
	if (!iit->GetInventory().empty())
	{
		SetColor(15, 0);
		for (std::vector<Item*>::iterator iter = iit->GetInventory().begin(); iter != iit->GetInventory().end(); ++iter)
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

				if (isEnter)
				{
					UseItemYesOrNo(x, y, *iter);
					isEnter = false;
				}
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


void ItemInventoryWindow::ChoiceUse()
{
	ShowItem(16, 14, 0);
	isEnter = false;

	int input;
	if (!iit->GetInventory().empty())
	{

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
						count = (count > iit->GetInventory().size() - 1) ? count : count += 1;
						ShowItem(16, 14, count);
						break;
					case UP_ARROW:
						count = (count < 2) ? count : count -= 1;
						ShowItem(16, 14, count);
						break;
					}
				}
				else if (input == Enter)
				{
					isEnter = true;
					ShowItem(16, 14, count);
					break;
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
	gotoxy(x + 53, y - 1);
	std::cout << "                                       ";
	gotoxy(x + 58, y + 27);
	std::cout << "                                       ";
	gotoxy(x + 70, y + 29);
	std::cout << "               ";
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
					MapManager mm;
					mm.Current_StackMap();
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
	PrintMoneyText(89, 5);
	PrintOptionText(30, 5, option);

	LeftRightInput();
}

ItemInventoryWindow::ItemInventoryWindow()
{
	iit = new ItemInventory;
	count = 0;
	isEnter = false;
	option = 0;
}

ItemInventoryWindow::~ItemInventoryWindow()
{
	delete iit;
}
