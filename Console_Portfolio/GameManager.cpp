#include "GameManager.h"

void GameManager::RandomEnemyUnit(int enemyLevel)
{
	ArcherDot ad;
	NinjaDot nd;
	srand(time(NULL));
	int num = rand() % 2;
	switch (enemyLevel)
	{
	case 1:
		if (num == 0)
		{
			nd.PrintEnemyLowerNinJa();
		}
		else
		{
			ad.PrintEnemyLowerArcher(130, 4);
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
	nj = new NinJa("����", "����");
	ah = new Archer("����", "�ü�");
	e_nj = new EnemyNinJa("(��)�ϱ� ����", "����");
	e_ah = new EnemyArcher("(��)�ϱ� ����", "�ü�");
	e_inj = new IntermediateNInJa("(��)�߱� ����", "����");
	e_iah = new IntermediateArcher("(��)�߱� ����", "�ü�");
	e_bnj = new BossNinJa("(��)������", "ȣī��");
	e_bah = new BossArcher("(��)���� ����", "�ü�");
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
