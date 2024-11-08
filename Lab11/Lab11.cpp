// Lab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "poly2.h"
#include <iomanip>
#include <string>

//Uppgift 3
//int main(){
//
//    //std::string name;
//    //std::cout << "Hello! What's your name?\n";
//    //std::getline(std::cin, name);
//
//    //std::cout << "Hello! " << name << ", welcome!" << std::endl;
// return 0;
//
//}
// 
//Uppgift 8
//int main() {
//    // Skapa polynom med olika koefficienter
//    Poly2 p1(1, 2, 1);   // x^2 + 2x + 1 (En dubbelrot)
//    Poly2 p2(2, -1, -1); // 2x^2 - x - 1 (Tv� r�tter)
//    Poly2 p3(1, 1, 1);   // x^2 + x + 1 (Inga reella r�tter)
//
//    // Testa eval-metoden
//    std::cout << "Eval f(x) f�r p1 (x = -1): " << p1.eval(-1) << std::endl;
//    std::cout << "Eval f(x) f�r p2 (x = 1): " << p2.eval(1) << std::endl;
//    std::cout << "Eval f(x) f�r p3 (x = 1): " << p3.eval(1) << std::endl;
//
//    // Testa findRoots-metoden
//    std::cout << "R�tter f�r p1: ";
//    p1.findRoots();
//    std::cout << "R�tter f�r p2: ";
//    p2.findRoots();
//    std::cout << "R�tter f�r p3: ";
//    p3.findRoots();
//
//    return 0;
//}

//////Uppgift 9
//int main() {
//    // Skapa polynom med olika koefficienter
//    Poly2 p1(1, 2, 1);   // x^2 + 2x + 1 (En dubbelrot)
//    Poly2 p2(2, -1, -1); // 2x^2 - x - 1 (Tv� r�tter)
//    Poly2 p3(1, 1, 1);   // x^2 + x + 1 (Inga reella r�tter)
//
//    // Testa eval-metoden f�r att f� v�rdet av polynomet f�r ett givet x
//    std::cout << "Eval f(x) f�r p1 (x = -1): " << p1.eval(-1) << std::endl;
//    std::cout << "Eval f(x) f�r p2 (x = 1): " << p2.eval(1) << std::endl;
//    std::cout << "Eval f(x) f�r p3 (x = 1): " << p3.eval(1) << std::endl;
//
//    // Testa findRoots-metoden
//    double root1, root2;
//
//    // F�r p1
//    std::cout << "R�tter f�r p1: ";
//    int numRoots1 = p1.findRoots(root1, root2);
//    std::cout << "Antal r�tter: " << numRoots1 << std::endl;
//    if (numRoots1 > 0) {
//        std::cout << "Rot 1: " << root1 << std::endl;
//    }
//    if (numRoots1 == 2) {
//        std::cout << "Rot 2: " << root2 << std::endl;
//    }
//
//    // F�r p2
//    std::cout << "R�tter f�r p2: ";
//    int numRoots2 = p2.findRoots(root1, root2);
//    std::cout << "Antal r�tter: " << numRoots2 << std::endl;
//    if (numRoots2 > 0) {
//        std::cout << "Rot 1: " << root1 << std::endl;
//    }
//    if (numRoots2 == 2) {
//        std::cout << "Rot 2: " << root2 << std::endl;
//    }
//
//    // F�r p3
//    std::cout << "R�tter f�r p3: ";
//    int numRoots3 = p3.findRoots(root1, root2);
//    std::cout << "Antal r�tter: " << numRoots3 << std::endl;
//    if (numRoots3 == 0) {
//        std::cout << "Inga reella r�tter." << std::endl;
//    }
//
//    return 0;
//}
//
// Uppgift 10
//int main() {
//    int a, b, c;
//    std::cout << "Ange koefficienter f�r ett polynom" << std::endl;
//    // Forts�tt l�sa in koefficienter tills EOF (Ctrl + X) p�tr�ffas
//    while (std::cin >> a >> b >> c) {
//
//        // Skapa ett nytt polynom med koefficienterna
//        Poly2 poly(a, b, c);
//
//        // H�mta och skriv ut r�tterna f�r det aktuella polynomet
//        int numRoots = 0;
//        double root1, root2;
//        poly.findRoots(numRoots, root1, root2);
//        // Skriv ut resultatet i main (ist�llet f�r i findRoots)
//        std::cout << "Polynom: " << a << "x^2 + " << b << "x + " << c << std::endl;
//        if (numRoots == 0) {
//            std::cout << "Inga reella r�tter." << std::endl;
//        }
//        else if (numRoots == 1) {
//            std::cout << "En dubbelrot: x = " << root1 << std::endl;
//        }
//        else {
//            std::cout << "Tv� r�tter: x1 = " << root1 << ", x2 = " << root2 << std::endl;
//        }
//    }
//
//    return 0;
//}

//Uppgift 11

int main() {
    std::ifstream inputFile("coeffs.txt"); // L�ser in koefficienterna fr�n filen
    std::ofstream outputFile("roots.txt"); // Skriver ut r�tterna till filen

    if (!inputFile) {
        std::cerr << "Filen kunde inte �ppnas!" << std::endl;
        return 1; // Avsluta om filen inte kan �ppnas
    }

    int a, b, c;
    while (inputFile >> a >> b >> c) {
        // Skapa polynom med l�sta koefficienter
        Poly2 poly(a, b, c);

        // H�mta r�tterna f�r det aktuella polynomet
        int numRoots = 0;
        double root1, root2;
        poly.findRoots(numRoots, root1, root2);

        // Skriv ut koefficienterna och r�tterna till outputFile
        outputFile << "Polynom: " << a << "x^2 + " << b << "x + " << c << std::endl;
        if (numRoots == 0) {
            outputFile << "Inga reella r�tter." << std::endl;
        }
        else if (numRoots == 1) {
            outputFile << "En dubbelrot: x = " << root1 << std::endl;
            outputFile << "Eval f�r rot: " << poly.eval(root1) << std::endl;
        }
        else {
            outputFile << "Tv� r�tter: x1 = " << root1 << ", x2 = " << root2 << std::endl;
            outputFile << "Eval f�r rot1: " << poly.eval(root1) << std::endl;
            outputFile << "Eval f�r rot2: " << poly.eval(root2) << std::endl;
        }
        outputFile << std::endl; // Ny rad efter varje polynom
    }

    inputFile.close();
    outputFile.close();

    return 0;
}



