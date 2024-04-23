#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "Dungeon1.h"
#include "MapManager.h"

class MapManager;
class Dungeon1;

class Village : public PrintSetting
{
private:
	int mapX;
	int mapY;
	char message[48] = {};
	int infoArr[8] = {};
public:
	MapDot* md;
	Dungeon1* dg;
	MapManager* mm;
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	void PrintOperation(int x, int y);
	bool PrintBuildingInfo();
	int CheckBuildingXY(int x, int y);
	void PrintTalkMessage(int x, int y, char message[50]);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);

	Village();
	~Village();
};

