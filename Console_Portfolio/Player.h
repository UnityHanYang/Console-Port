#pragma once	
#include <iostream>
class Player
{
private:
	static int money;
	
public:
	int GetMoney() { return money; } // ÇöÀç µ· Ãâ·Â
	void SetMoney(int num) { money += num; } // µ· ¼öÁ¤

	Player();
};

