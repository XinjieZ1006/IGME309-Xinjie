// A2_Part5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// functions for #3
int increment(int num)
{
    return num + 1;
}
int increment2(int& num)
{
    num += 1;
    return num;
}

void myFunc()
{
    cout << "myFunc() called!" << endl;
}
void myFuncPointer(void(*func)())
{
    func();
}
// 1. Copy Constructor vs. Copy Assignment Operator
class MyDemoClass
{
public:
    MyDemoClass(int i, string name = "Default");
    ~MyDemoClass();
    MyDemoClass(const MyDemoClass& obj); // copy constructor
    MyDemoClass& operator=(const MyDemoClass& obj); // copy assignment operator
    int someData;
    string name;
    void MyDemoFunc()const; // const member function - it cannot change *this!
    void MyDemoFunc2(); // non-const member function which can change *this.
    void MyDemoFunc3(const int& thingy);
    const string& GetName()const; // caller can't change the name because it returns reference to const
    string& GetName2(); // but for this one, the caller is able to change that!
    void operator()();
};
int main()
{
    // 1. Copy Constructor vs. Copy Assignment Operator
    cout << "Demo #1 - Copy Constructor vs. Copy Assignment Operator" << endl;
    MyDemoClass o1(10);
    cout << "o1: " << o1.someData << endl;
    MyDemoClass o2(20);
    cout << "o2: " << o2.someData << endl;
    cout << "Initializing o3 as a copy of o1. (this will call the copy constructor)" << endl;
    MyDemoClass o3 = o1;
    cout << "o3: " << o3.someData << endl;
    cout << "Now copy the value from o2 to o1, both are existing objects. (this will call the copy assignment operator)" << endl;
    o1 = o2;
    cout << "o1: " << o1.someData << endl;
    cout << endl;
    // Summary: copy constructor is used when initializing a new object using the value of an existing object, 
    // while copy assignment operator is used to copy the value from an existing object to another existing object.

    // 2. Const Correctness
    cout << "Demo #2 - Const Correctness" << endl;
    MyDemoClass o4(40, "Alice");
    cout << "o4: " << o4.someData << " Name: "<<o4.name << endl;
    cout << "Testing some functions on o4." << endl;
    o4.MyDemoFunc();
    o4.MyDemoFunc2();
    cout << "o4: " << o4.someData << endl;
    o4.MyDemoFunc3(444);
    cout << "o4: " << o4.someData << endl;
    cout << "Now get the name of o4..." << endl;
    cout << "GetName(): " << o4.GetName() << endl;
    cout << "Now do something shady using the alternative version" << endl;
    o4.GetName2() = "Bob";
    cout << o4.GetName2() << endl; // name changed to Bob!
    cout << endl;
    // Summary: using keyword const to prevent unintended modification of objects!
    // Mark function parameter that should not be modified as const.
    // Mark member functions as const if you don't want them to change the object values.
    // Mark references as const to prevent unwanted modification.
    // Reference: https://isocpp.org/wiki/faq/const-correctness

    // 3. Call by Value vs. Call by Reference
    cout << "Demo #3 - Call by Value vs. Call by Reference" << endl;
    int n1 = 10;
    int n2 = increment(n1);
    cout << n1 << " "<< n2 << endl;
    cout << "In this case, n1 is passed in as a value, which means the parameter 'num' stores the value of n1, therefore it won't get modified." << endl;
    int n3 = increment2(n1);
    cout << n1 << " " << n3 << endl;
    cout << "In this case, n1 is passed in as a reference, which means the function can modifiy n1 directly via num." << endl;
    cout << endl;

    // 4.Function Pointer vs. Function Object
    cout << "Demo #4 - Function Pointer vs. Function Object" << endl;
    cout << "Calling myFunc() directly: " << endl;
    myFunc();
    cout << "Calling myFuncPointer(): " << endl;
    myFuncPointer(myFunc);
    cout << "Calling MyDemoClass functor" << endl;
    o1();
    cout << endl;
    // Summary: a function pointer points to the memory address of a function, allowing it to be passed in as parameters and enables callback.
    // A function object is implemented by overloading the () operator of a class, allowing the class objects to be called like a function.

    // 5. Lambda Expressions
    cout << "Demo #5 - Lambda Expressions" << endl;
    vector<int> v{ 4, 1, 3, 5, 2, 3, 1, 7 };
    for_each(v.begin(), v.end(), [](int i)
             {
                 i++;
                 cout << i << " ";
             });
    cout << endl;
    // Lambda syntax: [//capture clause] (//parameters) { // lambda body}
}

MyDemoClass::MyDemoClass(int i,string name)
{
    someData = i;
    this->name = name;
    cout << "Regular constructor called!" << endl;
}

MyDemoClass::~MyDemoClass()
{
    //cout << "Destructor called!" << endl;
}

MyDemoClass::MyDemoClass(const MyDemoClass& obj)
{
    someData = obj.someData;
    cout << "Copy constructor called!" << endl;

}

MyDemoClass& MyDemoClass::operator=(const MyDemoClass& obj)
{
    if (this == &obj)
    {
        return *this;
    }
    someData = obj.someData;
    cout << "Copy Assignment operator called!" << endl;
}

void MyDemoClass::MyDemoFunc() const
{
    //someData = 100; // Can't modify!!
    cout << "MyDemoFunc(): Nothing happens because I'm a const member function and can't modify anything." << endl;
}

void MyDemoClass::MyDemoFunc2()
{
    someData = 100; // Can modify because it's not const
    cout << "MyDemoFunc2(): Successfully changed data to 100!" << endl;
}

void MyDemoClass::MyDemoFunc3(const int& thingy)
{
    someData = thingy;
    //thingy = 10; // cannot modify the passed-in value because it's marked as const.
    cout << "MyDemoFunc3(): Successfully changed data to" << thingy<< " !" << endl;
}

const string& MyDemoClass::GetName() const
{
    return name;
}

string& MyDemoClass::GetName2()
{
    return name;
}
void MyDemoClass::operator()()
{
    cout << "MyDemoClass object says HIIIII" << endl;
}
