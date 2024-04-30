#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>
#include "Player.h"
#include "MapManager.h"

class Casino
{
private:
	Player* player;
public:
	void PlayGame();
	int GetResult(std::string ranNum, int bettingMoney);

	Casino();
	~Casino();
};

