#include <iostream>

int main()
{
    int total = 0;
    int count = 0;
    int number = 1;

    while (count < 15) {
        total += number;
        number += 2;
        count += 1;
    }

    std::cout << "Total of the first 15 odd numbers is " << total << std::endl;

    return 0;
}