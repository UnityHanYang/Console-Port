#include "CharacterChoice.h"
#include <random>
#include <Windows.h>


#pragma region Ű���� �Է� ��ó����
#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter_Key 13
#pragma endregion


#pragma region ��� �޼���
void CharacterChoice::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void CharacterChoice::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void CharacterChoice::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#pragma endregion

#pragma region ĳ���� ����
bool CharacterChoice::ChoiceScene()
{
	std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
	std::cout << "\n\n\t\t\t   ����\t\t\t\t\t\t\t\t\t����\n\n";
	cbg.PrintBackGround(2, 2, 4, 12);
	cbg.PrintBackGround(2, 2, 72, 12);
	nd.PrintNinJaPortrait(20, 13);
	ad.PrintArcherPortrait(92, 13);
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
				system("cls");
				input = _getch();
				switch (input)
				{
				case LEFT_ARROW:
					std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
					std::cout << "\n\n\t\t\t �� ���� ��\t\t\t\t\t\t\t\t����\n\n";
					cbg.PrintBackGround(11, 11, 4, 12);
					cbg.PrintBackGround(2, 2, 72, 12);
					charNumber = 1;
					break;
				case RIGHT_ARROW:
					std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
					std::cout << "\n\n\t\t\t   ����\t\t\t\t\t\t\t\t    �� ���� ��\n\n";
					cbg.PrintBackGround(2, 2, 4, 12);
					cbg.PrintBackGround(11, 11, 72, 12);
					charNumber = 2;
					break;
				default:
					std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
					std::cout << "\n\n\t\t\t   ����\t\t\t\t\t\t\t\t\t����\n\n";
					cbg.PrintBackGround(2, 2, 4, 12);
					cbg.PrintBackGround(2, 2, 72, 12);
					charNumber = 0;
				}
			}
			else if (input == 13)
			{
				system("cls");
				if (charNumber == 1 || charNumber == 2)
				{
					ReadMore(charNumber);
					return true;
				}
				else
				{
					std::cout << "\n\t\t\t\t\t\t      ĳ���͸� �����ϼ���.\n\n\n\n";
					std::cout << "\n\n\t\t\t   ����\t\t\t\t\t\t\t\t      ����\n\n";
					cbg.PrintBackGround(2, 2, 4, 12);
					cbg.PrintBackGround(2, 2, 72, 12);
					charNumber = 0;
				}
			}
			nd.PrintNinJaPortrait(20, 13);
			ad.PrintArcherPortrait(92, 13);
			SetColor(15, 0);
			md.PrintOperation_Keys(130, 3);
			PrintOperate(132, 5);
		}
	}
}
#pragma endregion

#pragma region ����Ű
void CharacterChoice::PrintOperate(int x, int y)
{
	gotoxy(x, y);
	std::cout << "��: ������ ����";
	gotoxy(x, y + 2);
	std::cout << "��: ���� ����";
	gotoxy(x, y + 4);
	std::cout << "Enter: ����";
	gotoxy(x, y + 6);
	std::cout << "������ �ϰ� Enter Ű��";
	gotoxy(x, y + 7);
	std::cout << "������ ĳ���Ϳ� ����";
	gotoxy(x, y + 8);
	std::cout << "�ڼ��� �� �� �ֽ��ϴ�.";
	gotoxy(x, y + 10);
	std::cout << "������ �� �� ĳ���ʹ� ���߿�";
	gotoxy(x, y + 11);
	std::cout << "���ᰡ �Ǿ� ��Ƽ�� ���Ե˴ϴ�.";
}
#pragma endregion

#pragma region ĳ���� �ڼ��� ����
void CharacterChoice::ReadMore(int num)
{
	PrintCharacterAbility(num);
	SetColor(0, 15);
	gotoxy(20, 17);
	std::cout << "  �� ĳ���ͷ� �Ͻðڽ��ϱ�?";
	gotoxy(20, 20);
	std::cout << "         �� / �ƴϿ�";

	SetColor(15, 0);
	int yesOrNo = 0;
	int input;
	while (true)
	{
		if (_kbhit())
		{
			input = _getch();
			if (input == ARROW)
			{
				input = _getch();
				gotoxy(20, 17);
				SetColor(15, 15);
				std::cout << "                   ";
				gotoxy(20, 20);
				SetColor(15, 15);
				std::cout << "                         ";
				switch (input)
				{
				case LEFT_ARROW:
					gotoxy(20, 17);
					SetColor(0, 15);
					std::cout << "  �� ĳ���ͷ� �Ͻðڽ��ϱ�?";
					gotoxy(20, 20);
					SetColor(15, 15);
					std::cout << "        ";
					gotoxy(29, 20);
					SetColor(12, 15);
					std::cout << "��";
					gotoxy(31, 20);
					SetColor(0, 15);
					std::cout << " / �ƴϿ�";
					yesOrNo = 1;
					break;
				case RIGHT_ARROW:
					gotoxy(20, 17);
					SetColor(0, 15);
					std::cout << "  �� ĳ���ͷ� �Ͻðڽ��ϱ�?";
					gotoxy(20, 20);
					SetColor(0, 15);
					std::cout << "         �� / ";
					gotoxy(33, 20);
					SetColor(12, 15);
					std::cout << " �ƴϿ�";
					yesOrNo = 2;
					break;
				default:
					SetColor(0, 15);
					gotoxy(20, 17);
					std::cout << "  �� ĳ���ͷ� �Ͻðڽ��ϱ�?";
					gotoxy(20, 20);
					std::cout << "         �� / �ƴϿ�";
					break;
				}
			}
			else if (input == 13)
			{
				if (yesOrNo == 1)
				{
					GameManager* gm = GameManager::GetInstance();
					system("cls");
					if (num == 1)
					{
						gm->AddCharacter(gm->nj);
						gm->SetCharacter(1);
					}
					else
					{
						gm->AddCharacter(gm->ah);
						gm->SetCharacter(2);
					}
					break;
				}
				else if (yesOrNo == 2)
				{
					system("cls");
					charNumber = 0;
					ChoiceScene();
					break;
				}
			}
			SetColor(15, 0);
		}
	}
}
#pragma endregion


#pragma region ĳ���� ����
void CharacterChoice::PrintCharacterAbility(int num)
{
	GameManager* gm = GameManager::GetInstance();
	if (num == 1)
	{
		nd.PrintNinJa();
		cbg.PrintNinjarBackGround();
		SetColor(0, 15);
		PrintAbilityTool(135, 50);
		gotoxy(139, 52);
		std::cout << " �̸�: " << gm->nj->GetName();
		std::cout << "                ����: " << gm->nj->GetOccupation();
		gotoxy(139, 55);
		std::cout << " ���ݷ�: " << gm->nj->GetAtk();
		std::cout << "                ����: " << gm->nj->GetMaxMp();
		gotoxy(139, 58);
		std::cout << " ü��: " << gm->nj->GetMaxHp();
		std::cout << "                   ����: " << gm->nj->GetDef();
	}
	else
	{
		cbg.PrintArcherBack();
		ad.PrintArcher(156, 1);
		SetColor(0, 15);
		PrintAbilityTool(135, 46);
		gotoxy(139, 48);
		std::cout << " �̸�: " << gm->ah->GetName();
		std::cout << "                ����: " << gm->ah->GetOccupation();
		gotoxy(139, 51);
		std::cout << " ���ݷ�: " << gm->ah->GetAtk();
		std::cout << "                ����: " << gm->ah->GetMaxMp();
		gotoxy(139, 54);
		std::cout << " ü��: " << gm->ah->GetMaxHp();
		std::cout << "                   ����: " << gm->ah->GetDef();
	}
	md.PrintOperation_Keys(18, 3);
	SetColor(15, 0);
}


void CharacterChoice::PrintAbilityTool(int x, int y)
{

	gotoxy(x, y);
	std::cout << "����������������������������������������������������������������������������������������������������";
	gotoxy(x, y + 14);
	std::cout << "����������������������������������������������������������������������������������������������������";
}
CharacterChoice::CharacterChoice()
{
	charNumber = 0;
}
#pragma endregion