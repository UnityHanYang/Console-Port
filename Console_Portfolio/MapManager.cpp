#include "MapManager.h"

Map_State MapManager::ms = Map_State::village;

void MapManager::Current_Map()
{
	Village vg;
	Dungeon1 dg;
	DungeonBoss db;
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
}