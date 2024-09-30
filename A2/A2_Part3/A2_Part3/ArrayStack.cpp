// A2_Part3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"

int main()
{
    // test #1
    Stack<int>* intStack = new Stack<int>();
    intStack->Push(114);
    intStack->Push(514);
    intStack->Push(1919810);
    intStack->Print();
    intStack->Pop();
    intStack->Pop();
    intStack->Print();
    intStack->Push(5555);
    cout << "Change the top element to 1111" << endl;
    intStack->Top() = 1111;
    intStack->Print();
    cout << "Size of the stack: " << intStack->GetSize() << endl;

    // test #2
    Stack<char>* charStack = new Stack<char>();
    charStack->Push('A');
    charStack->Push('B');
    charStack->Push('C');
    charStack->Pop();
    charStack->Print();
    charStack->Push('D');
    charStack->Print();
    cout << "Change the top element to M" << endl;
    charStack->Top() = 'M';
    charStack->Print();

    charStack->Pop();
    charStack->Pop();
    cout << "Size of the stack: " << charStack->GetSize() << endl;
    charStack->Pop();
    charStack->Pop();
    //charStack->Top(); //CRASH!
    if (charStack->IsEmpty())
    {
        cout << "IsEmpty says the stack is empty." << endl;
    }

    // test #3
    Stack<string>* stringStack = new Stack<string>();
    stringStack->Push("hola");
    stringStack->Push("hello");
    stringStack->Push("salve");
    stringStack->Push("bonjour");
    stringStack->Push("ciao");
    stringStack->Print();
    stringStack->Pop();
    stringStack->Pop();
    stringStack->Top() = "ADIOS!!!";
    stringStack->Print();
    cout << "Size of the stack: " << stringStack->GetSize() << endl;

    // test copy assignment & constructor
    Stack<string>* newStringStack = new Stack<string>(*stringStack);
    newStringStack->Print();
    newStringStack->Pop();
    newStringStack->Pop();
    newStringStack->Print();
    *newStringStack = *stringStack;
    newStringStack->Print();

    // delete stuff on heap
    delete intStack;
    intStack = nullptr;
    delete charStack;
    charStack = nullptr;
    delete stringStack;
    stringStack = nullptr;
    delete newStringStack;
    newStringStack = nullptr;
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
