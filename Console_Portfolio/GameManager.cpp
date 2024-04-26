#include "GameManager.h"
#include <iostream>

GameManager::GameManager()
{
	nj = new NinJa("°ÕÁö", "´ÑÀÚ", 80, 5, 30, 5, 7, 2);
	ah = new Archer("ÇÑÁ¶", "±Ã¼ö", 70, 25, 25, 2, 10, 5);
}

GameManager::~GameManager()
{
	delete nj;
	delete ah;
}
