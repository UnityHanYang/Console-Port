#include "DungeonBoss.h"

int DungeonBoss::enemyArrXY[4] = { 30, 60, 80, 70 };

int DungeonBoss::currentX = 0;
int DungeonBoss::currentY = 0;
bool DungeonBoss::isXTrue = false;
int DungeonBoss::currentNum = 0;

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13
#define X_Key 120

#pragma region 상속 메서드
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
		std::cout << "ㅁ";
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
#pragma endregion

#pragma region 맵 출력, 플레이어 이동
void DungeonBoss::PrintMapAndCharMove(int x, int y)
{
	CharacterInfo ci;
	MapManager mm;
	ItemInventoryWindow iw;
	GameManager* gm = GameManager::GetInstance();
	Dungeon1 dg;
	int xCpy, yCpy;
	xCpy = yCpy = 0;

	md.SettingDungeonBossMap();

	md.PrintDungeonBossMap();
	SetColor(15, 0);
	md.PrintOperation_Keys(206, 10);
	PrintEnemy();
	PrintS(2, 1, 1, 1, x, y);
	PrintS(2, 1, 1, 0, x, y + 1);
	SetColor(15, 0);

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
	while (running)
	{
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
							if (!isXTrue)
							{
								if (CheckMapXY(mapX, mapY, -1, 0, -1, 1))
								{
									xCpy = mapX;
									yCpy = mapY;
									mapX -= 2;
								}
							}
							break;
						case RIGHT_ARROW:
							if (!isXTrue)
							{
								if (CheckMapXY(mapX, mapY, 2, 0, 2, 1))
								{
									xCpy = mapX;
									yCpy = mapY;
									mapX += 2;
								}
							}
							break;
						case UP_ARROW:
							if (!isXTrue)
							{
								if (CheckMapXY(mapX, mapY, 0, -1, 1, -1))
								{
									xCpy = mapX;
									yCpy = mapY;
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
									xCpy = mapX;
									yCpy = mapY;
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
						PrintS(1, CheckCurrentXY(xCpy, yCpy), CheckCurrentXY(xCpy, yCpy), 0, xCpy, yCpy);
						PrintS(1, CheckCurrentXY(xCpy + 2, yCpy), CheckCurrentXY(xCpy + 2, yCpy), 1, xCpy + 2, yCpy);
						PrintS(1, CheckCurrentXY(xCpy, yCpy + 1), CheckCurrentXY(xCpy, yCpy + 1), 0, xCpy, yCpy + 1);
						PrintS(1, CheckCurrentXY(xCpy + 2, yCpy + 1), CheckCurrentXY(xCpy + 2, yCpy + 1), 1, xCpy + 2, yCpy + 1);
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
							mm.SetStack(3);
							system("cls");
							ci.ChoiceCharacter();
							break;
						case 2:
							break;
						case 3:
							mm.SetStack(3);
							system("cls");
							iw.InventoryTool();
							break;
						case 4:
							break;
						}

					}
					if (CheckDungeonDoorXY(mapX, mapY))
					{
						if (input == Enter)
						{
							system("cls");
							dg.SetIsReturn(true);
							dg.SetIsPush(false);
							mm.ms = Map_State::dungeon;
							mm.Current_Map();
							break;
						}
					}
				}
			}
			else
			{
				currentX = mapX;
				currentY = mapY;
				system("cls");
				gm->RandomEnemyUnit(2);
				mm.ms = Map_State::battle;
				mm.Current_Map();
				break;

			}
		}
	}
}
#pragma endregion

#pragma region 조작법, 안내창
void DungeonBoss::PrintOperation(int x, int y)
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
	std::cout << ": 횟불";
	gotoxy(x, y + 6);
	SetColor(2, 2);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 의자";
	gotoxy(x, y + 8);
	SetColor(5, 5);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 적";
	gotoxy(x, y + 10);
	SetColor(6, 6);
	std::cout << "ㅁ";
	SetColor(15, 0);
	std::cout << ": 보스";
	gotoxy(x, y + 12);
	std::cout << "플레이어 조작";
	gotoxy(x, y + 14);
	std::cout << "   →: 오른쪽 이동";
	gotoxy(x, y + 15);
	std::cout << "   ←: 왼쪽 이동";
	gotoxy(x, y + 16);
	std::cout << "   ↑: 위쪽 이동";
	gotoxy(x, y + 17);
	std::cout << "   ↓: 아래쪽 이동";
	gotoxy(x, y + 19);
	std::cout << "Enter: 선택";
	gotoxy(x, y + 21);
	std::cout << "보스 앞에서 엔터를";
	gotoxy(x, y + 22);
	std::cout << "를 수 있습니다.";
	gotoxy(x, y + 24);
	std::cout << "용암을 밟으면 HP가";
	gotoxy(x, y + 25);
	std::cout << "감소합니다. 유의하세요!";
}

void DungeonBoss::CheckXState(int num)
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

bool DungeonBoss::CheckDungeonDoorXY(int x, int y)
{
	if (md.GetDungeonBossMap()[y + 2][x / 2] == 0 && md.GetDungeonBossMap()[y + 2][(x / 2) + 1] == 0)
	{
		return true;
	}
	return false;
}
#pragma endregion

#pragma region 체력 감소
void DungeonBoss::HpMinus()
{
	while (running)
	{
		if (CheckLavaZone(mapX, mapY))
		{
			GameManager* gm = GameManager::GetInstance();
			(gm->GetCharacter() == 1) ? gm->nj->SetCurrentHp(-2), std::this_thread::sleep_for(std::chrono::milliseconds(1000)) : gm->ah->SetCurrentHp(-2), std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
#pragma endregion

#pragma region 멀티스레드
void DungeonBoss::BossDungeonMultiThread()
{
	std::thread mainThread(&DungeonBoss::PrintMapAndCharMove, this, 162, 77);
	std::thread checkLavaZoneThread(&DungeonBoss::HpMinus, this);
	mainThread.join();
	checkLavaZoneThread.join();
}
#pragma endregion

#pragma region 플레이어 이동 제약 사항
bool DungeonBoss::CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count)
{
	SetColor(15, 0);
	if (md.GetDungeonBossMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 8 || md.GetDungeonBossMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 8 ||
		md.GetDungeonBossMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 2 || md.GetDungeonBossMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 2 ||
		md.GetDungeonBossMap()[y1 + y1Count][((x1 / 2) + x1Count)] == 6 || md.GetDungeonBossMap()[y1 + y2Count][((x1 / 2) + x2Count)] == 6)
		return false;

	return true;
}
#pragma endregion

#pragma region 충돌 감지
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

#pragma endregion

#pragma region 적 생성
void DungeonBoss::PrintEnemy()
{
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		PrintS(2, 5, 5, 1, enemyArrXY[i], enemyArrXY[i + 1]);
		PrintS(2, 5, 5, 0, enemyArrXY[i], enemyArrXY[i + 1] + 1);
	}
}
#pragma endregion

#pragma region 현재 위치 체크, 용암 감지
int DungeonBoss::CheckCurrentXY(int x, int y)
{
	int num = 0;
	if (md.GetDungeonBossMap()[y][x / 2] == 12)
	{
		num = 12;
		return num;
	}
	else if (md.GetDungeonBossMap()[y][x / 2] == 4)
	{
		num = 4;
		return num;
	}
	return 0;
}

bool DungeonBoss::CheckLavaZone(int x, int y)
{
	if (md.GetDungeonBossMap()[y][x / 2] == 4 || md.GetDungeonBossMap()[y][(x / 2) + 1] == 4 ||
		md.GetDungeonBossMap()[y + 1][x / 2] == 4 || md.GetDungeonBossMap()[y + 1][(x / 2) + 1] == 4)
	{
		return true;
	}
	return false;
}
#pragma endregion