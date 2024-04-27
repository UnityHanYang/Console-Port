#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <conio.h>
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "MapDot.h"
#include "MapManager.h"
#include "NinJa.h"
#include "Archer.h"
#include "GameManager.h"
#include "CharacterBackGround.h"

class CharacterChoice : public PrintSetting
{
private:
	NinjaDot nd;
	ArcherDot ad;
	MapDot md;
	CharacterBackGround cbg;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	bool ChoiceScene();
	void ReadMore(int num);
	void PrintOperate(int x, int y);
	void PrintCharacterAbility(int num);
	void PrintAbilityTool(int x, int y);

};

