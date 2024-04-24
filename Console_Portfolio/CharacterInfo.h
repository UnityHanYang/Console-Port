#pragma once
#include <iostream>
#include "PrintSetting.h"
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "Battle.h"
#include <Windows.h>
#include "MapDot.h"
#include <conio.h>
#include "CharacterChoice.h"
#include "GameManager.h"


class CharacterInfo : public PrintSetting
{
private:
	static bool isJoin;
	NinjaDot nd;
	ArcherDot ad;
	Battle bt;
	MapDot md;
	GameManager gm;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void CharacterOne();
	void CharacterTwo();
	void ReadMore(int num);
	void ChoiceCharacter();
	void PrintBackOperate(int x, int y);
	bool GetJoinWhether() { return isJoin; }
	void SetJoinWhether(bool b_Value) { isJoin = b_Value; }
	void PrintCharacterAbility(int num);
	void PrintOperate(int x, int y);

	CharacterInfo();
};

