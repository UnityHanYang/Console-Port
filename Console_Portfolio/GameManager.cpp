#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
{
	nj = new NinJa("겐지", "닌자");
	ah = new Archer("한조", "궁수");
	e_nj = new EnemyNinJa("(적)하급 겐지", "닌자");
	e_ah = new EnemyArcher("(적)하급 한조", "궁수");
	e_inj = new IntermediateNInJa("(적)중급 겐지", "닌자");
	e_iah = new IntermediateArcher("(적)중급 한조", "궁수");
	e_bnj = new BossNinJa("(적)나루토", "호카게");
	e_bah = new BossArcher("(적)보스 한조", "궁수");
}

GameManager::~GameManager()
{
	delete nj;
	delete ah;
	delete e_nj;
	delete e_ah;
	delete e_inj;
	delete e_iah;
	delete e_bnj;
	delete e_bah;
}
