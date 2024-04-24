#pragma once	
#include <iostream>
class Player
{
private:
	int money;
	
public:
	int GetMoney() { return money; }
	void SetMoney(int num) { money += num; }

	Player(int i_money) : money(i_money) {};
};

