// Stack_VS_Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void wrapper()
{
	// stack-allocated variable
	// they automatically destroy themselves when out of scope so there's no need to manually free them.
	int myStackArray[3];

	// heap-allocated variable (created using the "new" keyword)
	// don't delete themselves automatically, which means we have to manually deallocate the memory
	// otherwise we get memory leaks!
	int* myHeapArray = new int[3];

	// if I don't add these two lines it will say memory leaks
	delete[] myHeapArray;
	myHeapArray = nullptr;
}
int main()
{
	wrapper();
	if (_CrtDumpMemoryLeaks())
	{
		std::cout << "Mem leaks detected";
	}
}
