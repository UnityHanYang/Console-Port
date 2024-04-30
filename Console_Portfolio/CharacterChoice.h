#pragma once
#pragma region �������
#include <iostream>
#include "PrintSetting.h"
#include <conio.h>
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "MapDot.h"
#include "MapManager.h"
#include "NinJa.h"
#include "Archer.h"
#include "GameManager.h"
#include "CharacterBackGround.h"
#pragma endregion

class CharacterChoice : public PrintSetting
{
private:
#pragma region �ɹ� ����, Ŭ���� ���� �Ҵ�
	NinjaDot nd;
	ArcherDot ad;
	MapDot md;
	CharacterBackGround cbg;
	int charNumber;
#pragma endregion

public:
	virtual void SetColor(int fontColor, int backgroundColor) override; // ����, ��� �� ����
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y) override; // ����, ��� ���� �ش� ��ġ�� ���� �� ����
	virtual void gotoxy(int x, int y) override; // �ش� ��ġ�� �̵�
	bool ChoiceScene(); // ĳ���� ����â
	void ReadMore(int num); // ĳ���� �ڼ��� ����
	void PrintOperate(int x, int y); // ����Ű ���
	void PrintCharacterAbility(int num); // ĳ���� �Ӽ� ���
	void PrintAbilityTool(int x, int y); // ĳ���� �Ӽ� �׵θ� ���

	CharacterChoice();
};

