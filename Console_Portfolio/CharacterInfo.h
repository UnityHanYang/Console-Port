#pragma once

#pragma region �������
#include <iostream>
#include "PrintSetting.h"
#include "NinjaDot.h"
#include "ArcherDot.h"
#include "CharacterBackGround.h"
#include <Windows.h>
#include "MapDot.h"
#include <conio.h>
#include "CharacterChoice.h"
#include "GameManager.h"
#pragma endregion

class CharacterInfo : public PrintSetting
{
private:
#pragma region Ŭ���� ���� �Ҵ�
	NinjaDot nd;
	ArcherDot ad;
	MapDot md;
	CharacterBackGround cbg;
#pragma endregion

	
public:
	virtual void SetColor(int fontColor, int backgroundColor); // ����, ��� �� ����
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y); // ����, ��� ���� �ش� ��ġ�� ���� �� ����
	virtual void gotoxy(int x, int y); // �ش� ��ġ�� �̵�
	void CharacterOne(); // ���� ĳ���� ���
	void ReadMore(int num); // ĳ���� �ڼ��� ����
	void ChoiceCharacter(); // ĳ���� ����
	void PrintBackOperate(int x, int y, Character* ch); // ����Ű, ����ġ ���� ���
	void PrintCharacterAbility(int num); // ĳ���� �Ӽ� ���
	void PrintOperate(int x, int y); // ����Ű ���
};

