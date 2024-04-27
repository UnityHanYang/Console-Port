#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"

class BattleMapDot : public PrintSetting
{
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintSoloBattleMap();
	void PrintMultiBattleMap();
	void PrintEnemyInfoTool();
	void PrintEnmeyBack();
};

