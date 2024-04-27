#pragma once
#include<iostream>
#include<fstream>
#include<vector>

class FileInOut
{
private:
	std::vector<const char*> words = { "게임", "시작" };
	int len = static_cast<int>(words.size());

public:
	void FileReadWrite();
};

