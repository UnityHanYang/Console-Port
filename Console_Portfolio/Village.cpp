#include "Village.h"

bool isEqual = false;
#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13


void Village::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void Village::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void Village::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Village::PrintMapAndCharMove(int x, int y)
{
	MapDot* md = new MapDot;
	md->SettingVillageMap();

	md->PrintVillageMap();
	SetColor(15, 0);
	PrintS(2, 1, 1, 1, x, y);
	PrintS(2, 1, 1, 0, x, y + 1);
	SetColor(15, 0);
	md->PrintOperation_Keys(206, 10);
	PrintOperation(208, 12);
	md->PrintConsole(204, 57);
	mapX = x;
	mapY = y;
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
					if (CheckMapXY(mapX, mapY, -1, 0, -1, 1))
					{
						PrintS(2, 7, 7, 1, mapX, mapY);
						PrintS(2, 7, 7, 1, mapX, mapY + 1);
						mapX -= 2;
					}
					break;
				case RIGHT_ARROW:
					if (CheckMapXY(mapX, mapY, 2, 0, 2, 1))
					{
						PrintS(2, 7, 7, 1, mapX, mapY);
						PrintS(2, 7, 7, 1, mapX, mapY + 1);
						mapX += 2;
					}
					break;
				case UP_ARROW:
					if (CheckMapXY(mapX, mapY, 0, -1, 1, -1))
					{
						PrintS(2, 7, 7, 1, mapX, mapY);
						PrintS(2, 7, 7, 1, mapX, mapY + 1);
						--mapY;
					}
					break;
				case DOWN_ARROW:
					if (CheckMapXY(mapX, mapY, 0, 2, 1, 2))
					{
						PrintS(2, 7, 7, 1, mapX, mapY);
						PrintS(2, 7, 7, 1, mapX, mapY + 1);
						++mapY;
					}
					break;
				}
				PrintS(2, 1, 1, 1, mapX, mapY);
				PrintS(2, 1, 1, 1, mapX, mapY + 1);
				SetColor(15, 0);
			}
		}
		PrintBuildingName();
	}
	delete md;
}

void Village::PrintOperation(int x, int y)
{
	gotoxy(x, y);
	SetColor(6, 6);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 목재(창문, 울타리, 집)";
	gotoxy(x, y + 2);
	SetColor(13, 13);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 건물 이름창";
	gotoxy(x, y + 4);
	SetColor(7, 7);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 도로(인도)";
	gotoxy(x, y + 6);
	SetColor(2, 2);
	std::cout << "ㅁ";
	SetColor(0, 0);
	std::cout << ", ";
	SetColor(10, 10);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 풀, 나무, 꽃 , 지붕";
	gotoxy(x, y + 8);
	SetColor(9, 9);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 호수";
	gotoxy(x, y + 10);
	SetColor(8, 8);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 돌, 석재(울타리, 집)";
	gotoxy(x, y + 12);
	SetColor(4, 4);
	std::cout << "ㅁ";
	SetColor(0, 0);
	std::cout << ", ";
	SetColor(11, 11);
	std::cout << "ㅁ";
	SetColor(0, 0);
	std::cout << ", ";
	SetColor(14, 14);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 지붕";
	gotoxy(x, y + 15);
	SetColor(15, 0);
	std::cout << "플레이어 조작";
	gotoxy(x, y + 17);
	std::cout << "   →: 오른쪽 이동";
	gotoxy(x, y + 18);
	std::cout << "   ←: 왼쪽 이동";
	gotoxy(x, y + 19);
	std::cout << "   ↑: 위쪽 이동";
	gotoxy(x, y + 20);
	std::cout << "   ↓: 아래쪽 이동";
	gotoxy(x, y + 24);
	std::cout << "Enter: 선택";
	gotoxy(x, y + 26);
	std::cout << "입구 앞에서 엔터를";
	gotoxy(x, y + 27);
	std::cout << "누를 수 있습니다.";
	gotoxy(x, y + 29);
	std::cout << "플레이어는 도로만 지나다닐";
	gotoxy(x, y + 30);
	std::cout << "수 있습니다.";
	gotoxy(x, y + 32);
	std::cout << "건물 이름은 대화창에";
	gotoxy(x, y + 33);
	std::cout << "출력됩니다.";
}

void Village::PrintBuildingName()
{
	switch (CheckBuildingXY(mapX, mapY, false))
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		strcpy(message, "여관");
		break;
	case 6:
		strcpy(message, "상점");
		break;
	case 7:
		strcpy(message, "주민 집");
		break;
	case 8:
		strcpy(message, "도박장");
		break;
	default:
		strcpy(message, "      ");
		break;
	}
	PrintTalkMessage(207, 59, message);
}

void Village::PrintTalkMessage(int x, int y, char message[50])
{
	gotoxy(x, y);
	SetColor(15, 0);
	for (int i = 0; message[i] != '\0'; i++)
	{
		std::cout << message[i];
	}
}

int Village::CheckBuildingXY(int x, int y, bool isEntrance)
{
	int num = 0;
	int divide = x / 2;
	MapDot* md = new MapDot;
	if (isEntrance)
	{
		if (md->GetVillageMap()[y - 1][x] == 0 && md->GetVillageMap()[y - 1][x + 1] == 0)
		{
			if (x == 26 && x + 1 == 27 || x == 26 && x + 1 == 25)
			{
				num = 1;
			}
			else if (x == 61 && x + 1 == 62 || x == 62 && x + 1 == 63)
			{
				num = 2;
			}
			else if (x == 7 && x + 1 == 8 || x == 8 && x + 1 == 9 || x == 25 && x + 1 == 26 || x == 26 && x + 1 == 27)
			{
				num = 3;
			}
			else if (x == 83 && x + 1 == 84 || x == 84 && x + 1 == 85)
			{
				num = 4;
			}
		}
	}
	else
	{
		if (md->GetVillageMap()[y - 1][divide] == 13 && md->GetVillageMap()[y - 1][divide + 1] == 13)
		{
			if (divide == 28 && divide + 1 == 29)
			{
				num = 5;
			}
			else if (divide == 59 && divide + 1 == 60)
			{
				num = 6;
			}
			else if (divide == 22 && divide + 1 == 23)
			{
				num = 7;
			}
			else if (divide == 72 && divide + 1 == 73)
			{
				num = 8;
			}
		}
	}
	delete md;
	return num;
}

bool Village::CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count)
{
	MapDot* md = new MapDot;
	if (md->GetVillageMap()[y1 + y1Count][((x1 / 2) + x1Count)] != 7 || md->GetVillageMap()[y1 + y2Count][((x1 / 2) + x2Count)] != 7)
		return false;

	delete md;
	return true;
}

Village::Village()
{
	mapX = 0;
	mapY = 0;
}
