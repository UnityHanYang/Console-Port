#pragma once
#include "PrintSetting.h"
#include "NinJa.h"
#include "Archer.h"
#include "EnemyNinJa.h"
#include "EnemyArcher.h"


class GameManager
{
public:
	NinJa* nj;
	Archer* ah;
	EnemyNinJa* e_nj;
	EnemyArcher* e_ah;
	IntermediateNInJa* e_inj;
	IntermediateArcher* e_iah;
	BossNinJa* e_bnj;
	BossArcher* e_bah;

	GameManager();
	~GameManager();
};

