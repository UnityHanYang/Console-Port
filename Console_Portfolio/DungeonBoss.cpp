#include "DungeonBoss.h"

int DungeonBoss::enemyArrXY[4] = { 30, 60, 80, 70 };

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13

void DungeonBoss::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void DungeonBoss::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void DungeonBoss::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DungeonBoss::PrintMapAndCharMove(int x, int y)
{
	int xCpy, yCpy;
	xCpy = yCpy = 0;

	md->SettingDungeonBossMap();

	md->PrintDungeonBossMap();
	SetColor(15, 0);
	md->PrintOperation_Keys(206, 10);
	PrintOperation(208, 12);
	PrintEnemy();
	PrintS(2, 1, 1, 1, x, y);
	PrintS(2, 1, 1, 0, x, y + 1);
	SetColor(15, 0);
	md->PrintConsole(204, 57);
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
						break;
					}
					PrintS(1, CheckCurrentXY(xCpy, yCpy), CheckCurrentXY(xCpy, yCpy), 0, xCpy, yCpy);
					PrintS(1, CheckCurrentXY(xCpy + 2, yCpy), CheckCurrentXY(xCpy + 2, yCpy), 1, xCpy + 2, yCpy);
					PrintS(1, CheckCurrentXY(xCpy, yCpy + 1), CheckCurrentXY(xCpy, yCpy + 1), 0, xCpy, yCpy + 1);
					PrintS(1, CheckCurrentXY(xCpy + 2, yCpy + 1), CheckCurrentXY(xCpy + 2, yCpy + 1), 1, xCpy + 2, yCpy + 1);
					PrintS(2, 1, 1, 1, mapX, mapY);
					PrintS(2, 1, 1, 1, mapX, mapY + 1);
					SetColor(15, 0);
				}
				else if (input == Enter)
				{
				}
			}
		}
	}
}

void DungeonBoss::PrintOperation(int x, int y)
{
	gotoxy(x, y);
	SetColor(12, 12);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": �߰����� ������ ��";
	gotoxy(x, y + 2);
	SetColor(4, 4);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ���";
	gotoxy(x, y + 4);
	SetColor(14, 14);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": Ƚ��";
	gotoxy(x, y + 6);
	SetColor(2, 2);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ����";
	gotoxy(x, y + 8);
	SetColor(5, 5);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ��";
	gotoxy(x, y + 10);
	SetColor(6, 6);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ����";
	gotoxy(x, y + 12);
	std::cout << "�÷��̾� ����";
	gotoxy(x, y + 14);
	std::cout << "   ��: ������ �̵�";
	gotoxy(x, y + 15);
	std::cout << "   ��: ���� �̵�";
	gotoxy(x, y + 16);
	std::cout << "   ��: ���� �̵�";
	gotoxy(x, y + 17);
	std::cout << "   ��: �Ʒ��� �̵�";
	gotoxy(x, y + 19);
	std::cout << "Enter: ����";
	gotoxy(x, y + 21);
	std::cout << "���� �տ��� ���͸�";
	gotoxy(x, y + 22);
	std::cout << "�� �� �ֽ��ϴ�.";
	gotoxy(x, y + 24);
	std::cout << "����� ������ HP��";
	gotoxy(x, y + 25);
	std::cout << "�����մϴ�. �����ϼ���!";
}

int DungeonBoss::CheckObjectXY(int x, int y, bool isEntrance)
{
	return 0;
}

bool DungeonBoss::CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count)
{
	SetColor(15, 0);
	if (md->GetDungeonBossMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 8 || md->GetDungeonBossMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 8 ||
		md->GetDungeonBossMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 2 || md->GetDungeonBossMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 2 ||
		md->GetDungeonBossMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 6 || md->GetDungeonBossMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 6)
		return false;

	return true;
}

void DungeonBoss::PrintEnemy()
{
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		PrintS(2, 5, 5, 1, enemyArrXY[i], enemyArrXY[i + 1]);
		PrintS(2, 5, 5, 0, enemyArrXY[i], enemyArrXY[i + 1] + 1);
	}
}

int DungeonBoss::CheckCurrentXY(int x, int y)
{
	int num = 0;
	if (md->GetDungeonBossMap()[y][x / 2] == 12)
	{
		num = 12;
		return num;
	}
	else if (md->GetDungeonBossMap()[y][x / 2] == 4)
	{
		num = 4;
		return num;
	}
	return 0;
}

bool DungeonBoss::CheckEnemyXY(int x, int y)
{
	char message[50];
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		RECT playerSquare = { x - 2, y - 1, x + 3, y + 2 };
		RECT enemySquare = { enemyArrXY[i] - 2, enemyArrXY[i + 1] - 1, enemyArrXY[i] + 3, enemyArrXY[i + 1] + 2 };
		RECT intersect;

		if (IntersectRect(&intersect, &playerSquare, &enemySquare)) {
			return true;
		}
	}
	return false;
}

DungeonBoss::DungeonBoss() : mapX{ 0 }, mapY{ 0 }
{
	md = new MapDot;
}

DungeonBoss::~DungeonBoss()
{
	delete md;
}
