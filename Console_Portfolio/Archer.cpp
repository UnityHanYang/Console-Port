#include "Archer.h"

void Archer::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef(); // 최종 대미지
	target->SetCurrentHp(-damage);
}

void Archer::SkillAttack(Character* target)
{
}