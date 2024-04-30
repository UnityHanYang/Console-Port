#include "FileInOut.h"

#define ARROW 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define Enter 13
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

void FileInOut::FileWriteRead(std::vector<std::string> writeMessage)
{
	std::ifstream readfile("message.txt");
	std::ofstream writefile;
	int len = 0;
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
				case DOWN_ARROW:
					count = 0;
					len = static_cast<int>(writeMessage.size());
					if (readfile.is_open())
					{
						writeMessage.clear();
						char ch;
						while (readfile.get(ch)) {
							writeMessage.push_back(std::string(1, ch));
						}
						readfile.close();
					}
					else
					{
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
					break;
				case UP_ARROW:
					SetColor(15, 0);
					for (const auto& word : writeMessage) {
						gotoxy(10 + count, 3);
						std::cout << word;
						Sleep(100);
						count++;
					}
					break;
				}
			}
		}
	}
}
