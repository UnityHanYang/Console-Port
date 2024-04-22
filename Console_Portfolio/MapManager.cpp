#include "MapManager.h"

void MapManager::Current_Map()
{
	Village* vg = new Village;
	Dungeon1* dg = new Dungeon1;
	DungeonBoss* db = new DungeonBoss;

	//db->PrintMapAndCharMove(95, 50);
	delete db;
	dg->PrintMapAndCharMove(16, 78);
	delete dg;
	//vg->PrintMapAndCharMove(96, 80);
	delete vg;
}
