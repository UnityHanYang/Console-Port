#pragma once
#include "PrintSetting.h"
#include "NinJa.h"
#include "Archer.h"


class GameManager
{
public:
	NinJa* nj;
	Archer* ah;
	void GameScene();

	GameManager();
	~GameManager();
};

