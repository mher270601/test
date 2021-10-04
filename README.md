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
