#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "DoubleBuffer.h"
class DungeonBoss : public PrintSetting
{
private:
	int mapX;
	int mapY;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	void PrintOperation(int x, int y);
	int CheckObjectXY(int x, int y, bool isEntrance);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);

	DungeonBoss();
};

