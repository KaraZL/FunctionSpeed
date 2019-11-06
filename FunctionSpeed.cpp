// FunctionSpeed.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <chrono>

int SpeedTestCPP(int* y, int* x, int n);
extern "C" int SpeedTestASM(int* y, int* x, int n);

int main()
{
    std::cout << "Hello World!\n";
	

	//C++ Side
	int x[] = { 2,3,4,5,6,7,8,9 };
	const int length = sizeof(x) / sizeof(int);

	int y1[length];
	int y2[length];

	int sumCpp;
	int sumAsm;

	auto startCpp = std::chrono::steady_clock::now();
	sumCpp = SpeedTestCPP(y1, x, length);
	auto endCpp = std::chrono::steady_clock::now();
	std::cout << "Summary Cpp : " << sumCpp << std::endl;
	std::cout << "Timer : " << std::chrono::duration_cast<std::chrono::nanoseconds>(endCpp - startCpp).count() << std::endl;

	for (auto i : y1)
	{
		std::cout << "y1: " << i << std::endl;
	}

	//ASM Side
	

	auto startAsm = std::chrono::steady_clock::now();
	sumAsm = SpeedTestASM(y2, x, length);
	auto endAsm = std::chrono::steady_clock::now();
	std::cout << "Summary Asm : " << sumAsm << std::endl;
	std::cout << "Timer : " << std::chrono::duration_cast<std::chrono::nanoseconds>(endAsm - startAsm).count() << std::endl;

	for (auto o : y2)
	{
		std::cout << "y2: " << o << std::endl;
	}


	return 0;
}

int SpeedTestCPP(int* y, int* x, int n) {

	int sum = 0;
	for (int i = 0; i < n; i++) {
		y[i] = x[i] * x[i];
		sum += y[i];
	}


	return sum;
}

