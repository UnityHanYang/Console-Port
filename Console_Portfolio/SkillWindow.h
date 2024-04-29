#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>
#include "MapManager.h"
#include "SkillManager.h"
#include "ItemInventoryWindow.h"
#include "ItemSell.h"

class SkillWindow : public PrintSetting
{
private:
	SkillManager* sm;
	int option;
	int count;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);

	void SkillTool();
	void PrintOptionText(int x, int y, int num);
	void ControlLeftRight();
	void ShowSkill(int x, int y, int num);
	void NinjaSkill();
	void ArcherSkill();
	void NinjaSettingInfo(int x, int y, int num);
	void ArcherSettingInfo(int x, int y, int num);

	SkillWindow();
	~SkillWindow();
};

