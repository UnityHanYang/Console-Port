#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>

class NinjaDot : public PrintSetting
{
public:
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void gotoxy(int x, int y);
	void PrintNinZa1();
	void PrintNinZa2();
	void PrintNinZa3();
	void PrintNinZaPortrait1(int x, int y);
};

