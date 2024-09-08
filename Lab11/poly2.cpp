#include "poly2.h"
#include <cmath>
#include <iostream>

Poly2::Poly2(float a, float b, float c) : a(a), b(b), c(c) {}

float Poly2::eval(float x) {
    return a * x * x + b * x + c;
}

const float EPSILON = 1e-7;

int Poly2::findRoots(float& root1, float& root2) {
    // Hantera det speciella fallet när a = 0
    if (std::abs(a) < EPSILON) {
        if (std::abs(b) < EPSILON) {
            // Om både a och b är noll
            std::cerr << "Invalid polynomial (a and b cannot both be zero)." << std::endl;
            return 0; // Ingen rot
        }
        else {
            // Om endast a = 0, polynomet är linjärt: bx + c = 0
            root1 = -c / b;
            return 1; // En rot
        }
    }

    // Beräkna diskriminanten
    float d = b * b - 4 * a * c;

    if (d < -EPSILON) {
        // d < 0: Ingen reell rot
        return 0;
    }
    else if (std::abs(d) < EPSILON) {
        // d ≈ 0: En dubbelrot
        root1 = -b / (2 * a);
        return 1;
    }
    else {
        // d > 0: Två reella rötter
        float sqrt_d = std::sqrt(d);
        root1 = (-b + sqrt_d) / (2 * a);
        root2 = (-b - sqrt_d) / (2 * a);
        return 2;
    }
}

/*
* UPPGIFT 10
int Poly2::findRoots(float& root1, float& root2) {
    float discriminant = b * b - 4 * a * c;
    int nrOfRoots = 0;

    if (discriminant > 0) {
        // Två reella rötter
        float sqrtD = std::sqrt(discriminant);
        root1 = (-b + sqrtD) / (2 * a);
        root2 = (-b - sqrtD) / (2 * a);
        nrOfRoots = 2;
    }
    else if (discriminant == 0) {
        // En dubbelrot
        root1 = -b / (2 * a);
        nrOfRoots = 1;
    }
    else {
        // Ingen reell rot
        nrOfRoots = 0;
    }

    return nrOfRoots;
    */

/*UPPGIFT 8 void Poly2::findRoots() {
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        std::cout << "Inga reella rötter." << std::endl;
    } else if (discriminant == 0) {
        float root = -b / (2 * a);
        std::cout << "En reell rot (dubbelrot): " << root << std::endl;
    } else {
        float sqrtD = std::sqrt(discriminant);
        float root1 = (-b + sqrtD) / (2 * a);
        float root2 = (-b - sqrtD) / (2 * a);
        std::cout << "Två reella rötter: " << root1 << " och " << root2 << std::endl;
    }
    */

