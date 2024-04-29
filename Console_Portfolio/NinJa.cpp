#include "NinJa.h"

void NinJa::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void NinJa::SkillAttack(Character* target)
{
}
