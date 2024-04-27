#include "Battle.h"

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13

#pragma region 상속 메서드

void Battle::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void Battle::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void Battle::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#pragma endregion


void Battle::PrintBattleMap()
{
	GameManager gm;
	gm.RandomEnemyUnit(1);
	if (gm.GetCharacterCount().size() < 2)
	{
		bmd.PrintSoloBattleMap();
	}
	else
	{
		//bmd.PrintMultiBattleMap();
	}
	SetColor(15, 0);
	gotoxy(215, 72);
	std::cout << "공격";
	gotoxy(215, 74);
	std::cout << "방어";
	bmd.PrintEnemyInfoTool();
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
				case LEFT_ARROW:
					break;
				case RIGHT_ARROW:
					break;
				}
			}
		}

	}
}

void Battle::PrintEnemyInfoText(Character* character)
{
	SetColor(15, 0);
	gotoxy(244, 17);
	std::cout << "적 정보";
	gotoxy(244, 19);
	std::cout << "최대 Hp: " << character->GetMaxHp();
	gotoxy(244, 21);
	std::cout << "최대 Mp: " << character->GetMaxMp();
	gotoxy(244, 23);
	std::cout << "공격력: " << character->GetAtk();
	gotoxy(244, 25);
	std::cout << "방어력: " << character->GetDef();
	gotoxy(244, 27);
	std::cout << "치명타 확률: " << character->GetCritical();
}