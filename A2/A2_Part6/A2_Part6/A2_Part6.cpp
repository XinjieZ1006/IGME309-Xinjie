// A2_Part6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

int main()
{

    Vector<double> v1(1, 2, 3);
    Vector<double> v2(4, 5, 6);
    cout << "v1: ";
    v1.Print();
    cout << "v2: ";
    v2.Print();
    // testing arithmetics
    cout << "v1 + v2 = ";
    (v1 + v2).Print();
    cout << "v1 - v2 = ";
    (v1 - v2).Print();
    cout << "v1 * 5 = ";
    (v1 * 5).Print();
    cout << "v1 (Normalized): ";
    v1.Normalize().Print();
    cout << "Dot product of v1 and v2: " << v1.dot(v2) << endl;
    cout << "Cross product of v1 and v2: ";
    v1.cross(v2).Print();

    Matrix<double> matA({ { 1, 4, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    Matrix<double> matB({ { 9, 8, 7 }, { 6, 5, 4 }, { 3, 2, 1 } });
    cout << "MatA: ";
    matA.Print();
    cout << "MatB: ";
    matB.Print();
    cout << "MatA + MatB: ";
    (matA + matB).Print();
    cout << "MatA - MatB: ";
    (matA - matB).Print();
    cout << "MatA * MatB: ";
    (matA * matB).Print();
    cout << "MatA * v2: ";
    (matA * v2).Print();
    cout << "MatA Transposed: ";
    matA.Transpose().Print();
    cout <<"Determinant of MatA: "<< matA.Determinant() << endl;
    cout << "Inverse of MatA: ";
    matA.Inverse().Print();

    
}

