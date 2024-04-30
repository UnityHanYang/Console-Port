#include "GameManager.h"

GameManager* GameManager::instance = nullptr;
std::vector<Character*> GameManager::chracterCount = {};
int GameManager::characterNum = 0;
int GameManager::enemyLevelNum = 0;
int GameManager::randomNum = 0;

void GameManager::Start()
{
	MainScene ms;
	ms.PrintMainMap();
}

void GameManager::Update()
{
	CharacterChoice cc;
	if (cc.ChoiceScene())
	{
		MapManager* mm = new MapManager;
		mm->Current_Map();
		delete mm;
	}
	DeleteItem();
}

void GameManager::DeleteItem()
{
	Store* store = new Store;
	for (Item* item : store->GetItemVec())
	{
		delete item;
	}
}

void GameManager::RandomEnemyUnit(int enemyLevel)
{
	ArcherDot ad;
	NinjaDot nd;
	Battle bt;
	srand(time(NULL));
	int num = rand() % 2;
	enemyLevelNum = enemyLevel;
	switch (enemyLevel)
	{
	case 1:
		if (num == 0)
		{
			e_nj = new EnemyNinJa("(적)하급 겐지", "닌자", 1, 0, 0, 70, 70, 10, 10, 2, 6);
			nd.PrintEnemyLowerNinJa();
			randomNum = num;
		}
		else if(num == 1)
		{
			e_ah = new EnemyArcher("(적)하급 한조", "궁수", 1, 0, 0, 60, 60, 10, 10, 2, 6);
			bmd.PrintEnmeyBack();
			ad.PrintEnemyLowerArcher(156, 1);
			randomNum = num;
		}
		break;
	case 2:
		if (num == 0)
		{
			e_inj = new IntermediateNInJa("(적)중급 겐지", "닌자", 7, 0, 0, 100, 100, 20, 20, 5, 10);
			nd.PrintIntermediateNinJa();
			randomNum = num;
		}
		else if (num == 1)
		{
			e_iah = new IntermediateArcher("(적)중급 한조", "궁수", 7, 0, 0, 90, 90, 20, 20, 6, 13);
			bmd.PrintEnmeyBack();
			ad.PrintIntermediateArcher(156, 1);
			randomNum = num;
		}
		break;
	case 3:
		e_bnj = new BossNinJa("(적)나루토", "호카게", 20, 0, 0, 400, 400, 100, 100, 10, 30); 
		nd.PrintBossNinJa();
		randomNum = 1;
		break;
	}
}

GameManager::GameManager()
{
	nj = new NinJa("겐지", "닌자", 1, 0, 10, 80, 80, 30, 30, 2, 7);
	ah = new Archer("한조", "궁수", 1, 0, 10, 70, 70, 25, 25, 3, 10);
	e_nj = new EnemyNinJa("(적)하급 겐지", "닌자", 1, 0, 0, 70, 70, 10, 10, 2, 6);
	e_ah = new EnemyArcher("(적)하급 한조", "궁수", 1, 0, 0, 60, 60, 10, 10, 2, 6);
	e_inj = new IntermediateNInJa("(적)중급 겐지", "닌자", 7, 0, 0, 100, 100, 20, 20, 5, 10);
	e_iah = new IntermediateArcher("(적)중급 한조", "궁수", 7, 0, 0, 90, 90, 20, 20, 6, 13);
	e_bnj = new BossNinJa("(적)나루토", "호카게", 20, 0, 0, 400, 400, 100, 100, 10, 30);
	
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
	delete skill;
}
