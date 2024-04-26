#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "DungeonBoss.h"
#include "MapManager.h"
#include <vector>

class Dungeon1 : public PrintSetting
{
private:
	int mapX;
	int mapY;
	static int enemyArrXY[6];
	static int treasureBoxXY[6];
	MapDot md;
	DungeonBoss db;
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

	void PrintTalkMessage(int x, int y, char message[50]);

	Dungeon1() : mapX{ 0 }, mapY{ 0 } {}
};

