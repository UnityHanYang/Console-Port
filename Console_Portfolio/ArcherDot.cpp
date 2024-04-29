#include "ArcherDot.h"

#pragma region 상속 메서드
void ArcherDot::PrintS(int count, int font, int background, bool isEndl, int x, int y)
{
    SetColor(font, background);
    gotoxy(x, y);

    for (int i = 0; i < count; i++)
    {
        std::cout << "ㅁ";
    }

    if (isEndl)
    {
        std::cout << std::endl;
    }
}

void ArcherDot::SetColor(int fontColor, int backgroundColor)
{
    int Color = fontColor + backgroundColor * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void ArcherDot::gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#pragma endregion

#pragma region 궁수 캐릭터 출력(초상화)
void ArcherDot::PrintArcherPortrait(int x, int y)
{
    PrintS(4, 0, 0, 0, x, y);
    PrintS(7, 0, 0, 1, x + 12, y);
    PrintS(8, 0, 0, 0, x - 4, y + 1);
    PrintS(2, 6, 6, 0, x + 12, y + 1);
    PrintS(5, 0, 0, 1, x + 16, y + 1);
    PrintS(11, 0, 0, 0, x - 8, y + 2);
    PrintS(2, 6, 6, 0, x + 14, y + 2);
    PrintS(5, 0, 0, 1, x + 18, y + 2);
    PrintS(13, 0, 0, 0, x - 10, y + 3);
    PrintS(1, 6, 6, 0, x + 16, y + 3);
    PrintS(5, 0, 0, 1, x + 18, y + 3);
    PrintS(15, 0, 0, 0, x - 12, y + 4);
    PrintS(2, 6, 6, 0, x + 18, y + 4);
    PrintS(1, 0, 0, 1, x + 22, y + 4);
    PrintS(17, 0, 0, 0, x - 14, y + 5);
    PrintS(4, 6, 6, 1, x + 20, y + 5);
    PrintS(7, 0, 0, 0, x - 14, y + 6);
    PrintS(3, 14, 14, 0, x, y + 6);
    PrintS(8, 0, 0, 0, x + 6, y + 6);
    PrintS(5, 6, 6, 1, x + 20, y + 6);
    PrintS(6, 0, 0, 0, x - 16, y + 7);
    PrintS(6, 14, 14, 0, x - 4, y + 7);
    PrintS(7, 0, 0, 0, x + 8, y + 7);
    PrintS(5, 6, 6, 1, x + 20, y + 7);
    PrintS(3, 0, 0, 0, x - 16, y + 8);
    PrintS(1, 14, 14, 0, x - 10, y + 8);
    PrintS(1, 0, 0, 0, x - 8, y + 8);
    PrintS(8, 14, 14, 0, x - 6, y + 8);
    PrintS(6, 0, 0, 0, x + 10, y + 8);
    PrintS(5, 6, 6, 1, x + 20, y + 8);
    PrintS(2, 0, 0, 0, x - 16, y + 9);
    PrintS(8, 14, 14, 0, x - 12, y + 9);
    PrintS(1, 8, 8, 0, x + 4, y + 9);
    PrintS(2, 14, 14, 0, x + 6, y + 9);
    PrintS(6, 0, 0, 0, x + 10, y + 9);
    PrintS(3, 6, 6, 1, x + 24, y + 9);
    PrintS(2, 0, 0, 0, x - 16, y + 10);
    PrintS(1, 8, 8, 0, x - 12, y + 10);
    PrintS(6, 14, 14, 0, x - 10, y + 10);
    PrintS(3, 8, 8, 0, x + 2, y + 10);
    PrintS(1, 14, 14, 0, x + 8, y + 10);
    PrintS(3, 0, 0, 0, x + 10, y + 10);
    PrintS(2, 14, 14, 0, x + 16, y + 10);
    PrintS(1, 0, 0, 0, x + 20, y + 10);
    PrintS(1, 6, 6, 1, x + 28, y + 10);
    PrintS(2, 0, 0, 0, x - 16, y + 11);
    PrintS(2, 8, 8, 0, x - 10, y + 11);
    PrintS(2, 14, 14, 0, x - 6, y + 11);
    PrintS(3, 8, 8, 0, x - 2, y + 11);
    PrintS(1, 7, 7, 0, x + 4, y + 11);
    PrintS(2, 14, 14, 0, x + 6, y + 11);
    PrintS(2, 0, 0, 0, x + 10, y + 11);
    PrintS(2, 14, 14, 0, x + 14, y + 11);
    PrintS(2, 0, 0, 1, x + 18, y + 11);
    PrintS(3, 0, 0, 0, x - 18, y + 12);
    PrintS(2, 7, 7, 0, x - 10, y + 12);
    PrintS(2, 14, 14, 0, x - 6, y + 12);
    PrintS(1, 8, 8, 0, x - 2, y + 12);
    PrintS(2, 7, 7, 0, x, y + 12);
    PrintS(3, 14, 14, 0, x + 4, y + 12);
    PrintS(2, 0, 0, 0, x + 10, y + 12);
    PrintS(2, 14, 14, 0, x + 14, y + 12);
    PrintS(2, 0, 0, 1, x + 18, y + 12);
    PrintS(3, 0, 0, 0, x - 18, y + 13);
    PrintS(11, 14, 14, 0, x - 10, y + 13);
    PrintS(1, 0, 0, 0, x + 12, y + 13);
    PrintS(1, 14, 14, 0, x + 14, y + 13);
    PrintS(2, 0, 0, 1, x + 16, y + 13);
    PrintS(2, 0, 0, 0, x - 18, y + 14);
    PrintS(12, 14, 14, 0, x - 10, y + 14);
    PrintS(2, 0, 0, 0, x + 14, y + 14);
    PrintS(1, 14, 14, 1, x + 18, y + 14);
    PrintS(2, 0, 0, 0, x - 18, y + 15);
    PrintS(10, 14, 14, 0, x - 8, y + 15);
    PrintS(2, 0, 0, 0, x + 12, y + 15);
    PrintS(2, 14, 14, 1, x + 16, y + 15);
    PrintS(2, 0, 0, 0, x - 18, y + 16);
    PrintS(3, 14, 14, 0, x - 6, y + 16);
    PrintS(2, 8, 8, 0, x, y + 16);
    PrintS(4, 14, 14, 0, x + 4, y + 16);
    PrintS(2, 0, 0, 0, x + 12, y + 16);
    PrintS(2, 14, 14, 1, x + 16, y + 16);
    PrintS(2, 0, 0, 0, x - 18, y + 17);
    PrintS(2, 8, 8, 0, x - 6, y + 17);
    PrintS(3, 14, 14, 0, x - 2, y + 17);
    PrintS(2, 8, 8, 0, x + 4, y + 17);
    PrintS(1, 14, 14, 0, x + 8, y + 17);
    PrintS(2, 0, 0, 0, x + 10, y + 17);
    PrintS(3, 14, 14, 1, x + 14, y + 17);
    PrintS(2, 0, 0, 0, x - 18, y + 18);
    PrintS(1, 8, 8, 0, x - 6, y + 18);
    PrintS(5, 14, 14, 0, x - 4, y + 18);
    PrintS(3, 8, 8, 0, x + 6, y + 18);
    PrintS(5, 14, 14, 1, x + 12, y + 18);
    PrintS(1, 0, 0, 0, x - 16, y + 19);
    PrintS(1, 14, 14, 0, x - 4, y + 19);
    PrintS(1, 8, 8, 0, x - 2, y + 19);
    PrintS(3, 14, 14, 0, x, y + 19);
    PrintS(2, 8, 8, 0, x + 6, y + 19);
    PrintS(7, 14, 14, 1, x + 10, y + 19);
    PrintS(1, 0, 0, 0, x - 16, y + 20);
    PrintS(1, 7, 7, 0, x - 6, y + 20);
    PrintS(1, 14, 14, 0, x - 4, y + 20);
    PrintS(1, 8, 8, 0, x - 2, y + 20);
    PrintS(2, 14, 14, 0, x, y + 20);
    PrintS(2, 8, 8, 0, x + 4, y + 20);
    PrintS(9, 14, 14, 1, x + 8, y + 20);
    PrintS(3, 7, 7, 0, x - 10, y + 21);
    PrintS(5, 8, 8, 0, x - 4, y + 21);
    PrintS(10, 14, 14, 1, x + 6, y + 21);
    PrintS(5, 7, 7, 0, x - 12, y + 22);
    PrintS(15, 14, 14, 1, x - 2, y + 22);
    PrintS(7, 7, 7, 0, x - 16, y + 23);
    PrintS(15, 14, 14, 1, x - 2, y + 23);
    PrintS(8, 7, 7, 0, x - 18, y + 24);
    PrintS(15, 14, 14, 1, x - 2, y + 24);
}
#pragma endregion

#pragma region 궁수 캐릭터 출력(전신)
void ArcherDot::PrintArcher(int x, int y)
{
    PrintS(2, 0, 0, 1, x, y);
    PrintS(4, 0, 0, 1, x + 2, y + 1);
    PrintS(1, 7, 7, 0, x + 4, y + 2);
    PrintS(3, 0, 0, 1, x + 10, y + 2);
    PrintS(1, 7, 7, 0, x + 2, y + 3);
    PrintS(2, 14, 14, 1, x + 12, y + 3);
    PrintS(1, 7, 7, 0, x, y + 4);
    PrintS(1, 0, 0, 0, x + 12, y + 4);
    PrintS(1, 14, 14, 1, x + 14, y + 4);
    PrintS(1, 8, 8, 0, x + 16, y + 4);
    PrintS(2, 0, 0, 1, x + 18, y + 4);
    PrintS(3, 0, 0, 0, x - 36, y + 5);
    PrintS(1, 0, 0, 0, x - 26, y + 5);
    PrintS(1, 7, 7, 0, x, y + 5);
    PrintS(1, 0, 0, 0, x + 16, y + 5);
    PrintS(2, 8, 8, 0, x + 18, y + 5);
    PrintS(1, 0, 0, 1, x + 22, y + 5);
    PrintS(6, 0, 0, 0, x - 34, y + 6);
    PrintS(1, 7, 7, 0, x - 2, y + 6);
    PrintS(1, 0, 0, 0, x + 18, y + 6);
    PrintS(2, 8, 8, 0, x + 20, y + 6);
    PrintS(1, 0, 0, 1, x + 24, y + 6);
    PrintS(5, 0, 0, 0, x - 32, y + 7);
    PrintS(1, 7, 7, 0, x - 4, y + 7);
    PrintS(1, 0, 0, 0, x + 20, y + 7);
    PrintS(1, 8, 8, 0, x + 22, y + 7);
    PrintS(1, 0, 0, 1, x + 24, y + 7);
    PrintS(4, 0, 0, 0, x - 30, y + 8);
    PrintS(1, 0, 0, 0, x - 8, y + 8);
    PrintS(1, 7, 7, 0, x - 6, y + 8);
    PrintS(1, 0, 0, 0, x + 22, y + 8);
    PrintS(1, 8, 8, 0, x + 24, y + 8);
    PrintS(1, 0, 0, 1, x + 26, y + 8);

    PrintS(6, 0, 0, 0, x - 36, y + 9);
    PrintS(1, 14, 14, 0, x - 24, y + 9);
    PrintS(8, 0, 0, 0, x - 22, y + 9);
    PrintS(1, 7, 7, 0, x - 8, y + 9);
    PrintS(1, 0, 0, 0, x + 22, y + 9);
    PrintS(2, 8, 8, 0, x + 24, y + 9);
    PrintS(1, 0, 0, 1, x + 28, y + 9);
    PrintS(4, 0, 0, 0, x - 34, y + 10);
    PrintS(1, 14, 14, 0, x - 26, y + 10);
    PrintS(7, 0, 0, 0, x - 24, y + 10);
    PrintS(1, 7, 7, 0, x - 10, y + 10);
    PrintS(2, 0, 0, 0, x - 8, y + 10);
    PrintS(1, 0, 0, 0, x + 24, y + 10);
    PrintS(1, 8, 8, 0, x + 26, y + 10);
    PrintS(1, 0, 0, 1, x + 28, y + 10);
    PrintS(1, 14, 14, 0, x - 28, y + 11);
    PrintS(7, 0, 0, 0, x - 26, y + 11);
    PrintS(1, 7, 7, 0, x - 12, y + 11);
    PrintS(3, 0, 0, 0, x - 10, y + 11);
    PrintS(4, 0, 0, 1, x + 24, y + 11);

    PrintS(2, 0, 0, 0, x - 36, y + 12);
    PrintS(1, 0, 0, 0, x - 30, y + 12);
    PrintS(1, 14, 14, 0, x - 28, y + 12);
    PrintS(7, 0, 0, 0, x - 26, y + 12);
    PrintS(1, 7, 7, 0, x - 12, y + 12);
    PrintS(2, 14, 14, 0, x - 10, y + 12);
    PrintS(1, 0, 0, 0, x - 6, y + 12);
    PrintS(1, 0, 0, 0, x + 26, y + 12);
    PrintS(1, 1, 1, 0, x + 28, y + 12);
    PrintS(1, 0, 0, 0, x + 30, y + 12);

    PrintS(5, 0, 0, 0, x - 52, y + 13);
    PrintS(1, 0, 0, 0, x - 38, y + 13);
    PrintS(1, 6, 6, 0, x - 36, y + 13);
    PrintS(1, 14, 14, 0, x - 34, y + 13);
    PrintS(1, 6, 6, 0, x - 32, y + 13);
    PrintS(4, 0, 0, 0, x - 30, y + 13);
    PrintS(1, 8, 8, 0, x - 22, y + 13);
    PrintS(2, 0, 0, 0, x - 20, y + 13);
    PrintS(1, 14, 14, 0, x - 16, y + 13);
    PrintS(1, 7, 7, 0, x - 14, y + 13);
    PrintS(3, 14, 14, 0, x - 12, y + 13);
    PrintS(2, 0, 0, 0, x - 6, y + 13);
    PrintS(1, 0, 0, 0, x + 26, y + 13);
    PrintS(2, 1, 1, 0, x + 28, y + 13);
    PrintS(1, 0, 0, 1, x + 32, y + 13);

    PrintS(1, 0, 0, 0, x - 50, y + 14);
    PrintS(5, 6, 6, 0, x - 48, y + 14);
    PrintS(1, 0, 0, 0, x - 38, y + 14);
    PrintS(3, 6, 6, 0, x - 36, y + 14);
    PrintS(4, 0, 0, 0, x - 30, y + 14);
    PrintS(1, 8, 8, 0, x - 22, y + 14);
    PrintS(2, 0, 0, 0, x - 20, y + 14);
    PrintS(1, 14, 14, 0, x - 16, y + 14);
    PrintS(1, 7, 7, 0, x - 14, y + 14);
    PrintS(3, 14, 14, 0, x - 12, y + 14);
    PrintS(2, 0, 0, 0, x - 6, y + 14);
    PrintS(1, 0, 0, 0, x + 28, y + 14);
    PrintS(2, 1, 1, 0, x + 30, y + 14);
    PrintS(1, 0, 0, 1, x + 34, y + 14);

    PrintS(1, 0, 0, 0, x - 48, y + 15);
    PrintS(4, 6, 6, 0, x - 46, y + 15);
    PrintS(1, 0, 0, 0, x - 38, y + 15);
    PrintS(2, 14, 14, 0, x - 36, y + 15);
    PrintS(4, 0, 0, 0, x - 32, y + 15);
    PrintS(1, 8, 8, 0, x - 24, y + 15);
    PrintS(3, 0, 0, 0, x - 22, y + 15);
    PrintS(1, 7, 7, 0, x - 16, y + 15);
    PrintS(1, 14, 14, 0, x - 14, y + 15);
    PrintS(2, 0, 0, 0, x - 12, y + 15);
    PrintS(1, 14, 14, 0, x - 8, y + 15);
    PrintS(1, 0, 0, 0, x - 6, y + 15);
    PrintS(1, 14, 14, 0, x - 4, y + 15);
    PrintS(1, 0, 0, 0, x + 30, y + 15);
    PrintS(1, 1, 1, 0, x + 32, y + 15);
    PrintS(2, 0, 0, 1, x + 34, y + 15);

    PrintS(2, 6, 6, 0, x - 46, y + 16);
    PrintS(3, 0, 0, 0, x - 42, y + 16);
    PrintS(1, 6, 6, 0, x - 36, y + 16);
    PrintS(6, 0, 0, 0, x - 34, y + 16);
    PrintS(1, 14, 14, 0, x - 22, y + 16);
    PrintS(2, 0, 0, 0, x - 20, y + 16);
    PrintS(1, 7, 7, 0, x - 16, y + 16);
    PrintS(1, 0, 0, 0, x - 14, y + 16);
    PrintS(1, 0, 0, 0, x - 12, y + 16);
    PrintS(4, 14, 14, 0, x - 10, y + 16);
    PrintS(5, 0, 0, 1, x + 30, y + 16);

    PrintS(1, 0, 0, 0, x - 42, y + 17);
    PrintS(2, 6, 6, 0, x - 40, y + 17);
    PrintS(7, 0, 0, 0, x - 36, y + 17);
    PrintS(1, 14, 14, 0, x - 22, y + 17);
    PrintS(1, 0, 0, 0, x - 20, y + 17);
    PrintS(1, 7, 7, 0, x - 18, y + 17);
    PrintS(7, 14, 14, 0, x - 16, y + 17);
    PrintS(1, 0, 0, 0, x + 28, y + 17);
    PrintS(2, 14, 14, 0, x + 30, y + 17);
    PrintS(1, 0, 0, 0, x + 34, y + 17);
    PrintS(2, 8, 8, 0, x + 36, y + 17);
    PrintS(1, 0, 0, 1, x + 40, y + 17);

    PrintS(1, 0, 0, 0, x - 46, y + 18);
    PrintS(3, 6, 6, 0, x - 44, y + 18);
    PrintS(1, 0, 0, 0, x - 38, y + 18);
    PrintS(3, 1, 1, 0, x - 36, y + 18);
    PrintS(3, 0, 0, 0, x - 30, y + 18);
    PrintS(1, 8, 8, 0, x - 24, y + 18);
    PrintS(2, 0, 0, 0, x - 22, y + 18);
    PrintS(1, 7, 7, 0, x - 18, y + 18);
    PrintS(3, 14, 14, 0, x - 16, y + 18);
    PrintS(1, 8, 8, 0, x - 10, y + 18);
    PrintS(2, 14, 14, 0, x - 8, y + 18);
    PrintS(3, 0, 0, 0, x, y + 18);
    PrintS(3, 0, 0, 0, x + 28, y + 18);
    PrintS(2, 14, 14, 0, x + 34, y + 18);
    PrintS(3, 0, 0, 0, x + 38, y + 18);
    PrintS(3, 7, 7, 1, x + 46, y + 18);

    PrintS(2, 0, 0, 0, x - 50, y + 19);
    PrintS(3, 6, 6, 0, x - 46, y + 19);
    PrintS(1, 0, 0, 0, x - 40, y + 19);
    PrintS(1, 1, 1, 0, x - 38, y + 19);
    PrintS(2, 6, 6, 0, x - 36, y + 19);
    PrintS(1, 1, 1, 0, x - 32, y + 19);
    PrintS(1, 0, 0, 0, x - 30, y + 19);
    PrintS(2, 8, 8, 0, x - 28, y + 19);
    PrintS(2, 0, 0, 0, x - 24, y + 19);
    PrintS(2, 8, 8, 0, x - 20, y + 19);
    PrintS(1, 0, 0, 0, x - 16, y + 19);
    PrintS(1, 14, 14, 0, x - 14, y + 19);
    PrintS(2, 8, 8, 0, x - 12, y + 19);
    PrintS(2, 14, 14, 0, x - 8, y + 19);
    PrintS(2, 0, 0, 0, x - 4, y + 19);
    PrintS(3, 14, 14, 0, x, y + 19);
    PrintS(6, 0, 0, 0, x + 10, y + 19);
    PrintS(5, 0, 0, 0, x + 26, y + 19);
    PrintS(4, 14, 14, 0, x + 36, y + 19);
    PrintS(1, 0, 0, 1, x + 44, y + 19);
    PrintS(4, 7, 7, 1, x + 48, y + 19);

    PrintS(4, 6, 6, 1, x - 50, y + 20);
    PrintS(2, 0, 0, 0, x - 42, y + 20);
    PrintS(3, 6, 6, 0, x - 38, y + 20);
    PrintS(1, 1, 1, 0, x - 32, y + 20);
    PrintS(1, 8, 8, 0, x - 30, y + 20);
    PrintS(3, 7, 7, 0, x - 28, y + 20);
    PrintS(2, 8, 8, 0, x - 22, y + 20);
    PrintS(1, 0, 0, 0, x - 18, y + 20);
    PrintS(1, 6, 6, 0, x - 16, y + 20);
    PrintS(1, 0, 0, 0, x - 14, y + 20);
    PrintS(34, 6, 6, 0, x - 14, y + 20);
    PrintS(5, 7, 7, 1, x + 48, y + 20);

    PrintS(1, 0, 0, 0, x - 50, y + 21);
    PrintS(3, 6, 6, 0, x - 48, y + 21);
    PrintS(1, 1, 1, 0, x - 42, y + 21);
    PrintS(1, 0, 0, 0, x - 40, y + 21);
    PrintS(3, 6, 6, 0, x - 38, y + 21);
    PrintS(1, 1, 1, 0, x - 32, y + 21);
    PrintS(1, 0, 0, 0, x - 30, y + 21);
    PrintS(3, 7, 7, 0, x - 28, y + 21);
    PrintS(3, 0, 0, 0, x - 22, y + 21);
    PrintS(1, 7, 7, 0, x - 16, y + 21);
    PrintS(14, 14, 14, 0, x - 14, y + 21);
    PrintS(10, 0, 0, 0, x + 14, y + 21);
    PrintS(2, 8, 8, 0, x + 34, y + 21);
    PrintS(1, 14, 14, 0, x + 38, y + 21);
    PrintS(2, 0, 0, 0, x + 40, y + 21);
    PrintS(4, 7, 7, 1, x + 48, y + 21);

    PrintS(1, 0, 0, 0, x - 48, y + 22);
    PrintS(1, 14, 14, 0, x - 46, y + 22);
    PrintS(3, 0, 0, 0, x - 44, y + 22);
    PrintS(3, 8, 8, 0, x - 38, y + 22);
    PrintS(1, 0, 0, 0, x - 32, y + 22);
    PrintS(7, 8, 8, 0, x - 30, y + 22);
    PrintS(1, 0, 0, 0, x - 16, y + 22);
    PrintS(2, 7, 7, 0, x - 14, y + 22);
    PrintS(4, 14, 14, 0, x - 10, y + 22);
    PrintS(1, 0, 0, 0, x - 2, y + 22);
    PrintS(2, 0, 0, 0, x + 30, y + 22);
    PrintS(2, 8, 8, 0, x + 34, y + 22);
    PrintS(1, 0, 0, 0, x + 38, y + 22);
    PrintS(3, 7, 7, 1, x + 46, y + 22);

    PrintS(1, 0, 0, 0, x - 48, y + 23);
    PrintS(1, 14, 14, 0, x - 46, y + 23);
    PrintS(1, 0, 0, 0, x - 42, y + 23);
    PrintS(3, 8, 8, 0, x - 40, y + 23);
    PrintS(1, 0, 0, 0, x - 34, y + 23);
    PrintS(9, 8, 8, 0, x - 32, y + 23);
    PrintS(1, 0, 0, 0, x - 14, y + 23);
    PrintS(2, 7, 7, 0, x - 12, y + 23);
    PrintS(2, 14, 14, 0, x - 8, y + 23);
    PrintS(2, 0, 0, 0, x - 4, y + 23);
    PrintS(2, 0, 0, 0, x + 30, y + 23);
    PrintS(2, 8, 8, 0, x + 34, y + 23);
    PrintS(1, 0, 0, 1, x + 38, y + 23);

    PrintS(2, 14, 14, 0, x - 50, y + 24);
    PrintS(1, 0, 0, 0, x - 38, y + 24);
    PrintS(3, 8, 8, 0, x - 36, y + 24);
    PrintS(3, 0, 0, 0, x - 30, y + 24);
    PrintS(7, 8, 8, 0, x - 24, y + 24);
    PrintS(1, 0, 0, 0, x - 12, y + 24);
    PrintS(2, 7, 7, 0, x - 10, y + 24);
    PrintS(1, 14, 14, 0, x - 6, y + 24);
    PrintS(1, 0, 0, 0, x - 4, y + 24);
    PrintS(2, 0, 0, 0, x + 30, y + 24);
    PrintS(2, 8, 8, 0, x + 34, y + 24);
    PrintS(1, 0, 0, 1, x + 38, y + 24);

    PrintS(2, 0, 0, 0, x - 52, y + 25);
    PrintS(1, 0, 0, 0, x - 26, y + 25);
    PrintS(8, 8, 8, 0, x - 24, y + 25);
    PrintS(1, 0, 0, 0, x - 8, y + 25);
    PrintS(2, 7, 7, 0, x - 6, y + 25);
    PrintS(1, 0, 0, 0, x + 32, y + 25);
    PrintS(2, 8, 8, 0, x + 34, y + 25);
    PrintS(1, 0, 0, 1, x + 38, y + 25);

    PrintS(1, 0, 0, 0, x - 52, y + 26);
    PrintS(1, 0, 0, 0, x - 30, y + 26);
    PrintS(1, 8, 8, 0, x - 28, y + 26);
    PrintS(1, 1, 1, 0, x - 26, y + 26);
    PrintS(1, 8, 8, 0, x - 24, y + 26);
    PrintS(2, 0, 0, 0, x - 22, y + 26);
    PrintS(7, 8, 8, 0, x - 18, y + 26);
    PrintS(1, 0, 0, 0, x - 4, y + 26);
    PrintS(2, 7, 7, 0, x - 2, y + 26);
    PrintS(2, 1, 1, 0, x + 34, y + 26);
    PrintS(1, 0, 0, 1, x + 38, y + 26);

    PrintS(1, 0, 0, 0, x - 32, y + 27);
    PrintS(2, 8, 8, 0, x - 30, y + 27);
    PrintS(1, 1, 1, 0, x - 26, y + 27);
    PrintS(3, 8, 8, 0, x - 24, y + 27);
    PrintS(9, 0, 0, 0, x - 18, y + 27);
    PrintS(1, 7, 7, 0, x + 2, y + 27);
    PrintS(1, 0, 0, 0, x + 34, y + 27);
    PrintS(1, 1, 1, 0, x + 36, y + 27);
    PrintS(1, 0, 0, 1, x + 38, y + 27);

    PrintS(2, 0, 0, 0, x - 42, y + 28);
    PrintS(1, 0, 0, 0, x - 34, y + 28);
    PrintS(4, 8, 8, 0, x - 32, y + 28);
    PrintS(1, 1, 1, 0, x - 24, y + 28);
    PrintS(7, 0, 0, 0, x - 22, y + 28);
    PrintS(6, 8, 8, 0, x - 10, y + 28);
    PrintS(2, 7, 7, 0, x + 4, y + 28);
    PrintS(2, 1, 1, 0, x + 34, y + 28);
    PrintS(1, 0, 0, 1, x + 38, y + 28);


    PrintS(1, 0, 0, 0, x - 44, y + 29);
    PrintS(3, 1, 1, 0, x - 42, y + 29);
    PrintS(2, 0, 0, 0, x - 36, y + 29);
    PrintS(4, 8, 8, 0, x - 32, y + 29);
    PrintS(3, 0, 0, 0, x - 24, y + 29);
    PrintS(1, 8, 8, 0, x - 18, y + 29);
    PrintS(1, 0, 0, 0, x - 16, y + 29);
    PrintS(8, 8, 8, 0, x - 14, y + 29);
    PrintS(2, 0, 0, 0, x + 2, y + 29);
    PrintS(2, 7, 7, 0, x + 8, y + 29);
    PrintS(3, 0, 0, 1, x + 32, y + 29);

    PrintS(1, 0, 0, 0, x - 44, y + 30);
    PrintS(5, 1, 1, 0, x - 42, y + 30);
    PrintS(1, 0, 0, 0, x - 32, y + 30);
    PrintS(14, 8, 8, 0, x - 30, y + 30);
    PrintS(2, 0, 0, 0, x - 2, y + 30);
    PrintS(3, 8, 8, 0, x + 2, y + 30);
    PrintS(1, 0, 0, 0, x + 8, y + 30);
    PrintS(2, 7, 7, 0, x + 12, y + 30);
    PrintS(4, 0, 0, 1, x + 30, y + 30);

    PrintS(1, 3, 3, 0, x - 44, y + 31);
    PrintS(4, 1, 1, 0, x - 42, y + 31);
    PrintS(2, 15, 15, 0, x - 34, y + 31);
    PrintS(1, 8, 8, 0, x - 30, y + 31);
    PrintS(3, 0, 0, 0, x - 28, y + 31);
    PrintS(2, 8, 8, 0, x - 22, y + 31);
    PrintS(8, 0, 0, 0, x - 18, y + 31);
    PrintS(7, 8, 8, 0, x - 2, y + 31);
    PrintS(1, 0, 0, 0, x + 12, y + 31);
    PrintS(2, 7, 7, 0, x + 16, y + 31);
    PrintS(3, 0, 0, 1, x + 30, y + 31);

    PrintS(4, 3, 3, 0, x - 44, y + 32);
    PrintS(1, 0, 0, 0, x - 36, y + 32);
    PrintS(23, 8, 8, 0, x - 34, y + 32);
    PrintS(2, 7, 7, 0, x + 20, y + 32);
    PrintS(1, 6, 6, 1, x + 32, y + 32);

    PrintS(2, 3, 3, 0, x - 46, y + 33);
    PrintS(1, 0, 0, 0, x - 42, y + 33);
    PrintS(1, 0, 0, 0, x - 38, y + 33);
    PrintS(11, 8, 8, 0, x - 36, y + 33);
    PrintS(1, 0, 0, 0, x - 14, y + 33);
    PrintS(10, 8, 8, 0, x - 12, y + 33);
    PrintS(1, 7, 7, 0, x + 8, y + 33);
    PrintS(2, 0, 0, 0, x + 10, y + 33);
    PrintS(2, 7, 7, 0, x + 24, y + 33);
    PrintS(2, 0, 0, 1, x + 30, y + 33);

    PrintS(2, 0, 0, 0, x - 50, y + 34);
    PrintS(1, 0, 0, 0, x - 38, y + 34);
    PrintS(8, 8, 8, 0, x - 36, y + 34);
    PrintS(2, 0, 0, 0, x - 20, y + 34);
    PrintS(2, 0, 0, 0, x - 10, y + 34);
    PrintS(6, 8, 8, 0, x - 6, y + 34);
    PrintS(1, 0, 0, 0, x + 6, y + 34);
    PrintS(2, 7, 7, 0, x + 8, y + 34);
    PrintS(1, 0, 0, 0, x + 12, y + 34);
    PrintS(1, 7, 7, 0, x + 26, y + 34);
    PrintS(2, 0, 0, 1, x + 28, y + 34);

    PrintS(1, 0, 0, 0, x - 38, y + 35);
    PrintS(1, 8, 8, 0, x - 36, y + 35);
    PrintS(7, 0, 0, 0, x - 34, y + 35);
    PrintS(7, 0, 0, 0, x - 6, y + 35);
    PrintS(1, 7, 7, 0, x + 8, y + 35);
    PrintS(2, 0, 0, 0, x + 10, y + 35);
    PrintS(2, 0, 0, 1, x + 26, y + 35);

    PrintS(2, 0, 0, 0, x - 38, y + 36);
    PrintS(3, 8, 8, 0, x - 34, y + 36);
    PrintS(1, 0, 0, 0, x + 6, y + 36);
    PrintS(3, 7, 7, 0, x + 8, y + 36);
    PrintS(1, 0, 0, 0, x + 14, y + 36);
    PrintS(1, 0, 0, 1, x + 26, y + 36);

    PrintS(2, 0, 0, 0, x - 34, y + 37);
    PrintS(1, 8, 8, 0, x - 30, y + 37);
    PrintS(1, 0, 0, 0, x - 28, y + 37);
    PrintS(1, 0, 0, 0, x + 10, y + 37);
    PrintS(2, 7, 7, 0, x + 12, y + 37);
    PrintS(1, 0, 0, 1, x + 14, y + 37);

    PrintS(2, 0, 0, 0, x - 28, y + 38);
    PrintS(2, 0, 0, 1, x + 14, y + 38);

    PrintS(3, 0, 0, 0, x - 28, y + 39);
    PrintS(3, 0, 0, 1, x + 16, y + 39);

    PrintS(3, 0, 0, 0, x - 28, y + 40);
    PrintS(4, 0, 0, 1, x + 16, y + 40);

    PrintS(4, 0, 0, 0, x - 30, y + 41);
    PrintS(3, 0, 0, 1, x + 20, y + 41);
}


void ArcherDot::PrintEnemyLowerArcher(int x, int y)
{
    PrintS(2, 2, 2, 1, x, y);
    PrintS(4, 2, 2, 1, x + 2, y + 1);
    PrintS(1, 7, 7, 0, x + 4, y + 2);
    PrintS(3, 2, 2, 1, x + 10, y + 2);
    PrintS(1, 7, 7, 0, x + 2, y + 3);
    PrintS(2, 14, 14, 1, x + 12, y + 3);
    PrintS(1, 7, 7, 0, x, y + 4);
    PrintS(1, 2, 2, 0, x + 12, y + 4);
    PrintS(1, 14, 14, 1, x + 14, y + 4);
    PrintS(1, 8, 8, 0, x + 16, y + 4);
    PrintS(2, 2, 2, 1, x + 18, y + 4);
    PrintS(3, 2, 2, 0, x - 36, y + 5);
    PrintS(1, 2, 2, 0, x - 26, y + 5);
    PrintS(1, 7, 7, 0, x, y + 5);
    PrintS(1, 2, 2, 0, x + 16, y + 5);
    PrintS(2, 8, 8, 0, x + 18, y + 5);
    PrintS(1, 2, 2, 1, x + 22, y + 5);
    PrintS(6, 2, 2, 0, x - 34, y + 6);
    PrintS(1, 7, 7, 0, x - 2, y + 6);
    PrintS(1, 2, 2, 0, x + 18, y + 6);
    PrintS(2, 8, 8, 0, x + 20, y + 6);
    PrintS(1, 2, 2, 1, x + 24, y + 6);
    PrintS(5, 2, 2, 0, x - 32, y + 7);
    PrintS(1, 7, 7, 0, x - 4, y + 7);
    PrintS(1, 2, 2, 0, x + 20, y + 7);
    PrintS(1, 8, 8, 0, x + 22, y + 7);
    PrintS(1, 2, 2, 1, x + 24, y + 7);
    PrintS(4, 2, 2, 0, x - 30, y + 8);
    PrintS(1, 2, 2, 0, x - 8, y + 8);
    PrintS(1, 7, 7, 0, x - 6, y + 8);
    PrintS(1, 2, 2, 0, x + 22, y + 8);
    PrintS(1, 8, 8, 0, x + 24, y + 8);
    PrintS(1, 2, 2, 1, x + 26, y + 8);

    PrintS(6, 2, 2, 0, x - 36, y + 9);
    PrintS(1, 14, 14, 0, x - 24, y + 9);
    PrintS(8, 2, 2, 0, x - 22, y + 9);
    PrintS(1, 7, 7, 0, x - 8, y + 9);
    PrintS(1, 2, 2, 0, x + 22, y + 9);
    PrintS(2, 8, 8, 0, x + 24, y + 9);
    PrintS(1, 2, 2, 1, x + 28, y + 9);
    PrintS(4, 2, 2, 0, x - 34, y + 10);
    PrintS(1, 14, 14, 0, x - 26, y + 10);
    PrintS(7, 2, 2, 0, x - 24, y + 10);
    PrintS(1, 7, 7, 0, x - 10, y + 10);
    PrintS(2, 2, 2, 0, x - 8, y + 10);
    PrintS(1, 2, 2, 0, x + 24, y + 10);
    PrintS(1, 8, 8, 0, x + 26, y + 10);
    PrintS(1, 2, 2, 1, x + 28, y + 10);
    PrintS(1, 14, 14, 0, x - 28, y + 11);
    PrintS(7, 2, 2, 0, x - 26, y + 11);
    PrintS(1, 7, 7, 0, x - 12, y + 11);
    PrintS(3, 2, 2, 0, x - 10, y + 11);
    PrintS(4, 2, 2, 1, x + 24, y + 11);

    PrintS(2, 2, 2, 0, x - 36, y + 12);
    PrintS(1, 2, 2, 0, x - 30, y + 12);
    PrintS(1, 14, 14, 0, x - 28, y + 12);
    PrintS(7, 2, 2, 0, x - 26, y + 12);
    PrintS(1, 7, 7, 0, x - 12, y + 12);
    PrintS(2, 14, 14, 0, x - 10, y + 12);
    PrintS(1, 2, 2, 0, x - 6, y + 12);
    PrintS(1, 2, 2, 0, x + 26, y + 12);
    PrintS(1, 1, 1, 0, x + 28, y + 12);
    PrintS(1, 2, 2, 0, x + 30, y + 12);

    PrintS(5, 2, 2, 0, x - 52, y + 13);
    PrintS(1, 2, 2, 0, x - 38, y + 13);
    PrintS(1, 6, 6, 0, x - 36, y + 13);
    PrintS(1, 14, 14, 0, x - 34, y + 13);
    PrintS(1, 6, 6, 0, x - 32, y + 13);
    PrintS(4, 2, 2, 0, x - 30, y + 13);
    PrintS(1, 8, 8, 0, x - 22, y + 13);
    PrintS(2, 2, 2, 0, x - 20, y + 13);
    PrintS(1, 14, 14, 0, x - 16, y + 13);
    PrintS(1, 7, 7, 0, x - 14, y + 13);
    PrintS(3, 14, 14, 0, x - 12, y + 13);
    PrintS(2, 2, 2, 0, x - 6, y + 13);
    PrintS(1, 2, 2, 0, x + 26, y + 13);
    PrintS(2, 1, 1, 0, x + 28, y + 13);
    PrintS(1, 2, 2, 1, x + 32, y + 13);

    PrintS(1, 2, 2, 0, x - 50, y + 14);
    PrintS(5, 6, 6, 0, x - 48, y + 14);
    PrintS(1, 2, 2, 0, x - 38, y + 14);
    PrintS(3, 6, 6, 0, x - 36, y + 14);
    PrintS(4, 2, 2, 0, x - 30, y + 14);
    PrintS(1, 8, 8, 0, x - 22, y + 14);
    PrintS(2, 2, 2, 0, x - 20, y + 14);
    PrintS(1, 14, 14, 0, x - 16, y + 14);
    PrintS(1, 7, 7, 0, x - 14, y + 14);
    PrintS(3, 14, 14, 0, x - 12, y + 14);
    PrintS(2, 2, 2, 0, x - 6, y + 14);
    PrintS(1, 2, 2, 0, x + 28, y + 14);
    PrintS(2, 1, 1, 0, x + 30, y + 14);
    PrintS(1, 2, 2, 1, x + 34, y + 14);

    PrintS(1, 2, 2, 0, x - 48, y + 15);
    PrintS(4, 6, 6, 0, x - 46, y + 15);
    PrintS(1, 2, 2, 0, x - 38, y + 15);
    PrintS(2, 14, 14, 0, x - 36, y + 15);
    PrintS(4, 2, 2, 0, x - 32, y + 15);
    PrintS(1, 8, 8, 0, x - 24, y + 15);
    PrintS(3, 2, 2, 0, x - 22, y + 15);
    PrintS(1, 7, 7, 0, x - 16, y + 15);
    PrintS(1, 14, 14, 0, x - 14, y + 15);
    PrintS(2, 2, 2, 0, x - 12, y + 15);
    PrintS(1, 14, 14, 0, x - 8, y + 15);
    PrintS(1, 2, 2, 0, x - 6, y + 15);
    PrintS(1, 14, 14, 0, x - 4, y + 15);
    PrintS(1, 2, 2, 0, x + 30, y + 15);
    PrintS(1, 1, 1, 0, x + 32, y + 15);
    PrintS(2, 2, 2, 1, x + 34, y + 15);

    PrintS(2, 6, 6, 0, x - 46, y + 16);
    PrintS(3, 2, 2, 0, x - 42, y + 16);
    PrintS(1, 6, 6, 0, x - 36, y + 16);
    PrintS(6, 2, 2, 0, x - 34, y + 16);
    PrintS(1, 14, 14, 0, x - 22, y + 16);
    PrintS(2, 2, 2, 0, x - 20, y + 16);
    PrintS(1, 7, 7, 0, x - 16, y + 16);
    PrintS(1, 2, 2, 0, x - 14, y + 16);
    PrintS(1, 2, 2, 0, x - 12, y + 16);
    PrintS(4, 14, 14, 0, x - 10, y + 16);
    PrintS(5, 2, 2, 1, x + 30, y + 16);

    PrintS(1, 2, 2, 0, x - 42, y + 17);
    PrintS(2, 6, 6, 0, x - 40, y + 17);
    PrintS(7, 2, 2, 0, x - 36, y + 17);
    PrintS(1, 14, 14, 0, x - 22, y + 17);
    PrintS(1, 2, 2, 0, x - 20, y + 17);
    PrintS(1, 7, 7, 0, x - 18, y + 17);
    PrintS(7, 14, 14, 0, x - 16, y + 17);
    PrintS(1, 2, 2, 0, x + 28, y + 17);
    PrintS(2, 14, 14, 0, x + 30, y + 17);
    PrintS(1, 2, 2, 0, x + 34, y + 17);
    PrintS(2, 8, 8, 0, x + 36, y + 17);
    PrintS(1, 2, 2, 1, x + 40, y + 17);

    PrintS(1, 2, 2, 0, x - 46, y + 18);
    PrintS(3, 6, 6, 0, x - 44, y + 18);
    PrintS(1, 2, 2, 0, x - 38, y + 18);
    PrintS(3, 1, 1, 0, x - 36, y + 18);
    PrintS(3, 2, 2, 0, x - 30, y + 18);
    PrintS(1, 8, 8, 0, x - 24, y + 18);
    PrintS(2, 2, 2, 0, x - 22, y + 18);
    PrintS(1, 7, 7, 0, x - 18, y + 18);
    PrintS(3, 14, 14, 0, x - 16, y + 18);
    PrintS(1, 8, 8, 0, x - 10, y + 18);
    PrintS(2, 14, 14, 0, x - 8, y + 18);
    PrintS(3, 2, 2, 0, x, y + 18);
    PrintS(3, 2, 2, 0, x + 28, y + 18);
    PrintS(2, 14, 14, 0, x + 34, y + 18);
    PrintS(3, 2, 2, 0, x + 38, y + 18);
    PrintS(3, 7, 7, 1, x + 46, y + 18);

    PrintS(2, 2, 2, 0, x - 50, y + 19);
    PrintS(3, 6, 6, 0, x - 46, y + 19);
    PrintS(1, 2, 2, 0, x - 40, y + 19);
    PrintS(1, 1, 1, 0, x - 38, y + 19);
    PrintS(2, 6, 6, 0, x - 36, y + 19);
    PrintS(1, 1, 1, 0, x - 32, y + 19);
    PrintS(1, 2, 2, 0, x - 30, y + 19);
    PrintS(2, 8, 8, 0, x - 28, y + 19);
    PrintS(2, 2, 2, 0, x - 24, y + 19);
    PrintS(2, 8, 8, 0, x - 20, y + 19);
    PrintS(1, 2, 2, 0, x - 16, y + 19);
    PrintS(1, 14, 14, 0, x - 14, y + 19);
    PrintS(2, 8, 8, 0, x - 12, y + 19);
    PrintS(2, 14, 14, 0, x - 8, y + 19);
    PrintS(2, 2, 2, 0, x - 4, y + 19);
    PrintS(3, 14, 14, 0, x, y + 19);
    PrintS(6, 2, 2, 0, x + 10, y + 19);
    PrintS(5, 2, 2, 0, x + 26, y + 19);
    PrintS(4, 14, 14, 0, x + 36, y + 19);
    PrintS(1, 2, 2, 1, x + 44, y + 19);
    PrintS(4, 7, 7, 1, x + 48, y + 19);

    PrintS(4, 6, 6, 1, x - 50, y + 20);
    PrintS(2, 2, 2, 0, x - 42, y + 20);
    PrintS(3, 6, 6, 0, x - 38, y + 20);
    PrintS(1, 1, 1, 0, x - 32, y + 20);
    PrintS(1, 8, 8, 0, x - 30, y + 20);
    PrintS(3, 7, 7, 0, x - 28, y + 20);
    PrintS(2, 8, 8, 0, x - 22, y + 20);
    PrintS(1, 2, 2, 0, x - 18, y + 20);
    PrintS(1, 6, 6, 0, x - 16, y + 20);
    PrintS(1, 2, 2, 0, x - 14, y + 20);
    PrintS(34, 6, 6, 0, x - 14, y + 20);
    PrintS(5, 7, 7, 1, x + 48, y + 20);

    PrintS(1, 2, 2, 0, x - 50, y + 21);
    PrintS(3, 6, 6, 0, x - 48, y + 21);
    PrintS(1, 1, 1, 0, x - 42, y + 21);
    PrintS(1, 2, 2, 0, x - 40, y + 21);
    PrintS(3, 6, 6, 0, x - 38, y + 21);
    PrintS(1, 1, 1, 0, x - 32, y + 21);
    PrintS(1, 2, 2, 0, x - 30, y + 21);
    PrintS(3, 7, 7, 0, x - 28, y + 21);
    PrintS(3, 2, 2, 0, x - 22, y + 21);
    PrintS(1, 7, 7, 0, x - 16, y + 21);
    PrintS(14, 14, 14, 0, x - 14, y + 21);
    PrintS(10, 2, 2, 0, x + 14, y + 21);
    PrintS(2, 8, 8, 0, x + 34, y + 21);
    PrintS(1, 14, 14, 0, x + 38, y + 21);
    PrintS(2, 2, 2, 0, x + 40, y + 21);
    PrintS(4, 7, 7, 1, x + 48, y + 21);

    PrintS(1, 2, 2, 0, x - 48, y + 22);
    PrintS(1, 14, 14, 0, x - 46, y + 22);
    PrintS(3, 2, 2, 0, x - 44, y + 22);
    PrintS(3, 8, 8, 0, x - 38, y + 22);
    PrintS(1, 2, 2, 0, x - 32, y + 22);
    PrintS(7, 8, 8, 0, x - 30, y + 22);
    PrintS(1, 2, 2, 0, x - 16, y + 22);
    PrintS(2, 7, 7, 0, x - 14, y + 22);
    PrintS(4, 14, 14, 0, x - 10, y + 22);
    PrintS(1, 2, 2, 0, x - 2, y + 22);
    PrintS(2, 2, 2, 0, x + 30, y + 22);
    PrintS(2, 8, 8, 0, x + 34, y + 22);
    PrintS(1, 2, 2, 0, x + 38, y + 22);
    PrintS(3, 7, 7, 1, x + 46, y + 22);

    PrintS(1, 2, 2, 0, x - 48, y + 23);
    PrintS(1, 14, 14, 0, x - 46, y + 23);
    PrintS(1, 2, 2, 0, x - 42, y + 23);
    PrintS(3, 8, 8, 0, x - 40, y + 23);
    PrintS(1, 2, 2, 0, x - 34, y + 23);
    PrintS(9, 8, 8, 0, x - 32, y + 23);
    PrintS(1, 2, 2, 0, x - 14, y + 23);
    PrintS(2, 7, 7, 0, x - 12, y + 23);
    PrintS(2, 14, 14, 0, x - 8, y + 23);
    PrintS(2, 2, 2, 0, x - 4, y + 23);
    PrintS(2, 2, 2, 0, x + 30, y + 23);
    PrintS(2, 8, 8, 0, x + 34, y + 23);
    PrintS(1, 2, 2, 1, x + 38, y + 23);

    PrintS(2, 14, 14, 0, x - 50, y + 24);
    PrintS(1, 2, 2, 0, x - 38, y + 24);
    PrintS(3, 8, 8, 0, x - 36, y + 24);
    PrintS(3, 2, 2, 0, x - 30, y + 24);
    PrintS(7, 8, 8, 0, x - 24, y + 24);
    PrintS(1, 2, 2, 0, x - 12, y + 24);
    PrintS(2, 7, 7, 0, x - 10, y + 24);
    PrintS(1, 14, 14, 0, x - 6, y + 24);
    PrintS(1, 2, 2, 0, x - 4, y + 24);
    PrintS(2, 2, 2, 0, x + 30, y + 24);
    PrintS(2, 8, 8, 0, x + 34, y + 24);
    PrintS(1, 2, 2, 1, x + 38, y + 24);

    PrintS(2, 2, 2, 0, x - 52, y + 25);
    PrintS(1, 2, 2, 0, x - 26, y + 25);
    PrintS(8, 8, 8, 0, x - 24, y + 25);
    PrintS(1, 2, 2, 0, x - 8, y + 25);
    PrintS(2, 7, 7, 0, x - 6, y + 25);
    PrintS(1, 2, 2, 0, x + 32, y + 25);
    PrintS(2, 8, 8, 0, x + 34, y + 25);
    PrintS(1, 2, 2, 1, x + 38, y + 25);

    PrintS(1, 2, 2, 0, x - 52, y + 26);
    PrintS(1, 2, 2, 0, x - 30, y + 26);
    PrintS(1, 8, 8, 0, x - 28, y + 26);
    PrintS(1, 1, 1, 0, x - 26, y + 26);
    PrintS(1, 8, 8, 0, x - 24, y + 26);
    PrintS(2, 2, 2, 0, x - 22, y + 26);
    PrintS(7, 8, 8, 0, x - 18, y + 26);
    PrintS(1, 2, 2, 0, x - 4, y + 26);
    PrintS(2, 7, 7, 0, x - 2, y + 26);
    PrintS(2, 1, 1, 0, x + 34, y + 26);
    PrintS(1, 2, 2, 1, x + 38, y + 26);

    PrintS(1, 2, 2, 0, x - 32, y + 27);
    PrintS(2, 8, 8, 0, x - 30, y + 27);
    PrintS(1, 1, 1, 0, x - 26, y + 27);
    PrintS(3, 8, 8, 0, x - 24, y + 27);
    PrintS(9, 2, 2, 0, x - 18, y + 27);
    PrintS(1, 7, 7, 0, x + 2, y + 27);
    PrintS(1, 2, 2, 0, x + 34, y + 27);
    PrintS(1, 1, 1, 0, x + 36, y + 27);
    PrintS(1, 2, 2, 1, x + 38, y + 27);

    PrintS(2, 2, 2, 0, x - 42, y + 28);
    PrintS(1, 2, 2, 0, x - 34, y + 28);
    PrintS(4, 8, 8, 0, x - 32, y + 28);
    PrintS(1, 1, 1, 0, x - 24, y + 28);
    PrintS(7, 2, 2, 0, x - 22, y + 28);
    PrintS(6, 8, 8, 0, x - 10, y + 28);
    PrintS(2, 7, 7, 0, x + 4, y + 28);
    PrintS(2, 1, 1, 0, x + 34, y + 28);
    PrintS(1, 2, 2, 1, x + 38, y + 28);


    PrintS(1, 2, 2, 0, x - 44, y + 29);
    PrintS(3, 1, 1, 0, x - 42, y + 29);
    PrintS(2, 2, 2, 0, x - 36, y + 29);
    PrintS(4, 8, 8, 0, x - 32, y + 29);
    PrintS(3, 2, 2, 0, x - 24, y + 29);
    PrintS(1, 8, 8, 0, x - 18, y + 29);
    PrintS(1, 2, 2, 0, x - 16, y + 29);
    PrintS(8, 8, 8, 0, x - 14, y + 29);
    PrintS(2, 2, 2, 0, x + 2, y + 29);
    PrintS(2, 7, 7, 0, x + 8, y + 29);
    PrintS(3, 2, 2, 1, x + 32, y + 29);

    PrintS(1, 2, 2, 0, x - 44, y + 30);
    PrintS(5, 1, 1, 0, x - 42, y + 30);
    PrintS(1, 2, 2, 0, x - 32, y + 30);
    PrintS(14, 8, 8, 0, x - 30, y + 30);
    PrintS(2, 2, 2, 0, x - 2, y + 30);
    PrintS(3, 8, 8, 0, x + 2, y + 30);
    PrintS(1, 2, 2, 0, x + 8, y + 30);
    PrintS(2, 7, 7, 0, x + 12, y + 30);
    PrintS(4, 2, 2, 1, x + 30, y + 30);

    PrintS(1, 3, 3, 0, x - 44, y + 31);
    PrintS(4, 1, 1, 0, x - 42, y + 31);
    PrintS(2, 2, 2, 0, x - 34, y + 31);
    PrintS(1, 8, 8, 0, x - 30, y + 31);
    PrintS(3, 2, 2, 0, x - 28, y + 31);
    PrintS(2, 8, 8, 0, x - 22, y + 31);
    PrintS(8, 2, 2, 0, x - 18, y + 31);
    PrintS(7, 8, 8, 0, x - 2, y + 31);
    PrintS(1, 2, 2, 0, x + 12, y + 31);
    PrintS(2, 7, 7, 0, x + 16, y + 31);
    PrintS(3, 2, 2, 1, x + 30, y + 31);

    PrintS(4, 3, 3, 0, x - 44, y + 32);
    PrintS(1, 2, 2, 0, x - 36, y + 32);
    PrintS(23, 8, 8, 0, x - 34, y + 32);
    PrintS(2, 7, 7, 0, x + 20, y + 32);
    PrintS(1, 6, 6, 1, x + 32, y + 32);

    PrintS(2, 3, 3, 0, x - 46, y + 33);
    PrintS(1, 2, 2, 0, x - 42, y + 33);
    PrintS(1, 2, 2, 0, x - 38, y + 33);
    PrintS(11, 8, 8, 0, x - 36, y + 33);
    PrintS(1, 2, 2, 0, x - 14, y + 33);
    PrintS(10, 8, 8, 0, x - 12, y + 33);
    PrintS(1, 7, 7, 0, x + 8, y + 33);
    PrintS(2, 2, 2, 0, x + 10, y + 33);
    PrintS(2, 7, 7, 0, x + 24, y + 33);
    PrintS(2, 2, 2, 1, x + 30, y + 33);

    PrintS(2, 2, 2, 0, x - 50, y + 34);
    PrintS(1, 2, 2, 0, x - 38, y + 34);
    PrintS(8, 8, 8, 0, x - 36, y + 34);
    PrintS(2, 2, 2, 0, x - 20, y + 34);
    PrintS(2, 2, 2, 0, x - 10, y + 34);
    PrintS(6, 8, 8, 0, x - 6, y + 34);
    PrintS(1, 2, 2, 0, x + 6, y + 34);
    PrintS(2, 7, 7, 0, x + 8, y + 34);
    PrintS(1, 2, 2, 0, x + 12, y + 34);
    PrintS(1, 7, 7, 0, x + 26, y + 34);
    PrintS(2, 2, 2, 1, x + 28, y + 34);

    PrintS(1, 2, 2, 0, x - 38, y + 35);
    PrintS(1, 8, 8, 0, x - 36, y + 35);
    PrintS(7, 2, 2, 0, x - 34, y + 35);
    PrintS(7, 2, 2, 0, x - 6, y + 35);
    PrintS(1, 7, 7, 0, x + 8, y + 35);
    PrintS(2, 2, 2, 0, x + 10, y + 35);
    PrintS(2, 2, 2, 1, x + 26, y + 35);

    PrintS(2, 2, 2, 0, x - 38, y + 36);
    PrintS(3, 8, 8, 0, x - 34, y + 36);
    PrintS(1, 2, 2, 0, x + 6, y + 36);
    PrintS(3, 7, 7, 0, x + 8, y + 36);
    PrintS(1, 2, 2, 0, x + 14, y + 36);
    PrintS(1, 2, 2, 1, x + 26, y + 36);

    PrintS(2, 2, 2, 0, x - 34, y + 37);
    PrintS(1, 8, 8, 0, x - 30, y + 37);
    PrintS(1, 2, 2, 0, x - 28, y + 37);
    PrintS(1, 2, 2, 0, x + 10, y + 37);
    PrintS(2, 7, 7, 0, x + 12, y + 37);
    PrintS(1, 2, 2, 1, x + 14, y + 37);

    PrintS(2, 2, 2, 0, x - 28, y + 38);
    PrintS(2, 2, 2, 1, x + 14, y + 38);

    PrintS(3, 2, 2, 0, x - 28, y + 39);
    PrintS(3, 2, 2, 1, x + 16, y + 39);

    PrintS(3, 2, 2, 0, x - 28, y + 40);
    PrintS(4, 2, 2, 1, x + 16, y + 40);

    PrintS(4, 2, 2, 0, x - 30, y + 41);
    PrintS(3, 2, 2, 1, x + 20, y + 41);
}
void ArcherDot::PrintIntermediateArcher(int x, int y)
{
    PrintS(2, 4, 4, 1, x, y);
    PrintS(4, 4, 4, 1, x + 2, y + 1);
    PrintS(1, 7, 7, 0, x + 4, y + 2);
    PrintS(3, 4, 4, 1, x + 10, y + 2);
    PrintS(1, 7, 7, 0, x + 2, y + 3);
    PrintS(2, 14, 14, 1, x + 12, y + 3);
    PrintS(1, 7, 7, 0, x, y + 4);
    PrintS(1, 4, 4, 0, x + 12, y + 4);
    PrintS(1, 14, 14, 1, x + 14, y + 4);
    PrintS(1, 8, 8, 0, x + 16, y + 4);
    PrintS(2, 4, 4, 1, x + 18, y + 4);
    PrintS(3, 4, 4, 0, x - 36, y + 5);
    PrintS(1, 4, 4, 0, x - 26, y + 5);
    PrintS(1, 7, 7, 0, x, y + 5);
    PrintS(1, 4, 4, 0, x + 16, y + 5);
    PrintS(2, 8, 8, 0, x + 18, y + 5);
    PrintS(1, 4, 4, 1, x + 22, y + 5);
    PrintS(6, 4, 4, 0, x - 34, y + 6);
    PrintS(1, 7, 7, 0, x - 2, y + 6);
    PrintS(1, 4, 4, 0, x + 18, y + 6);
    PrintS(2, 8, 8, 0, x + 20, y + 6);
    PrintS(1, 4, 4, 1, x + 24, y + 6);
    PrintS(5, 4, 4, 0, x - 32, y + 7);
    PrintS(1, 7, 7, 0, x - 4, y + 7);
    PrintS(1, 4, 4, 0, x + 20, y + 7);
    PrintS(1, 8, 8, 0, x + 22, y + 7);
    PrintS(1, 4, 4, 1, x + 24, y + 7);
    PrintS(4, 4, 4, 0, x - 30, y + 8);
    PrintS(1, 4, 4, 0, x - 8, y + 8);
    PrintS(1, 7, 7, 0, x - 6, y + 8);
    PrintS(1, 4, 4, 0, x + 22, y + 8);
    PrintS(1, 8, 8, 0, x + 24, y + 8);
    PrintS(1, 4, 4, 1, x + 26, y + 8);

    PrintS(6, 4, 4, 0, x - 36, y + 9);
    PrintS(1, 14, 14, 0, x - 24, y + 9);
    PrintS(8, 4, 4, 0, x - 22, y + 9);
    PrintS(1, 7, 7, 0, x - 8, y + 9);
    PrintS(1, 4, 4, 0, x + 22, y + 9);
    PrintS(2, 8, 8, 0, x + 24, y + 9);
    PrintS(1, 4, 4, 1, x + 28, y + 9);
    PrintS(4, 4, 4, 0, x - 34, y + 10);
    PrintS(1, 14, 14, 0, x - 26, y + 10);
    PrintS(7, 4, 4, 0, x - 24, y + 10);
    PrintS(1, 7, 7, 0, x - 10, y + 10);
    PrintS(2, 4, 4, 0, x - 8, y + 10);
    PrintS(1, 4, 4, 0, x + 24, y + 10);
    PrintS(1, 8, 8, 0, x + 26, y + 10);
    PrintS(1, 4, 4, 1, x + 28, y + 10);
    PrintS(1, 14, 14, 0, x - 28, y + 11);
    PrintS(7, 4, 4, 0, x - 26, y + 11);
    PrintS(1, 7, 7, 0, x - 12, y + 11);
    PrintS(3, 4, 4, 0, x - 10, y + 11);
    PrintS(4, 4, 4, 1, x + 24, y + 11);

    PrintS(2, 4, 4, 0, x - 36, y + 12);
    PrintS(1, 4, 4, 0, x - 30, y + 12);
    PrintS(1, 14, 14, 0, x - 28, y + 12);
    PrintS(7, 4, 4, 0, x - 26, y + 12);
    PrintS(1, 7, 7, 0, x - 12, y + 12);
    PrintS(2, 14, 14, 0, x - 10, y + 12);
    PrintS(1, 4, 4, 0, x - 6, y + 12);
    PrintS(1, 4, 4, 0, x + 26, y + 12);
    PrintS(1, 1, 1, 0, x + 28, y + 12);
    PrintS(1, 4, 4, 0, x + 30, y + 12);

    PrintS(5, 4, 4, 0, x - 52, y + 13);
    PrintS(1, 4, 4, 0, x - 38, y + 13);
    PrintS(1, 6, 6, 0, x - 36, y + 13);
    PrintS(1, 14, 14, 0, x - 34, y + 13);
    PrintS(1, 6, 6, 0, x - 32, y + 13);
    PrintS(4, 4, 4, 0, x - 30, y + 13);
    PrintS(1, 8, 8, 0, x - 22, y + 13);
    PrintS(2, 4, 4, 0, x - 20, y + 13);
    PrintS(1, 14, 14, 0, x - 16, y + 13);
    PrintS(1, 7, 7, 0, x - 14, y + 13);
    PrintS(3, 14, 14, 0, x - 12, y + 13);
    PrintS(2, 4, 4, 0, x - 6, y + 13);
    PrintS(1, 4, 4, 0, x + 26, y + 13);
    PrintS(2, 1, 1, 0, x + 28, y + 13);
    PrintS(1, 4, 4, 1, x + 32, y + 13);

    PrintS(1, 4, 4, 0, x - 50, y + 14);
    PrintS(5, 6, 6, 0, x - 48, y + 14);
    PrintS(1, 4, 4, 0, x - 38, y + 14);
    PrintS(3, 6, 6, 0, x - 36, y + 14);
    PrintS(4, 4, 4, 0, x - 30, y + 14);
    PrintS(1, 8, 8, 0, x - 22, y + 14);
    PrintS(2, 4, 4, 0, x - 20, y + 14);
    PrintS(1, 14, 14, 0, x - 16, y + 14);
    PrintS(1, 7, 7, 0, x - 14, y + 14);
    PrintS(3, 14, 14, 0, x - 12, y + 14);
    PrintS(2, 4, 4, 0, x - 6, y + 14);
    PrintS(1, 4, 4, 0, x + 28, y + 14);
    PrintS(2, 1, 1, 0, x + 30, y + 14);
    PrintS(1, 4, 4, 1, x + 34, y + 14);

    PrintS(1, 4, 4, 0, x - 48, y + 15);
    PrintS(4, 6, 6, 0, x - 46, y + 15);
    PrintS(1, 4, 4, 0, x - 38, y + 15);
    PrintS(2, 14, 14, 0, x - 36, y + 15);
    PrintS(4, 4, 4, 0, x - 32, y + 15);
    PrintS(1, 8, 8, 0, x - 24, y + 15);
    PrintS(3, 4, 4, 0, x - 22, y + 15);
    PrintS(1, 7, 7, 0, x - 16, y + 15);
    PrintS(1, 14, 14, 0, x - 14, y + 15);
    PrintS(2, 4, 4, 0, x - 12, y + 15);
    PrintS(1, 14, 14, 0, x - 8, y + 15);
    PrintS(1, 4, 4, 0, x - 6, y + 15);
    PrintS(1, 14, 14, 0, x - 4, y + 15);
    PrintS(1, 4, 4, 0, x + 30, y + 15);
    PrintS(1, 1, 1, 0, x + 32, y + 15);
    PrintS(2, 4, 4, 1, x + 34, y + 15);

    PrintS(2, 6, 6, 0, x - 46, y + 16);
    PrintS(3, 4, 4, 0, x - 42, y + 16);
    PrintS(1, 6, 6, 0, x - 36, y + 16);
    PrintS(6, 4, 4, 0, x - 34, y + 16);
    PrintS(1, 14, 14, 0, x - 22, y + 16);
    PrintS(2, 4, 4, 0, x - 20, y + 16);
    PrintS(1, 7, 7, 0, x - 16, y + 16);
    PrintS(1, 4, 4, 0, x - 14, y + 16);
    PrintS(1, 4, 4, 0, x - 12, y + 16);
    PrintS(4, 14, 14, 0, x - 10, y + 16);
    PrintS(5, 4, 4, 1, x + 30, y + 16);

    PrintS(1, 4, 4, 0, x - 42, y + 17);
    PrintS(2, 6, 6, 0, x - 40, y + 17);
    PrintS(7, 4, 4, 0, x - 36, y + 17);
    PrintS(1, 14, 14, 0, x - 22, y + 17);
    PrintS(1, 4, 4, 0, x - 20, y + 17);
    PrintS(1, 7, 7, 0, x - 18, y + 17);
    PrintS(7, 14, 14, 0, x - 16, y + 17);
    PrintS(1, 4, 4, 0, x + 28, y + 17);
    PrintS(2, 14, 14, 0, x + 30, y + 17);
    PrintS(1, 4, 4, 0, x + 34, y + 17);
    PrintS(2, 8, 8, 0, x + 36, y + 17);
    PrintS(1, 4, 4, 1, x + 40, y + 17);

    PrintS(1, 4, 4, 0, x - 46, y + 18);
    PrintS(3, 6, 6, 0, x - 44, y + 18);
    PrintS(1, 4, 4, 0, x - 38, y + 18);
    PrintS(3, 1, 1, 0, x - 36, y + 18);
    PrintS(3, 4, 4, 0, x - 30, y + 18);
    PrintS(1, 8, 8, 0, x - 24, y + 18);
    PrintS(2, 4, 4, 0, x - 22, y + 18);
    PrintS(1, 7, 7, 0, x - 18, y + 18);
    PrintS(3, 14, 14, 0, x - 16, y + 18);
    PrintS(1, 8, 8, 0, x - 10, y + 18);
    PrintS(2, 14, 14, 0, x - 8, y + 18);
    PrintS(3, 4, 4, 0, x, y + 18);
    PrintS(3, 4, 4, 0, x + 28, y + 18);
    PrintS(2, 14, 14, 0, x + 34, y + 18);
    PrintS(3, 4, 4, 0, x + 38, y + 18);
    PrintS(3, 7, 7, 1, x + 46, y + 18);

    PrintS(2, 4, 4, 0, x - 50, y + 19);
    PrintS(3, 6, 6, 0, x - 46, y + 19);
    PrintS(1, 4, 4, 0, x - 40, y + 19);
    PrintS(1, 1, 1, 0, x - 38, y + 19);
    PrintS(2, 6, 6, 0, x - 36, y + 19);
    PrintS(1, 1, 1, 0, x - 32, y + 19);
    PrintS(1, 4, 4, 0, x - 30, y + 19);
    PrintS(2, 8, 8, 0, x - 28, y + 19);
    PrintS(2, 4, 4, 0, x - 24, y + 19);
    PrintS(2, 8, 8, 0, x - 20, y + 19);
    PrintS(1, 4, 4, 0, x - 16, y + 19);
    PrintS(1, 14, 14, 0, x - 14, y + 19);
    PrintS(2, 8, 8, 0, x - 12, y + 19);
    PrintS(2, 14, 14, 0, x - 8, y + 19);
    PrintS(2, 4, 4, 0, x - 4, y + 19);
    PrintS(3, 14, 14, 0, x, y + 19);
    PrintS(6, 4, 4, 0, x + 10, y + 19);
    PrintS(5, 4, 4, 0, x + 26, y + 19);
    PrintS(4, 14, 14, 0, x + 36, y + 19);
    PrintS(1, 4, 4, 1, x + 44, y + 19);
    PrintS(4, 7, 7, 1, x + 48, y + 19);

    PrintS(4, 6, 6, 1, x - 50, y + 20);
    PrintS(2, 4, 4, 0, x - 42, y + 20);
    PrintS(3, 6, 6, 0, x - 38, y + 20);
    PrintS(1, 1, 1, 0, x - 32, y + 20);
    PrintS(1, 8, 8, 0, x - 30, y + 20);
    PrintS(3, 7, 7, 0, x - 28, y + 20);
    PrintS(2, 8, 8, 0, x - 22, y + 20);
    PrintS(1, 4, 4, 0, x - 18, y + 20);
    PrintS(1, 6, 6, 0, x - 16, y + 20);
    PrintS(1, 4, 4, 0, x - 14, y + 20);
    PrintS(34, 6, 6, 0, x - 14, y + 20);
    PrintS(5, 7, 7, 1, x + 48, y + 20);

    PrintS(1, 4, 4, 0, x - 50, y + 21);
    PrintS(3, 6, 6, 0, x - 48, y + 21);
    PrintS(1, 1, 1, 0, x - 42, y + 21);
    PrintS(1, 4, 4, 0, x - 40, y + 21);
    PrintS(3, 6, 6, 0, x - 38, y + 21);
    PrintS(1, 1, 1, 0, x - 32, y + 21);
    PrintS(1, 4, 4, 0, x - 30, y + 21);
    PrintS(3, 7, 7, 0, x - 28, y + 21);
    PrintS(3, 4, 4, 0, x - 22, y + 21);
    PrintS(1, 7, 7, 0, x - 16, y + 21);
    PrintS(14, 14, 14, 0, x - 14, y + 21);
    PrintS(10, 4, 4, 0, x + 14, y + 21);
    PrintS(2, 8, 8, 0, x + 34, y + 21);
    PrintS(1, 14, 14, 0, x + 38, y + 21);
    PrintS(2, 4, 4, 0, x + 40, y + 21);
    PrintS(4, 7, 7, 1, x + 48, y + 21);

    PrintS(1, 4, 4, 0, x - 48, y + 22);
    PrintS(1, 14, 14, 0, x - 46, y + 22);
    PrintS(3, 4, 4, 0, x - 44, y + 22);
    PrintS(3, 8, 8, 0, x - 38, y + 22);
    PrintS(1, 4, 4, 0, x - 32, y + 22);
    PrintS(7, 8, 8, 0, x - 30, y + 22);
    PrintS(1, 4, 4, 0, x - 16, y + 22);
    PrintS(2, 7, 7, 0, x - 14, y + 22);
    PrintS(4, 14, 14, 0, x - 10, y + 22);
    PrintS(1, 4, 4, 0, x - 2, y + 22);
    PrintS(2, 4, 4, 0, x + 30, y + 22);
    PrintS(2, 8, 8, 0, x + 34, y + 22);
    PrintS(1, 4, 4, 0, x + 38, y + 22);
    PrintS(3, 7, 7, 1, x + 46, y + 22);

    PrintS(1, 4, 4, 0, x - 48, y + 23);
    PrintS(1, 14, 14, 0, x - 46, y + 23);
    PrintS(1, 4, 4, 0, x - 42, y + 23);
    PrintS(3, 8, 8, 0, x - 40, y + 23);
    PrintS(1, 4, 4, 0, x - 34, y + 23);
    PrintS(9, 8, 8, 0, x - 32, y + 23);
    PrintS(1, 4, 4, 0, x - 14, y + 23);
    PrintS(2, 7, 7, 0, x - 12, y + 23);
    PrintS(2, 14, 14, 0, x - 8, y + 23);
    PrintS(2, 4, 4, 0, x - 4, y + 23);
    PrintS(2, 4, 4, 0, x + 30, y + 23);
    PrintS(2, 8, 8, 0, x + 34, y + 23);
    PrintS(1, 4, 4, 1, x + 38, y + 23);

    PrintS(2, 14, 14, 0, x - 50, y + 24);
    PrintS(1, 4, 4, 0, x - 38, y + 24);
    PrintS(3, 8, 8, 0, x - 36, y + 24);
    PrintS(3, 4, 4, 0, x - 30, y + 24);
    PrintS(7, 8, 8, 0, x - 24, y + 24);
    PrintS(1, 4, 4, 0, x - 12, y + 24);
    PrintS(2, 7, 7, 0, x - 10, y + 24);
    PrintS(1, 14, 14, 0, x - 6, y + 24);
    PrintS(1, 4, 4, 0, x - 4, y + 24);
    PrintS(2, 4, 4, 0, x + 30, y + 24);
    PrintS(2, 8, 8, 0, x + 34, y + 24);
    PrintS(1, 4, 4, 1, x + 38, y + 24);

    PrintS(2, 4, 4, 0, x - 52, y + 25);
    PrintS(1, 4, 4, 0, x - 26, y + 25);
    PrintS(8, 8, 8, 0, x - 24, y + 25);
    PrintS(1, 4, 4, 0, x - 8, y + 25);
    PrintS(2, 7, 7, 0, x - 6, y + 25);
    PrintS(1, 4, 4, 0, x + 32, y + 25);
    PrintS(2, 8, 8, 0, x + 34, y + 25);
    PrintS(1, 4, 4, 1, x + 38, y + 25);

    PrintS(1, 4, 4, 0, x - 52, y + 26);
    PrintS(1, 4, 4, 0, x - 30, y + 26);
    PrintS(1, 8, 8, 0, x - 28, y + 26);
    PrintS(1, 1, 1, 0, x - 26, y + 26);
    PrintS(1, 8, 8, 0, x - 24, y + 26);
    PrintS(2, 4, 4, 0, x - 22, y + 26);
    PrintS(7, 8, 8, 0, x - 18, y + 26);
    PrintS(1, 4, 4, 0, x - 4, y + 26);
    PrintS(2, 7, 7, 0, x - 2, y + 26);
    PrintS(2, 1, 1, 0, x + 34, y + 26);
    PrintS(1, 4, 4, 1, x + 38, y + 26);

    PrintS(1, 4, 4, 0, x - 32, y + 27);
    PrintS(2, 8, 8, 0, x - 30, y + 27);
    PrintS(1, 1, 1, 0, x - 26, y + 27);
    PrintS(3, 8, 8, 0, x - 24, y + 27);
    PrintS(9, 4, 4, 0, x - 18, y + 27);
    PrintS(1, 7, 7, 0, x + 2, y + 27);
    PrintS(1, 4, 4, 0, x + 34, y + 27);
    PrintS(1, 1, 1, 0, x + 36, y + 27);
    PrintS(1, 4, 4, 1, x + 38, y + 27);

    PrintS(2, 4, 4, 0, x - 42, y + 28);
    PrintS(1, 4, 4, 0, x - 34, y + 28);
    PrintS(4, 8, 8, 0, x - 32, y + 28);
    PrintS(1, 1, 1, 0, x - 24, y + 28);
    PrintS(7, 4, 4, 0, x - 22, y + 28);
    PrintS(6, 8, 8, 0, x - 10, y + 28);
    PrintS(2, 7, 7, 0, x + 4, y + 28);
    PrintS(2, 1, 1, 0, x + 34, y + 28);
    PrintS(1, 4, 4, 1, x + 38, y + 28);


    PrintS(1, 4, 4, 0, x - 44, y + 29);
    PrintS(3, 1, 1, 0, x - 42, y + 29);
    PrintS(2, 4, 4, 0, x - 36, y + 29);
    PrintS(4, 8, 8, 0, x - 32, y + 29);
    PrintS(3, 4, 4, 0, x - 24, y + 29);
    PrintS(1, 8, 8, 0, x - 18, y + 29);
    PrintS(1, 4, 4, 0, x - 16, y + 29);
    PrintS(8, 8, 8, 0, x - 14, y + 29);
    PrintS(2, 4, 4, 0, x + 2, y + 29);
    PrintS(2, 7, 7, 0, x + 8, y + 29);
    PrintS(3, 4, 4, 1, x + 32, y + 29);

    PrintS(1, 4, 4, 0, x - 44, y + 30);
    PrintS(5, 1, 1, 0, x - 42, y + 30);
    PrintS(1, 4, 4, 0, x - 32, y + 30);
    PrintS(14, 8, 8, 0, x - 30, y + 30);
    PrintS(2, 4, 4, 0, x - 2, y + 30);
    PrintS(3, 8, 8, 0, x + 2, y + 30);
    PrintS(1, 4, 4, 0, x + 8, y + 30);
    PrintS(2, 7, 7, 0, x + 12, y + 30);
    PrintS(4, 4, 4, 1, x + 30, y + 30);

    PrintS(1, 3, 3, 0, x - 44, y + 31);
    PrintS(4, 1, 1, 0, x - 42, y + 31);
    PrintS(2, 4, 4, 0, x - 34, y + 31);
    PrintS(1, 8, 8, 0, x - 30, y + 31);
    PrintS(3, 4, 4, 0, x - 28, y + 31);
    PrintS(2, 8, 8, 0, x - 22, y + 31);
    PrintS(8, 4, 4, 0, x - 18, y + 31);
    PrintS(7, 8, 8, 0, x - 2, y + 31);
    PrintS(1, 4, 4, 0, x + 12, y + 31);
    PrintS(2, 7, 7, 0, x + 16, y + 31);
    PrintS(3, 4, 4, 1, x + 30, y + 31);

    PrintS(4, 3, 3, 0, x - 44, y + 32);
    PrintS(1, 4, 4, 0, x - 36, y + 32);
    PrintS(23, 8, 8, 0, x - 34, y + 32);
    PrintS(2, 7, 7, 0, x + 20, y + 32);
    PrintS(1, 6, 6, 1, x + 32, y + 32);

    PrintS(2, 3, 3, 0, x - 46, y + 33);
    PrintS(1, 4, 4, 0, x - 42, y + 33);
    PrintS(1, 4, 4, 0, x - 38, y + 33);
    PrintS(11, 8, 8, 0, x - 36, y + 33);
    PrintS(1, 4, 4, 0, x - 14, y + 33);
    PrintS(10, 8, 8, 0, x - 12, y + 33);
    PrintS(1, 7, 7, 0, x + 8, y + 33);
    PrintS(2, 4, 4, 0, x + 10, y + 33);
    PrintS(2, 7, 7, 0, x + 24, y + 33);
    PrintS(2, 4, 4, 1, x + 30, y + 33);

    PrintS(2, 4, 4, 0, x - 50, y + 34);
    PrintS(1, 4, 4, 0, x - 38, y + 34);
    PrintS(8, 8, 8, 0, x - 36, y + 34);
    PrintS(2, 4, 4, 0, x - 20, y + 34);
    PrintS(2, 4, 4, 0, x - 10, y + 34);
    PrintS(6, 8, 8, 0, x - 6, y + 34);
    PrintS(1, 4, 4, 0, x + 6, y + 34);
    PrintS(2, 7, 7, 0, x + 8, y + 34);
    PrintS(1, 4, 4, 0, x + 12, y + 34);
    PrintS(1, 7, 7, 0, x + 26, y + 34);
    PrintS(2, 4, 4, 1, x + 28, y + 34);

    PrintS(1, 4, 4, 0, x - 38, y + 35);
    PrintS(1, 8, 8, 0, x - 36, y + 35);
    PrintS(7, 4, 4, 0, x - 34, y + 35);
    PrintS(7, 4, 4, 0, x - 6, y + 35);
    PrintS(1, 7, 7, 0, x + 8, y + 35);
    PrintS(2, 4, 4, 0, x + 10, y + 35);
    PrintS(2, 4, 4, 1, x + 26, y + 35);

    PrintS(2, 4, 4, 0, x - 38, y + 36);
    PrintS(3, 8, 8, 0, x - 34, y + 36);
    PrintS(1, 4, 4, 0, x + 6, y + 36);
    PrintS(3, 7, 7, 0, x + 8, y + 36);
    PrintS(1, 4, 4, 0, x + 14, y + 36);
    PrintS(1, 4, 4, 1, x + 26, y + 36);

    PrintS(2, 4, 4, 0, x - 34, y + 37);
    PrintS(1, 8, 8, 0, x - 30, y + 37);
    PrintS(1, 4, 4, 0, x - 28, y + 37);
    PrintS(1, 4, 4, 0, x + 10, y + 37);
    PrintS(2, 7, 7, 0, x + 12, y + 37);
    PrintS(1, 4, 4, 1, x + 14, y + 37);

    PrintS(2, 4, 4, 0, x - 28, y + 38);
    PrintS(2, 4, 4, 1, x + 14, y + 38);

    PrintS(3, 4, 4, 0, x - 28, y + 39);
    PrintS(3, 4, 4, 1, x + 16, y + 39);

    PrintS(3, 4, 4, 0, x - 28, y + 40);
    PrintS(4, 4, 4, 1, x + 16, y + 40);

    PrintS(4, 4, 4, 0, x - 30, y + 41);
    PrintS(3, 4, 4, 1, x + 20, y + 41);
}
void ArcherDot::PrintBossArcher(int x, int y)
{
    PrintS(2, 2, 2, 1, x, y);
    PrintS(4, 2, 2, 1, x + 2, y + 1);
    PrintS(1, 7, 7, 0, x + 4, y + 2);
    PrintS(3, 2, 2, 1, x + 10, y + 2);
    PrintS(1, 7, 7, 0, x + 2, y + 3);
    PrintS(2, 14, 14, 1, x + 12, y + 3);
    PrintS(1, 7, 7, 0, x, y + 4);
    PrintS(1, 2, 2, 0, x + 12, y + 4);
    PrintS(1, 14, 14, 1, x + 14, y + 4);
    PrintS(1, 8, 8, 0, x + 16, y + 4);
    PrintS(2, 2, 2, 1, x + 18, y + 4);
    PrintS(3, 2, 2, 0, x - 36, y + 5);
    PrintS(1, 2, 2, 0, x - 26, y + 5);
    PrintS(1, 7, 7, 0, x, y + 5);
    PrintS(1, 2, 2, 0, x + 16, y + 5);
    PrintS(2, 8, 8, 0, x + 18, y + 5);
    PrintS(1, 2, 2, 1, x + 22, y + 5);
    PrintS(6, 2, 2, 0, x - 34, y + 6);
    PrintS(1, 7, 7, 0, x - 2, y + 6);
    PrintS(1, 2, 2, 0, x + 18, y + 6);
    PrintS(2, 8, 8, 0, x + 20, y + 6);
    PrintS(1, 2, 2, 1, x + 24, y + 6);
    PrintS(5, 2, 2, 0, x - 32, y + 7);
    PrintS(1, 7, 7, 0, x - 4, y + 7);
    PrintS(1, 2, 2, 0, x + 20, y + 7);
    PrintS(1, 8, 8, 0, x + 22, y + 7);
    PrintS(1, 2, 2, 1, x + 24, y + 7);
    PrintS(4, 2, 2, 0, x - 30, y + 8);
    PrintS(1, 2, 2, 0, x - 8, y + 8);
    PrintS(1, 7, 7, 0, x - 6, y + 8);
    PrintS(1, 2, 2, 0, x + 22, y + 8);
    PrintS(1, 8, 8, 0, x + 24, y + 8);
    PrintS(1, 2, 2, 1, x + 26, y + 8);

    PrintS(6, 2, 2, 0, x - 36, y + 9);
    PrintS(1, 14, 14, 0, x - 24, y + 9);
    PrintS(8, 2, 2, 0, x - 22, y + 9);
    PrintS(1, 7, 7, 0, x - 8, y + 9);
    PrintS(1, 2, 2, 0, x + 22, y + 9);
    PrintS(2, 8, 8, 0, x + 24, y + 9);
    PrintS(1, 2, 2, 1, x + 28, y + 9);
    PrintS(4, 2, 2, 0, x - 34, y + 10);
    PrintS(1, 14, 14, 0, x - 26, y + 10);
    PrintS(7, 2, 2, 0, x - 24, y + 10);
    PrintS(1, 7, 7, 0, x - 10, y + 10);
    PrintS(2, 2, 2, 0, x - 8, y + 10);
    PrintS(1, 2, 2, 0, x + 24, y + 10);
    PrintS(1, 8, 8, 0, x + 26, y + 10);
    PrintS(1, 2, 2, 1, x + 28, y + 10);
    PrintS(1, 14, 14, 0, x - 28, y + 11);
    PrintS(7, 2, 2, 0, x - 26, y + 11);
    PrintS(1, 7, 7, 0, x - 12, y + 11);
    PrintS(3, 2, 2, 0, x - 10, y + 11);
    PrintS(4, 2, 2, 1, x + 24, y + 11);

    PrintS(2, 2, 2, 0, x - 36, y + 12);
    PrintS(1, 2, 2, 0, x - 30, y + 12);
    PrintS(1, 14, 14, 0, x - 28, y + 12);
    PrintS(7, 2, 2, 0, x - 26, y + 12);
    PrintS(1, 7, 7, 0, x - 12, y + 12);
    PrintS(2, 14, 14, 0, x - 10, y + 12);
    PrintS(1, 2, 2, 0, x - 6, y + 12);
    PrintS(1, 2, 2, 0, x + 26, y + 12);
    PrintS(1, 1, 1, 0, x + 28, y + 12);
    PrintS(1, 2, 2, 0, x + 30, y + 12);

    PrintS(5, 2, 2, 0, x - 52, y + 13);
    PrintS(1, 2, 2, 0, x - 38, y + 13);
    PrintS(1, 6, 6, 0, x - 36, y + 13);
    PrintS(1, 14, 14, 0, x - 34, y + 13);
    PrintS(1, 6, 6, 0, x - 32, y + 13);
    PrintS(4, 2, 2, 0, x - 30, y + 13);
    PrintS(1, 8, 8, 0, x - 22, y + 13);
    PrintS(2, 2, 2, 0, x - 20, y + 13);
    PrintS(1, 14, 14, 0, x - 16, y + 13);
    PrintS(1, 7, 7, 0, x - 14, y + 13);
    PrintS(3, 14, 14, 0, x - 12, y + 13);
    PrintS(2, 2, 2, 0, x - 6, y + 13);
    PrintS(1, 2, 2, 0, x + 26, y + 13);
    PrintS(2, 1, 1, 0, x + 28, y + 13);
    PrintS(1, 2, 2, 1, x + 32, y + 13);

    PrintS(1, 2, 2, 0, x - 50, y + 14);
    PrintS(5, 6, 6, 0, x - 48, y + 14);
    PrintS(1, 2, 2, 0, x - 38, y + 14);
    PrintS(3, 6, 6, 0, x - 36, y + 14);
    PrintS(4, 2, 2, 0, x - 30, y + 14);
    PrintS(1, 8, 8, 0, x - 22, y + 14);
    PrintS(2, 2, 2, 0, x - 20, y + 14);
    PrintS(1, 14, 14, 0, x - 16, y + 14);
    PrintS(1, 7, 7, 0, x - 14, y + 14);
    PrintS(3, 14, 14, 0, x - 12, y + 14);
    PrintS(2, 2, 2, 0, x - 6, y + 14);
    PrintS(1, 2, 2, 0, x + 28, y + 14);
    PrintS(2, 1, 1, 0, x + 30, y + 14);
    PrintS(1, 2, 2, 1, x + 34, y + 14);

    PrintS(1, 2, 2, 0, x - 48, y + 15);
    PrintS(4, 6, 6, 0, x - 46, y + 15);
    PrintS(1, 2, 2, 0, x - 38, y + 15);
    PrintS(2, 14, 14, 0, x - 36, y + 15);
    PrintS(4, 2, 2, 0, x - 32, y + 15);
    PrintS(1, 8, 8, 0, x - 24, y + 15);
    PrintS(3, 2, 2, 0, x - 22, y + 15);
    PrintS(1, 7, 7, 0, x - 16, y + 15);
    PrintS(1, 14, 14, 0, x - 14, y + 15);
    PrintS(2, 2, 2, 0, x - 12, y + 15);
    PrintS(1, 14, 14, 0, x - 8, y + 15);
    PrintS(1, 2, 2, 0, x - 6, y + 15);
    PrintS(1, 14, 14, 0, x - 4, y + 15);
    PrintS(1, 2, 2, 0, x + 30, y + 15);
    PrintS(1, 1, 1, 0, x + 32, y + 15);
    PrintS(2, 2, 2, 1, x + 34, y + 15);

    PrintS(2, 6, 6, 0, x - 46, y + 16);
    PrintS(3, 2, 2, 0, x - 42, y + 16);
    PrintS(1, 6, 6, 0, x - 36, y + 16);
    PrintS(6, 2, 2, 0, x - 34, y + 16);
    PrintS(1, 14, 14, 0, x - 22, y + 16);
    PrintS(2, 2, 2, 0, x - 20, y + 16);
    PrintS(1, 7, 7, 0, x - 16, y + 16);
    PrintS(1, 2, 2, 0, x - 14, y + 16);
    PrintS(1, 2, 2, 0, x - 12, y + 16);
    PrintS(4, 14, 14, 0, x - 10, y + 16);
    PrintS(5, 2, 2, 1, x + 30, y + 16);

    PrintS(1, 2, 2, 0, x - 42, y + 17);
    PrintS(2, 6, 6, 0, x - 40, y + 17);
    PrintS(7, 2, 2, 0, x - 36, y + 17);
    PrintS(1, 14, 14, 0, x - 22, y + 17);
    PrintS(1, 2, 2, 0, x - 20, y + 17);
    PrintS(1, 7, 7, 0, x - 18, y + 17);
    PrintS(7, 14, 14, 0, x - 16, y + 17);
    PrintS(1, 2, 2, 0, x + 28, y + 17);
    PrintS(2, 14, 14, 0, x + 30, y + 17);
    PrintS(1, 2, 2, 0, x + 34, y + 17);
    PrintS(2, 8, 8, 0, x + 36, y + 17);
    PrintS(1, 2, 2, 1, x + 40, y + 17);

    PrintS(1, 2, 2, 0, x - 46, y + 18);
    PrintS(3, 6, 6, 0, x - 44, y + 18);
    PrintS(1, 2, 2, 0, x - 38, y + 18);
    PrintS(3, 1, 1, 0, x - 36, y + 18);
    PrintS(3, 2, 2, 0, x - 30, y + 18);
    PrintS(1, 8, 8, 0, x - 24, y + 18);
    PrintS(2, 2, 2, 0, x - 22, y + 18);
    PrintS(1, 7, 7, 0, x - 18, y + 18);
    PrintS(3, 14, 14, 0, x - 16, y + 18);
    PrintS(1, 8, 8, 0, x - 10, y + 18);
    PrintS(2, 14, 14, 0, x - 8, y + 18);
    PrintS(3, 2, 2, 0, x, y + 18);
    PrintS(3, 2, 2, 0, x + 28, y + 18);
    PrintS(2, 14, 14, 0, x + 34, y + 18);
    PrintS(3, 2, 2, 0, x + 38, y + 18);
    PrintS(3, 7, 7, 1, x + 46, y + 18);

    PrintS(2, 2, 2, 0, x - 50, y + 19);
    PrintS(3, 6, 6, 0, x - 46, y + 19);
    PrintS(1, 2, 2, 0, x - 40, y + 19);
    PrintS(1, 1, 1, 0, x - 38, y + 19);
    PrintS(2, 6, 6, 0, x - 36, y + 19);
    PrintS(1, 1, 1, 0, x - 32, y + 19);
    PrintS(1, 2, 2, 0, x - 30, y + 19);
    PrintS(2, 8, 8, 0, x - 28, y + 19);
    PrintS(2, 2, 2, 0, x - 24, y + 19);
    PrintS(2, 8, 8, 0, x - 20, y + 19);
    PrintS(1, 2, 2, 0, x - 16, y + 19);
    PrintS(1, 14, 14, 0, x - 14, y + 19);
    PrintS(2, 8, 8, 0, x - 12, y + 19);
    PrintS(2, 14, 14, 0, x - 8, y + 19);
    PrintS(2, 2, 2, 0, x - 4, y + 19);
    PrintS(3, 14, 14, 0, x, y + 19);
    PrintS(6, 2, 2, 0, x + 10, y + 19);
    PrintS(5, 2, 2, 0, x + 26, y + 19);
    PrintS(4, 14, 14, 0, x + 36, y + 19);
    PrintS(1, 2, 2, 1, x + 44, y + 19);
    PrintS(4, 7, 7, 1, x + 48, y + 19);

    PrintS(4, 6, 6, 1, x - 50, y + 20);
    PrintS(2, 2, 2, 0, x - 42, y + 20);
    PrintS(3, 6, 6, 0, x - 38, y + 20);
    PrintS(1, 1, 1, 0, x - 32, y + 20);
    PrintS(1, 8, 8, 0, x - 30, y + 20);
    PrintS(3, 7, 7, 0, x - 28, y + 20);
    PrintS(2, 8, 8, 0, x - 22, y + 20);
    PrintS(1, 2, 2, 0, x - 18, y + 20);
    PrintS(1, 6, 6, 0, x - 16, y + 20);
    PrintS(1, 2, 2, 0, x - 14, y + 20);
    PrintS(34, 6, 6, 0, x - 14, y + 20);
    PrintS(5, 7, 7, 1, x + 48, y + 20);

    PrintS(1, 2, 2, 0, x - 50, y + 21);
    PrintS(3, 6, 6, 0, x - 48, y + 21);
    PrintS(1, 1, 1, 0, x - 42, y + 21);
    PrintS(1, 2, 2, 0, x - 40, y + 21);
    PrintS(3, 6, 6, 0, x - 38, y + 21);
    PrintS(1, 1, 1, 0, x - 32, y + 21);
    PrintS(1, 2, 2, 0, x - 30, y + 21);
    PrintS(3, 7, 7, 0, x - 28, y + 21);
    PrintS(3, 2, 2, 0, x - 22, y + 21);
    PrintS(1, 7, 7, 0, x - 16, y + 21);
    PrintS(14, 14, 14, 0, x - 14, y + 21);
    PrintS(10, 2, 2, 0, x + 14, y + 21);
    PrintS(2, 8, 8, 0, x + 34, y + 21);
    PrintS(1, 14, 14, 0, x + 38, y + 21);
    PrintS(2, 2, 2, 0, x + 40, y + 21);
    PrintS(4, 7, 7, 1, x + 48, y + 21);

    PrintS(1, 2, 2, 0, x - 48, y + 22);
    PrintS(1, 14, 14, 0, x - 46, y + 22);
    PrintS(3, 2, 2, 0, x - 44, y + 22);
    PrintS(3, 8, 8, 0, x - 38, y + 22);
    PrintS(1, 2, 2, 0, x - 32, y + 22);
    PrintS(7, 8, 8, 0, x - 30, y + 22);
    PrintS(1, 2, 2, 0, x - 16, y + 22);
    PrintS(2, 7, 7, 0, x - 14, y + 22);
    PrintS(4, 14, 14, 0, x - 10, y + 22);
    PrintS(1, 2, 2, 0, x - 2, y + 22);
    PrintS(2, 2, 2, 0, x + 30, y + 22);
    PrintS(2, 8, 8, 0, x + 34, y + 22);
    PrintS(1, 2, 2, 0, x + 38, y + 22);
    PrintS(3, 7, 7, 1, x + 46, y + 22);

    PrintS(1, 2, 2, 0, x - 48, y + 23);
    PrintS(1, 14, 14, 0, x - 46, y + 23);
    PrintS(1, 2, 2, 0, x - 42, y + 23);
    PrintS(3, 8, 8, 0, x - 40, y + 23);
    PrintS(1, 2, 2, 0, x - 34, y + 23);
    PrintS(9, 8, 8, 0, x - 32, y + 23);
    PrintS(1, 2, 2, 0, x - 14, y + 23);
    PrintS(2, 7, 7, 0, x - 12, y + 23);
    PrintS(2, 14, 14, 0, x - 8, y + 23);
    PrintS(2, 2, 2, 0, x - 4, y + 23);
    PrintS(2, 2, 2, 0, x + 30, y + 23);
    PrintS(2, 8, 8, 0, x + 34, y + 23);
    PrintS(1, 2, 2, 1, x + 38, y + 23);

    PrintS(2, 14, 14, 0, x - 50, y + 24);
    PrintS(1, 2, 2, 0, x - 38, y + 24);
    PrintS(3, 8, 8, 0, x - 36, y + 24);
    PrintS(3, 2, 2, 0, x - 30, y + 24);
    PrintS(7, 8, 8, 0, x - 24, y + 24);
    PrintS(1, 2, 2, 0, x - 12, y + 24);
    PrintS(2, 7, 7, 0, x - 10, y + 24);
    PrintS(1, 14, 14, 0, x - 6, y + 24);
    PrintS(1, 2, 2, 0, x - 4, y + 24);
    PrintS(2, 2, 2, 0, x + 30, y + 24);
    PrintS(2, 8, 8, 0, x + 34, y + 24);
    PrintS(1, 2, 2, 1, x + 38, y + 24);

    PrintS(2, 2, 2, 0, x - 52, y + 25);
    PrintS(1, 2, 2, 0, x - 26, y + 25);
    PrintS(8, 8, 8, 0, x - 24, y + 25);
    PrintS(1, 2, 2, 0, x - 8, y + 25);
    PrintS(2, 7, 7, 0, x - 6, y + 25);
    PrintS(1, 2, 2, 0, x + 32, y + 25);
    PrintS(2, 8, 8, 0, x + 34, y + 25);
    PrintS(1, 2, 2, 1, x + 38, y + 25);

    PrintS(1, 2, 2, 0, x - 52, y + 26);
    PrintS(1, 2, 2, 0, x - 30, y + 26);
    PrintS(1, 8, 8, 0, x - 28, y + 26);
    PrintS(1, 1, 1, 0, x - 26, y + 26);
    PrintS(1, 8, 8, 0, x - 24, y + 26);
    PrintS(2, 2, 2, 0, x - 22, y + 26);
    PrintS(7, 8, 8, 0, x - 18, y + 26);
    PrintS(1, 2, 2, 0, x - 4, y + 26);
    PrintS(2, 7, 7, 0, x - 2, y + 26);
    PrintS(2, 1, 1, 0, x + 34, y + 26);
    PrintS(1, 2, 2, 1, x + 38, y + 26);

    PrintS(1, 2, 2, 0, x - 32, y + 27);
    PrintS(2, 8, 8, 0, x - 30, y + 27);
    PrintS(1, 1, 1, 0, x - 26, y + 27);
    PrintS(3, 8, 8, 0, x - 24, y + 27);
    PrintS(9, 2, 2, 0, x - 18, y + 27);
    PrintS(1, 7, 7, 0, x + 2, y + 27);
    PrintS(1, 2, 2, 0, x + 34, y + 27);
    PrintS(1, 1, 1, 0, x + 36, y + 27);
    PrintS(1, 2, 2, 1, x + 38, y + 27);

    PrintS(2, 2, 2, 0, x - 42, y + 28);
    PrintS(1, 2, 2, 0, x - 34, y + 28);
    PrintS(4, 8, 8, 0, x - 32, y + 28);
    PrintS(1, 1, 1, 0, x - 24, y + 28);
    PrintS(7, 2, 2, 0, x - 22, y + 28);
    PrintS(6, 8, 8, 0, x - 10, y + 28);
    PrintS(2, 7, 7, 0, x + 4, y + 28);
    PrintS(2, 1, 1, 0, x + 34, y + 28);
    PrintS(1, 2, 2, 1, x + 38, y + 28);


    PrintS(1, 2, 2, 0, x - 44, y + 29);
    PrintS(3, 1, 1, 0, x - 42, y + 29);
    PrintS(2, 2, 2, 0, x - 36, y + 29);
    PrintS(4, 8, 8, 0, x - 32, y + 29);
    PrintS(3, 2, 2, 0, x - 24, y + 29);
    PrintS(1, 8, 8, 0, x - 18, y + 29);
    PrintS(1, 2, 2, 0, x - 16, y + 29);
    PrintS(8, 8, 8, 0, x - 14, y + 29);
    PrintS(2, 2, 2, 0, x + 2, y + 29);
    PrintS(2, 7, 7, 0, x + 8, y + 29);
    PrintS(3, 2, 2, 1, x + 32, y + 29);

    PrintS(1, 2, 2, 0, x - 44, y + 30);
    PrintS(5, 1, 1, 0, x - 42, y + 30);
    PrintS(1, 2, 2, 0, x - 32, y + 30);
    PrintS(14, 8, 8, 0, x - 30, y + 30);
    PrintS(2, 2, 2, 0, x - 2, y + 30);
    PrintS(3, 8, 8, 0, x + 2, y + 30);
    PrintS(1, 2, 2, 0, x + 8, y + 30);
    PrintS(2, 7, 7, 0, x + 12, y + 30);
    PrintS(4, 2, 2, 1, x + 30, y + 30);

    PrintS(1, 3, 3, 0, x - 44, y + 31);
    PrintS(4, 1, 1, 0, x - 42, y + 31);
    PrintS(2, 2, 2, 0, x - 34, y + 31);
    PrintS(1, 8, 8, 0, x - 30, y + 31);
    PrintS(3, 2, 2, 0, x - 28, y + 31);
    PrintS(2, 8, 8, 0, x - 22, y + 31);
    PrintS(8, 2, 2, 0, x - 18, y + 31);
    PrintS(7, 8, 8, 0, x - 2, y + 31);
    PrintS(1, 2, 2, 0, x + 12, y + 31);
    PrintS(2, 7, 7, 0, x + 16, y + 31);
    PrintS(3, 2, 2, 1, x + 30, y + 31);

    PrintS(4, 3, 3, 0, x - 44, y + 32);
    PrintS(1, 2, 2, 0, x - 36, y + 32);
    PrintS(23, 8, 8, 0, x - 34, y + 32);
    PrintS(2, 7, 7, 0, x + 20, y + 32);
    PrintS(1, 6, 6, 1, x + 32, y + 32);

    PrintS(2, 3, 3, 0, x - 46, y + 33);
    PrintS(1, 2, 2, 0, x - 42, y + 33);
    PrintS(1, 2, 2, 0, x - 38, y + 33);
    PrintS(11, 8, 8, 0, x - 36, y + 33);
    PrintS(1, 2, 2, 0, x - 14, y + 33);
    PrintS(10, 8, 8, 0, x - 12, y + 33);
    PrintS(1, 7, 7, 0, x + 8, y + 33);
    PrintS(2, 2, 2, 0, x + 10, y + 33);
    PrintS(2, 7, 7, 0, x + 24, y + 33);
    PrintS(2, 2, 2, 1, x + 30, y + 33);

    PrintS(2, 2, 2, 0, x - 50, y + 34);
    PrintS(1, 2, 2, 0, x - 38, y + 34);
    PrintS(8, 8, 8, 0, x - 36, y + 34);
    PrintS(2, 2, 2, 0, x - 20, y + 34);
    PrintS(2, 2, 2, 0, x - 10, y + 34);
    PrintS(6, 8, 8, 0, x - 6, y + 34);
    PrintS(1, 2, 2, 0, x + 6, y + 34);
    PrintS(2, 7, 7, 0, x + 8, y + 34);
    PrintS(1, 2, 2, 0, x + 12, y + 34);
    PrintS(1, 7, 7, 0, x + 26, y + 34);
    PrintS(2, 2, 2, 1, x + 28, y + 34);

    PrintS(1, 2, 2, 0, x - 38, y + 35);
    PrintS(1, 8, 8, 0, x - 36, y + 35);
    PrintS(7, 2, 2, 0, x - 34, y + 35);
    PrintS(7, 2, 2, 0, x - 6, y + 35);
    PrintS(1, 7, 7, 0, x + 8, y + 35);
    PrintS(2, 2, 2, 0, x + 10, y + 35);
    PrintS(2, 2, 2, 1, x + 26, y + 35);

    PrintS(2, 2, 2, 0, x - 38, y + 36);
    PrintS(3, 8, 8, 0, x - 34, y + 36);
    PrintS(1, 2, 2, 0, x + 6, y + 36);
    PrintS(3, 7, 7, 0, x + 8, y + 36);
    PrintS(1, 2, 2, 0, x + 14, y + 36);
    PrintS(1, 2, 2, 1, x + 26, y + 36);

    PrintS(2, 2, 2, 0, x - 34, y + 37);
    PrintS(1, 8, 8, 0, x - 30, y + 37);
    PrintS(1, 2, 2, 0, x - 28, y + 37);
    PrintS(1, 2, 2, 0, x + 10, y + 37);
    PrintS(2, 7, 7, 0, x + 12, y + 37);
    PrintS(1, 2, 2, 1, x + 14, y + 37);

    PrintS(2, 2, 2, 0, x - 28, y + 38);
    PrintS(2, 2, 2, 1, x + 14, y + 38);

    PrintS(3, 2, 2, 0, x - 28, y + 39);
    PrintS(3, 2, 2, 1, x + 16, y + 39);

    PrintS(3, 2, 2, 0, x - 28, y + 40);
    PrintS(4, 2, 2, 1, x + 16, y + 40);

    PrintS(4, 2, 2, 0, x - 30, y + 41);
    PrintS(3, 2, 2, 1, x + 20, y + 41);
}
#pragma endregion