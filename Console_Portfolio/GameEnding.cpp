#include "GameEnding.h"

void GameEnding::EndingScene()
{
	std::cout << "������ Ŭ���� �ϼ̽��ϴ�\n����ȭ������ ���ư��ϴ�";

	Sleep(1500);
	system("cls");
	GameManager gm;
	gm.Start();
}

GameEnding::GameEnding()
{
}
