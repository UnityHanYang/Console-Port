#include "CharacterChoice.h"
#include "MapManager.h"
#include "Store.h"
#include "GameEnding.h"
#include <iostream>
#include "GameManager.h"

void CursorView();

void main()
{
	CursorView();
	
	GameManager gm;
	gm.Start();
}


void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

