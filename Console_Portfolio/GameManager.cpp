#include "GameManager.h"

GameManager* GameManager::instance = nullptr;
std::vector<Character*> GameManager::chracterCount = {};
int GameManager::characterNum = 0;
int GameManager::enemyLevelNum = 0;
int GameManager::randomNum = 0;

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
			nd.PrintEnemyLowerNinJa();
			randomNum = num;
		}
		else if(num == 1)
		{
			bmd.PrintEnmeyBack();
			ad.PrintEnemyLowerArcher(156, 1);
			randomNum = num;
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
	nj = new NinJa("����", "����", 1, 0, 10, 80, 80, 30, 30, 4, 7, 2);
	ah = new Archer("����", "�ü�", 1, 0, 10, 70, 70, 25, 25, 6, 10, 5);
	e_nj = new EnemyNinJa("(��)�ϱ� ����", "����", 1, 0, 0, 70, 70, 10, 10, 3, 6, 0);
	e_ah = new EnemyArcher("(��)�ϱ� ����", "�ü�", 1, 0, 0, 60, 60, 10, 10, 3, 6, 0);
	e_inj = new IntermediateNInJa("(��)�߱� ����", "����", 7, 0, 0, 100, 100, 20, 20, 7, 10, 5);
	e_iah = new IntermediateArcher("(��)�߱� ����", "�ü�", 7, 0, 0, 90, 90, 20, 20, 9, 13, 8);
	e_bnj = new BossNinJa("(��)������", "ȣī��", 20, 0, 0, 300, 400, 100, 100, 17, 30, 15);
	e_bah = new BossArcher("(��)���� ����", "�ü�", 20, 0, 0, 280, 380, 120, 120, 20, 35, 20);
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
