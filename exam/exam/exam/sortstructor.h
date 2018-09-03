#ifndef _SORT_STRUCTOR_
#define _SORT_STRUCTOR_
#include <fstream>
#include <string>
#include "stdlib.h"
#include <time.h> 
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

void InsertSort(int array[] , unsigned int nNum);
void QuickSort(int array[] , int left,int right);
void ShellInsert(int Array[], int d, int iDataNum);
void FindMaxInHeap(int arr[], const int size) ;
void HeapSort(int arr[], const int size) ;
int FindkndMaxValue(int array[], const int size, int k);
void specialsort(int input[],int n, int output[]);
void SortAction();
#endif 