#include "MapManager.h"

std::stack<int> MapManager::s_map = { };
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

void MapManager::Current_StackMap()
{
	if (!s_map.empty())
	{
		int a = s_map.top();
		switch (a)
		{
		case 1:
			vg->PrintMapAndCharMove(1, 1);
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
			ci->ChoiceCharacter();
			break;
		case 7:
			break;
		default:
			break;
		}
		s_map.pop();
	}
}

MapManager::MapManager()
{
	vg = new Village;
	ci = new CharacterInfo;
}

MapManager::~MapManager()
{
	delete vg;
	delete ci;
}
