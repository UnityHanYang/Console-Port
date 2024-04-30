#pragma once
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>

class InformationTool : public PrintSetting
{
public:
	virtual void SetColor(int fontColor, int backgroundColor); // 글자, 배경 색 설정
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y); // 글자, 배경 색을 해당 위치에 여러 번 설정
	virtual void gotoxy(int x, int y); // 해당 위치로 이동
	void ClearOperation(int x, int y); // 조작키 지우기(더블 버퍼링 대체)
	void PrintInfo(int x, int y, int num); // 정보창 옵션 출력
};

