#include <iostream>
#include <thread>
#include <stdlib.h>
#include "input.hpp"
void go_up(int[][11], int&, int&, int);
void go_left(int[][11], int&, int&, int);
void go_right(int[][11], int&, int&, int);
void go_down(int[][11], int&, int&, int);
void charge(int [][11], int);

//constexpr nn1 = 11;

int main()
{   
    std::cout << "Control with '>(right)', '^(up)', '<(left)', 'v(down)' buttons" << std::endl;
    // Initialization
    int x = 10, y = 6, n = 11, matric[11][11];
    short xm = 1, ym = 2;
    bool game = true;

    for (short i = 0; i < n; ++i)
    {
        for (short j = 0; j < n; ++j)
        {
            matric[i][j] = 0;
        }
    }
    matric[x][y] = 1;

	cbreak();

	while(game){
		char pressed = keypress();
		int key_prs = int(pressed);
		switch (key_prs) {
			case 65:
				go_up(matric, x, y, n);
			break;
			case 66:
				go_down(matric, x, y, n);
			break;
			case 67:
				go_right(matric, x, y, n);
			break;
			case 68: 
				go_left(matric, x, y, n);
			break;
			case 'q':
				game = false;
			break;		
		}
	}
	normal();

    return 0;
}

void go_right(int matric1[][11], int& x1, int& y1, int n1) {
    bool game = true;
    //std::cout << y1+1 << " < " << n1 << std::endl;
	// check that the next element is in the matrix
    while (y1 + 1 < n1 && game == true)
    {
        // equate the next element to 1
        matric1[x1][++y1] = 1;
        // Clear the console screen
        system("clear");
        // Print the matrix
        for (short i = 0; i < n1; ++i)
        {
            for (short j = 0; j < n1; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
      //Sleep(300);
        // If another button clicked, leave from here and go to the appropriate function
    	//cbreak();
		char pressed = keypress();
		int key_prs = int(pressed);
		switch (key_prs) {
			case 65:
				go_up(matric1, x1, y1, n1);
			break;
			case 66:
				go_down(matric1, x1, y1, n1);
			break;
			case 68:
				go_left(matric1, x1, y1, n1);
			break;
			case 'q':
				game = false;
			break;	
		}
	
	//normal();
    }
    charge(matric1, n1);
}

void go_up(int matric1[][11], int& x1, int& y1, int n1) {
    bool game = true;
    while (x1 - 1 >= 0 && game == true)
    {
        matric1[--x1][y1] = 1;
        system("clear");
        for (short i = 0; i < n1; ++i)
        {
            for (short j = 0; j < n1; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
      //  Sleep(300);
    //cbreak();
    		char pressed = keypress();
		int key_prs = int(pressed);
		switch (key_prs) {
			case 67:
				go_right(matric1, x1, y1, n1);
			break;
			case 66:
				go_down(matric1, x1, y1, n1);
			break;
			case 68:
				go_left(matric1, x1, y1, n1);
			break;
			case 'q':
				game = false;
			break;	
		}
	
	//normal();
    }
    charge(matric1, n1);
}

void go_left(int matric1[][11], int& x1, int& y1, int n1) {
    bool game = true;
    while (y1 - 1 >= 0 && game == true)
    {
        matric1[x1][--y1] = 1;
        system("clear");
        for (short i = 0; i < n1; ++i)
        {
            for (short j = 0; j < n1; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
      //  Sleep(300);
    //cbreak();
		char pressed = keypress();
		int key_prs = int(pressed);
		switch (key_prs) {
			case 65:
				go_up(matric1, x1, y1, n1);
			break;
			case 66:
				go_down(matric1, x1, y1, n1);
			break;
			case 67:
				go_right(matric1, x1, y1, n1);
			break;
			case 'q':
				game = false;
			break;	
		}

	//normal();
    }
    charge(matric1, n1);
}

void go_down(int matric1[][11], int& x1, int& y1, int n1) {
    bool game = true;
    while (x1 + 1 < n1 && game == true)
    {
        matric1[++x1][y1] = 1;
        system("clear");
        for (short i = 0; i < n1; ++i)
        {
            for (short j = 0; j < n1; ++j)
            {
                std::cout << matric1[i][j];
            }
            std::cout << "\n";
        }
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
      //  Sleep(300);
    	//cbreak();
		char pressed = keypress();
		int key_prs = int(pressed);
		switch (key_prs) {
			case 65:
				go_up(matric1, x1, y1, n1);
			break;
			case 67:
				go_right(matric1, x1, y1, n1);
			break;
			case 68:
				go_left(matric1, x1, y1, n1);
			break;
			case 'q':
				game = false;
			break;	
		}
	
	//normal();
    }
    charge(matric1, n1);
}

void charge(int matric1[][11], int n1) 
{
    int x = 0, y = 0;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n1; ++j)
        {
            if (matric1[i][j] == 1)
            {
                /*std::cout << "x[" << i << "][" << j << "] = " << matric1[i][j];*/
                while (matric1[i][j+2] != 1 && j + 2 < n1)
                {
                    matric1[i][++j] = 1;
                }          
                matric1[i][++j] = 1;
                /*matric1[i][j + 1] != 1 && matric1[i][j + 2] != 0*/
            }
            //    Sleep(10000);
            //    /*do
            //    {   
            //        if (j >= 11)
            //        {
            //            break;
            //        }
            //        matric1[i][++j] = 1;
            //    } while (matric1[i][j+1] != 1 && matric1[i][j+2] != 0);*/
            //}
        }
    }
    system("clear");
    std::cout << "Charged matrix" << std::endl;
    for (short i = 0; i < n1; ++i)
    {
        for (short j = 0; j < n1; ++j)
        {
            std::cout << matric1[i][j];
        }
        std::cout << "\n";
    }
  //  Sleep(92000);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
