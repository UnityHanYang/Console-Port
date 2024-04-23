#pragma once
#include <iostream>
#include <Windows.h>
#include "Village.h"
#include "Dungeon1.h"
#include "DungeonBoss.h"

class Village;

enum Map_State
{
	village,
	dungeon,
	boss_dungeon
};

class MapManager
{
public:
	static Map_State ms;
	void Current_Map();
};
