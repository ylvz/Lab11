#ifndef POLY2_H
#define POLY2_H
#include <vector>

class Poly2 {
public:
    Poly2(float a, float b, float c);  // Konstruktor
    float eval(float x);               // Utvärdera polynomet vid x
    ////Uppgift 9
    //int findRoots(double& root1, double& root2) const;
    //Uppgift 8
    //void findRoots() const;
    //Uppgift 11
    void findRoots(int& rootCount, double& root1, double& root2) const;
    

private:
    float a, b, c;  // Koefficienter för polynomet
};

#endif
