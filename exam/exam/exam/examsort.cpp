#include "stdafx.h"
#include "sortstructor.h"
#include <iostream>
using namespace std;

void InsertSort(int array[] , unsigned int nNum)
{
    int temp,j;
    unsigned int i;
    for (i = 1; i < nNum; ++i)
    {
        if (array[i] < array[i - 1])
        {
            temp = array[i];
            array[i] = array[i - 1];
            for (j = i - 1;j >= 0 && temp < array[j]; --j)
            {
                array[j + 1] = array[j];
            }
            array[j + 1] = temp;
        }
    }
}
///////////////////////////////////////////////////
void QuickSort(int array[] , int left,int right)
{
    if (left < right)
    {
        int key = array[left];
        int low = left;
        int high = right;

        while (low < high)
        {
            while (low < high && array[high] >= key)
                high--;

            array[low] = array[high];

            while (low < high && array[low] <= key)
                low++;

            array[high] = array[low];
        }

        array[low] = key;

        QuickSort(array, left   , low - 1);
        QuickSort(array, low + 1, right);
    }
}

///////////////////////////////////////////////////
#if 0
void ShellInsert(int Array[],int size,int dk)
{
    int i,j,temp;
    for (i = dk + 1; i <= size;++i)
    {
        if (Array[i] < Array[i - dk])
        {
            Array[0] = Array[i];
            //temp = Array[i];
            for (j = i - dk; j > 0 && Array[0] < Array[j]; j -= dk)
            {
                Array[j + dk] = Array[j];
            }
            Array[j + dk] = Array[0];
            //Array[j + dk] = temp;
        }
    }
}
void ShellSort(int Array[],int n)
{
    int dlta[] = {4,3,2};
    int i;
    for (i = 0;i < sizeof(dlta) / sizeof(int);i++)
    {
        ShellInsert(Array,n, dlta[i]);
    }
}

#else
void ShellInsert(int Array[], int d, int iDataNum)
{
    for (int i = d; i < iDataNum; i += 1) 
    {
        int j = i - d;
        int temp = Array[i];  
        while (j >= 0 && Array[j] > temp)  
        {
            Array[j+d] = Array[j];   
            j -= d;
        }

        if (j != i - d)
            Array[j+d] = temp;
    }
}

void ShellSort(int Array[], int iDataNum)
{
    int d = iDataNum / 2;   
    while(d >= 1)
    {
        ShellInsert(Array, d, iDataNum);
        d = d / 2;    
    }
}
#endif
///////////////////////////////////////////////////
#if 0
void HeapAdjust(int array[], int s,int m)
{
    int rc = array[s], j;
    for (j = 2 * s ; j<= m; j *= 2)
    {
        if ((j < m) && (array[j] < array[j +1]))
            j++;

        if (!(rc < array[j]))
            break;

        array[s] = array[j];
        s = j;
    }
    array[s] = rc;
}

void HeapSort(int array[], unsigned int size)
{
    int i;
    for (i = size / 2 ;i > 0; --i)
    {
        HeapAdjust(array, i, size);
    }
    for (i = size; i > 1; --i)
    {
        int temp;
        temp = array[1];
        array[1] = array[i];
        array[i] = temp;

        HeapAdjust(array, 1 , i - 1);
    }
}

#else

void FindMaxInHeap(int arr[], const int size) 
{
    for (int j = size - 1; j > 0; --j) 
    {
        int parent = j / 2;
        int child = j;

        if (j < size - 1 && arr[j] < arr[j + 1]) 
        {
            ++child;
        }

        if (arr[child] > arr[parent]) 
        {
            int tmp = arr[child];
            arr[child] = arr[parent];
            arr[parent] = tmp;
        }
    }
}

void HeapSort(int arr[], const int size) 
{
    for (int j = size; j > 0; --j) 
    {
        FindMaxInHeap(arr, j);

        int tmp = arr[0];
        arr[0] = arr[j - 1];
        arr[j - 1] = tmp;
    }
}
#endif
int FindkndMaxValue(int array[], const int size, int k)
{
    int i;
    int maxknd = 0;
    int *a = (int*)malloc(k * sizeof(int));
    memset(a,-1,k * sizeof(int));

    for (i = 0;i < size ;i++)
    {
        if (array[i] > a[0])
        {
            a[0] = array[i];
            InsertSort(a,k);
        }
    }
    maxknd = a[0];
    free(a);
    return maxknd;
}

void specialsort(int input[],int n, int output[])
{
    int nmax;
    int i,index,midindex;
    int iodd = n % 2;

    midindex = n / 2;
    output[midindex] = FindkndMaxValue(input,n,1);
    index = midindex;
    
    for (i = 2;i <= n;i++)
    {
        nmax = FindkndMaxValue(input,n,i);
        if (i % 2 == 0)
        {
            output[--index] = nmax;
        }
        else
        {
            output[n - index - iodd] = nmax;
        }
    }    
}

void SortAction()
{
    int arr1[] = {13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230};
    int arr2[] = {13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230};
    int arr3[] = {13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230};
    int arr4[] = {13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230};
    int arr5[] = {13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230};
    int arr6[sizeof(arr5) / sizeof(int)] = {};
    int k = 3;
    int maxknd = FindkndMaxValue(arr1, sizeof(arr1) / sizeof(int), k);
    cout << "\n===========================Sort===========================" << endl;
    printf("%d nd max value is:%d \n", k ,maxknd);

    InsertSort(arr1,sizeof(arr1) / sizeof(int));
    QuickSort(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
    ShellSort( arr3, sizeof(arr3) / sizeof(int));
    HeapSort(arr4, sizeof(arr4) / sizeof(int));
    specialsort(arr5, sizeof(arr5) / sizeof(int),arr6);
    printf("\narr1:");
    for (int i = 0;i < sizeof(arr1) / sizeof(int) ;i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\narr2:");
    for (int i = 0;i < sizeof(arr2) / sizeof(int) ;i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\narr3:");
    for (int i = 0;i < sizeof(arr3) / sizeof(int) ;i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\narr4:");
    for (int i = 0;i < sizeof(arr4) / sizeof(int) ;i++)
    {
        printf("%d ", arr4[i]);
    }
    printf("\narr6:");
    for (int i = 0;i < sizeof(arr6) / sizeof(int) ;i++)
    {
        printf("%d ", arr6[i]);
    }
}

