#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "Character.h"

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
	void PrintHpTool(int x, int y);
	void PrintEnemyCurrentHpMp(Character* character, int x, int y);
	void PrintEnemyInfoText(Character* character);
	void PrintHeroHp(Character* character, int x, int y);
	void PrintConsoleText(const char* text, int x, int y);
};

