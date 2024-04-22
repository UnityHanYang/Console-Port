#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

class DoubleBuffer
{
public:
    void SetPixel(int x, int y, char ch);

    void Clear();

    void Render();
    DoubleBuffer(int width, int height) : width(width), height(height) 
    {
        frontBuffer.resize(height, std::vector<char>(width, ' '));
    };

private:
    std::vector<std::vector<char>> frontBuffer;
    int width, height;
};

