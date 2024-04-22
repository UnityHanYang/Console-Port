#include "DoubleBuffer.h"

void DoubleBuffer::SetPixel(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height) {
        frontBuffer[y][x] = ch;
    }
}

void DoubleBuffer::Clear()
{
    for (auto& row : frontBuffer) {
        std::fill(row.begin(), row.end(), ' ');
    }
}

void DoubleBuffer::Render()
{
    system("cls");
    for (const auto& row : frontBuffer) {
        for (char ch : row) {
            std::cout << ch;
        }
        std::cout << '\n';
    }
}
