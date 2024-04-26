#include "MapManager.h"

std::stack<int> MapManager::s_map = { };
Map_State MapManager::ms = Map_State::village;

#pragma region ∏  ¿Ãµø(enum, stack)
void MapManager::Current_Map()
{
	Village vg;
	Dungeon1 dg;
	DungeonBoss db;
	Battle bt;
	if (ms == Map_State::village)
	{
		vg.PrintMapAndCharMove(96, 80);
	}
	else if (ms == Map_State::dungeon)
	{
		dg.PrintMapAndCharMove(16, 78);
	}
	else if (ms == Map_State::boss_dungeon)
	{
		db.PrintMapAndCharMove(162, 79);
	}
	else if (ms == Map_State::battle)
	{
		bt.PrintBattleMap();
	}
}

void MapManager::Current_StackMap()
{
	Village vg;
	CharacterInfo ci;
	if (!s_map.empty())
	{
		int a = s_map.top();
		s_map.pop();
		switch (a)
		{
		case 1:
			vg.PrintMapAndCharMove(vg.GetCurrentX(), vg.GetCurrentY());
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			ci.ChoiceCharacter();
			break;
		}
	}
}
#pragma endregion