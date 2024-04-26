#pragma once
#include <iostream>
#include <vector>
#include "Character.h"

class Hotel
{
private:
	static std::vector<Character*> chracterCount;
public:
	void CharacterHeal(std::vector<Character*> characterVec);
	std::vector<Character*> GetCharacterCount() { return chracterCount; }
	void AddCharacter(Character* ch) { chracterCount.push_back(ch); }
};

