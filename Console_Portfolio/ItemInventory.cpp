#include "ItemInventory.h"

void ItemInventory::PrintName(int x, int y, int num)
{
	int this_count = 0;
	int index = 1;
	for (std::vector<Item*>::iterator it = itemVec.begin(); it != itemVec.end(); ++it) {
		gotoxy(x, y + this_count);
		if (index == count)
		{
			std::cout << "                " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << "¢º " << (*it)->GetName() << std::endl;
			PrintFeature(x + 54, y - 3, *it);
		}
		else
		{
			std::cout << "                " << std::endl;
			gotoxy(x, y + this_count);
			std::cout << (*it)->GetName() << std::endl;
		}
		index++;
		this_count += 2;
	}
}
