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
