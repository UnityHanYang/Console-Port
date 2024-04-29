#include "BattleInventory.h"

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13
#define ESC 27

void BattleInventory::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void BattleInventory::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void BattleInventory::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void BattleInventory::ItemChoice()
{
	ClearOption(196, 60);
	Battle bt;
	ShowItem(195, 60, 0);

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
					case UP_ARROW:
						count = (count < 2) ? count : count -= 1;
						ClearOption(196, 60);
						ShowItem(195, 60, count);
						break;
					case DOWN_ARROW:
						count = (count > iit->GetInventory().size() - 1) ? count : count += 1;
						ClearOption(196, 60);
						ShowItem(195, 60, count);
						break;
					}
				}
				else if (input == Enter)
				{
					isEnter = true;
					ShowItem(195, 60, count);
					break;
				}
				else if (input == ESC)
				{
					count = 0;
					bt.DownUpInput();
					break;
				}
			}
		}
	}
}

void BattleInventory::ShowItem(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x+2, y);
	std::cout << "-포션-";
	gotoxy(x, y + 2);
	std::cout << "       이름                                    수량  ";


	SettingInfo(x, y+ 4, num);

}

void BattleInventory::SettingInfo(int x, int y, int num)
{
	int this_count = 0;
	CharacterInfo ci;
	GameManager* gm = GameManager::GetInstance();
	int index = 1;
	if (!iit->GetInventory().empty())
	{
		SetColor(15, 0);
		std::vector<Item*>::iterator iter;
		for (iter = iit->GetInventory().begin(); iter != iit->GetInventory().end(); ++iter)
		{
			gotoxy(x, y + this_count);
			if (index == num)
			{
				std::cout << "                                                     " << std::endl;
				gotoxy(x + 4, y + this_count);
				std::cout << "▶ " << (*iter)->GetName() << "                            "
					<< (*iter)->GetCount() << " ◀" << std::endl;

				if (isEnter)
				{
					if (ci.GetJoinWhether())
					{

					}
					else
					{
						if (gm->GetCharacter() == 1)
						{
							HpMpHeal(*gm->nj, *iter, 195, 60);
						}
						else if (gm->GetCharacter() == 2)
						{
							HpMpHeal(*gm->ah, *iter, 195, 60);
						}
					}
				}
			}
			else
			{
				std::cout << "                                                     " << std::endl;
				gotoxy(x+4, y + this_count);
				std::cout << (*iter)->GetName() << "                              " 
					<< (*iter)->GetCount() << std::endl;
			}
			index++;
			this_count += 2;
		}
	}
}

void BattleInventory::ChoiceHealChar(int x, int y, Item* item)
{
	GameManager* gm = GameManager::GetInstance();
	CharacterChoice cc;
	CharacterInfo ci;
	int characterNum = 0;
	SetColor(15, 0);
	gotoxy(x + 65, y + 27);
	std::cout << "                     ";
	gotoxy(x + 65, y + 27);

	if (ci.GetJoinWhether())
	{
		if (gm->GetCharacter() == 1)
		{
			std::cout << "▶ " << gm->nj->GetName() << ":  ";
			if (item->GetItemType() == ItemType::hpPotion)
			{
				std::cout << gm->nj->GetCurrentHp() << " / " << gm->nj->GetMaxHp();
			}
			else if (item->GetItemType() == ItemType::mpPotion)
			{
				std::cout << gm->nj->GetCurrentMp() << " / " << gm->nj->GetMaxMp();
			}
			characterNum = 1;
		}
		else if (gm->GetCharacter() == 2)
		{
			std::cout << "▶ " << gm->ah->GetName() << ":  ";
			if (item->GetItemType() == ItemType::hpPotion)
			{
				std::cout << gm->ah->GetCurrentHp() << " / " << gm->ah->GetMaxHp();
			}
			else if (item->GetItemType() == ItemType::mpPotion)
			{
				std::cout << gm->ah->GetCurrentMp() << " / " << gm->ah->GetMaxMp();
			}
			characterNum = 2;
		}
	}
	else
	{
		if (gm->GetCharacter() == 1)
		{
			characterNum = 1;
		}
		else if (gm->GetCharacter() == 2)
		{
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
					HpMpHeal(*gm->nj, item, x, y);
					break;
				}
				else if (characterNum == 2)
				{
					HpMpHeal(*gm->ah, item, x, y);
					break;
				}
			}
		}
	}
}

void BattleInventory::HpMpHeal(Character& character, Item* item, int x, int y)
{
	Battle bt;
	isEnter = false;
	if (item->GetItemType() == ItemType::hpPotion)
	{
		if (character.GetCurrentHp() < character.GetMaxHp())
		{
			(character.GetCurrentHp() + item->GetHeal() <= character.GetMaxHp()) ? character.SetCurrentHp(item->GetHeal()) : character.SetCurrentHp(character.GetMaxHp() -character.GetCurrentHp());
			item->MinusCount();
			ClearOption(196, 60);
			if (item->GetCount() > 0)
			{
				CharacterHpMpBar(&character);
			}
			else
			{
				iit->FindInventory(item);
				CharacterHpMpBar(&character);
				ClearOption(196, 60);
			}
			bt.EnemyTurn();
		}
		else
		{
			ClearOption(196, 60);
			ItemChoice();
		}
	}
	else if (item->GetItemType() == ItemType::mpPotion)
	{
		if (character.GetCurrentMp() < character.GetMaxMp())
		{
			(character.GetCurrentMp() + item->GetHeal() <= character.GetMaxMp()) ? character.SetCurrentMp(item->GetHeal()) : character.SetCurrentMp(character.GetMaxMp() - character.GetCurrentMp());
			item->MinusCount();
			ClearOption(196, 60);
			if (item->GetCount() > 0)
			{
				CharacterHpMpBar(&character);
			}
			else
			{
				ItemInventory iit;
				iit.FindInventory(item);
			}
			bt.EnemyTurn();
		}
		else
		{
			ClearOption(196, 60);
			ItemChoice();
		}
	}
	if (iit->GetInventory().empty())
	{
		Battle bt;
		bt.DownUpInput();
	}
}

void BattleInventory::ClearOption(int x, int y)
{
	SetColor(0, 0);
	gotoxy(x, y);
	std::cout << "                                                            ";
	gotoxy(x, y+1);
	std::cout << "                                                            ";
	gotoxy(x, y + 2);
	std::cout << "                                                            ";
	gotoxy(x, y + 3);
	std::cout << "                                                            ";
	gotoxy(x, y + 4);
	std::cout << "                                                            ";
	gotoxy(x, y + 5);
	std::cout << "                                                            ";
	gotoxy(x, y + 6);
	std::cout << "                                                            ";
	gotoxy(x, y + 7);
	std::cout << "                                                            ";
	gotoxy(x, y + 8);
	std::cout << "                                                            ";
	gotoxy(x, y + 9);
	std::cout << "                                                            ";
	gotoxy(x, y + 10);
	std::cout << "                                                            ";
}

void BattleInventory::CharacterHpMpBar(Character* ch)
{
	int hpBar = (ch->GetCurrentHp() * 20) / ch->GetMaxHp();
	int mpBar = (ch->GetCurrentMp() * 20) / ch->GetMaxMp();
	if (hpBar <= 0)
	{
		if (ch->GetCurrentHp() > 0)
		{
			bmd.PrintHeroHp(ch, 102, 88, 1, mpBar);
		}
	}
	else
	{
		bmd.PrintHeroHp(ch, 102, 88, hpBar, mpBar);
	}
}

BattleInventory::BattleInventory()
{
	iit = new ItemInventory;
	count = 0;
	isEnter = false;
}

BattleInventory::~BattleInventory()
{
	delete iit;
}
