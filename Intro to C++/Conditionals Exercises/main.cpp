#include <iostream>

int main()
{
	int y = 0;
	int x = 0;

	if (y == 0)
	{
		x = 100;
	}

	int userNum1;
	int userNum2;
	int largerNum;

	std::cout << "Please input a number:\n";
	std::cin >> userNum1;
	std::cout << "Please input a second number:\n";
	std::cin >> userNum2;

	if (userNum1 <= userNum2)
	{
		largerNum = userNum2;
	}
	else
	{
		largerNum = userNum1;
	}
	std::cout << largerNum << " is the largest number.\n";

	int num1 = 44;
	int num2 = 56;
	int num3 = 78;
	int num4 = 100;
	int num5 = 2;

	int numTotal = num1 + num2 + num3 + num4 + num5;

	if (numTotal == 0)
	{
		std::cout << "Zero";
	}
	else if (numTotal % 2 == 0)
	{
		std::cout << "Positive";
	}
	else
	{
		std::cout << "Negative";
	}

	int choice = 4;

	switch (choice)
	{
	case 1:
		std::cout << "1";
		break;
	case 2:
		std::cout << "2 or 3";
		break;
	case 3:
		std::cout << "2 or 3";
		break;
	case 4:
		std::cout << "4";
		break;
	default:
		std::cout << "Invalid";
	}

	int result = (x == 0) ? y = 0 : y = 10 / x;

}