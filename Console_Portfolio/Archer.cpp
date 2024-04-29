#include "Archer.h"

void Archer::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void Archer::SkillAttack(Character* target)
{
}