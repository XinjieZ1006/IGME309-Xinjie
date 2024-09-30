// A2_Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <time.h>
#include "SortingMethods.h"
using namespace std;

template<typename T>
void printList(std::vector<T>& list);

template<typename T>
inline void selectionSort(std::vector<T>& list)
{
	int size = list.size();
	for (int i = 0; i < size - 1; ++i)
	{

		int minIndex = i;
		// find the smallest element in the "unsorted" sub-list
		for (int j = i + 1; j < size; ++j)
		{
			if (list[j] < list[minIndex])
			{
				minIndex = j;
			}
		}
		//swap the current and the min
		std::swap(list[i], list[minIndex]);
	}
}

template<typename T>
inline void insertionSort(std::vector<T>& list)
{
	int size = list.size();
	for (int i = 1; i < size; ++i)
	{
		int j = i;
		// keep moving the current element to the left until it's in the right place
		while (j > 0 && list[j - 1] > list[j])
		{
			std::swap(list[j - 1], list[j]);
			--j;
		}
	}
}

template<typename T>
inline void bubbleSort(std::vector<T>& list)
{
	int size = list.size();
	// compare 2 adjacent elements, and swap as needed
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			// bigger element goes to the left
			if (list[i] > list[j])
			{
				std::swap(list[i], list[j]);
			}
		}
	}
}

template<typename T>
inline void quickSort(std::vector<T>& list, int start, int end)
{
	if (start < end) // keep sorting until the start and end collides
	{
		int pivot = partition(list, start, end);
		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
	}
}

template<typename T>
inline int partition(std::vector<T>& list, int start, int end)
{
	int i = start + 1;
	int pivotIndex = start + rand() % (end - start + 1); // set the random pivot
	auto pivot = list[pivotIndex];
	swap(list[start], list[pivotIndex]);
	for (int j = start + 1; j <= end; j++) // move start to the right until it finds an element less than pivot
	{
		if (list[j] < pivot)
		{
			swap(list[j], list[i]); // swap the elements
			i++;
		}
	}
	swap(list[start], list[i - 1]); // place pivot back
	return i - 1; // return current pivot position

}

template<typename T>
inline void mergeSort(std::vector<T>& list, int start, int end)
{
	if (start < end)
	{
		int mid = start + (start + end) / 2;
		mergeSort(list, start, mid);
		mergeSort(list, mid + 1, end);
		merge(list, start, end, mid);
	}
}

template<typename T>
inline void merge(std::vector<T>& list, int start, int end, int mid)
{
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	vector<T> leftList(leftSize);
	vector<T> rightList(rightSize);
	for (int i = 0; i < leftList.size(); ++i)
	{
		leftList[i] = list[start + 1];
	}
	for (int j = 0; j < leftList.size(); ++j)
	{
		leftList[j] = list[mid + 1 + j];
	}
	int i = 0, j = 0, k = start;
	while (i < leftList.size() && j < rightList.size())
	{
		if (leftList[i] <= rightList[j])
		{
			list[k] = leftList[i];
			i++;
		}
		else
		{
			list[k] = rightList[j];
			j++;
		}
	}
	while (i < leftSize)
	{
		list[k] = leftList[i];
		++k;
		++i;
	}
	while (i < rightSize)
	{
		list[k] = rightList[j];
		++k;
		++j;
	}
}

template<typename T>
inline void printList(std::vector<T>& list)
{
	for (auto i : list)
	{
		std::cout << i << ",";
	}
	std::cout << std::endl;
}

// helper function to print info and calculate time cost
template <typename T>
void timeSort(void(*sortFunc)(vector<T>&), vector<T>& list, const string& sortName)
{
    cout << "\nOriginal list:" << endl;
    printList(list);
    auto start = chrono::high_resolution_clock::now();
    sortFunc(list);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nSorted using " << sortName << ": " << endl;
    printList(list);
    cout << "\nTime taken by " << sortName << ": " << duration.count() << " microseconds\n" << endl;
}
template <typename T>
void timeSort(void(*sortFunc)(vector<T>&,int,int), vector<T>& list, const string& sortName,int _start,int _end)
{
    cout << "\nOriginal list:" << endl;
    printList(list);
    auto start = chrono::high_resolution_clock::now();
    sortFunc(list,_start,_end);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nSorted using " << sortName << ": " << endl;
    printList(list);
    cout << "\nTime taken by " << sortName << ": " << duration.count() << " microseconds\n" << endl;
}

int main()
{
    srand(time(0));
    bool isRunning = true;
    std::vector<int> list(100);
    for (auto& i : list)
    {
        i = rand() % 101;
    }
    while (isRunning)
    {
        cout << "Welcome to Sorty McSortface! Please select a sorting method." << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Exit" << endl;

        vector<int> listCopy = list;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            timeSort(bubbleSort, listCopy, "Bubble Sort");
            break;
        case 2:
            timeSort(selectionSort, listCopy, "Selection Sort");
            break;
        case 3:
            timeSort(insertionSort, listCopy, "Insertion Sort");
            break;
        case 4:
            timeSort(mergeSort, listCopy, "Merge Sort",0, listCopy.size() - 1);
            break;
        case 5:
            timeSort(quickSort, listCopy, "Quick Sort",0,listCopy.size() - 1);
            break;
        case 6:
            cout << "Thank you for using Sorty McSortface!" << endl;
            isRunning = false;
            break;
        default:
            cout << "Invalid input!" << endl;
            break;
        }
    }
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
