#pragma once
#include "BattleMapDot.h"
#include "GameManager.h"
#include <conio.h>
#include "PrintSetting.h"

class Battle : public PrintSetting
{
private:
	BattleMapDot bmd;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintEnemyInfoText(Character* character);
	void PrintBattleMap();
};

