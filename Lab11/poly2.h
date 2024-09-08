#ifndef POLY2_H
#define POLY2_H

class Poly2 {
public:
    Poly2(float a, float b, float c);  // Konstruktor
    float eval(float x);               // Utv�rdera polynomet vid x
    int findRoots(float& root1, float& roat2);
    

private:
    float a, b, c;  // Koefficienter f�r polynomet
};

#endif
