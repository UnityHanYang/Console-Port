#include "GameEnding.h"

void GameEnding::EndingScene()
{
	std::cout << "게임을 클리어 하셨습니다\n메인화면으로 돌아갑니다";

	Sleep(1500);
	system("cls");
	GameManager gm;
	gm.Start();
}

GameEnding::GameEnding()
{
}
