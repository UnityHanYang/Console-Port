#include "GameManager.h"

GameManager* GameManager::instance = nullptr;
std::vector<Character*> GameManager::chracterCount = {};
int GameManager::characterNum = 0;

void GameManager::RandomEnemyUnit(int enemyLevel)
{
	ArcherDot ad;
	NinjaDot nd;
	Battle bt;
	srand(time(NULL));
	int num = rand() % 2;
	GameManager* gm = GameManager::GetInstance();
	switch (enemyLevel)
	{
	case 1:
		if (num == 0)
		{
			nd.PrintEnemyLowerNinJa();
			//.PrintEnemyInfoText(gm->nj);
		}
		else if(num == 1)
		{
			nd.PrintEnemyLowerNinJa();
			//bt.PrintEnemyInfoText(gm->ah);
			//bmd.PrintEnmeyBack();
			//ad.PrintEnemyLowerArcher(156, 1);
		}
		break;
	case 2:
		break;
	case 3:
		break;
	}
}

GameManager::GameManager()
{
	nj = new NinJa("겐지", "닌자", 1, 0, 10, 60, 80, 10, 30, 4, 7, 2);
	ah = new Archer("한조", "궁수", 1, 0, 10, 70, 70, 25, 25, 6, 10, 5);
	e_nj = new EnemyNinJa("(적)하급 겐지", "닌자", 1, 0, 0, 70, 70, 0, 0, 3, 6, 0);
	e_ah = new EnemyArcher("(적)하급 한조", "궁수", 1, 0, 0, 60, 60, 0, 0, 3, 6, 0);
	e_inj = new IntermediateNInJa("(적)중급 겐지", "닌자", 7, 0, 0, 100, 100, 20, 20, 7, 10, 5);
	e_iah = new IntermediateArcher("(적)중급 한조", "궁수", 7, 0, 0, 90, 90, 20, 20, 9, 13, 8);
	e_bnj = new BossNinJa("(적)나루토", "호카게", 20, 0, 0, 300, 400, 100, 100, 17, 30, 15);
	e_bah = new BossArcher("(적)보스 한조", "궁수", 20, 0, 0, 280, 380, 120, 120, 20, 35, 20);
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
