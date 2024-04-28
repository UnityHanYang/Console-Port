#include "EnemyArcher.h"

void EnemyArcher::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void EnemyArcher::SkillAttack(Character* target)
{
}

void IntermediateArcher::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void IntermediateArcher::SkillAttack(Character* target)
{
}

void BossArcher::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef();
	target->SetCurrentHp(-damage);
}

void BossArcher::SkillAttack(Character* target)
{
}
