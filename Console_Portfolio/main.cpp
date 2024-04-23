#include "PrintSetting.h"
#include "CharacterChoice.h"
#include "MapManager.h"
#include <iostream>

void CursorView();

void main()
{
	CharacterChoice cc;
	std::cout << "asdf";
	CursorView();
	if (cc.ChoiceScene())
	{
		MapManager* mm = new MapManager;
		mm->Current_Map();
		delete mm;
	}
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
