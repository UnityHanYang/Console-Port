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

#pragma region 상속 메서드
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
#pragma endregion

#pragma region 맵 출력, 플레이어 이동
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
					strcpy_s(message, " 회복 완료                                ");
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

#pragma region 조작법, 안내창
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
	std::cout << "건물 입구나 던전 입구";
	gotoxy(x, y + 27);
	std::cout << " 앞에서 엔터를";
	gotoxy(x, y + 28);
	std::cout << " 누를 수 있습니다.";
	gotoxy(x, y + 30);
	std::cout << "플레이어는 도로만 지나다닐";
	gotoxy(x, y + 31);
	std::cout << "수 있습니다.";
	gotoxy(x, y + 33);
	std::cout << "X키를 눌러 정보창으로";
	gotoxy(x, y + 34);
	std::cout << "전환할 수 있습니다.";
}
#pragma endregion

#pragma region 대화창
int Village::PrintBuildingInfo()
{
	switch (CheckBuildingXY(mapX, mapY))
	{
	case 1:
		strcpy_s(message, " 여관에서 쉬시겠습니까?(Hp, Mp 회복)      ");
		break;
	case 2:
		strcpy_s(message, " 상점을 여시겠습니까?                    ");
		break;
	case 3:
		strcpy_s(message, " 남의 집에 함부로 들어가지 맙시다.       ");
		break;
	case 4:
		break;
	case 5:
		strcpy_s(message, " 여관                                   ");
		break;
	case 6:
		strcpy_s(message, " 상점                                   ");
		break;
	case 7:
		strcpy_s(message, " 주민 집                                ");
		break;
	case 8:
		strcpy_s(message, " 도박장                                 ");
		break;
	case 9:
		strcpy_s(message, " 던전에 입장하시겠습니까?                ");
		break;
	default:
		if (!isRelax)
		{
			strcpy_s(message, " 건물 이름은 이곳에 출력됩니다.          ");
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

#pragma region 건물 감지
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

#pragma region 플레이어 이동 제약 사항
bool Village::CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count)
{
	if (md.GetVillageMap()[y1 + y1Count][((x1 / 2) + x1Count)] != 7 || md.GetVillageMap()[y1 + y2Count][((x1 / 2) + x2Count)] != 7)
		return false;

	return true;
}
#pragma endregion