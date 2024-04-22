#include "DungeonBoss.h"

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
	MapDot* md = new MapDot;
	md->SettingDungeonBossMap();

	md->PrintDungeonBossMap();
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
				md->PrintDungeonBossMap();
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
			}
		}
	}
	delete md;
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
	MapDot* md = new MapDot;
	SetColor(15, 0);
	if (md->GetDungeonBossMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 8 || md->GetDungeonBossMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 8)
		return false;

	delete md;
	return true;
}
