#include "CharacterInfo.h"


#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter_Key 13
#define ESC 27
int charChoiceNum = 0;

#pragma region 상속 메서드
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
		std::cout << "ㅁ";
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

#pragma region 캐릭터 선택
void CharacterInfo::CharacterOne()
{
	SetColor(15, 0);
	GameManager gm;
	CharacterChoice cc;
	if (gm.GetCharacter() == 1)
	{
		std::cout << "\n\t\t\t\t\t\t      캐릭터를 선택하세요.\n\n\n\n";
		std::cout << "\n\n\t\t\t ▶ 겐지(주인공) ◀\n\n";
		cbg.PrintBackGround(11, 11, 4, 12);
		nd.PrintNinJaPortrait(20, 13);
		SetColor(15, 0);
		charChoiceNum = 1;
	}
	else if (gm.GetCharacter() == 2)
	{
		std::cout << "\n\t\t\t\t\t\t      캐릭터를 선택하세요.\n\n\n\n";
		std::cout << "\n\n\t\t\t ▶ 한조(주인공) ◀\n\n";
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

#pragma region 캐릭터 정보
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
		std::cout << " 이름: " << gm->nj->GetName();
		std::cout << "                직업: " << gm->nj->GetOccupation();
		gotoxy(139, 55);
		std::cout << " 레벨: " << gm->nj->GetLevel();
		std::cout << "                   공격력: " << gm->nj->GetAtk();
		gotoxy(139, 58);
		std::cout << " 마나: " << gm->nj->GetCurrentMp();
		std::cout << "                  체력: " << gm->nj->GetCurrentHp();
		gotoxy(139, 61);
		std::cout << " 방어력: " << gm->nj->GetDef();
		ch = gm->nj;
	}
	else
	{
		cbg.PrintArcherBack();
		ad.PrintArcher(156, 1);
		SetColor(0, 15);
		cc.PrintAbilityTool(135, 46);
		gotoxy(139, 48);
		std::cout << " 이름: " << gm->ah->GetName();
		std::cout << "                직업: " << gm->ah->GetOccupation();
		gotoxy(139, 51);
		std::cout << " 레벨: " << gm->ah->GetLevel();
		std::cout << "                   공격력: " << gm->ah->GetAtk();
		gotoxy(139, 54);
		std::cout << " 마나: " << gm->ah->GetCurrentMp();
		std::cout << "                  체력: " << gm->ah->GetCurrentHp();
		gotoxy(139, 57);
		std::cout << " 방어력: " << gm->ah->GetDef();
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

#pragma region 조작키
void CharacterInfo::PrintBackOperate(int x, int y, Character* ch)
{
	gotoxy(x, y);
	std::cout << "ESC: 뒤로가기";
	gotoxy(x, y + 10);
	std::cout << "현재 경험치: " << ch->GetCurrentExp();
	gotoxy(x, y + 12);
	std::cout << "다음 레벨 경험치: " << ch->GetMaxExp();
	gotoxy(x, y + 14);
	std::cout << "다음 레벨까지 경험치: " << ch->GetMaxExp() - ch->GetCurrentExp();
}

void CharacterInfo::PrintOperate(int x, int y)
{
	gotoxy(x, y);
	std::cout << "→: 오른쪽 선택";
	gotoxy(x, y + 2);
	std::cout << "←: 왼쪽 선택";
	gotoxy(x, y + 4);
	std::cout << "Enter: 선택";
	gotoxy(x, y + 6);
	std::cout << "ESC: 뒤로가기";
	SetColor(15, 0);
}
#pragma endregion
