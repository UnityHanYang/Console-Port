#pragma once
#include <iostream>
#include <Windows.h>
#include "PrintSetting.h"
#include "InformationTool.h"
#include "ItemInventoryWindow.h"
#include "CharacterInfo.h"
#include "MapManager.h"
#include "MapDot.h"
#include "SkillWindow.h"
#include <conio.h>

class DungeonBoss : public PrintSetting
{
private:
	int mapX;
	int mapY;
	static std::vector<int> enemyArrXY;
	int c_EnemyArrXY[6];
	static int currentX;
	static int currentY;
	InformationTool it;
	static bool isXTrue;
	static bool isPush;
	static int currentEnemyIndex;
	static int currentNum;
	static bool isReturn;
	static bool isEnemyKill;
	MapDot md;
public:
	virtual void SetColor(int fontColor, int backgroundColor);
	virtual void PrintS(int count, int font, int background, bool isEndl, int x, int y);
	virtual void gotoxy(int x, int y);
	void PrintMapAndCharMove(int x, int y);
	void PrintOperation(int x, int y);
	bool CheckMapXY(int x1, int y1, int x1Count, int y1Count, int x2Count, int y2Count);
	void PrintEnemy();
	int CheckCurrentXY(int x, int y);
	bool CheckEnemyXY(int x, int y);
	void CheckXState(int num);
	bool CheckDungeonDoorXY(int x, int y);
	int GetCurrentX() { return currentX; }
	int GetCurrentY() { return currentY; }
	bool GetIsXTrue() { return isXTrue; }
	void HpMinus();
	void BossDungeonMultiThread();
	bool CheckLavaZone(int x, int y);
	int GetCurrentEnemyIndex() { return currentEnemyIndex; }
	void SetIsPush(bool ispush) { isPush = ispush; }
	std::vector<int>* GetEnemyArrXY() { return &enemyArrXY; }
	void VecInit();
	void SetIsReturn(bool isreturn) { isReturn = isreturn; }
	void SetIsEnemyKill(bool isenemyKill) { isEnemyKill = isenemyKill; }
	void SetEnemyArrXY(int index);
	std::atomic<bool> running{ true };

	DungeonBoss() : mapX{ 0 }, mapY{ 0 }, c_EnemyArrXY{} {};
};

