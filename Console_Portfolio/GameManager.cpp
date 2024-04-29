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
			e_nj = new EnemyNinJa("(��)�ϱ� ����", "����", 1, 0, 0, 10, 70, 10, 10, 2, 6, 0);
			nd.PrintEnemyLowerNinJa();
			randomNum = num;
		}
		else if(num == 1)
		{
			e_ah = new EnemyArcher("(��)�ϱ� ����", "�ü�", 1, 0, 0, 10, 60, 10, 10, 2, 6, 0);
			bmd.PrintEnmeyBack();
			ad.PrintEnemyLowerArcher(156, 1);
			randomNum = num;
		}
		break;
	case 2:
		if (num == 0)
		{
			e_inj = new IntermediateNInJa("(��)�߱� ����", "����", 7, 0, 0, 10, 100, 20, 20, 5, 10, 5);
			nd.PrintIntermediateNinJa();
			randomNum = num;
		}
		else if (num == 1)
		{
			e_iah = new IntermediateArcher("(��)�߱� ����", "�ü�", 7, 0, 0, 10, 90, 20, 20, 6, 13, 8);
			bmd.PrintEnmeyBack();
			ad.PrintIntermediateArcher(156, 1);
			randomNum = num;
		}
		break;
	case 3:
		break;
	}
}

GameManager::GameManager()
{
	nj = new NinJa("����", "����", 1, 0, 10, 80, 80, 30, 30, 2, 7, 2);
	ah = new Archer("����", "�ü�", 1, 0, 10, 70, 70, 25, 25, 3, 10, 5);
	e_nj = new EnemyNinJa("(��)�ϱ� ����", "����", 1, 0, 0, 10, 70, 10, 10, 2, 6, 0);
	e_ah = new EnemyArcher("(��)�ϱ� ����", "�ü�", 1, 0, 0, 10, 60, 10, 10, 2, 6, 0);
	e_inj = new IntermediateNInJa("(��)�߱� ����", "����", 7, 0, 0, 10, 100, 20, 20, 5, 10, 5);
	e_iah = new IntermediateArcher("(��)�߱� ����", "�ü�", 7, 0, 0, 10, 90, 20, 20, 6, 13, 8);
	e_bnj = new BossNinJa("(��)������", "ȣī��", 20, 0, 0, 300, 400, 100, 100, 10, 30, 15);
	e_bah = new BossArcher("(��)���� ����", "�ü�", 20, 0, 0, 280, 380, 120, 120, 12, 35, 20);
	skill = new Skill("ƨ�ܳ���", 30, "�̸��� ƨ�ܳ��� �� �� ������ ƨ�ܳ��� �ʴ´�.", 5);
	
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
	delete skill;
}
