#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "Dungeon1.h"
#include "MapManager.h"
#include "CharacterInfo.h"
#include "InformationTool.h"

class Dungeon1;
class MapManager;
class CharacterInfo;

class Village : public PrintSetting
{
private:
	int mapX;
	int mapY;
	static int currentX;
	static int currentY;
	char message[48] = {};
	int infoArr[8] = {};
public:
	MapDot* md;
	Dungeon1* dg;
	MapManager* mm;
	CharacterInfo* ci;
	InformationTool* it;
	void PrintOperation(int x, int y);
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	bool PrintBuildingInfo();
	int CheckBuildingXY(int x, int y);
	void PrintTalkMessage(int x, int y, char message[50]);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);
	void CheckXState(int num);
	int GetCurrentX() { return currentX; }
	int GetCurrentY() { return currentY; }

	Village();
	~Village();
};

