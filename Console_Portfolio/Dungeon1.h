#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "MapDot.h"
#include <conio.h>
#include "DungeonBoss.h"
#include "MapManager.h"
#include "InformationTool.h"
#include "ItemInventoryWindow.h"
#include "CharacterInfo.h"
#include "GameManager.h"
#include <vector>
#include <thread>
#include "SkillWindow.h"

class Dungeon1 : public PrintSetting
{
private:
	int mapX;
	int mapY;
	static int currentX;
	static int currentY;
	static std::vector<int> enemyArrXY;
	int c_EnemyArrXY[6];
	InformationTool it;
	static bool isXTrue;
	static int currentNum;
	static bool isPush;
	static int currentEnemyIndex;
	static bool isReturn;
	static bool isEnemyKill;
	MapDot md;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	void PrintOperation(int x, int y);
	bool CheckEnemyXY(int x, int y);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);
	void PrintEnemy();
	int CheckCurrentXY(int x, int y);
	bool CheckEntranceXY(int x, int y);
	void CheckXState(int num);
	int GetCurrentX() { return currentX; }
	int GetCurrentY() { return currentY; }
	bool GetIsXTrue() { return isXTrue; }
	int GetCurrentEnemyIndex() { return currentEnemyIndex; }
	void SetIsPush(bool ispush) { isPush = ispush; }
	void VecInit();
	std::vector<int>* GetEnemyArrXY() { return &enemyArrXY; }
	void SetIsReturn(bool isreturn) { isReturn = isreturn; }
	void SetIsEnemyKill(bool isenemyKill) { isEnemyKill = isenemyKill; }

	void SetEnemyArrXY(int index);
	void HpMinus();
	void DungeonMultiThread();
	std::atomic<bool> running{ true };

	void PrintTalkMessage(int x, int y, char message[50]);

	Dungeon1() : mapX{ 0 }, mapY{ 0 }, c_EnemyArrXY{}{}
};

