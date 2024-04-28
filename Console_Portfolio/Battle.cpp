#include "Battle.h"

#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13

#pragma region 상속 메서드

void Battle::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void Battle::PrintS(int count, int font, int background, bool isEndl, int x, int y)
{
	SetColor(font, background);
	gotoxy(x, y);

	for (int i = 0; i < count; i++)
	{
		std::cout << "ㅁ";
	}

	if (isEndl)
	{
		std::cout << std::endl;
	}
}

void Battle::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#pragma endregion


void Battle::PrintBattleMap()
{
	int count = 0;
	GameManager* gm = GameManager::GetInstance();
	gm->RandomEnemyUnit(1);
	if (gm->GetCharacterCount().size() < 2)
	{
		bmd.PrintSoloBattleMap();
	}
	else
	{
		bmd.PrintMultiBattleMap();
	}
	if (gm->GetCharacter() == 1)
	{
		chr = gm->nj;
	}
	else
	{
		chr = gm->ah;
	}
	if (gm->GetRandomNum() == 0)
	{
		target = gm->e_nj;
	}
	else
	{
		target = gm->e_ah;
	}
	PrintOption(count, 206, 62);
	
	bmd.PrintEnemyInfoTool();
	bmd.PrintHpTool(141, 46);
	md.PrintConsole(192, 83);
	bmd.PrintConsoleText("플레이어 턴 입니다", "", "", "", "", "", 195, 85);
	switch (gm->GetEnemyLevelNum())
	{
	case 1:
		hpBar = (chr->GetCurrentHp() * 20) / chr->GetMaxHp();
		mpBar = (chr->GetCurrentMp() * 20) / chr->GetMaxMp();
		if (gm->GetCharacter() == 1)
		{
			nd.PrintNinJaPortrait(116, 60);
			bmd.PrintHeroHp(gm->nj, 102, 88, hpBar, mpBar);
		}
		else if (gm->GetCharacter() == 2)
		{
			ad.PrintArcherPortrait(120, 60);
			bmd.PrintHeroHp(gm->ah, 102, 88, hpBar, mpBar);
		}

		hpBar = (target->GetCurrentHp() * 20) / target->GetMaxHp();
		mpBar = (target->GetCurrentMp() * 20) / target->GetMaxMp();
		if (gm->GetRandomNum() == 0)
		{
			bmd.PrintEnemyCurrentHpMp(gm->e_nj, 145, 48, hpBar, mpBar);
			bmd.PrintEnemyInfoText(gm->e_nj);
		}
		else if (gm->GetRandomNum() == 1)
		{
			bmd.PrintEnemyCurrentHpMp(gm->e_ah, 145, 48, hpBar, mpBar);
			bmd.PrintEnemyInfoText(gm->e_ah);
		}
		break;
	case 2:
		break;
	case 3:
		break;
	}
	int input;
	while (true)
	{
		if (_kbhit())
		{
			input = _getch();
			if (input == ARROW)
			{
				input = _getch();
				switch (input)
				{
				case UP_ARROW:
					count = (count < 2) ? count : count -= 1;
					PrintOption(count, 206, 62);
					break;
				case DOWN_ARROW:
					count = (count > 2) ? count : count += 1;
					PrintOption(count, 206, 62);
					break;
				}
			}
			else if (input == Enter)
			{
				if (count == 1)
				{
					chr->NorMalAttack(target);
					char buffer[50];
					sprintf(buffer, "%d", (chr->GetAtk() - target->GetDef()));
					const char* cstr = buffer;
					bmd.PrintConsoleText(chr->GetName(), "가 ", target->GetName(), "에게 ", cstr, "만큼 피해를 입혔습니다", 195, 85);
					hpBar = (target->GetCurrentHp() * 20) / target->GetMaxHp();
					mpBar = (target->GetCurrentMp() * 20) / target->GetMaxMp();
					bmd.PrintEnemyCurrentHpMp(target, 145, 48, hpBar, mpBar);
					Sleep(2000);
					EnemyTurn();
				}
			}
		}

	}
}

void Battle::EnemyTurn()
{
	bmd.PrintConsoleText("상대턴 턴 입니다", "", "", "", "", "", 195, 85);
	srand(time(NULL));
	int ran = (rand() % 500) + 1000;
	Sleep(ran);
	target->NorMalAttack(chr);
	char buffer[50];
	sprintf(buffer, "%d", (target->GetAtk() - chr->GetDef()));
	const char* cstr = buffer;
	bmd.PrintConsoleText(target->GetName(), "가 ", chr->GetName(), "에게 ", cstr, "만큼 피해를 입혔습니다", 195, 85);
	hpBar = (chr->GetCurrentHp() * 20) / chr->GetMaxHp();
	mpBar = (chr->GetCurrentMp() * 20) / chr->GetMaxMp();
	bmd.PrintHeroHp(chr, 102, 88, hpBar, mpBar);
	Sleep(2000);
	bmd.PrintConsoleText("플레이어 턴 입니다", "", "", "", "", "", 195, 85);
}	

void Battle::PrintOption(int num, int x, int y)
{
	SetColor(15, 0);
	switch (num)
	{
	case 1:
		gotoxy(x - 2, y);
		std::cout << "             ";
		gotoxy(x - 2, y);
		std::cout << "▶ 공격 ◀";
		gotoxy(x - 4, y+4);
		std::cout << "             ";
		gotoxy(x, y+4);
		std::cout << "스킬";
		gotoxy(x- 5, y+8);
		std::cout << "             ";
		gotoxy(x- 1, y+8);
		std::cout << "아이템";
		break;
	case 2:
		gotoxy(x - 4, y );
		std::cout << "               ";
		gotoxy(x, y );
		std::cout << "공격";
		gotoxy(x - 6, y + 4);
		std::cout << "               ";
		gotoxy(x - 2, y + 4);
		std::cout << "▶ 스킬 ◀";
		gotoxy(x - 5, y + 8);
		std::cout << "               ";
		gotoxy(x - 1, y + 8);
		std::cout << "아이템";
		break;
	case 3:
		gotoxy(x - 4, y);
		std::cout << "               ";
		gotoxy(x, y);
		std::cout << "공격";
		gotoxy(x - 4, y+4);
		std::cout << "               ";
		gotoxy(x, y+4);
		std::cout << "스킬";
		gotoxy(x-7, y+8);
		std::cout << "               ";
		gotoxy(x-3, y+8);
		std::cout << "▶ 아이템 ◀";
		break;
	default:
		gotoxy(x - 4, y);
		std::cout << "               ";
		gotoxy(x, y);
		std::cout << "공격";
		gotoxy(x - 4, y+4);
		std::cout << "               ";
		gotoxy(x, y+4);
		std::cout << "스킬";
		gotoxy(x-5, y+8);
		std::cout << "               ";
		gotoxy(x-1, y+8);
		std::cout << "아이템";
		break;
	}
}