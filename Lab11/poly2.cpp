#include "poly2.h"
#include <cmath>
#include <iostream>

Poly2::Poly2(float a, float b, float c) : a(a), b(b), c(c) {}

float Poly2::eval(float x) {
    return a * x * x + b * x + c;
}


//Uppgift 8
//void Poly2::findRoots() const {
//    double discriminant = b * b - 4 * a * c;  // Diskriminanten (d)
//
//    if (discriminant < 0) {
//        std::cout << "Inga reella rötter (imaginära rötter)." << std::endl;
//    }
//    else if (discriminant == 0) {
//        // En dubbelrot
//        double root = -b / (2 * a);
//        std::cout << "En dubbelrot: x = " << root << std::endl;
//    }
//    else {
//        // Två reella rötter
//        double root1 = (-b + sqrt(discriminant)) / (2 * a);
//        double root2 = (-b - sqrt(discriminant)) / (2 * a);
//        std::cout << "Två rötter: x1 = " << root1 << ", x2 = " << root2 << std::endl;
//    }
//}

//
//Uppgift 9
//int Poly2::findRoots(double& root1, double& root2) const {
//    double discriminant = b * b - 4 * a * c;  // Diskriminanten (d)
//    if (discriminant < 0) {
//        // Inga reella rötter
//        return 0;
//    }
//    else if (discriminant == 0) {
//        // En dubbelrot
//        root1 = -b / (2 * a);
//        return 1;  // En dubbelrot
//    }
//    else {
//        // Två reella rötter
//        root1 = (-b + sqrt(discriminant)) / (2 * a);
//        root2 = (-b - sqrt(discriminant)) / (2 * a);
//        return 2;  // Två rötter
//    }
//}
//

//Uppgift 10 och 11
void Poly2::findRoots(int& numRoots, double& root1, double& root2) const {
    double discriminant = b * b - 4 * a * c;  // Diskriminanten (d)

    if (discriminant < 0) {
        numRoots = 0; // Inga reella rötter
    }
    else if (discriminant == 0) {
        numRoots = 1; // En dubbelrot
        root1 = -b / (2 * a);
    }
    else {
        numRoots = 2; // Två reella rötter
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
    }
}


