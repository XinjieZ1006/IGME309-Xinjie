// A2_Part4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class AnyClass>
class Queue
{
public:
    Queue(int cap = 10);
    ~Queue();
    void Enqueue(const AnyClass& item);
    void Dequeue();
    bool IsEmpty();
    int getSize();
    AnyClass& Peek();
    void Print();
protected:
    AnyClass* queueArray;
    int size,capacity, front, rear;
};
template <class AnyClass>
class ModifiedQueue : public Queue<AnyClass>
{
public:
    using Queue<AnyClass>::Queue;
    void Enqueue(const AnyClass& item);
    void Dequeue();
};
int main()
{
    // testing simple queue
    Queue<int> queue(3);

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(30);
    queue.Print();
    queue.Dequeue();
    std::cout << "Test Original Queue Dequeue - Expected Front: 20, Actual Front: " << queue.Peek() << std::endl;

    ModifiedQueue<int> circularQueue(3);
    circularQueue.Enqueue(10);
    circularQueue.Enqueue(20);
    circularQueue.Enqueue(30);
    circularQueue.Print();
    circularQueue.Dequeue();
    circularQueue.Enqueue(40);
    circularQueue.Print();

}

template<class AnyClass>
Queue<AnyClass>::Queue(int cap)
{
    this->size = 0;
    this->front = 0;
    this->rear = -1;
    this->capacity = cap;
    this->queueArray = new AnyClass[capacity]();
}

template<class AnyClass>
Queue<AnyClass>::~Queue()
{
    delete[] this->queueArray;
    this->queueArray = nullptr;
}

template<class AnyClass>
void Queue<AnyClass>::Enqueue(const AnyClass& item)
{
    if (size == capacity)
    {
        cout << "Queue is full!" << endl;
        return;
    }
    rear++;
    queueArray[rear] = item;
    cout << "Added " << item << " to queue." << endl;
    size++;
}

template<class AnyClass>
void Queue<AnyClass>::Dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Removed " << queueArray[front] << " from queue." << endl;
    front = front + 1;
    size--;
}

template<class AnyClass>
bool Queue<AnyClass>::IsEmpty()
{
    return this->size == 0;
}

template<class AnyClass>
int Queue<AnyClass>::getSize()
{
    return this->size;
}

template<class AnyClass>
AnyClass& Queue<AnyClass>::Peek()
{
    if (this->IsEmpty())
    {
        throw std::underflow_error("Queue is empty.");
    }
    return this->queueArray[this->front];
}

template<class AnyClass>
void Queue<AnyClass>::Print()
{
    if (this->IsEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    int count = this->size;
    int index = front;
    while (count--)
    {
        cout << queueArray[index] << endl;
        index = (index + 1) % capacity; // Move circularly
    }
}


template<class AnyClass>
void ModifiedQueue<AnyClass>::Enqueue(const AnyClass& item)
{
    if (this->size == this->capacity)
    {
        cout << "Queue is full!" << endl;
        return;
    }
    this->rear = (this->rear + 1) % this->capacity;
    this->queueArray[this->rear] = item;
    this->size++;
    cout << "Added " << item << " to queue." << endl;
}

template<class AnyClass>
void ModifiedQueue<AnyClass>::Dequeue()
{
    if (this->IsEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Removed " << this->queueArray[this->front] << " from queue." << endl;
    this->front = (this->front + 1) % this->capacity;
    this->size--;
}
