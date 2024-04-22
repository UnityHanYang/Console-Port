#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"

#define COL_SIZE 100
#define ROW_SIZE 82

class MapDot : public PrintSetting
{
private:
	static int villageMap[ROW_SIZE][COL_SIZE];
	static int villageNextMap[ROW_SIZE][COL_SIZE];
	static int dungeonMap[ROW_SIZE][COL_SIZE];
	static int dungeonBossMap[ROW_SIZE][COL_SIZE];
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void SettingVillageMap();
	void SettingDungeonMap();
	void SettingDungeonBossMap();
	void PrintOperation_Keys(int x, int y);
	void PrintVillageMap();
	void PrintDungeonMap();
	void PrintDungeonBossMap();
	void PrintConsole(int x, int y);
	int(*GetVillageMap())[100] { return villageMap; }
	int(*GetVillageNextMap())[100]{ return villageNextMap; }
	int(*GetDungeonMap())[100]{ return dungeonMap; }
	int(*GetDungeonBossMap())[100]{ return dungeonBossMap; }
};

