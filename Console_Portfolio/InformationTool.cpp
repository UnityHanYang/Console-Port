#include "InformationTool.h"

void InformationTool::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void InformationTool::PrintS(int count, int font, int background, bool isEndl, int x, int y)
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

void InformationTool::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void InformationTool::ClearOperation(int x, int y)
{
	gotoxy(x, y);
	SetColor(0, 0);
	std::cout << "                             ";
	gotoxy(x, y + 2);
	std::cout << "                             ";
	gotoxy(x, y + 3);
	std::cout << "                             ";
	gotoxy(x, y + 4);
	std::cout << "                             ";
	gotoxy(x, y + 6);
	std::cout << "                             ";
	gotoxy(x, y + 8);
	std::cout << "                             ";
	gotoxy(x, y + 9);
	std::cout << "                             ";
	gotoxy(x, y + 10);
	std::cout << "                             ";
	gotoxy(x, y + 12);
	std::cout << "                             ";
	gotoxy(x, y + 13);
	std::cout << "                             ";
	gotoxy(x, y + 14);
	std::cout << "                             ";
	gotoxy(x, y + 15);
	std::cout << "                             ";
	gotoxy(x, y + 17);
	std::cout << "                             ";
	gotoxy(x, y + 18);
	std::cout << "                             ";
	gotoxy(x, y + 19);
	std::cout << "                             ";
	gotoxy(x, y + 20);
	std::cout << "                             ";
	gotoxy(x, y + 24);
	std::cout << "                             ";
	gotoxy(x, y + 26);
	std::cout << "                             ";
	gotoxy(x, y + 27);
	std::cout << "                             ";
	gotoxy(x, y + 28);
	std::cout << "                             ";
	gotoxy(x, y + 30);
	std::cout << "                             ";
	gotoxy(x, y + 31);
	std::cout << "                             ";
	gotoxy(x, y + 33);
	std::cout << "                             ";
	gotoxy(x, y + 34);
	std::cout << "                             ";
}

void InformationTool::PrintInfo(int x, int y, int num)
{
	SetColor(15, 0);
	gotoxy(x, y);
	(num == 1) ? (printf("%s", "       �� ĳ���� ���� ��")) : (printf("%s", "         ĳ���� ����"));
	gotoxy(x, y + 3);
	(num == 2) ? (printf("%s", "          �� ��� ��")) : (printf("%s", "            ���"));
	gotoxy(x, y + 6);
	(num == 3) ? (printf("%s", "         �� ������ ��")) : (printf("%s", "           ������"));
	gotoxy(x, y + 9);
	(num == 4) ? (printf("%s", "          �� ��ų ��")) : (printf("%s", "            ��ų"));
	gotoxy(x, y + 13);
	std::cout << "  XŰ�� ���� ���Ӿȳ� â����";
	gotoxy(x, y + 14);
	std::cout << "    ���ư� �� �ֽ��ϴ�.";
}
