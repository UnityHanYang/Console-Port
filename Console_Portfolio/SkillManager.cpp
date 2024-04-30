#include "SkillManager.h"

std::vector<Skill*> SkillManager::ninjaSkills = {};
std::vector<Skill*> SkillManager::archerSkills = {};

void SkillManager::AddNinJaSkill(Skill* skill)
{
	ninjaSkills.push_back(skill);
}

void SkillManager::AddArcherSkill(Skill* skill)
{
	archerSkills.push_back(skill);
}

SkillManager::SkillManager()
{
	//njnjaSkill = new Skill("질풍참", 1000, "검이 적을 관통해 큰 피해를 입힘", 10);
	//archerSkill = new Skill("갈래화살", 1000, "화살이 갈라져 적에게 큰 피해를 입힘", 10);
}
//
//SkillManager::~SkillManager()
//{
//	delete njnjaSkill;
//	delete archerSkill;
//}
