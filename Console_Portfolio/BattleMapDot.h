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
	void PrintEnemyCurrentHpMp(Character* character, int x, int y, int hpBarCount, int mpBarCount);
	void PrintEnemyInfoText(Character* character);
	void PrintHeroHp(Character* character, int x, int y, int hpBarCount, int mpBarCount);
	void PrintConsoleText(const char* text1, const char* text2, const char* text3, const char* text4, const char* text5, const char* text6, int x, int y);
};

