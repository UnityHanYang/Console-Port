#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Skill.h"
#include <algorithm>

class SkillManager
{
private:
	static std::vector<Skill*> ninjaSkills;
	static std::vector<Skill*> archerSkills;
	
public:
	//Skill* njnjaSkill;
	//Skill* archerSkill;
	void AddNinJaSkill(Skill* skill);
	void AddArcherSkill(Skill* skill);
	std::vector<Skill*>& GetNinjaSkills() { return ninjaSkills; }
	std::vector<Skill*>& GetArcherSkills() { return archerSkills; }

	SkillManager();
	//~SkillManager();
};

