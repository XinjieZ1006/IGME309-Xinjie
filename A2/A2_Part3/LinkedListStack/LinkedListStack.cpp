// LinkedListStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StackLinkedList.h"

int main()
{
    StackLinkedList<int>* intStack = new StackLinkedList<int>();
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
    StackLinkedList<char>* charStack = new StackLinkedList<char>();
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
    StackLinkedList<string>* stringStack = new StackLinkedList<string>();
    stringStack->Push("hola");
    stringStack->Push("hello");
    stringStack->Push("salve");
    stringStack->Push("bonjour");
    stringStack->Push("ciao");
    stringStack->Print();
    stringStack->Pop();
    stringStack->Pop();
    stringStack->Top() = "ADIOS!!!";
    cout << "Change the top element to ADIOS!!!"  << endl;
    stringStack->Print();
    cout << "Size of the stack: " << stringStack->GetSize() << endl;

    // test copy assignment & constructor
    StackLinkedList<string>* newStringStack = new StackLinkedList<string>(*stringStack);
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
}

