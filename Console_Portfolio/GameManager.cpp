#include "GameManager.h"
#include <iostream>


void GameManager::GameScene()
{
}

GameManager::GameManager()
{
	nj = new NinJa("����", "����", 80, 30, 5, 7, 2);
	ah = new Archer("����", "�ü�", 70, 25, 2, 10, 5);
}

GameManager::~GameManager()
{
	delete nj;
	delete ah;
}
