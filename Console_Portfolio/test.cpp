#include "test.h"

void test::GetHp()
{
	std::cout <<	nj->GetHp();
}

test::test()
{
	nj = new NinJa("°ÕÁö", "±Ã¼ö", 30, 30, 4, 10, 4);
}

test::~test()
{
	delete nj;
}
