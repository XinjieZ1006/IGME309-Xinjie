// A2_Part1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    step1();
    step2();
    step3();
    step4();
}

void step1()
{
    // Function 1
    int a, b, c, d;
    a = 3;
    b = a++ + ++a;
    c = a++ + ++b;
    cout << a << b << c;
    cout << endl;

}

void step2()
{
    int a, b, c, d;
    a = 5;
    b = 2;
    c = a < b;
    cout << c;
    cout << endl;
    c = a < b + 4;
    cout << c;
    cout << endl;
    d = a < b++;
    cout << a << b << c << d;
    cout << endl;
    c = a + b++ + c++;
    d = ++a + b++ + ++c;
    cout << a << b << c << d;
    cout << endl;

}

void step3()
{
    // Function 3
    int a, b, * p, * q, * r;
    a = 3;
    b = 6;
    p = &b;
    q = &a;
    *p = *q + 3;
    r = p;
    p = q;
    q = r;
    cout << a << b << *p << *q << *r;
    cout << endl;

}
void step4()
{
    // Function 4
    int a, b = 7;
    int* p, * q, ** r, *** s;
    s = &r;
    r = &q;
    p = &a;
    r = &p;
    a = 5;
    q = &b;
    **r = *p - 6; // fixed!
    cout << a << b << *p << *q << **r << ***s;
    cout << endl;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
