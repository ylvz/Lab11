// Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "poly2.h"
#include <iomanip>

int main() {
    float a, b, c;
    std::cout << "Enter coefficients a, b, and c (end with EOF):" << std::endl;

    while (std::cin >> a >> b >> c) {
        Poly2 poly(a, b, c);

        float root1, root2;
        int numRoots = poly.findRoots(root1, root2);

        std::cout << std::fixed << std::setprecision(10); // Sätt precision för flyttal

        std::cout << "Roots of the polynomial " << a << "x^2 + " << b << "x + " << c << ":" << std::endl;
        if (numRoots == 2) {
            std::cout << "Two real roots: " << root1 << " and " << root2 << std::endl;
            std::cout << "Eval for root1: " << poly.eval(root1) << std::endl;
            std::cout << "Eval for root2: " << poly.eval(root2) << std::endl;
        }
        else if (numRoots == 1) {
            std::cout << "One real root (double root): " << root1 << std::endl;
            std::cout << "Eval for root: " << poly.eval(root1) << std::endl;
        }
        else {
            std::cout << "No real roots." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

/*UPPGIFT 10
int main(int argc, char* argv[]) {
    std::istream* inputStream = &std::cin;
    std::ostream* outputStream = &std::cout;

    // Kontrollera om ett utmatningsfilnamn anges
    if (argc > 1) {
        std::ofstream* outputFile = new std::ofstream(argv[1]);
        if (!*outputFile) {
            std::cerr << "Error opening output file." << std::endl;
            return 1;
        }
        outputStream = outputFile;
    }

    float a, b, c;
    while (*inputStream >> a >> b >> c) {
        // Hantera det speciella fallet när a = 0
        if (a == 0) {
            *outputStream << "Invalid polynomial (a cannot be 0)." << std::endl;
            continue;
        }

        // Skapa ett polynom med inmatade koefficienter
        Poly2 poly(a, b, c);

        // Hitta rötter
        float root1, root2;
        int numRoots = poly.findRoots(root1, root2);

        // Skriv ut rötter
        *outputStream << "Rötter av polynomet " << a << "x^2 + " << b << "x + " << c << ":" << std::endl;
        if (numRoots == 2) {
            *outputStream << "Två reella rötter: " << root1 << " och " << root2 << std::endl;
            *outputStream << "Eval för rot1: " << poly.eval(root1) << std::endl;
            *outputStream << "Eval för rot2: " << poly.eval(root2) << std::endl;
        }
        else if (numRoots == 1) {
            *outputStream << "En reell rot (dubbelrot): " << root1 << std::endl;
            *outputStream << "Eval för rot: " << poly.eval(root1) << std::endl;
        }
        else {
            *outputStream << "Inga reella rötter." << std::endl;
        }

        *outputStream << std::endl;
    }

    // Stäng utmatningsfil om det behövs
    if (outputStream != &std::cout) {
        delete outputStream;
    }

    return 0;
}*/


/*int main()
{
    /* Uppgift 3
    std::string name;
    std::cout << "Hello World! Nice to see you, Astro!\n";
    std::getline(std::cin, name);

    std::cout << "Hello! " << name << "welcome!" << std::endl;


    
    double sum = 0.0;
    double number;

    std::cout << "Ange ett tal att summera.";

    while (std::cin >> number) {
        sum += number;
    }

    std::cout << "Summan av talen är:" << sum << std::endl;




    return 0;

    // Create a polynomial object with specific coefficients
    Poly2 poly(1, -3, 2); // Represents the polynomial x^2 - 3x + 2

    // Test the eval method
    float x = 1;
    float value = poly.eval(x);
    std::cout << "The value of the polynomial at x = " << x << " is: " << value << std::endl;

    // Test the findRoots method
    float root1, root2;
    int numRoots = poly.findRoots(root1, root2);

    if (numRoots == 0) {
        std::cout << "No real roots." << std::endl;
    }
    else if (numRoots == 1) {
        std::cout << "One real root (double root): " << root1 << std::endl;
    }
    else if (numRoots == 2) {
        std::cout << "Two real roots: " << root1 << " and " << root2 << std::endl;
    }
    
    UPPGIFT 8
    // Skapa ett polynom med specifika koefficienter
    Poly2 poly1(1, -3, 2);  // Polynom: x^2 - 3x + 2
    Poly2 poly2(1, 2, 1);   // Polynom: x^2 + 2x + 1
    Poly2 poly3(1, 1, 1);   // Polynom: x^2 + x + 1

    // Testa eval-metoden
    float x = 2;
    std::cout << "Värdet av poly1 vid x = " << x << " är: " << poly1.eval(x) << std::endl;
    std::cout << "Värdet av poly2 vid x = " << x << " är: " << poly2.eval(x) << std::endl;
    std::cout << "Värdet av poly3 vid x = " << x << " är: " << poly3.eval(x) << std::endl;

    // Testa findRoots-metoden
    std::cout << "Rötter av poly1:" << std::endl;
    poly1.findRoots();

    std::cout << "Rötter av poly2:" << std::endl;
    poly2.findRoots();

    std::cout << "Rötter av poly3:" << std::endl;
    poly3.findRoots();

    return 0;

    UPPGIFT 9
    // Skapa polynom med olika koefficienter
    Poly2 poly1(1, -3, 2);  // Polynom: x^2 - 3x + 2
    Poly2 poly2(1, 2, 1);   // Polynom: x^2 + 2x + 1
    Poly2 poly3(1, 1, 1);   // Polynom: x^2 + x + 1

    float root1, root2;
    int numRoots;

    // Testa findRoots-metoden
    numRoots = poly1.findRoots(root1, root2);
    std::cout << "Rötter av poly1:" << std::endl;
    if (numRoots == 2) {
        std::cout << "Två reella rötter: " << root1 << " och " << root2 << std::endl;
    }
    else if (numRoots == 1) {
        std::cout << "En reell rot (dubbelrot): " << root1 << std::endl;
    }
    else {
        std::cout << "Inga reella rötter." << std::endl;
    }

    numRoots = poly2.findRoots(root1, root2);
    std::cout << "Rötter av poly2:" << std::endl;
    if (numRoots == 2) {
        std::cout << "Två reella rötter: " << root1 << " och " << root2 << std::endl;
    }
    else if (numRoots == 1) {
        std::cout << "En reell rot (dubbelrot): " << root1 << std::endl;
    }
    else {
        std::cout << "Inga reella rötter." << std::endl;
    }

    numRoots = poly3.findRoots(root1, root2);
    std::cout << "Rötter av poly3:" << std::endl;
    if (numRoots == 2) {
        std::cout << "Två reella rötter: " << root1 << " och " << root2 << std::endl;
    }
    else if (numRoots == 1) {
        std::cout << "En reell rot (dubbelrot): " << root1 << std::endl;
    }
    else {
        std::cout << "Inga reella rötter." << std::endl;
    }

    return 0;

float a, b, c;
while (true) {
    std::cout << "Ange koefficienter för ett polynom (a, b, c)" << std::endl;
    std::cout << "a: ";
    if (!(std::cin >> a)) {
        // Om det inte går att läsa in a (t.ex. EOF eller felaktig inmatning)
        break;
    }

    std::cout << "b: ";
    if (!(std::cin >> b)) {
        // Om det inte går att läsa in b (t.ex. EOF eller felaktig inmatning)
        break;
    }

    std::cout << "c: ";
    if (!(std::cin >> c)) {
        // Om det inte går att läsa in c (t.ex. EOF eller felaktig inmatning)
        break;
    }

    // Skapa ett polynom med inmatade koefficienter
    Poly2 poly(a, b, c);

    // Hitta rötter
    float root1, root2;
    int numRoots = poly.findRoots(root1, root2);

    // Skriv ut rötter
    std::cout << "Rötter av polynomet " << a << "x^2 + " << b << "x + " << c << ":" << std::endl;
    if (numRoots == 2) {
        std::cout << "Två reella rötter: " << root1 << " och " << root2 << std::endl;
    }
    else if (numRoots == 1) {
        std::cout << "En reell rot (dubbelrot): " << root1 << std::endl;
    }
    else {
        std::cout << "Inga reella rötter." << std::endl;
    }

    std::cout << std::endl;
}

// Återställ std::cin till sitt ursprungliga tillstånd efter avslutad inmatning
std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}*/




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
