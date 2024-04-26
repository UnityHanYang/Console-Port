#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>

class ArcherDot : public PrintSetting
{
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintArcher(int x, int y);
	void PrintEnemyLowerArcher(int x, int y);
	void PrintIntermediateArcher(int x, int y);
	void PrintBossArcher(int x, int y);
	void PrintArcherPortrait(int x, int y);
};