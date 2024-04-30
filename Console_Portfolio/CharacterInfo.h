#pragma once

#pragma region 헤더파일
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
#pragma region 클래스 정적 할당
	NinjaDot nd;
	ArcherDot ad;
	MapDot md;
	CharacterBackGround cbg;
#pragma endregion

	
public:
	virtual void SetColor(int fontColor, int backgroundColor); // 글자, 배경 색 설정
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y); // 글자, 배경 색을 해당 위치에 여러 번 설정
	virtual void gotoxy(int x, int y); // 해당 위치로 이동
	void CharacterOne(); // 현재 캐릭터 출력
	void ReadMore(int num); // 캐릭터 자세히 보기
	void ChoiceCharacter(); // 캐릭터 선택
	void PrintBackOperate(int x, int y, Character* ch); // 조작키, 경험치 정보 출력
	void PrintCharacterAbility(int num); // 캐릭터 속성 출력
	void PrintOperate(int x, int y); // 조작키 출력
};

