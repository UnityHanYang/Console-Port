#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "DoubleBuffer.h"
#include <string.h>
class Village : public PrintSetting
{
private:
	int mapX;
	int mapY;
	char message[50];
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	void PrintOperation(int x, int y);
	void PrintBuildingName();
	int CheckBuildingXY(int x, int y, bool isEntrance);
	void PrintTalkMessage(int x, int y, char message[50]);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);

	Village();
};

