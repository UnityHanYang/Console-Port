#pragma once
#pragma region 헤더파일
#include <iostream>
#include "PrintSetting.h"
#include <Windows.h>
#include "MapManager.h"
#include "ItemInventory.h"
#include "CharacterInfo.h"
#include "GameManager.h"
#include "CharacterChoice.h"
#include "ItemSell.h"
#include "Item.h"
#include "Player.h"

#pragma endregion


class ItemInventoryWindow : public PrintSetting
{
private:
#pragma region 맴버 변수, 클래스 동적, 정적 할당
	int count;
	int option;
	ItemInventory* iit;
	Player player;
	bool isEnter;
#pragma endregion

public:
	virtual void SetColor(int fontColor, int backgroundColor); // 글자, 배경 색 설정
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y); // 글자, 배경 색을 해당 위치에 여러 번 설정
	virtual void gotoxy(int x, int y); // 해당 위치로 이동
	void PrintItemAndCancelTool(int x, int y); // 아이템, 취소 옵션 테두리 출력
	void PrintMoneyTool(int x, int y); // 머니 테두리 출력
	void PrintItemTool(int x, int y); // 아이템 테두리 출력
	void PrintItemDetailTool(int x, int y); // 아이템 정보 테두리 출력
	void PrintMoneyText(int x, int y); // 머니값 출력
	void ShowItem(int x, int y, int num); // 아이템 목록 출력
	void ChoiceUse(); // 아이템 선택
	void ClearText(int x, int y); // 부분 텍스트 삭제
	void ChoiceHealChar(int x, int y, Item* item); // 회복시킬 캐릭터 선택
	void LeftRightInput(); // 왼쪽, 오른쪽 입력
	void PrintOptionText(int x, int y, int num); // 옵션 텍스트 출력
	void UseItemYesOrNo(int x, int y, Item* item); // 아이템 사용 여부
	void ClearSection(int x, int y); // 해당 부분 삭제
	void SettingInfo(int x, int y, int num); // 현재 남은 물약 설정
	void ClearSection2(int x, int y); // 해당 부분 삭제
	void HpMpHeal(Character& charcater, Item* item, int x, int y); // Hp, Mp 회복

	void InventoryTool(); // 인벤토리 출력

	ItemInventoryWindow();
	~ItemInventoryWindow();
};