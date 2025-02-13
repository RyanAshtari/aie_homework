#include <iostream>

const float _GALLONS_TO_LITRES = 3.78533f;

int NumberOfCalls(int calls);

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		NumberOfCalls(i);
	}

	std::cout << "Welcome to the Gallons to Litres converter!\nPlease indicate how many Gallons you have: ";
	float gallons;
	std::cin >> gallons;
	float litres = gallons * _GALLONS_TO_LITRES;
	std::cout << gallons << " Gallons will give you " << litres << " Litres!\n";
}

int NumberOfCalls(int calls)
{
	std::cout << "The number of times this function has been called is: " << calls << "\n";
	return 0;
}