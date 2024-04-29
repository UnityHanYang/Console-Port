#include "Battle.h"


#define ARROW 224
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13
#define ESC 27

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


void Battle::CharacterTarget()
{
	GameManager* gm = GameManager::GetInstance();
	
	if (gm->GetCharacter() == 1)
	{
		chr = gm->nj;
	}
	else
	{
		chr = gm->ah;
	}
	switch (gm->GetEnemyLevelNum())
	{
	case 1:
		if (gm->GetRandomNum() == 0)
		{
			target = gm->e_nj;
		}
		else
		{
			target = gm->e_ah;
		}
		break;
	case 2:
		if (gm->GetRandomNum() == 0)
		{
			target = gm->e_inj;
		}
		else
		{
			target = gm->e_iah;
		}
		break;
	case 3:
		if (gm->GetRandomNum() == 1)
		{
			target = gm->e_bnj;
		}
		break;
	}

	bmd.PrintConsoleText("플레이어 턴", "", "", "", "", "", 195, 85);
	
}

void Battle::PrintBattleMap()
{
	GameManager* gm = GameManager::GetInstance();
	if (gm->GetCharacterCount().size() < 2)
	{
		bmd.PrintSoloBattleMap();
	}
	else
	{
		bmd.PrintMultiBattleMap();
	}
	CharacterTarget();
	int count = 0;
	PrintOption(count, 206, 62);
	bmd.PrintEnemyInfoTool();
	bmd.PrintHpTool(141, 46);
	md.PrintConsole(192, 83);
	hpBar = (chr->GetCurrentHp() * 20) / chr->GetMaxHp();
	mpBar = (chr->GetCurrentMp() * 20) / chr->GetMaxMp();
	if (hpBar <= 0)
	{
		if (chr->GetCurrentHp() > 0)
		{
			bmd.PrintHeroHp(chr, 102, 88, 1, mpBar);
		}
	}
	else
	{
		bmd.PrintHeroHp(chr, 102, 88, hpBar, mpBar);
	}

	hpBar = (target->GetCurrentHp() * 20) / target->GetMaxHp();
	mpBar = (target->GetCurrentMp() * 20) / target->GetMaxMp();

	bmd.PrintEnemyInfoText(target);

	if (hpBar <= 0)
	{
		if (chr->GetCurrentHp() > 0)
		{
			bmd.PrintEnemyCurrentHpMp(target, 145, 48, 1, mpBar);
		}
	}
	else
	{
		bmd.PrintEnemyCurrentHpMp(target, 145, 48, hpBar, mpBar);
	}

	if (gm->GetCharacter() == 1)
	{
		nd.PrintNinJaPortrait(116, 60);
	}
	else if (gm->GetCharacter() == 2)
	{
		ad.PrintArcherPortrait(120, 60);

	}
	DownUpInput();
}

void Battle::EnemyTurn()
{
	CharacterTarget();
	GameManager gm;
	bmd.PrintConsoleText("상대 턴", "", "", "", "", "", 195, 85);
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
	if (hpBar <= 0)
	{
		if (chr->GetCurrentHp() > 0)
		{
			bmd.PrintHeroHp(chr, 102, 88, 1, mpBar);
		}
		else
		{
			bmd.PrintHeroHp(chr, 102, 88, 0, mpBar);
		}
	}
	else
	{
		bmd.PrintHeroHp(chr, 102, 88, hpBar, mpBar);
	}
	if (CheckPlayerDie(gm.GetCharacterCount()))
	{
		Sleep(2000);
		PlayerDie(gm.GetCharacterCount());
	}
	Sleep(2000);
	bmd.PrintConsoleText("플레이어 턴", "", "", "", "", "", 195, 85);
	PrintOption(0, 206, 62);

}

void Battle::PlayerDie(std::vector<Character*> characterVec)
{
	MapManager mm;
	bmd.PrintConsoleText("전투 패배... 마을로 돌아갑니다.", "", "", "", "", "", 195, 85);
	Sleep(2000);

	std::vector<Character*>::iterator iter;
	for (iter = characterVec.begin(); iter != characterVec.end(); iter++)
	{
		(*iter)->SetCurrentHp((*iter)->GetMaxHp());
		(*iter)->SetCurrentMp((*iter)->GetMaxMp());
	}
	system("cls");
	mm.ms = Map_State::village;
	mm.Current_Map();
}

void Battle::CheckExpLevel(std::vector<Character*> characterVec, int exp)
{
	std::vector<Character*>::iterator iter;
	bool isEnter = false;
	for (iter = characterVec.begin(); iter != characterVec.end(); iter++)
	{
		(*iter)->SetCurrentExp(exp);
		while (true)
		{
			if ((*iter)->GetCurrentExp() >= (*iter)->GetMaxExp())
			{
				SpecUp(*iter);
				isEnter = true;
			}
			else
			{
				break;
			}
		}
		if (isEnter)
		{
			Sleep(1000);
			char buffer[50];
			sprintf(buffer, "%d", (*iter)->GetLevel());
			const char* cstr = buffer;
			bmd.PrintConsoleText((*iter)->GetName(), ": ", cstr, "레벨 달성", "", "", 195, 85);
			isEnter = false;
		}
	}
}

void Battle::SpecUp(Character* ch)
{
	ch->SetLevel(1);
	ch->SetCurrentExp(-ch->GetMaxExp());
	ch->SetMaxExp(10);
	ch->SetCritical(1);
	ch->SetMaxHp(10);
	ch->SetCurrentHp(10);
	ch->SetAtk(2);
	ch->SetDef(1);
	ch->SetMaxMp(3);
	ch->SetCurrentMp(3);
}

void Battle::DownUpInput()
{
	CharacterTarget();
	BattleInventory bi;
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
					bi.ClearOption(196, 60);
					PrintOption(count, 206, 62);
					break;
				case DOWN_ARROW:
					count = (count > 2) ? count : count += 1;
					bi.ClearOption(196, 60);
					PrintOption(count, 206, 62);
					break;
				}
			}
			else if (input == Enter)
			{
				if (count == 1)
				{
					ClearOption(206, 62);
					chr->NorMalAttack(target);
					char buffer[50];
					sprintf(buffer, "%d", (chr->GetAtk() - target->GetDef()));
					const char* cstr = buffer;
					bmd.PrintConsoleText(chr->GetName(), "가 ", target->GetName(), "에게 ", cstr, "만큼 피해를 입혔습니다", 195, 85);
					hpBar = (target->GetCurrentHp() * 20) / target->GetMaxHp();
					mpBar = (target->GetCurrentMp() * 20) / target->GetMaxMp();
					if (hpBar <= 0)
					{
						if (target->GetCurrentHp() > 0)
						{
							bmd.PrintEnemyCurrentHpMp(target, 145, 48, 1, mpBar);
						}
						else
						{
							bmd.PrintEnemyCurrentHpMp(target, 145, 48, 0, mpBar);
							EnemyDie();
						}
					}
					else
					{
						bmd.PrintEnemyCurrentHpMp(target, 145, 48, hpBar, mpBar);
					}
					Sleep(2000);
					EnemyTurn();
					count = 0;
				}
				else if (count == 2)
				{
					BattleSkill bs;
					bs.NinJaSkillChoice();
				}
				else if (count == 3)
				{
					BattleInventory bi;
					bi.ItemChoice();
				}
			}
		}

	}
}


void Battle::EnemyDie()
{
	GameManager gm;
	Dungeon1 dg;
	DungeonBoss db;
	MapManager mm;
	int exp = 0;
	int money = 0;
	Sleep(1500);
	bmd.PrintConsoleText("전투 승리", "", "", "", "", "", 195, 85);
	Sleep(1000);
	switch (gm.GetEnemyLevelNum())
	{
	case 1:
		bmd.PrintConsoleText("300원 획득", "", "", "", "", "", 195, 85);
		Sleep(0500);
		bmd.PrintConsoleText("경험치 30 획득", "", "", "", "", "", 195, 85);
		money = 300;
		exp = 30;
		break;
	case 2:
		bmd.PrintConsoleText("700원 획득", "", "", "", "", "", 195, 85);
		Sleep(1000);
		bmd.PrintConsoleText("경험치 80 획득", "", "", "", "", "", 195, 85);
		money = 700;
		exp = 80;
		break;
	case 3:
		bmd.PrintConsoleText("3000원 획득", "", "", "", "", "", 195, 85);
		Sleep(1000);
		bmd.PrintConsoleText("경험치 300 획득", "", "", "", "", "", 195, 85);
		money = 3000;
		exp = 300;
		break;
	}
	CheckExpLevel(gm.GetCharacterCount(), exp);
	player.SetMoney(money);
	Sleep(1000);
	if (mm.ds == Dungeon_State::current_dungeon)
	{
		dg.SetEnemyArrXY(dg.GetCurrentEnemyIndex());
		system("cls");
		dg.SetIsEnemyKill(true);
	}
	else if (mm.ds == Dungeon_State::current_boss_dungeon)
	{
		db.SetEnemyArrXY(db.GetCurrentEnemyIndex());
		system("cls");
		db.SetIsEnemyKill(true);
	}
	mm.Current_StackMap();
}

bool Battle::CheckPlayerDie(std::vector<Character*> characterVec)
{
	bool isDie = false;
	GameManager gm;
	std::vector<Character*>::iterator iter;
	for (iter = characterVec.begin(); iter != characterVec.end(); iter++)
	{
		if ((*iter)->GetCurrentHp() < 1)
		{
			isDie = true;
		}
		else
		{
			isDie = false;
		}
	}
	return isDie;
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
		gotoxy(x - 4, y + 4);
		std::cout << "             ";
		gotoxy(x, y + 4);
		std::cout << "스킬";
		gotoxy(x - 5, y + 8);
		std::cout << "             ";
		gotoxy(x - 1, y + 8);
		std::cout << "아이템";
		break;
	case 2:
		gotoxy(x - 4, y);
		std::cout << "               ";
		gotoxy(x, y);
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
		gotoxy(x - 4, y + 4);
		std::cout << "               ";
		gotoxy(x, y + 4);
		std::cout << "스킬";
		gotoxy(x - 7, y + 8);
		std::cout << "               ";
		gotoxy(x - 3, y + 8);
		std::cout << "▶ 아이템 ◀";
		break;
	default:
		gotoxy(x - 4, y);
		std::cout << "               ";
		gotoxy(x, y);
		std::cout << "공격";
		gotoxy(x - 4, y + 4);
		std::cout << "               ";
		gotoxy(x, y + 4);
		std::cout << "스킬";
		gotoxy(x - 5, y + 8);
		std::cout << "               ";
		gotoxy(x - 1, y + 8);
		std::cout << "아이템";
		break;
	}
}

void Battle::ClearOption(int x, int y)
{
	gotoxy(x - 6, y);
	std::cout << "                 ";
	gotoxy(x - 6, y + 2);
	std::cout << "                 ";
	gotoxy(x - 6, y + 4);
	std::cout << "                 ";
	gotoxy(x - 6, y + 6);
	std::cout << "                 ";
	gotoxy(x - 6, y + 8);
	std::cout << "                 ";
	gotoxy(x - 6, y + 10);
	std::cout << "                 ";
}