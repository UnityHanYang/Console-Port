#pragma once
#include "BattleMapDot.h"
#include "GameManager.h"
#include <conio.h>
#include "PrintSetting.h"
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "Character.h"
#include "MapDot.h"

class Battle : public PrintSetting
{
private:
	BattleMapDot bmd;
	NinjaDot nd;
	ArcherDot ad;
	MapDot md;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintBattleMap();
	void PrintOption(int num, int x, int y);
};

