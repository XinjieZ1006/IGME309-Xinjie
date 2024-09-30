#pragma once
#include <iostream>
using namespace std;
template <class AnyClass>
class Stack
{
public:
	Stack();
	~Stack();

	// copy constructor
	Stack(const Stack& other);
	// copy assignment oprtr
	Stack<AnyClass>& operator =(const Stack<AnyClass>& other);


	void Push(AnyClass item);
	AnyClass& Top();
	void Pop();
	void Print();
	unsigned int GetSize();
	bool IsEmpty();
	bool IsFull();
private:
	AnyClass* stackArray;
	unsigned int stackSize;
	unsigned int lastFreeIndex;
};

template<class AnyClass>
inline Stack<AnyClass>::Stack()
{
	stackSize = 1;
	stackArray = new AnyClass[stackSize]{};
	lastFreeIndex = 0;
}

template<class AnyClass>
inline Stack<AnyClass>::~Stack()
{
	stackSize = 0;
	lastFreeIndex = 0;
	delete[] stackArray;
	stackArray = nullptr;
}

template<class AnyClass>
inline Stack<AnyClass>::Stack(const Stack& other)
{
	stackSize = other.stackSize;
	lastFreeIndex = other.lastFreeIndex;
	stackArray = new AnyClass[stackSize]{};
	for (int i = 0; i < stackSize; i++)
	{
		stackArray[i] = other.stackArray[i];
	}
}

template<class AnyClass>
inline Stack<AnyClass>& Stack<AnyClass>::operator=(const Stack<AnyClass>& other)
{
	if (&other == this)
	{
		return *this;
	}
	else
	{
		stackSize = other.stackSize;
		lastFreeIndex = other.lastFreeIndex;
		if (stackArray != nullptr)
		{
			delete[] stackArray;
			stackArray = nullptr;
		}
		delete[] stackArray;
		stackArray = nullptr;
		stackArray = new AnyClass[stackSize]{};
		std::copy(other.stackArray, other.stackArray + other.stackSize, stackArray);
		return *this;
	}
}

template<class AnyClass>
inline void Stack<AnyClass>::Push(AnyClass item)
{
	if (lastFreeIndex + 1 > stackSize)
	{
		int newSize = stackSize * 2;
		AnyClass* newArray = new AnyClass[newSize]{};
		std::move(stackArray, stackArray + stackSize, newArray);
		delete[] stackArray;
		stackArray = nullptr;
		stackArray = newArray;
		stackSize = newSize;
	}
	stackArray[lastFreeIndex] = item;
	lastFreeIndex++;
	cout << "Pushed " << item << " to stack." << endl;
}

template<class AnyClass>
inline AnyClass& Stack<AnyClass>::Top()
{
	try
	{
		if (lastFreeIndex > 0)
		{
			return stackArray[lastFreeIndex - 1];
		}
		else
		{
			throw std::out_of_range("Stack is EMPTY!!!!!");
		}

	}
	catch (int e)
	{
		//
	}
}

template<class AnyClass>
inline void Stack<AnyClass>::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is empty!";
		return;
	}
	else
	{
		AnyClass popped = stackArray[lastFreeIndex - 1];
		std::cout << "Removed " << popped << " from stack." << std::endl;
		lastFreeIndex--;
		stackSize--;
		return;
	}
}

template<class AnyClass>
inline void Stack<AnyClass>::Print()
{
	std::cout << "Elements in this stack: " << std::endl;
	if (!IsEmpty())
	{
		for (unsigned int i = 0; i < lastFreeIndex; ++i)
		{
			std::cout << stackArray[i] << std::endl;
		}
	}
	else
	{
		cout << "Stack is empty" << endl;
	}
}

template<class AnyClass>
inline unsigned int Stack<AnyClass>::GetSize()
{
	if (lastFreeIndex > 0)
	{
		return lastFreeIndex;
	}
	else
	{
		cout << "Stack is empty." << endl;
		return 0;
	}
}

template<class AnyClass>
inline bool Stack<AnyClass>::IsEmpty()
{
	return lastFreeIndex <= 0;
}

template<class AnyClass>
inline bool Stack<AnyClass>::IsFull()
{
	return lastFreeIndex+1 >= stackSize;
}
