#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "DungeonBoss.h"
#include "MapManager.h"
#include "InformationTool.h"
#include "ItemInventoryWindow.h"
#include "CharacterInfo.h"
#include <vector>
#include <thread>

class Dungeon1 : public PrintSetting
{
private:
	int mapX;
	int mapY;
	static int treasureBoxXY[6];
	static std::vector<int> enemyArrXY;
	static int currentX;
	int c_EnemyArrXY[6];
	static int currentY;
	InformationTool it;
	static bool isXTrue;
	static int currentNum;
	static int currentEnemyIndex;
	MapDot md;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	void PrintOperation(int x, int y);
	bool CheckEnemyXY(int x, int y);
	void CheckTreasureXY(int x, int y);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);
	void PrintEnemy();
	void PrintTreasure();
	int CheckCurrentXY(int x, int y);
	bool CheckEntranceXY(int x, int y);
	void CheckXState(int num);
	int GetCurrentX() { return currentX; }
	int GetCurrentY() { return currentY; }
	bool GetIsXTrue() { return isXTrue; }
	int GetCurrentEnemyIndex() {return currentEnemyIndex; }

	void SetEnemyArrXY(int index) { enemyArrXY.erase(enemyArrXY.begin() + index); enemyArrXY.erase(enemyArrXY.begin() + index+1); }
	void HpMinus();
	void DungeonMultiThread();
	bool CheckLavaZone(int x, int y);
	std::atomic<bool> running{ true };

	void PrintTalkMessage(int x, int y, char message[50]);

	Dungeon1() : mapX{ 0 }, mapY{ 0 }, c_EnemyArrXY{}
	{
		enemyArrXY.push_back(140);
		enemyArrXY.push_back(36);
		enemyArrXY.push_back(32);
		enemyArrXY.push_back(60);
		enemyArrXY.push_back(120);
		enemyArrXY.push_back(15);
	}
};

