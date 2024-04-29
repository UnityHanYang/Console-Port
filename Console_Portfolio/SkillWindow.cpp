#include "SkillWindow.h"

#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter 13
#define ESC 27

void SkillWindow::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void SkillWindow::PrintS(int count, int font, int background, bool isEndl, int x, int y)
{
	SetColor(font, background);

	for (int i = 0; i < count; i++)
	{
		std::cout << "ㅁ";
	}

	if (isEndl)
	{
		std::cout << std::endl;
	}
}

void SkillWindow::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SkillWindow::SkillTool()
{
	ItemInventoryWindow iiw;
	iiw.PrintItemAndCancelTool(10, 3);
	iiw.PrintMoneyTool(86, 3);
	iiw.PrintItemTool(10, 8);
	iiw.PrintItemDetailTool(65, 8);
	PrintOptionText(30, 5, option);

	ControlLeftRight();
}

void SkillWindow::ShowSkill(int x, int y, int num)
{
	GameManager* gm = GameManager::GetInstance();
	SetColor(15, 0);
	gotoxy(x, y - 4);
	std::cout << "-스킬-";
	gotoxy(x, y - 2);
	std::cout << "     이름                          ";

	if (gm->GetCharacter() == 1)
	{
		NinjaSettingInfo(x, y, num);
	}
	else if(gm->GetCharacter() == 2)
	{
		ArcherSettingInfo(x, y, num);
	}

}

void SkillWindow::NinjaSettingInfo(int x, int y, int num)
{
	int this_count = 0;
	int index = 1;
	if (!sm->GetNinjaSkills().empty())
	{
		SetColor(15, 0);
		std::vector<Skill*>::iterator iter;
		for (iter = sm->GetNinjaSkills().begin(); iter != sm->GetNinjaSkills().end(); ++iter)
		{
			gotoxy(x, y + this_count);
			if (index == num)
			{
				std::cout << "                        " << std::endl;
				gotoxy(x, y + this_count);
				std::cout << "▶ " << (*iter)->GetName() << std::endl;

				gotoxy(x + 54, y - 1);
				std::cout << "                             ";
				gotoxy(x + 54, y - 1);
				std::cout << (*iter)->GetFeature() << std::endl;
				gotoxy(x + 54, y +2);
				std::cout << "                             ";
				gotoxy(x + 54, y + 2);
				std::cout << "데미지: " << (*iter)->GetDamage() << std::endl;
				gotoxy(x + 54, y + 4);
				std::cout << "                             ";
				gotoxy(x + 54, y + 4);
				std::cout << "마나 코스트: " << (*iter)->GetCost() << std::endl;

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

void SkillWindow::ArcherSettingInfo(int x, int y, int num)
{
	int this_count = 0;
	int index = 1;
	if (!sm->GetArcherSkills().empty())
	{
		SetColor(15, 0);
		std::vector<Skill*>::iterator iter;
		for (iter = sm->GetArcherSkills().begin(); iter != sm->GetArcherSkills().end(); ++iter)
		{
			gotoxy(x, y + this_count);
			if (index == num)
			{
				std::cout << "                        " << std::endl;
				gotoxy(x, y + this_count);
				std::cout << "▶ " << (*iter)->GetName() << std::endl;

				gotoxy(x + 54, y - 1);
				std::cout << "                             ";
				gotoxy(x + 54, y - 1);
				std::cout << (*iter)->GetFeature() << std::endl;
				gotoxy(x + 54, y + 2);
				std::cout << "                             ";
				gotoxy(x + 54, y + 2);
				std::cout << "데미지: " << (*iter)->GetDamage() << std::endl;
				gotoxy(x + 54, y + 4);
				std::cout << "                             ";
				gotoxy(x + 54, y + 4);
				std::cout << "마나 코스트: " << (*iter)->GetCost() << std::endl;

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

void SkillWindow::NinjaSkill()
{
	ItemSell itemS;
	ShowSkill(16, 14, 0);

	int input;
	if (!sm->GetNinjaSkills().empty())
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
						count = (count > sm->GetNinjaSkills().size() - 1) ? count : count += 1;
						ShowSkill(16, 14, count);
						break;
					case UP_ARROW:
						count = (count < 2) ? count : count -= 1;
						ShowSkill(16, 14, count);
						break;
					}
				}
				else if (input == Enter)
				{
					ShowSkill(16, 14, count);
					break;
				}
				else if (input == ESC)
				{
					itemS.ClearRightSection(66, 9, 37);
					itemS.ClearRightSection(11, 13, 30);
					ControlLeftRight();
					break;
				}
			}
		}
	}
}

void SkillWindow::ArcherSkill()
{
	ItemSell itemS;
	ShowSkill(16, 14, 0);

	int input;
	if (!sm->GetArcherSkills().empty())
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
						count = (count > sm->GetArcherSkills().size() - 1) ? count : count += 1;
						ShowSkill(16, 14, count);
						break;
					case UP_ARROW:
						count = (count < 2) ? count : count -= 1;
						ShowSkill(16, 14, count);
						break;
					}
				}
				else if (input == Enter)
				{
					ShowSkill(16, 14, count);
					break;
				}
				else if (input == ESC)
				{
					itemS.ClearRightSection(66, 9, 37);
					itemS.ClearRightSection(11, 13, 30);
					ControlLeftRight();
					break;
				}
			}
		}
	}
}

void SkillWindow::PrintOptionText(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x, y);
	switch (num)
	{
	case 1:
		std::cout << "                                            ";
		gotoxy(x, y);
		std::cout << " ▶ 스킬 ◀                        취소";
		break;
	case 2:
		std::cout << "                                            ";
		gotoxy(x, y);
		std::cout << "   스킬                        ▶ 취소 ◀";
		break;
	default:
		std::cout << "                                            ";
		gotoxy(x, y);
		std::cout << "스킬                          취소 ";
		break;
	}
}

void SkillWindow::ControlLeftRight()
{
	ItemSell itemS;
	GameManager* gm = GameManager::GetInstance();
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
					itemS.ClearRightSection(11, 10, 30);
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

					if (gm->GetCharacter() == 1)
					{
						NinjaSkill();
					}
					else
					{
						ArcherSkill();
					}
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

SkillWindow::SkillWindow()
{
	option = 0;
	count = 0;
	sm = new SkillManager;
}

SkillWindow::~SkillWindow()
{
	delete sm;
}
