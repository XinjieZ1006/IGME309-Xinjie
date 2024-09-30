#pragma once
#include <iostream>

using namespace std;
template <class AnyClass>
class StackLinkedList
{
public:
	StackLinkedList();
	~StackLinkedList();

	// copy constructor
	StackLinkedList(const StackLinkedList<AnyClass>& other);
	// copy assignment oprtr
	StackLinkedList<AnyClass>& operator =(const StackLinkedList<AnyClass>& other);


	void Push(AnyClass item);
	AnyClass& Top();
	void Pop();
	void Print();
	unsigned int GetSize();
	bool IsEmpty();
	void copyList(const StackLinkedList<AnyClass>& other);
private:
	struct Node
	{
		AnyClass data;
		Node* next;

		Node(const AnyClass& data, Node* next = nullptr);
	};
	unsigned int stackSize;
	Node* head;
};

template<class AnyClass>
inline StackLinkedList<AnyClass>::StackLinkedList()
{
	head = nullptr;
	stackSize = 0;
}

template<class AnyClass>
inline StackLinkedList<AnyClass>::~StackLinkedList()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

template<class AnyClass>
inline StackLinkedList<AnyClass>::StackLinkedList(const StackLinkedList<AnyClass>& other)
{
	copyList(other);
}

template<class AnyClass>
inline StackLinkedList<AnyClass>& StackLinkedList<AnyClass>::operator=(const StackLinkedList<AnyClass>& other)
{
	if (&other == this)
	{
		return *this;
	}
	while (!IsEmpty())
	{
		Pop();
	}
	copyList(other);
	return *this;

}

template<class AnyClass>
inline void StackLinkedList<AnyClass>::Push(AnyClass item)
{
	Node* newItem = new Node(item);
	newItem->next = head;
	head = newItem;
	stackSize++;
}

template<class AnyClass>
inline AnyClass& StackLinkedList<AnyClass>::Top()
{
	try
	{
		if (!IsEmpty())
		{
			return head->data;
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
inline void StackLinkedList<AnyClass>::Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is empty" << endl;
		return;
	}
	cout << "Popped " << head->data << " from the stack." << endl;
	Node* temp = head;
	head = head->next;
	delete temp;
	stackSize--;
}

template<class AnyClass>
inline void StackLinkedList<AnyClass>::Print()
{
	cout << "Printing " << stackSize << " items in this list..." << endl;
	if (IsEmpty())
	{
		return;
	}
	else
	{
		Node* current = head;
		while (current)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
}

template<class AnyClass>
inline unsigned int StackLinkedList<AnyClass>::GetSize()
{
	return stackSize;
}

template<class AnyClass>
inline bool StackLinkedList<AnyClass>::IsEmpty()
{
	return head == nullptr;
}

template<class AnyClass>
inline StackLinkedList<AnyClass>::Node::Node(const AnyClass& data, Node* next)
{
	this->data = data;
	this->next = next;

}

template<class AnyClass>
inline void StackLinkedList<AnyClass>::copyList(const StackLinkedList<AnyClass>& other)
{
	if (other.head == nullptr) // if other is empty
	{
		head = nullptr;
		stackSize = 0;
		return;
	}
	// copy the head
	head = new Node(other.head->data);
	Node* current = head;
	Node* otherCurrent = other.head->next;
	// copy the nodes
	while (otherCurrent != nullptr)
	{
		current->next = new Node(otherCurrent->data);
		current = current->next;
		otherCurrent = otherCurrent->next;
	}
	stackSize = other.stackSize;
}
