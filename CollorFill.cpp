#include <iostream>
#include <windows.h>
#include "includes/input.hpp"
void go_up(int[][11], int&, int&);
void go_left(int[][11], int&, int&);
void go_right(int[][11], int&, int&);
void go_down(int[][11], int&, int&);

int main()
{
    std::cout << "Control with '>(right)', '^(up)', '<(left)', 'v(down)' buttons" << std::endl;
    // Initialization
    int x = 10, y = 6, n=12, matric[11][11];
    Sleep(2000);
 
    for (short i = 0; i < 11; ++i)
    {
        for (short j = 0; j < 11; ++j)
        {
            matric[i][j] = 0;
        }
    }
    matric[x][y] = 1;
    // If button clicked, go to the appropriate function
    if (GetAsyncKeyState(VK_RIGHT))
    {
        go_right(matric, x, y);
    }

    if (GetAsyncKeyState(VK_UP))
    {
        go_up(matric, x, y);
    }

    if (GetAsyncKeyState(VK_LEFT))
    {
        go_left(matric, x, y);
    }

    if (GetAsyncKeyState(VK_DOWN))
    {
        go_down(matric, x, y);
    }
    
    return 0;
}
    
void go_right(int matric1[][11], int &x1, int &y1) {
    // check that the next element is in the matrix
    while (y1 + 1 < 11)
    {
        // equate the next element to 1
        matric1[x1][++y1] = 1;
        // Clear the console screen
        system("cls");
        // Print the matrix
        for (short i = 0; i < 11; ++i)
        {
            for (short j = 0; j < 11; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
        Sleep(1000);
        // If another button clicked, leave from here and go to the appropriate function
        if (GetAsyncKeyState(VK_UP))
        {
            go_up(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            go_left(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            go_down(matric1, x1, y1);
            return;
        }
    }
}

void go_up(int matric1[][11], int& x1, int& y1) {
    while (x1 - 1 >= 0)
    {
        matric1[--x1][y1] = 1;
        system("cls");
        for (short i = 0; i < 11; ++i)
        {
            for (short j = 0; j < 11; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
        Sleep(1000);
        if (GetAsyncKeyState(VK_RIGHT))
        {
            go_right(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            go_left(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            go_down(matric1, x1, y1);
            return;
        }
    }
}

void go_left(int matric1[][11], int& x1, int& y1) {
    while (y1 - 1 >= 0)
    {
        matric1[x1][--y1] = 1;
        system("cls");
        for (short i = 0; i < 11; ++i)
        {
            for (short j = 0; j < 11; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
        Sleep(1000);
        if (GetAsyncKeyState(VK_RIGHT))
        {
            go_right(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            go_up(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            go_down(matric1, x1, y1);
            return;
        }
    }
}

void go_down(int matric1[][11], int& x1, int& y1) {
    while (x1 + 1 < 11)
    {
        matric1[++x1][y1] = 1;
        system("cls");
        for (short i = 0; i < 11; ++i)
        {
            for (short j = 0; j < 11; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
        Sleep(1000);
        if (GetAsyncKeyState(VK_RIGHT))
        {
            go_right(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_LEFT))
        {
            go_left(matric1, x1, y1);
            return;
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            go_up(matric1, x1, y1);
            return;
        }
    }
}
