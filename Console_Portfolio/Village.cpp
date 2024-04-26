#include "Village.h"

int Village::currentX = 0;
int Village::currentY = 0;
bool Village::isXTrue = false;
int Village::currentNum = 0;

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13
#define X_Key 120

#pragma region ��� �޼���
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
#pragma endregion

#pragma region �� ���, �÷��̾� �̵�
void Village::PrintMapAndCharMove(int x, int y)
{
	MapManager mm;
	StoreMap sm;
	CharacterInfo ci;
	ItemInventoryWindow iw;
	md.SettingVillageMap();
	md.PrintVillageMap();
	SetColor(15, 0);
	PrintS(2, 1, 1, 1, x, y);
	PrintS(2, 1, 1, 0, x, y + 1);
	SetColor(15, 0);
	md.PrintOperation_Keys(206, 10);
	if (isXTrue)
	{
		it.PrintInfo(208, 12, currentNum);
	}
	else
	{
		PrintOperation(208, 12);
	}
	md.PrintConsole(204, 57);
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
					if (!isXTrue)
					{
						if (CheckMapXY(mapX, mapY, -1, 0, -1, 1))
						{
							PrintS(2, 7, 7, 1, mapX, mapY);
							PrintS(2, 7, 7, 1, mapX, mapY + 1);
							mapX -= 2;
						}
					}
					break;
				case RIGHT_ARROW:
					if (!isXTrue)
					{
						if (CheckMapXY(mapX, mapY, 2, 0, 2, 1))
						{
							PrintS(2, 7, 7, 1, mapX, mapY);
							PrintS(2, 7, 7, 1, mapX, mapY + 1);
							mapX += 2;
						}
					}
					break;
				case UP_ARROW:
					if (!isXTrue)
					{
						if (CheckMapXY(mapX, mapY, 0, -1, 1, -1))
						{
							PrintS(2, 7, 7, 1, mapX, mapY);
							PrintS(2, 7, 7, 1, mapX, mapY + 1);
							--mapY;
						}
					}
					else
					{
						it.ClearOperation(208, 12);
						it.PrintInfo(208, 12, currentNum = (currentNum < 2) ? currentNum : currentNum -= 1);
					}
					break;
				case DOWN_ARROW:
					if (!isXTrue)
					{
						if (CheckMapXY(mapX, mapY, 0, 2, 1, 2))
						{
							PrintS(2, 7, 7, 1, mapX, mapY);
							PrintS(2, 7, 7, 1, mapX, mapY + 1);
							++mapY;
						}
					}
					else
					{
						it.ClearOperation(208, 12);
						it.PrintInfo(208, 12, currentNum = (currentNum > 3) ? currentNum : currentNum += 1);
					}
					break;
				}
				PrintS(2, 1, 1, 1, mapX, mapY);
				PrintS(2, 1, 1, 1, mapX, mapY + 1);
				SetColor(15, 0);
			}
			else if (input == X_Key)
			{
				currentNum = 0;
				CheckXState(currentNum);
			}
			else if (input == Enter)
			{
				currentX = mapX;
				currentY = mapY;
				switch (currentNum)
				{
				case 1:
					mm.SetStack(1);
					system("cls");
					ci.ChoiceCharacter();
					break;
				case 2:
					break;
				case 3:
					mm.SetStack(1);
					system("cls");
					iw.InventoryTool();
					break;
				case 4:
					break;
				}

			}

			switch (PrintBuildingInfo())
			{
			case 1:
				if (input == Enter)
				{
					hotel.CharacterHeal(hotel.GetCharacterCount());
					isRelax = true;
					strcpy_s(message, " ȸ�� �Ϸ�                                ");
					PrintTalkMessage(207, 59, message);
					Sleep(1500);
					isRelax = false;
				}
				break;
			case 2:
				if (input == Enter)
				{
					system("cls");
					sm.PrintStoreMap();
				}
				break;
			case 9:
				if (input == Enter)
				{
					system("cls");
					mm.ms = Map_State::dungeon;
					mm.Current_Map();
				}
				break;
			}
		}
	}
}
#pragma endregion

#pragma region ���۹�, �ȳ�â
void Village::CheckXState(int num)
{
	if (!isXTrue)
	{
		it.ClearOperation(208, 12);
		it.PrintInfo(208, 12, num);
		isXTrue = true;
	}
	else
	{
		it.ClearOperation(208, 12);
		PrintOperation(208, 12);
		isXTrue = false;
	}
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
	std::cout << "�ǹ� �Ա��� ���� �Ա�";
	gotoxy(x, y + 27);
	std::cout << " �տ��� ���͸�";
	gotoxy(x, y + 28);
	std::cout << " ���� �� �ֽ��ϴ�.";
	gotoxy(x, y + 30);
	std::cout << "�÷��̾�� ���θ� �����ٴ�";
	gotoxy(x, y + 31);
	std::cout << "�� �ֽ��ϴ�.";
	gotoxy(x, y + 33);
	std::cout << "XŰ�� ���� ����â����";
	gotoxy(x, y + 34);
	std::cout << "��ȯ�� �� �ֽ��ϴ�.";
}
#pragma endregion

#pragma region ��ȭâ
int Village::PrintBuildingInfo()
{
	switch (CheckBuildingXY(mapX, mapY))
	{
	case 1:
		strcpy_s(message, " �������� ���ðڽ��ϱ�?(Hp, Mp ȸ��)      ");
		break;
	case 2:
		strcpy_s(message, " ������ ���ðڽ��ϱ�?                    ");
		break;
	case 3:
		strcpy_s(message, " ���� ���� �Ժη� ���� ���ô�.       ");
		break;
	case 4:
		break;
	case 5:
		strcpy_s(message, " ����                                   ");
		break;
	case 6:
		strcpy_s(message, " ����                                   ");
		break;
	case 7:
		strcpy_s(message, " �ֹ� ��                                ");
		break;
	case 8:
		strcpy_s(message, " ������                                 ");
		break;
	case 9:
		strcpy_s(message, " ������ �����Ͻðڽ��ϱ�?                ");
		break;
	default:
		if (!isRelax)
		{
			strcpy_s(message, " �ǹ� �̸��� �̰��� ��µ˴ϴ�.          ");
		}
		break;
	}
	PrintTalkMessage(207, 59, message);
	return CheckBuildingXY(mapX, mapY);
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
#pragma endregion

#pragma region �ǹ� ����
int Village::CheckBuildingXY(int x, int y)
{
	int num = 0;
	int divide = x / 2;
	if (y == 80)
	{
		num = 9;
		return num;
	}
	if (md.GetVillageMap()[y - 1][divide] == 0 && md.GetVillageMap()[y - 1][divide + 1] == 0)
	{
		if (divide == 26 && divide + 1 == 27 && y - 1 == 26  || 
			divide == 25 && divide + 1 == 26 && y - 1 == 26 ||
			divide == 7 && divide + 1 == 8 && y - 1 == 26 || 
			divide == 8 && divide + 1 == 9 && y - 1 == 26)
		{
			num = 3;
		}
		else if (divide == 61 && divide + 1 == 62 || divide == 62 && divide + 1 == 63)
		{
			num = 2;
		}
		else if (divide == 25 && divide + 1 == 26 && y - 1 == 65 || divide == 26 && divide + 1 == 27 && y - 1 == 65)
		{
			num = 1;
		}
		else if (divide == 83 && divide + 1 == 84 || divide == 84 && divide + 1 == 85)
		{
			num = 4;
		}
	}
	if (md.GetVillageMap()[y - 1][divide] == 13 && md.GetVillageMap()[y - 1][divide + 1] == 13)
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
	return num;
}
#pragma endregion

#pragma region �÷��̾� �̵� ���� ����
bool Village::CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count)
{
	if (md.GetVillageMap()[y1 + y1Count][((x1 / 2) + x1Count)] != 7 || md.GetVillageMap()[y1 + y2Count][((x1 / 2) + x2Count)] != 7)
		return false;

	return true;
}
#pragma endregion