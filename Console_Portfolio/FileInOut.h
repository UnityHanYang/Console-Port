#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include <string>
#include <Windows.h>

class FileInOut
{
private:
	int count = 0;
public:
	void SetColor(int fontColor, int backgroundColor);
	void gotoxy(int x, int y);
	void FileWriteRead(std::vector<std::string> writeMessage, std::vector<std::string> readMessage);
};

