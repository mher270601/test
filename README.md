#include <iostream>
#include <chrono>

int main() {
	// Kodi tevoxutyan skzbnachapum
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	
	int x[9], y[9], f[10], k=0, n;
	// N qanaki stacum (2-ic 10 mijakayqum)
	do
	{
		std::cout << "Enter n: ";
		std::cin >> n;
	} while (n < 2 || n > 9);
	// Massivneri 1 kam 0 arjeqneri nermucum
	for (short i = 0; i < n; ++i)
	{
		do
		{
			std::cout << "Enter X[" << i << "]";
			std::cin >> x[i];
		} while (x[i] != 0 && x[i] != 1);
		do
		{
			std::cout << "Enter Y[" << i << "]";
			std::cin >> y[i];
		} while (y[i] != 0 && y[i] != 1);
	}
	// Verjnakan massivi hashvarkum ev stacum
	for (int i = n-1; i >= 0; --i)
	{
		if (x[i] + y[i] == 2 && k == 1)
		{
			f[i + 1] = 1;

		}
		else if (x[i] + y[i] == 0 && k == 1)
		{
			k = 0;
			f[i + 1] = 1;
		}
		else if (x[i] + y[i] == 2 && k == 0)
		{
			f[i + 1] = 0;
			k = 1;
		}
		else if (x[i] + y[i] == 0 && k == 0)
		{
			f[i + 1] = 0;
		}
		else if (x[i] + y[i] == 1 && k == 1)
		{
			f[i + 1] = 0;
		}
		else if (x[i] + y[i] == 1 && k == 0)
		{
			f[i + 1] = 1;
		}
	}
	// Verjnakan mnacordayin stugum
	if (k == 1)
	{
		f[0] = 1;
	}
	for (int i = 0; i < n+1; ++i)
	{
		std::cout << f[i];
	}
	// Kodi tevoxutyan verjnachapum

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	// Jamanaky varkyannerov
	std::cout << "\nDuration = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " seconds" << std::endl;
	return 0;
}

Write a program that adds two n-bit binary numbers, stored in two arrays of size n. The some should be stored in an array of size (n+1).
2.1 Write a program that finds the maximum element in an array of size n. 2.1.1 State the problem formally. 2.1.2 Prove the correctness by stating the loop invariant and making sure it fulfills all three properties: initializatation, maintenance and termination. 2.1.3 Analyse the running time.

2.2 Use the maximum finding algorithm to construct and implement an algorithm that sorts the given array of integers in non-increasing order. 2.2.1 Prove the correctness by stating the loop invariant and making sure it fulfills all three properties: initializatation, maintenance and termination. 2.2.2 Analyse the running time.
	
	
#include <iostream>
#include <windows.h>
#include "includes/input.hpp"
void go_up(int[][11], int&, int&);
void go_left(int[][11], int&, int&);
void go_right(int[][11], int&, int&);
void go_down(int[][11], int&, int&);
void charge(int [][11]);

int main()
{   
    std::cout << "Control with '>(right)', '^(up)', '<(left)', 'v(down)' buttons" << std::endl;
    // Initialization
    int x = 10, y = 6, n = 12, matric[11][11];
    bool xm = true, ym = true;
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

void go_right(int matric1[][11], int& x1, int& y1) {
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
    charge(matric1);
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

void charge(int matric1[][11]) {
    int x = 0, y = 0;
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            if (matric1[i][j] == 1)
            {
                do
                {
                    matric1[i][++j] = 1;
                } while (matric1[i][j+1] != 1 && matric1[i][j+2] != 0 && j < 11);
            }
        }
    }
    system("cls");
    std::cout << "Charged matrix" << std::endl;
    for (short i = 0; i < 11; ++i)
    {
        for (short j = 0; j < 11; ++j)
        {
            std::cout << matric1[i][j];
        }
        std::cout << "\n";
    }
    Sleep(92000);
}
