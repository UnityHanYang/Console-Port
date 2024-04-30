#pragma once
#pragma region �������
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
#pragma region �ɹ� ����, Ŭ���� ����, ���� �Ҵ�
	int count;
	int option;
	ItemInventory* iit;
	Player player;
	bool isEnter;
#pragma endregion

public:
	virtual void SetColor(int fontColor, int backgroundColor); // ����, ��� �� ����
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y); // ����, ��� ���� �ش� ��ġ�� ���� �� ����
	virtual void gotoxy(int x, int y); // �ش� ��ġ�� �̵�
	void PrintItemAndCancelTool(int x, int y); // ������, ��� �ɼ� �׵θ� ���
	void PrintMoneyTool(int x, int y); // �Ӵ� �׵θ� ���
	void PrintItemTool(int x, int y); // ������ �׵θ� ���
	void PrintItemDetailTool(int x, int y); // ������ ���� �׵θ� ���
	void PrintMoneyText(int x, int y); // �Ӵϰ� ���
	void ShowItem(int x, int y, int num); // ������ ��� ���
	void ChoiceUse(); // ������ ����
	void ClearText(int x, int y); // �κ� �ؽ�Ʈ ����
	void ChoiceHealChar(int x, int y, Item* item); // ȸ����ų ĳ���� ����
	void LeftRightInput(); // ����, ������ �Է�
	void PrintOptionText(int x, int y, int num); // �ɼ� �ؽ�Ʈ ���
	void UseItemYesOrNo(int x, int y, Item* item); // ������ ��� ����
	void ClearSection(int x, int y); // �ش� �κ� ����
	void SettingInfo(int x, int y, int num); // ���� ���� ���� ����
	void ClearSection2(int x, int y); // �ش� �κ� ����
	void HpMpHeal(Character& charcater, Item* item, int x, int y); // Hp, Mp ȸ��

	void InventoryTool(); // �κ��丮 ���

	ItemInventoryWindow();
	~ItemInventoryWindow();
};