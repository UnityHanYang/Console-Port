#pragma once
#pragma region 헤더파일
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
#pragma region 맴버 변수, 클래스 정적 할당
	NinjaDot nd;
	ArcherDot ad;
	MapDot md;
	CharacterBackGround cbg;
	int charNumber;
#pragma endregion

public:
	virtual void SetColor(int fontColor, int backgroundColor) override; // 글자, 배경 색 설정
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y) override; // 글자, 배경 색을 해당 위치에 여러 번 설정
	virtual void gotoxy(int x, int y) override; // 해당 위치로 이동
	bool ChoiceScene(); // 캐릭터 선택창
	void ReadMore(int num); // 캐릭터 자세히 보기
	void PrintOperate(int x, int y); // 조작키 출력
	void PrintCharacterAbility(int num); // 캐릭터 속성 출력
	void PrintAbilityTool(int x, int y); // 캐릭터 속성 테두리 출력

	CharacterChoice();
};

