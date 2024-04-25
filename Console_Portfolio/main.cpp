#include "PrintSetting.h"
#include "CharacterChoice.h"
#include "MapManager.h"
#include "Store.h"
#include <iostream>

void CursorView();
void DeleteItem();

void main()
{
	CharacterChoice cc;
	CursorView();
	if (cc.ChoiceScene())
	{
		MapManager* mm = new MapManager;
		mm->Current_Map();
		delete mm;
	}
	DeleteItem();
}

void DeleteItem()
{
	Store* store = new Store;
	for (Item* item : store->GetItemVec())
	{
		delete item;
	}
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
