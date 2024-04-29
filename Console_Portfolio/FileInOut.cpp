#include "FileInOut.h"

void FileInOut::SetColor(int fontColor, int backgroundColor)
{
	int Color = fontColor + backgroundColor * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void FileInOut::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void FileInOut::FileWriteRead(std::vector<std::string> writeMessage, std::vector<std::string> readMessage)
{
	std::ifstream readfile("message.txt");
	int len = static_cast<int>(readMessage.size());
	count = 0;
	if (readfile.is_open())
	{
		readMessage.clear();
		while (!readfile.eof())
		{
			std::string str;
			std::getline(readfile, str);
			SetColor(15, 0);
			for (size_t i = 0; i < str.size(); ++i)
			{
				gotoxy(195 + count, 85); // 위치 조정이 필요할 수 있음
				std::cout << str[i];
				Sleep(500); // 한 글자씩 출력할 때마다 지연
				count++;
			}
			readMessage.push_back(str);
		}
	}
	else
	{
		std::ofstream writefile;
		writefile.open("message.txt");
		for (int i = 0; i < len; i++)
		{
			std::string tmp = writeMessage[i];
			if (i != len - 1)
			{
				tmp += "\n";
			}
			writefile.write(tmp.c_str(), tmp.size());
		}
		writefile.close();
	}
}
