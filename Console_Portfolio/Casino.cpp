#include "Casino.h"

#define FOR_COUNT 3

std::string currentNumStr;

auto setNum = []() -> void
{
	std::string getNum;
	int ran;
	bool isNumEqual = false;
	int numberArr[FOR_COUNT];
	for (int i = 0; i < 3; i++)
	{
		while (true)
		{
			srand(time(NULL));
			ran = rand() % 10;
			for (int i = 0; i < (sizeof(numberArr) / sizeof(int)); i++)
			{
				if (ran == numberArr[i])
				{
					isNumEqual = true;
				}
			}
			if (!isNumEqual)
			{
				numberArr[i] = ran;
				break;
			}
			isNumEqual = false;
		}
	}
	std::cout << "슬롯 머신 숫자: ";
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int i = 0; i < 10; i++)
			{
				srand(time(NULL));
				ran = (i > 9) ? 0 : i;
				std::cout << ran;
				if (k == 1 && numberArr[j] == ran)
				{
					goto RANDOM_NUM;
				}
				Sleep(90);
				std::cout << '\b';
			}
		}
	RANDOM_NUM:
		std::cout << "  ";
		currentNumStr += std::to_string(ran);
	}
};

void Casino::PlayGame()
{
	int money = player->GetMoney();
	int betting;

	while (true)
	{
		char choice;
		bool isCin;
		bool isEnable;
		isCin = true;
		isEnable = false;

		int bettingNumber;
		int currentMoney;
		if (isCin)
		{
			do
			{
				std::cout << "배팅할 금액을 입력하세요(최소 배팅금액: 100, 배팅 단위: 100): ";

				std::cin >> betting;

			} while (betting < 100 || betting % 100 != 0 || betting > money);

			std::cout << std::endl;

			if (isEnable)
			{
				std::cout << "숫자를 입력해주세요: ";

				std::cin >> bettingNumber;
				std::string playerInput = std::to_string(bettingNumber);
				currentMoney = money - player->GetMoney();
				money += GetResult(playerInput, betting);
				player->SetMoney(currentMoney);
			}
			else
			{
				setNum();
				std::cout << '\n';
				money += GetResult(currentNumStr, betting);
				currentMoney = money - player->GetMoney();
				player->SetMoney(currentMoney);
			}

			std::cout << "보유금: " << player->GetMoney() << std::endl;
			std::cout << "\n게임을 그만 하시려면 n을 입력해주시고, 게임을 계속 \n하시려면 n을 제외한 나머지 문자를 입력해주세요: ";
			char gameCancel;
			std::cin >> gameCancel;
			std::cout << '\n';
			isCin = false;
			if (gameCancel == 'n')
			{
				system("cls");
				MapManager mm;
				mm.Current_StackMap();
				break;
			}
		}
	}
}

int Casino::GetResult(std::string ranNum, int bettingMoney)
{
	int result = 0;
	int count = 0;
	bool isEqual = true;

	char cValue = ranNum[0];
	for (int i = 1; i < ranNum.size(); i++)
	{
		if ((int)cValue != (int)ranNum[i])
		{
			count++;
			isEqual = false;
		}
	}

	if (stoi(ranNum) == 777)
	{
		result = bettingMoney * 12;
		std::cout << "12배 당첨\n";
	}
	else if (isEqual)
	{
		result = bettingMoney * 5;
		std::cout << "5배 당첨\n";
	}
	else if (count == 1)
	{
		result = bettingMoney * 2;
		std::cout << "2배 당첨\n";
	}
	else
	{
		result = bettingMoney * (-1);
		std::cout << "배팅금 획득 실패\n";
	}
	return result;
}

Casino::Casino()
{
	player = new Player;
}

Casino::~Casino()
{
	delete player;
}
