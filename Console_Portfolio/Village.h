#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "MapManager.h"
#include "CharacterInfo.h"
#include "InformationTool.h"
#include "StoreMap.h"
#include "ItemInventoryWindow.h"


class Village : public PrintSetting
{
private:
	int mapX;
	int mapY;
	static int currentX;
	static int currentY;
	static bool isXTrue;
	static int currentNum;
	char message[48] = {};
	int infoArr[8] = {};
	MapDot md;
	InformationTool it;
public:
	void PrintOperation(int x, int y);
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	int PrintBuildingInfo();
	int CheckBuildingXY(int x, int y);
	void PrintTalkMessage(int x, int y, char message[50]);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);
	void CheckXState(int num);
	int GetCurrentX() { return currentX; }
	int GetCurrentY() { return currentY; }
	bool GetIsXTrue() { return isXTrue; }

	Village() : mapX{ 0 }, mapY{ 0 }, message{}, infoArr{ 28, 29, 59, 60, 22, 23, 72, 73 } {};
};

