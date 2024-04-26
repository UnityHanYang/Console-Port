#include "Dungeon1.h"

int Dungeon1::enemyArrXY[6] = { 140, 36, 32, 60, 120, 15 };
int Dungeon1::treasureBoxXY[6] = { 10, 3, 182, 51, 88, 7 };

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13

#pragma region 상속 메서드
void Dungeon1::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void Dungeon1::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void Dungeon1::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#pragma endregion

#pragma region 맵 출력, 플레이어 이동
void Dungeon1::PrintMapAndCharMove(int x, int y)
{
	int xCpy, yCpy;
	xCpy = yCpy = 0;
	md.SettingDungeonMap();

	MapManager mm;
	md.PrintDungeonMap();
	SetColor(15, 0);
	md.PrintOperation_Keys(206, 10);
	PrintOperation(208, 12);
	PrintEnemy();
	PrintTreasure();
	PrintS(2, 1, 1, 1, x, y);
	PrintS(2, 1, 1, 0, x, y + 1);
	SetColor(15, 0);
	md.PrintConsole(204, 57);
	mapX = x;
	mapY = y;
	int input;
	while (true)
	{
		if (!CheckEnemyXY(mapX, mapY))
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
							xCpy = mapX;
							yCpy = mapY;
							mapX -= 2;
						}
						break;
					case RIGHT_ARROW:
						if (CheckMapXY(mapX, mapY, 2, 0, 2, 1))
						{
							xCpy = mapX;
							yCpy = mapY;
							mapX += 2;
						}
						break;
					case UP_ARROW:
						if (CheckMapXY(mapX, mapY, 0, -1, 1, -1))
						{
							xCpy = mapX;
							yCpy = mapY;
							--mapY;
						}
						break;
					case DOWN_ARROW:
						if (CheckMapXY(mapX, mapY, 0, 2, 1, 2))
						{
							xCpy = mapX;
							yCpy = mapY;
							++mapY;
						}
					}
					CheckTreasureXY(mapX, mapY);
					PrintS(1, CheckCurrentXY(xCpy, yCpy), CheckCurrentXY(xCpy, yCpy), 0, xCpy, yCpy);
					PrintS(1, CheckCurrentXY(xCpy + 2, yCpy), CheckCurrentXY(xCpy + 2, yCpy), 1, xCpy + 2, yCpy);
					PrintS(1, CheckCurrentXY(xCpy, yCpy + 1), CheckCurrentXY(xCpy, yCpy + 1), 0, xCpy, yCpy + 1);
					PrintS(1, CheckCurrentXY(xCpy + 2, yCpy + 1), CheckCurrentXY(xCpy + 2, yCpy + 1), 1, xCpy + 2, yCpy + 1);
					PrintS(2, 1, 1, 1, mapX, mapY);
					PrintS(2, 1, 1, 1, mapX, mapY + 1);
					SetColor(15, 0);
				}
				if (CheckEntranceXY(mapX, mapY))
				{
					if (input == Enter)
					{
						isEntrance = true;
						break;
					}
				}
			}
		}
		else
		{
			isCollsionEnemy = true;
			break;
		}
	}
	system("cls");
	if (isEntrance)
	{
		mm.ms = Map_State::boss_dungeon;
		mm.Current_Map();
		isEntrance = false;
	}
	if(isCollsionEnemy)
	{
		mm.ms = Map_State::battle;
		mm.Current_Map();
		isCollsionEnemy = false;
	}
}
#pragma endregion

#pragma region 조작법, 안내창
void Dungeon1::PrintOperation(int x, int y)
{
	gotoxy(x, y);
	SetColor(12, 12);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 뜨겁지만 안전한 땅";
	gotoxy(x, y + 2);
	SetColor(4, 4);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 용암";
	gotoxy(x, y + 4);
	SetColor(14, 14);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 랜덤 보물상자";
	gotoxy(x, y + 6);
	SetColor(5, 5);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 적";
	gotoxy(x, y + 8);
	SetColor(8, 8);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 기둥";
	gotoxy(x, y + 10);
	std::cout << "플레이어 조작";
	gotoxy(x, y + 12);
	std::cout << "   →: 오른쪽 이동";
	gotoxy(x, y + 13);
	std::cout << "   ←: 왼쪽 이동";
	gotoxy(x, y + 14);
	std::cout << "   ↑: 위쪽 이동";
	gotoxy(x, y + 15);
	std::cout << "   ↓: 아래쪽 이동";
	gotoxy(x, y + 17);
	std::cout << "Enter: 선택";
	gotoxy(x, y + 19);
	std::cout << "입구나 보물상자 앞에서";
	gotoxy(x, y + 20);
	std::cout << "엔터를 누를 수 있습니다.";
	gotoxy(x, y + 22);
	std::cout << "용암을 밟으면 HP가";
	gotoxy(x, y + 23);
	std::cout << "감소합니다. 유의하세요!";
}
#pragma endregion

#pragma region 대화창
void Dungeon1::PrintTalkMessage(int x, int y, char message[50])
{
	gotoxy(x, y);
	SetColor(15, 0);
	for (int i = 0; message[i] != '\0'; i++)
	{
		std::cout << message[i];
	}
}
#pragma endregion

#pragma region 충돌 처리
bool Dungeon1::CheckEnemyXY(int x, int y)
{
	char message[50] = {};
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		RECT playerSquare = { x - 1, y - 1, x + 3, y + 2 };
		RECT enemySquare = { enemyArrXY[i] - 2, enemyArrXY[i + 1] - 1, enemyArrXY[i] + 4, enemyArrXY[i + 1] + 2 };
		RECT intersect;

		if (IntersectRect(&intersect, &playerSquare, &enemySquare)) {
			return true;
		}
	}
	return false;
}

void Dungeon1::CheckTreasureXY(int x, int y)
{
	// 충돌처리 구현 안 됨
	char message[50] = {};
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		RECT playerSquare = { x - 1, y - 1, x + 2, y + 2 };
		RECT treasureSquare = { treasureBoxXY[i] - 3, treasureBoxXY[i + 1] - 1, treasureBoxXY[i] + 4, treasureBoxXY[i + 1] + 1 };
		RECT intersect;
		intersect.left = 0;
		intersect.top = 0,
			intersect.right = 0;
		intersect.bottom = 0;

		if (IntersectRect(&intersect, &playerSquare, &treasureSquare))
		{

		}
	}
}
#pragma endregion

#pragma region 적, 보물상자 생성
void Dungeon1::PrintEnemy()
{
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		PrintS(2, 5, 5, 1, enemyArrXY[i], enemyArrXY[i + 1]);
		PrintS(2, 5, 5, 0, enemyArrXY[i], enemyArrXY[i + 1] + 1);
	}
}

void Dungeon1::PrintTreasure()
{
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		PrintS(2, 14, 14, 1, treasureBoxXY[i], treasureBoxXY[i + 1]);
	}
}

#pragma endregion

#pragma region 현재 위치, 던전 입구 감지
int Dungeon1::CheckCurrentXY(int x, int y)
{
	int num = 0;
	if (md.GetDungeonMap()[y][x / 2] == 12)
	{
		num = 12;
		return num;
	}
	else if (md.GetDungeonMap()[y][x / 2] == 4)
	{
		num = 4;
		return num;
	}
	return 0;
}

bool Dungeon1::CheckEntranceXY(int x, int y)
{
	if (md.GetDungeonMap()[y - 1][x / 2] == 0 && md.GetDungeonMap()[y - 1][(x / 2) + 1] == 0)
	{
		return true;
	}
	return false;
}
#pragma endregion

#pragma region 플레이어 제약 사항
bool Dungeon1::CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count)
{
	if (md.GetDungeonMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 8 || md.GetDungeonMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 8)
	{
		return false;
	}

	return true;
}
#pragma endregion