#include <iostream>

void main()
{
    int first = 0;
    int second = 0;

    std::cout << "Enter the first number: " << std::endl;
    std::cin >> first;

    if (std::cin.fail()) {
        std::cout << "You didn't enter an Integer. We'll just use '5' instead." << std::endl;
        first = 5;
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }

    std::cout << "Enter the second number: " << std::endl;
    std::cin >> second;

    if (std::cin.fail()) {
        std::cout << "You didn't enter an integer. We'll just use '8' instead."
            << std::endl;
        second = 8;
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }
    std::cout << "The two numbers entered are: " << first << " and " << second << "." << std::endl;
    std::cout << first << " + " << second << " = " << (first + second) << std::endl;
    std::cout << first << " - " << second << " = " << (first - second) << std::endl;
    std::cout << first << " / " << second << " = " << (first / second) << std::endl;
    std::cout << first << " * " << second << " = " << (first * second) << std::endl;
    std::cout << first << " % " << second << " = " << (first % second) << std::endl;

    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
}