#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void selectionSort(std::vector<T>& list);
template<typename T>
void insertionSort(std::vector<T>& list);
template<typename T>
void bubbleSort(std::vector<T>& list);
template<typename T>
void quickSort(std::vector<T>& list, int start, int end);
// quick sort helper method
template<typename T>
int partition(std::vector<T>& list, int start, int end);
template<typename T>
void mergeSort(std::vector<T>& list, int start, int end);
// merge sort helper
template<typename T>
void merge(std::vector<T>& list,int start,int end,int mid);



