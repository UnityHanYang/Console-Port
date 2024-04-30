#include "BattleSkill.h"

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13
#define ESC 27

void BattleSkill::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void BattleSkill::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void BattleSkill::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void BattleSkill::NinJaSkillChoice()
{
	ClearOption(196, 60);
	Battle bt;
	ShowSkill(195, 60, 0);

	int input;
	SkillManager sm;
	if (!sm.GetNinjaSkills().empty())
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
						ShowSkill(195, 60, count);
						break;
					case DOWN_ARROW:
						count = (count > sm.GetNinjaSkills().size() - 1) ? count : count += 1;
						ClearOption(196, 60);
						ShowSkill(195, 60, count);
						break;
					}
				}
				else if (input == Enter)
				{
					isEnter = true;
					ShowSkill(195, 60, count);
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

void BattleSkill::ArcherSkillChoice()
{
	ClearOption(196, 60);
	Battle bt;
	ShowSkill(195, 60, 0);

	SkillManager sm;
	int input;
	if (!sm.GetArcherSkills().empty())
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
						ShowSkill(195, 60, count);
						break;
					case DOWN_ARROW:
						count = (count > sm.GetArcherSkills().size() - 1) ? count : count += 1;
						ClearOption(196, 60);
						ShowSkill(195, 60, count);
						break;
					}
				}
				else if (input == Enter)
				{
					isEnter = true;
					ShowSkill(195, 60, count);
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

void BattleSkill::ShowSkill(int x, int y, int num)
{
	GameManager* gm = GameManager::GetInstance();
	SetColor(15, 0);
	gotoxy(x + 2, y);
	std::cout << "-스킬-";
	gotoxy(x, y + 2);
	std::cout << "       이름                 데미지          마나 소모량  ";

	if (gm->GetCharacterCount().size() < 2)
	{
		if (gm->GetCharacter() == 1)
		{
			NinjaSkillInfo(x, y + 4, num);
		}
		else if (gm->GetCharacter() == 2)
		{
			ArcherkillInfo(x, y + 4, num);
		}
	}

}

void BattleSkill::NinjaSkillInfo(int x, int y, int num)
{
	int this_count = 0;
	CharacterInfo ci;

	SkillManager sm;
	GameManager* gm = GameManager::GetInstance();
	int index = 1;
	if (!sm.GetNinjaSkills().empty())
	{
		SetColor(15, 0);
		std::vector<Skill*>::iterator iter;
		for (iter = sm.GetNinjaSkills().begin(); iter != sm.GetNinjaSkills().end(); ++iter)
		{
			gotoxy(x, y + this_count);
			if (index == num)
			{
				std::cout << "                                                       " << std::endl;
				gotoxy(x + 4, y + this_count);
				std::cout << "▶ " << (*iter)->GetName() << "                 "
					<< (*iter)->GetDamage() << "                " << (*iter)->GetCost() << " ◀" << std::endl;

				if (isEnter)
				{
					//HpMpHeal(*gm->nj, *iter, 195, 60);
				}
			}
			else
			{
				std::cout << "                                                       " << std::endl;
				gotoxy(x + 4, y + this_count);
				std::cout  << (*iter)->GetName() << "                  "
					<< (*iter)->GetDamage() << "                 " << (*iter)->GetCost()  << std::endl;

			}
			index++;
			this_count += 2;
		}
	}
}

void BattleSkill::ArcherkillInfo(int x, int y, int num)
{
	int this_count = 0;
	CharacterInfo ci;

	SkillManager sm;
	GameManager* gm = GameManager::GetInstance();
	int index = 1;
	if (!sm.GetArcherSkills().empty())
	{
		SetColor(15, 0);
		std::vector<Skill*>::iterator iter;
		for (iter = sm.GetArcherSkills().begin(); iter != sm.GetArcherSkills().end(); ++iter)
		{
			gotoxy(x, y + this_count);
			if (index == num)
			{
				std::cout << "                                                       " << std::endl;
				gotoxy(x + 4, y + this_count);
				std::cout << "▶ " << (*iter)->GetName() << "                 "
					<< (*iter)->GetDamage() << "                " << (*iter)->GetCost() << " ◀" << std::endl;

				if (isEnter)
				{
					//HpMpHeal(*gm->nj, *iter, 195, 60);
				}
			}
			else
			{
				std::cout << "                                                       " << std::endl;
				gotoxy(x + 4, y + this_count);
				std::cout << (*iter)->GetName() << "                  "
					<< (*iter)->GetDamage() << "                 " << (*iter)->GetCost() << std::endl;

			}
			index++;
			this_count += 2;
		}
	}
}

void BattleSkill::ClearOption(int x, int y)
{
	SetColor(0, 0);
	gotoxy(x, y);
	std::cout << "                                                            ";
	gotoxy(x, y + 1);
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


BattleSkill::BattleSkill()
{
	//sm = new SkillManager;
	count = 0;
	isEnter = false;
}

BattleSkill::~BattleSkill()
{
	//delete sm;
}
