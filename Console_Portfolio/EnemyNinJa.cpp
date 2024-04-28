#include "EnemyNinJa.h"

void EnemyNinJa::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void EnemyNinJa::SkillAttack(Character* target)
{
}

void IntermediateNInJa::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void IntermediateNInJa::SkillAttack(Character* target)
{
}

void BossNinJa::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void BossNinJa::SkillAttack(Character* target)
{
}
