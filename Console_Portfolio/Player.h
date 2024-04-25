#pragma once	
#include <iostream>
class Player
{
private:
	static int money;
	
public:
	int GetMoney() { return money; }
	void SetMoney(int num) { money += num; }

	Player();
};

