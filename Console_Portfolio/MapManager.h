#pragma once
#include <iostream>
#include <Windows.h>
#include "Village.h"
#include "Dungeon1.h"
#include "DungeonBoss.h"
#include "CharacterInfo.h"
#include <stack>

enum Map_State
{
	village,
	dungeon,
	boss_dungeon
};

class MapManager
{
private:
	static std::stack<int> s_map;
	
public:
	static Map_State ms;
	void Current_Map();
	void Current_StackMap();
	std::stack<int> GetStack() { return s_map; }
	void SetStack(int num) { s_map.push(num); }

	MapManager();

};
