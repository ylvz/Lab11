#include <iostream>

//Uppgift 4-7
int main() {
    double sum = 0.0;
    double number;

    std::cout << "Ange ett tal att summera (Ctrl-X f�r att avsluta): ";

    while (std::cin >> number) {
        sum += number;
    }

    std::cout << "Summan av talen �r: " << sum << std::endl;

    return 0;
}