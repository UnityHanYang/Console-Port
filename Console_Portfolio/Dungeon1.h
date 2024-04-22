#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "DoubleBuffer.h"
#include <vector>

class Dungeon1 : public PrintSetting
{
private:
	int mapX;
	int mapY;
	static int enemyArrXY[6];
	static int treasureBoxXY[6];
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	void PrintOperation(int x, int y);
	bool CheckObjectXY(int x, int y, bool isEntrance);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);
	void PrintEnemy();
	void PrintTreasure();
	int CheckCurrentXY(int x, int y);

	Dungeon1();
};

