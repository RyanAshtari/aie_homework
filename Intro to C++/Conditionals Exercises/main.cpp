#include <iostream>
#include <string>

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
		std::cout << "Zero\n";
	}
	else if (numTotal % 2 == 0)
	{
		std::cout << "Positive\n";
	}
	else
	{
		std::cout << "Negative\n";
	}

	int choice = 4;

	switch (choice)
	{
	case 1:
		std::cout << "1\n";
		break;
	case 2:
		std::cout << "2 or 3\n";
		break;
	case 3:
		std::cout << "2 or 3\n";
		break;
	case 4:
		std::cout << "4\n";
		break;
	default:
		std::cout << "Invalid\n";
	}

	int result = (x == 0) ? y = 0 : y = 10 / x;

	std::cout << "Please input one number: ";
	int userInput1;
	std::cin >> userInput1;
	std::cout << "\nNow input a second number: ";
	int userInput2;
	std::cin >> userInput2;
	std::cout << "\nFinally input one of these operators (+,-,*,/,%): ";
	std::string userInputOperator;
	std::cin >> userInputOperator;

	if (userInputOperator == "+")
	{
		std::cout << userInput1 << " + " << userInput2 << " = " << userInput1 + userInput2;
	}
	else if (userInputOperator == "-")
	{
		std::cout << userInput1 << " - " << userInput2 << " = " << userInput1 - userInput2;
	}
	else if (userInputOperator == "*")
	{
		std::cout << userInput1 << " * " << userInput2 << " = " << userInput1 * userInput2;
	}
	else if (userInputOperator == "/")
	{
		std::cout << userInput1 << " / " << userInput2 << " = " << userInput1 / userInput2;
	}
	else if (userInputOperator == "%")
	{
		std::cout << userInput1 << " % " << userInput2 << " = " << userInput1 % userInput2;
	}
	else
	{
		std::cout << "\nError: one of your input's was not appropriate, the program will not run.";
	}

	std::cout << "\nPlease input a number from 1-12 representing a month of the year: ";
	int userMonth;
	std::cin >> userMonth;

	switch (userMonth)
	{
	case 1:
		std::cout << "\nThere are 31 days in January.";
		break;
	case 2:
		std::cout << "\nThere are 28 days in February during a common year, and 29 days in a leap year.";
		break;
	case 3:
		std::cout << "\nThere are 31 days in March.";
		break;
	case 4:
		std::cout << "\nThere are 30 days in April.";
		break;
	case 5:
		std::cout << "\nThere are 31 days in May.";
		break;
	case 6:
		std::cout << "\nThere are 30 days in June.";
		break;
	case 7:
		std::cout << "\nThere are 31 days in July.";
		break;
	case 8:
		std::cout << "\nThere are 31 days in August.";
		break;
	case 9:
		std::cout << "\nThere are 30 days in September.";
		break;
	case 10:
		std::cout << "\nThere are 31 days in October.";
		break;
	case 11:
		std::cout << "\nThere are 30 days in November.";
		break;
	case 12:
		std::cout << "\nThere are 31 days in December.";
		break;
	default:
		std::cout << "\nError! You have not selected a valid input. The program will not run.";
	}
}