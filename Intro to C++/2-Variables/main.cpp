#include <iostream>

int main()
{
	int number = 11;
	std::cout << number << "\n";
	number = 12;
	std::cout << number << "\n";
	number = 01;
	std::cout << number << "\n";
	number = 22;
	std::cout << number << "\n";

	int number2 = 6;
	int number3 = 4;
	int sumNum2And3 = number2 + number3;
	std::cout << sumNum2And3 << "\n";

	int num4 = 9 / 3;
	int num5 = 12 / 4;
	int sumNum4And5 = num4 + num5;
	std::cout << sumNum4And5 << "\n";

	float num6 = 0.45;
	float num7 = 0.65;
	float sumNum6And7 = num6 + num7;
	std::cout << sumNum6And7 << "\n";

	float num8 = 1;
	float num9 = 3;
	float sumNum8And9 = num8 + num9;
	std::cout << sumNum8And9 << "\n";

	std::cout << "Please input a number: ";
	float userNum = 0;
	std::cin >> userNum;
	std::cout << "\n" << userNum << " is a very cool number. Nice choice!\n";

}