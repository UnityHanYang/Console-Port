#include "MapDot.h"
#include "PrintSetting.h"
#include "CharacterChoice.h"
#include "MapManager.h"
#include <iostream>
#include "NinJa.h"
#include "test.h"

void CursorView();

void main()
{
	//ms->PrintMain();
	CharacterChoice cc;
	//md.PrintMap();
	//ci.PrintNinZaPortrait1(36, 55);
	//bt.PrintBattleMap();
	//ad.PrintArcherPortrait1(40, 7);
	//md.PrintEnmeyBack();
	//ci.PrintNinZa1();
	CursorView();
	//NinJa* nj = new NinJa("°ÕÁö", "±Ã¼ö", 30, 30, 4, 10, 4);
	//NinJa* nja = new NinJa("°ÕÁö", "±Ã¼ö", 50, 30, 4, 10, 4);
	test* tes = new test;
	std::cout << tes->nj->GetHp();
	//std::cout << nj->GetHp() << ",  " << nja->GetHp();
	/*if (cc.ChoiceScene())
	{
		MapManager* mm = new MapManager;
		mm->Current_Map();
		delete mm;
	}*/
	//ad.PrintArcher1(60, 1);
	/*Player p("Àü»ç", 3, 3, 3);
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
