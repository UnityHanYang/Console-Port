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
	//njnjaSkill = new Skill("��ǳ��", 1000, "���� ���� ������ ū ���ظ� ����", 10);
	//archerSkill = new Skill("����ȭ��", 1000, "ȭ���� ������ ������ ū ���ظ� ����", 10);
}
//
//SkillManager::~SkillManager()
//{
//	delete njnjaSkill;
//	delete archerSkill;
//}
