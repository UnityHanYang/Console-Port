#pragma once
class PrintSetting
{
public:
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y) = 0;
	virtual void SetColor(int fontColor, int backgroundColor) = 0;
	virtual void gotoxy(int x, int y) = 0;
};

