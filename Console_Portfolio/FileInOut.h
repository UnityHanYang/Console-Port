#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <codecvt>
#include <locale>
#include "GameManager.h"

class FileInOut
{
private:
	int count = 0;
public:
	void SetColor(int fontColor, int backgroundColor);
	void gotoxy(int x, int y);
	void FileWriteRead(std::vector<std::string> writeMessage);
};

