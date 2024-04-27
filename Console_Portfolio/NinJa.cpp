#include "NinJa.h"

void NinJa::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() * (1 - (target->GetDef() / (100 + target->GetDef())));
	target->SetCurrentHp(-damage);
}

void NinJa::SkillAttack(Character* target)
{
}

void NinJa::ItemUse(Item* item)
{
}
