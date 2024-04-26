#include "GameManager.h"
#include <iostream>

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
