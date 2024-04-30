#include "CharacterInfo.h"


#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter_Key 13
#define ESC 27
int charChoiceNum = 0;

#pragma region ��� �޼���
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
#pragma endregion

#pragma region ĳ���� ����
void CharacterInfo::CharacterOne()
{
	SetColor(15, 0);
	GameManager gm;
	CharacterChoice cc;
	if (gm.GetCharacter() == 1)
	{
		std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
		std::cout << "\n\n\t\t\t �� ����(���ΰ�) ��\n\n";
		cbg.PrintBackGround(11, 11, 4, 12);
		nd.PrintNinJaPortrait(20, 13);
		SetColor(15, 0);
		charChoiceNum = 1;
	}
	else if (gm.GetCharacter() == 2)
	{
		std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
		std::cout << "\n\n\t\t\t �� ����(���ΰ�) ��\n\n";
		cbg.PrintBackGround(11, 11, 4, 12);
		ad.PrintArcherPortrait(24, 13);
		SetColor(15, 0);
		charChoiceNum = 2;
	}
}


void CharacterInfo::ChoiceCharacter()
{
	MapManager mm;
	CharacterChoice cc;
	CharacterOne();
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
			if (input == Enter_Key)
			{
				system("cls");
				if (charChoiceNum == 1 || charChoiceNum == 2)
				{
					mm.SetStack(6);
					ReadMore(charChoiceNum);
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
#pragma endregion

#pragma region ĳ���� ����
void CharacterInfo::ReadMore(int num)
{
	PrintCharacterAbility(num);
}

void CharacterInfo::PrintCharacterAbility(int num)
{
	CharacterChoice cc;
	GameManager* gm = GameManager::GetInstance();
	MapManager mm;
	Character* ch;
	if (num == 1)
	{
		nd.PrintNinJa();
		cbg.PrintNinjarBackGround();
		SetColor(0, 15);
		cc.PrintAbilityTool(135, 50);
		gotoxy(139, 52);
		std::cout << " �̸�: " << gm->nj->GetName();
		std::cout << "                ����: " << gm->nj->GetOccupation();
		gotoxy(139, 55);
		std::cout << " ����: " << gm->nj->GetLevel();
		std::cout << "                   ���ݷ�: " << gm->nj->GetAtk();
		gotoxy(139, 58);
		std::cout << " ����: " << gm->nj->GetCurrentMp();
		std::cout << "                  ü��: " << gm->nj->GetCurrentHp();
		gotoxy(139, 61);
		std::cout << " ����: " << gm->nj->GetDef();
		ch = gm->nj;
	}
	else
	{
		cbg.PrintArcherBack();
		ad.PrintArcher(156, 1);
		SetColor(0, 15);
		cc.PrintAbilityTool(135, 46);
		gotoxy(139, 48);
		std::cout << " �̸�: " << gm->ah->GetName();
		std::cout << "                ����: " << gm->ah->GetOccupation();
		gotoxy(139, 51);
		std::cout << " ����: " << gm->ah->GetLevel();
		std::cout << "                   ���ݷ�: " << gm->ah->GetAtk();
		gotoxy(139, 54);
		std::cout << " ����: " << gm->ah->GetCurrentMp();
		std::cout << "                  ü��: " << gm->ah->GetCurrentHp();
		gotoxy(139, 57);
		std::cout << " ����: " << gm->ah->GetDef();
		ch = gm->ah;
	}
	SetColor(0, 15);
	md.PrintOperation_Keys(230, 3);
	PrintBackOperate(232, 5, ch);
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
#pragma endregion

#pragma region ����Ű
void CharacterInfo::PrintBackOperate(int x, int y, Character* ch)
{
	gotoxy(x, y);
	std::cout << "ESC: �ڷΰ���";
	gotoxy(x, y + 10);
	std::cout << "���� ����ġ: " << ch->GetCurrentExp();
	gotoxy(x, y + 12);
	std::cout << "���� ���� ����ġ: " << ch->GetMaxExp();
	gotoxy(x, y + 14);
	std::cout << "���� �������� ����ġ: " << ch->GetMaxExp() - ch->GetCurrentExp();
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
#pragma endregion
