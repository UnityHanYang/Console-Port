#include "CharacterInfo.h"

bool CharacterInfo::isJoin = false;

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter_Key 13
#define ESC 27
int charChoiceNum = 0;


void CharacterInfo::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void CharacterInfo::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void CharacterInfo::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CharacterInfo::CharacterOne()
{
	SetColor(15, 0);
	CharacterChoice cc;
	if (cc.GetCharacter() == 1)
	{
		std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
		std::cout << "\n\n\t\t\t �� ����(���ΰ�) ��\n\n";
		cc.PrintBackGround(11, 11, 4, 12);
		nd.PrintNinZaPortrait1(20, 13);
		SetColor(15, 0);
		charChoiceNum = 1;
	}
	else if (cc.GetCharacter() == 2)
	{
		std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
		std::cout << "\n\n\t\t\t �� ����(���ΰ�) ��\n\n";
		cc.PrintBackGround(11, 11, 4, 12);
		ad.PrintArcherPortrait1(24, 13);
		SetColor(15, 0);
		charChoiceNum = 2;
	}
}

void CharacterInfo::CharacterTwo()
{
}

void CharacterInfo::ChoiceCharacter()
{
	MapManager mm;
	CharacterChoice cc;
	if (GetJoinWhether())
	{
		CharacterTwo();
	}
	else
	{
		CharacterOne();
	}
	SetColor(15, 0);
	md.PrintOperation_Keys(130, 3);
	PrintOperate(132, 5);
	std::cout << "\n\n\n";
	int input;
	while (true)
	{
		if (_kbhit())
		{
			input = _getch();
			if (input == ARROW)
			{
				if (!GetJoinWhether())
					continue;
				system("cls");
				input = _getch();
				switch (input)
				{
				case LEFT_ARROW:
					std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
					std::cout << "\n\n\t\t\t �� ���� ��\t\t\t\t\t\t\t\t����\n\n";
					cc.PrintBackGround(11, 11, 4, 12);
					cc.PrintBackGround(2, 2, 72, 12);
					nd.PrintNinZaPortrait1(20, 13);
					ad.PrintArcherPortrait1(92, 13);
					charChoiceNum = 1;
					break;
				case RIGHT_ARROW:
					std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
					std::cout << "\n\n\t\t\t   ����\t\t\t\t\t\t\t\t    �� ���� ��\n\n";
					cc.PrintBackGround(2, 2, 4, 12);
					cc.PrintBackGround(11, 11, 72, 12);
					nd.PrintNinZaPortrait1(20, 13);
					ad.PrintArcherPortrait1(92, 13);
					SetColor(15, 0);
					charChoiceNum = 2;
					break;
				default:
					std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
					std::cout << "\n\n\t\t\t   ����\t\t\t\t\t\t\t\t\t����\n\n";
					cc.PrintBackGround(2, 2, 4, 12);
					cc.PrintBackGround(2, 2, 72, 12);
					nd.PrintNinZaPortrait1(20, 13);
					ad.PrintArcherPortrait1(92, 13);
					SetColor(15, 0);
				}
				SetColor(15, 0);
				md.PrintOperation_Keys(130, 3);
				PrintOperate(132, 5);
			}
			else if (input == Enter_Key)
			{
				system("cls");
				if (charChoiceNum == 1 || charChoiceNum == 2)
				{
					mm.SetStack(6);
					ReadMore(charChoiceNum);
				}
				else
				{
					CharacterTwo();
				}
			}
			else if (input == ESC)
			{
				system("cls");
				mm.Current_StackMap();
				break;
			}
		}
	}
}


void CharacterInfo::PrintCharacterAbility(int num)
{
	CharacterChoice cc;
	MapManager mm;
	if (num == 1)
	{
		nd.PrintNinZa1();
		cc.PrintNinjarBackGround();
		SetColor(0, 15);
		cc.PrintAbilityTool(135, 50);
		gotoxy(139, 52);
		std::cout << " �̸�: " << gm.nj->GetName();
		std::cout << "                ����: " << gm.nj->GetOccupation();
		gotoxy(139, 55);
		std::cout << " ���ݷ�: " << gm.nj->GetAtk();
		std::cout << "                ����: " << gm.nj->GetMaxMp();
		gotoxy(139, 58);
		std::cout << " ü��: " << gm.nj->GetMaxHp();
		std::cout << "                   ����: " << gm.nj->GetDef();
		gotoxy(139, 61);
		std::cout << " ġ��Ÿ Ȯ��: " << gm.nj->GetCritical() << "%";
	}
	else
	{
		bt.PrintEnmeyBack();
		ad.PrintArcher1(156, 1);
		SetColor(0, 15);
		cc.PrintAbilityTool(135, 46);
		gotoxy(139, 48);
		std::cout << " �̸�: " << gm.ah->GetName();
		std::cout << "                ����: " << gm.ah->GetOccupation();
		gotoxy(139, 51);
		std::cout << " ���ݷ�: " << gm.ah->GetAtk();
		std::cout << "                ����: " << gm.ah->GetMaxMp();
		gotoxy(139, 54);
		std::cout << " ü��: " << gm.ah->GetMaxHp();
		std::cout << "                   ����: " << gm.ah->GetDef();
		gotoxy(139, 57);
		std::cout << " ġ��Ÿ Ȯ��: " << gm.ah->GetCritical() << "%";
	}
	SetColor(0, 15);
	md.PrintOperation_Keys(230, 3);
	PrintBackOperate(232, 5);
	SetColor(15, 0);
	int input;
	while (true)
	{
		if (_kbhit())
		{
			input = _getch();
			if (input == ESC)
			{
				system("cls");
				SetColor(0, 15);
				mm.Current_StackMap();
				break;
			}
		}
	}
}

void CharacterInfo::PrintBackOperate(int x, int y)
{
	gotoxy(x, y);
	std::cout << "ESC: �ڷΰ���";
}

void CharacterInfo::PrintOperate(int x, int y)
{
	gotoxy(x, y);
	std::cout << "��: ������ ����";
	gotoxy(x, y + 2);
	std::cout << "��: ���� ����";
	gotoxy(x, y + 4);
	std::cout << "Enter: ����";
	gotoxy(x, y + 6);
	std::cout << "ESC: �ڷΰ���";
	SetColor(15, 0);
}

void CharacterInfo::ReadMore(int num)
{
	PrintCharacterAbility(num);
}

CharacterInfo::CharacterInfo()
{
}
