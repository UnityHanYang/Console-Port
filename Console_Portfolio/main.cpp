#include "MapDot.h"
#include "PrintSetting.h"
#include "Player.h"
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "CharacterChoice.h"
#include "Battle.h"
#include "DoubleBuffer.h"
#include "MapManager.h"
#include <iostream>

void CursorView();

void main()
{
	//ms->PrintMain();
	NinjaDot ci;
	ArcherDot ad;
	MapDot md;
	Battle bt;
	CharacterChoice cc;
	//md.PrintMap();
	//ci.PrintNinZaPortrait1(36, 55);
	//bt.PrintBattleMap();
	//ad.PrintArcherPortrait1(40, 7);
	//md.PrintEnmeyBack();
	//ci.PrintNinZa1();
	CursorView();
	if (cc.ChoiceScene())
	{
		MapManager* mm = new MapManager;
		mm->Current_Map();
		delete mm;
	}
	//ad.PrintArcher1(60, 1);
	/*Player p("ภüป็", 3, 3, 3);
	std::cout << p.GetHp() << ",  " << p.GetName();
	ASDF as;
	as.GetHp();*/
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
