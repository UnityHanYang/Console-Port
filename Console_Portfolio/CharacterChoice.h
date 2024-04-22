#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <conio.h>
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "MapDot.h"
#include "Battle.h"
#include "MapManager.h"


class CharacterChoice : public PrintSetting
{
private:
	static int characterNum;
public:

	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	bool ChoiceScene();
	void ReadMore(int num);
	void PrintBackGround(int font, int background, int x, int y);
	void PrintOperate(int x, int y);
	void PrintNinjarBackGround();
	void PrintCharacterAbility(int num);
	void PrintAbilityTool(int x, int y);
	int GetCharacter() { return characterNum; }
	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(int x, int y, std::string s);
	void Render();
};

