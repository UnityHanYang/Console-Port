#pragma once
#include <iostream>
#include <Windows.h>

class Skill
{
private:
	const char* name;
	int damage;
	const char* feature;
	int cost;
public:
	Skill(const char* c_Name, int c_Damage, const char* c_Feature, int c_Cost) : name(c_Name), damage(c_Damage), feature(c_Feature), cost(c_Cost) {}


	const char* GetName() { return name; }
	int GetDamage() { return damage; }
	const char* GetFeature() { return feature; }
	int GetCost() { return cost; }
	void SetDamage(int damage) { this->damage = damage; }
};

