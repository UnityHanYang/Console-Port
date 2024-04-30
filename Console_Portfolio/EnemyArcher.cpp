#include "EnemyArcher.h"

void EnemyArcher::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef(); // 최종 대미지
	target->SetCurrentHp(-damage);
}

void EnemyArcher::SkillAttack(Character* target)
{
}

void IntermediateArcher::NorMalAttack(Character* target)
{
	int damage = this->GetAtk() - target->GetDef(); // 최종 대미지
	target->SetCurrentHp(-damage);
}

void IntermediateArcher::SkillAttack(Character* target)
{
}