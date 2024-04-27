#include "Battle.h"

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13

#pragma region ��� �޼���

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
		std::cout << "��";
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
	std::cout << "����";
	gotoxy(215, 74);
	std::cout << "���";
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
	std::cout << "�� ����";
	gotoxy(244, 19);
	std::cout << "�ִ� Hp: " << character->GetMaxHp();
	gotoxy(244, 21);
	std::cout << "�ִ� Mp: " << character->GetMaxMp();
	gotoxy(244, 23);
	std::cout << "���ݷ�: " << character->GetAtk();
	gotoxy(244, 25);
	std::cout << "����: " << character->GetDef();
	gotoxy(244, 27);
	std::cout << "ġ��Ÿ Ȯ��: " << character->GetCritical();
}