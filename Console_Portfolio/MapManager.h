#pragma once
#include <iostream>
#include <Windows.h>
#include "Village.h"
#include "Dungeon1.h"
#include "DungeonBoss.h"
#include "Dungeon1.h"
#include "DungeonBoss.h"
#include "CharacterInfo.h"
#include "Village.h"
#include <stack>

class Village;

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
	Village* vg;
	CharacterInfo* ci;
	static Map_State ms;
	void Current_Map();
	void Current_StackMap();
	std::stack<int> GetStack() { return s_map; }

	MapManager();
	~MapManager();
};
