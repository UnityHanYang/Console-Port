#include "Hotel.h"


#pragma region 플레이어 회복
void Hotel::CharacterHeal(std::vector<Character*> characterVec)
{
	std::vector<Character*>::iterator iter;
	for (iter = characterVec.begin(); iter != characterVec.end(); iter++)
	{
		int hp = (*iter)->GetMaxHp() - (*iter)->GetCurrentHp();
		int mp = (*iter)->GetMaxMp() - (*iter)->GetCurrentMp();

		(*iter)->SetCurrentHp(hp);
		(*iter)->SetCurrentMp(mp);
	}
}
#pragma endregion

