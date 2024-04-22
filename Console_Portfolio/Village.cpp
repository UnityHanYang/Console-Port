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
		std::cout << "��";
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
	md->PrintOperation_Keys(206, 10);
	PrintOperation(208, 12);
	PrintS(2, 1, 1, 1, x, y);
	PrintS(2, 1, 1, 1, x, y + 1);
	SetColor(15, 0);
	//md->PrintConsole(200, 330);
	SetColor(15, 0);
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
				system("cls");
				md->PrintVillageMap();
				SetColor(15, 0);
				md->PrintOperation_Keys(206, 10);
				PrintOperation(208, 12);
				input = _getch();
				switch (input)
				{
				case LEFT_ARROW:
					if (CheckMapXY(mapX, mapY, -1, 0, -1, 1))
					{
						mapX -= 2;
					}
					break;
				case RIGHT_ARROW:
					if (CheckMapXY(mapX, mapY, 2, 0, 2, 1))
					{
						mapX += 2;
					}
					break;
				case UP_ARROW:
					if (CheckMapXY(mapX, mapY, 0, -1, 1, -1))
					{
						--mapY;
					}
					break;
				case DOWN_ARROW:
					if (CheckMapXY(mapX, mapY, 0, 2, 1, 2))
					{
						++mapY;
					}
					break;
				}
				PrintS(2, 1, 1, 1, mapX, mapY);
				PrintS(2, 1, 1, 1, mapX, mapY + 1);
				SetColor(15, 0);
			}
			else if (input == Enter)
			{
				PrintBuildingName();
			}
		}
	}
	delete md;
}

void Village::PrintOperation(int x, int y)
{
	gotoxy(x, y);
	SetColor(6, 6);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ����(â��, ��Ÿ��, ��)";
	gotoxy(x, y + 2);
	SetColor(13, 13);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": �ǹ� �̸�â";
	gotoxy(x, y + 4);
	SetColor(7, 7);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ����(�ε�)";
	gotoxy(x, y + 6);
	SetColor(2, 2);
	std::cout << "��";
	SetColor(0, 0);
	std::cout << ", ";
	SetColor(10, 10);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": Ǯ, ����, �� , ����";
	gotoxy(x, y + 8);
	SetColor(9, 9);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ȣ��";
	gotoxy(x, y + 10);
	SetColor(8, 8);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ��, ����(��Ÿ��, ��)";
	gotoxy(x, y + 12);
	SetColor(4, 4);
	std::cout << "��";
	SetColor(0, 0);
	std::cout << ", ";
	SetColor(11, 11);
	std::cout << "��";
	SetColor(0, 0);
	std::cout << ", ";
	SetColor(14, 14);
	std::cout << "��";
	SetColor(15, 0);
	std::cout << ": ����";
	gotoxy(x, y + 15);
	SetColor(15, 0);
	std::cout << "�÷��̾� ����";
	gotoxy(x, y + 17);
	std::cout << "   ��: ������ �̵�";
	gotoxy(x, y + 18);
	std::cout << "   ��: ���� �̵�";
	gotoxy(x, y + 19);
	std::cout << "   ��: ���� �̵�";
	gotoxy(x, y + 20);
	std::cout << "   ��: �Ʒ��� �̵�";
	gotoxy(x, y + 24);
	std::cout << "Enter: ����";
	gotoxy(x, y + 26);
	std::cout << "�Ա��� �ǹ� �̸�â �տ���";
	gotoxy(x, y + 27);
	std::cout << "���͸� ���� �� �ֽ��ϴ�.";
	gotoxy(x, y + 29);
	std::cout << "�÷��̾�� ���θ� �����ٴ�";
	gotoxy(x, y + 30);
	std::cout << "�� �ֽ��ϴ�.";
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
	}
}

int Village::CheckBuildingXY(int x, int y, bool isEntrance)
{
	int num = 0;
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
		if (md->GetVillageMap()[y - 1][x] == 13 && md->GetVillageMap()[y - 1][x + 1] == 13)
		{
			if (x == 28 && x + 1 == 29)
			{
				num = 1;
			}
			else if (x == 59 && x + 1 == 60)
			{
				num = 2;
			}
			else if (x == 22 && x + 1 == 23)
			{
				num = 3;
			}
			else if (x == 72 && x + 1 == 73)
			{
				num = 4;
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
