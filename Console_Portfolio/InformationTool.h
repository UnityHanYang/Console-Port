#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>

class InformationTool : public PrintSetting
{
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void ClearOperation(int x, int y);
	void PrintInfo(int x, int y, int num);
};

