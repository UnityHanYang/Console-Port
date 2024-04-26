#include "CharacterChoice.h"
#include <random>
#include <Windows.h>

int CharacterChoice::characterNum = 0;
int charNum = 0;


#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define Enter_Key 13

#pragma region 상속 메서드
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
		std::cout << "ㅁ";
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

#pragma region 캐릭터 선택
bool CharacterChoice::ChoiceScene()
{
	std::cout << "\n\t\t\t\t\t\t      캐릭터를 선택하세요.\n\n\n\n";
	std::cout << "\n\n\t\t\t   겐지\t\t\t\t\t\t\t\t\t한조\n\n";
	PrintBackGround(2, 2, 4, 12);
	PrintBackGround(2, 2, 72, 12);
	nd.PrintNinZaPortrait1(20, 13);
	ad.PrintArcherPortrait1(92, 13);
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
					std::cout << "\n\t\t\t\t\t\t      캐릭터를 선택하세요.\n\n\n\n";
					std::cout << "\n\n\t\t\t ▶ 겐지 ◀\t\t\t\t\t\t\t\t한조\n\n";
					PrintBackGround(11, 11, 4, 12);
					PrintBackGround(2, 2, 72, 12);
					charNum = 1;
					break;
				case RIGHT_ARROW:
					std::cout << "\n\t\t\t\t\t\t      캐릭터를 선택하세요.\n\n\n\n";
					std::cout << "\n\n\t\t\t   겐지\t\t\t\t\t\t\t\t    ▶ 한조 ◀\n\n";
					PrintBackGround(2, 2, 4, 12);
					PrintBackGround(11, 11, 72, 12);
					charNum = 2;
					break;
				default:
					std::cout << "\n\t\t\t\t\t\t      캐릭터를 선택하세요.\n\n\n\n";
					std::cout << "\n\n\t\t\t   겐지\t\t\t\t\t\t\t\t\t한조\n\n";
					PrintBackGround(2, 2, 4, 12);
					PrintBackGround(2, 2, 72, 12);
					charNum = 0;
				}
			}
			else if (input == 13)
			{
				system("cls");
				if (charNum == 1 || charNum == 2)
				{
					ReadMore(charNum);
					return true;
				}
				else
				{
					std::cout << "\n\t\t\t\t\t\t      캐릭터를 선택하세요.\n\n\n\n";
					std::cout << "\n\n\t\t\t   겐지\t\t\t\t\t\t\t\t      한조\n\n";
					PrintBackGround(2, 2, 4, 12);
					PrintBackGround(2, 2, 72, 12);
					charNum = 0;
				}
			}
			nd.PrintNinZaPortrait1(20, 13);
			ad.PrintArcherPortrait1(92, 13);
			SetColor(15, 0);
			md.PrintOperation_Keys(130, 3);
			PrintOperate(132, 5);
		}
	}
}
#pragma endregion

#pragma region 조작키
void CharacterChoice::PrintOperate(int x, int y)
{
	gotoxy(x, y);
	std::cout << "→: 오른쪽 선택";
	gotoxy(x, y + 2);
	std::cout << "←: 왼쪽 선택";
	gotoxy(x, y + 4);
	std::cout << "Enter: 선택";
	gotoxy(x, y + 6);
	std::cout << "선택을 하고 Enter 키를";
	gotoxy(x, y + 7);
	std::cout << "누르면 캐릭터에 대해";
	gotoxy(x, y + 8);
	std::cout << "자세히 볼 수 있습니다.";
	gotoxy(x, y + 10);
	std::cout << "선택이 안 된 캐릭터는 나중에";
	gotoxy(x, y + 11);
	std::cout << "동료가 되어 파티에 가입됩니다.";
}
#pragma endregion

#pragma region 캐릭터 자세히 보기
void CharacterChoice::ReadMore(int num)
{
	PrintCharacterAbility(num);
	SetColor(0, 15);
	gotoxy(20, 17);
	std::cout << "  이 캐릭터로 하시겠습니까?";
	gotoxy(20, 20);
	std::cout << "         예 / 아니오";

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
					std::cout << "  이 캐릭터로 하시겠습니까?";
					gotoxy(20, 20);
					SetColor(15, 15);
					std::cout << "        ";
					gotoxy(29, 20);
					SetColor(12, 15);
					std::cout << "예";
					gotoxy(31, 20);
					SetColor(0, 15);
					std::cout << " / 아니오";
					yesOrNo = 1;
					break;
				case RIGHT_ARROW:
					gotoxy(20, 17);
					SetColor(0, 15);
					std::cout << "  이 캐릭터로 하시겠습니까?";
					gotoxy(20, 20);
					SetColor(0, 15);
					std::cout << "         예 / ";
					gotoxy(33, 20);
					SetColor(12, 15);
					std::cout << " 아니오";
					yesOrNo = 2;
					break;
				default:
					SetColor(0, 15);
					gotoxy(20, 17);
					std::cout << "  이 캐릭터로 하시겠습니까?";
					gotoxy(20, 20);
					std::cout << "         예 / 아니오";
					break;
				}
			}
			else if (input == 13)
			{
				if (yesOrNo == 1)
				{
					system("cls");
					if (num == 1)
					{
						hotel.AddCharacter(gm.nj);
						characterNum = 1;
					}
					else
					{
						hotel.AddCharacter(gm.ah);
						characterNum = 2;
					}
					break;
				}
				else if (yesOrNo == 2)
				{
					system("cls");
					charNum = 0;
					ChoiceScene();
					break;
				}
			}
			SetColor(15, 0);
		}
	}
}
#pragma endregion

#pragma region 배경
void CharacterChoice::PrintBackGround(int font, int background, int x, int y)
{
	PrintS(26, font, background, 1, x, y);
	PrintS(26, font, background, 1, x, y + 1);
	PrintS(26, font, background, 1, x, y + 2);
	PrintS(26, font, background, 1, x, y + 3);
	PrintS(26, font, background, 1, x, y + 4);
	PrintS(26, font, background, 1, x, y + 5);
	PrintS(26, font, background, 1, x, y + 6);
	PrintS(26, font, background, 1, x, y + 7);
	PrintS(26, font, background, 1, x, y + 8);
	PrintS(26, font, background, 1, x, y + 9);
	PrintS(26, font, background, 1, x, y + 10);
	PrintS(26, font, background, 1, x, y + 11);
	PrintS(26, font, background, 1, x, y + 12);
	PrintS(26, font, background, 1, x, y + 13);
	PrintS(26, font, background, 1, x, y + 14);
	PrintS(26, font, background, 1, x, y + 15);
	PrintS(26, font, background, 1, x, y + 16);
	PrintS(26, font, background, 1, x, y + 17);
	PrintS(26, font, background, 1, x, y + 18);
	PrintS(26, font, background, 1, x, y + 19);
	PrintS(26, font, background, 1, x, y + 20);
	PrintS(26, font, background, 1, x, y + 21);
	PrintS(26, font, background, 1, x, y + 22);
	PrintS(26, font, background, 1, x, y + 23);
	PrintS(26, font, background, 1, x, y + 24);
	PrintS(26, font, background, 1, x, y + 25);
	PrintS(26, font, background, 1, x, y + 26);
}

void CharacterChoice::PrintNinjarBackGround()
{
	int background[18][157] = {
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
		{15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
	};


	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 157; j++)
		{
			SetColor(background[i][j], background[i][j]);
			std::cout << "ㅁ";
			SetColor(15, 15);
		}
		std::cout << std::endl;
	}

}
#pragma endregion

#pragma region 캐릭터 정보
void CharacterChoice::PrintCharacterAbility(int num)
{
	if (num == 1)
	{
		nd.PrintNinZa1();
		PrintNinjarBackGround();
		SetColor(0, 15);
		PrintAbilityTool(135, 50);
		gotoxy(139, 52);
		std::cout << " 이름: " << gm.nj->GetName();
		std::cout << "                직업: " << gm.nj->GetOccupation();
		gotoxy(139, 55);
		std::cout << " 공격력: " << gm.nj->GetAtk();
		std::cout << "                마나: " << gm.nj->GetMaxMp();
		gotoxy(139, 58);
		std::cout << " 체력: " << gm.nj->GetMaxHp();
		std::cout << "                   방어력: " << gm.nj->GetDef();
		gotoxy(139, 61);
		std::cout << " 치명타 확률: " << gm.nj->GetCritical() << "%";
	}
	else
	{
		bt.PrintEnmeyBack();
		ad.PrintArcher1(156, 1);
		SetColor(0, 15);
		PrintAbilityTool(135, 46);
		gotoxy(139, 48);
		std::cout << " 이름: " << gm.ah->GetName();
		std::cout << "                직업: " << gm.ah->GetOccupation();
		gotoxy(139, 51);
		std::cout << " 공격력: " << gm.ah->GetAtk();
		std::cout << "                마나: " << gm.ah->GetMaxMp();
		gotoxy(139, 54);
		std::cout << " 체력: " << gm.ah->GetMaxHp();
		std::cout << "                   방어력: " << gm.ah->GetDef();
		gotoxy(139, 57);
		std::cout << " 치명타 확률: " << gm.ah->GetCritical() << "%";
	}
	md.PrintOperation_Keys(18, 3);
	SetColor(15, 0);
}


void CharacterChoice::PrintAbilityTool(int x, int y)
{

	gotoxy(x, y);
	std::cout << "──────────────────────────────────────────────────";
	gotoxy(x, y + 14);
	std::cout << "──────────────────────────────────────────────────";
}
#pragma endregion