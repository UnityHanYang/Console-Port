#include "test.h"

void test::GetHp()
{
	std::cout <<	nj->GetHp();
}

test::test()
{
	nj = new NinJa("����", "�ü�", 30, 30, 4, 10, 4);
}

test::~test()
{
	delete nj;
}
