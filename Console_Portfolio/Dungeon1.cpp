#include "Dungeon1.h"

int Dungeon1::treasureBoxXY[6] = { 10, 3, 182, 51, 88, 7 };
std::vector<int> Dungeon1::enemyArrXY = {};
bool Dungeon1::isReturn = false;
bool Dungeon1::isEnemyKill = false;

bool Dungeon1::isXTrue = false;
bool Dungeon1::isPush = false;
int Dungeon1::currentNum = 0;
int Dungeon1::currentEnemyIndex = 0;
int Dungeon1::currentX = 0;
int Dungeon1::currentY = 0;

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13
#define X_Key 120

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
	if (!isPush)
	{
		VecInit();
		isPush = true;
	}
	MapManager mm;
	CharacterInfo ci;
	ItemInventoryWindow iw;
	SkillWindow sw;
	GameManager* gm = GameManager::GetInstance();
	md.PrintDungeonMap();
	SetColor(15, 0);
	md.PrintOperation_Keys(206, 10);
	PrintEnemy();
	PrintTreasure();
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
						CheckTreasureXY(mapX, mapY);
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
							mm.SetStack(2);
							system("cls");
							ci.ChoiceCharacter();
							break;
						case 2:
							mm.SetStack(1);
							system("cls");
							sw.SkillTool();
							break;
						case 3:
							mm.SetStack(2);
							system("cls");
							iw.InventoryTool();
							break;
						case 4:
							break;
						}

					}
					if (CheckEntranceXY(mapX, mapY))
					{
						if (input == Enter)
						{
							system("cls");
							mm.ms = Map_State::boss_dungeon;
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
				gm->RandomEnemyUnit(1);
				mm.ms = Map_State::battle;
				mm.Current_Map();
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

#pragma region 체력 감소
void Dungeon1::VecInit()
{
	enemyArrXY.clear();
	enemyArrXY.push_back(140);
	enemyArrXY.push_back(36);
	enemyArrXY.push_back(32);
	enemyArrXY.push_back(60);
	enemyArrXY.push_back(120);
	enemyArrXY.push_back(15);
}
void Dungeon1::SetEnemyArrXY(int index)
{
	if (!enemyArrXY.empty())
	{
		enemyArrXY.erase(enemyArrXY.begin() + index);
		enemyArrXY.erase(enemyArrXY.begin() + index);
	}
}
void Dungeon1::HpMinus()
{
	GameManager* gm = GameManager::GetInstance();
	while (running)
	{
		if (CheckLavaZone(mapX, mapY))
		{
			if (gm->GetCharacter() == 1)
			{
				gm->nj->SetCurrentHp(-2);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			else
			{
				gm->ah->SetCurrentHp(-2);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	}
}
#pragma endregion

#pragma region 멀티스레드
void Dungeon1::DungeonMultiThread()
{
	if (isReturn)
	{
		std::thread mainThread(&Dungeon1::PrintMapAndCharMove, this, 162, 5);
		isReturn = false;
		std::thread checkLavaZoneThread(&Dungeon1::HpMinus, this);
		mainThread.join();
		checkLavaZoneThread.join();
	}
	else
	{
		if (isEnemyKill)
		{
			std::thread mainThread(&Dungeon1::PrintMapAndCharMove, this, currentX, currentY);
			std::thread checkLavaZoneThread(&Dungeon1::HpMinus, this);
			mainThread.join();
			checkLavaZoneThread.join();
			isEnemyKill = false;
		}
		else
		{
			std::thread mainThread(&Dungeon1::PrintMapAndCharMove, this, 16, 78);
			std::thread checkLavaZoneThread(&Dungeon1::HpMinus, this);
			mainThread.join();
			checkLavaZoneThread.join();
		}
	}
}
#pragma endregion

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

void Dungeon1::CheckXState(int num)
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
	if (!enemyArrXY.empty())
	{
		char message[50] = {};
		std::vector<int>::iterator iter;
		int num = 0;
		for (iter = enemyArrXY.begin(); iter != enemyArrXY.end(); iter += 2)
		{
			if (iter + 1 != enemyArrXY.end())
			{
				RECT playerSquare = { x - 1, y - 1, x + 3, y + 2 };
				RECT enemySquare = { *iter, *(iter + 1), *iter + 2, *(iter + 1) + 1 };
				RECT intersect;

				if (IntersectRect(&intersect, &playerSquare, &enemySquare)) {
					currentEnemyIndex = num;
					return true;
				}
				num += 2;
			}
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
	std::vector<int>::iterator iter;
	for (iter = enemyArrXY.begin(); iter != enemyArrXY.end(); iter += 2)
	{
		if (iter + 1 != enemyArrXY.end())
		{
			PrintS(2, 5, 5, 1, *(iter), *(iter + 1));
			PrintS(2, 5, 5, 0, *(iter), *(iter + 1) + 1);
		}
	}
}

void Dungeon1::PrintTreasure()
{
	for (int i = 0; i < sizeof(enemyArrXY) / sizeof(enemyArrXY[0]); i += 2)
	{
		//PrintS(2, 14, 14, 1, treasureBoxXY[i], treasureBoxXY[i + 1]);
	}
}

#pragma endregion

#pragma region 현재 위치, 던전 입구 감지, 용암 감지
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

bool Dungeon1::CheckLavaZone(int x, int y)
{
	//SetColor(13, 0);
	//std::cout << (x/2) << ",  " << y << std::endl;
	/*std::cout << md.GetDungeonMap()[y][x / 2] << std::endl;
	std::cout << md.GetDungeonMap()[y][(x / 2) + 1] << std::endl;
	std::cout << md.GetDungeonMap()[y + 1][x / 2] q	sssssssssssss<< std::endl;
	std::cout << md.GetDungeonMap()[y + 1][(x / 2) + 1] << std::endl;*/
	Sleep(3000);
	if (md.GetDungeonMap()[y][(x / 2) + 1] == 4 || md.GetDungeonMap()[y][(x / 2) + 2] == 4 ||
		md.GetDungeonMap()[y + 1][(x / 2) + 1] == 4 || md.GetDungeonMap()[y + 1][(x / 2) + 2] == 4)
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