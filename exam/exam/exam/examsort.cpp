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
            while (low < high && key <= array[high])
                high--;

            array[low] = array[high];

            while (low < high && key >= array[low])
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
void shellsort2(int v[],int n)
{
    int gap,i,j,temp;
    for(gap = n / 2;gap > 0; gap /= 2)
    {
        for (i = gap; i < n;i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j-= gap)
            {
                temp = v[j];v[j] = v[j + gap];v[j + gap] = temp;
            }
        }
    }
}
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
void SelectSort(int a[], const int n)
{
	for (int i = 0; i < n - 1; i++) 
	{
		int min = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (a[min] > a[j])
				min = j;
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right)
{
	// 如果 left == right，表示数组只有一个元素，则不用递归排序
	if (left < right)
	{
		// 把大的数组分隔成两个数组
		int mid = (left + right) / 2;
		// 对左半部分进行排序
		mergeSort(arr, left, mid);
		// 对右半部分进行排序
		mergeSort(arr, mid + 1, right);
		//进行合并
		merge(arr, left, mid, right);
	}
}
// 合并函数，把两个有序的数组合并起来
// arr[left..mif]表示一个数组，arr[mid+1 .. right]表示一个数组
void merge(int arr[], int left, int mid, int right)
{
	//先用一个临时数组把他们合并汇总起来
	//int[] a = new int[right - left + 1];
	int *a = (int*)malloc((right - left + 1) * sizeof(int));
	memset(a, 0x00, (right - left + 1) * sizeof(int));
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			a[k++] = arr[i++];
		}
		else
		{
			a[k++] = arr[j++];
		}
	}
	while (i <= mid)
		a[k++] = arr[i++];
	while (j <= right)
		a[k++] = arr[j++];
	// 把临时数组复制到原数组
	for (i = 0; i < k; i++)
	{
		arr[left++] = a[i];
	}
}

void mergeSort2(int arr[],int n) 
{
	// 子数组的大小分别为1，2，4，8...
	// 刚开始合并的数组大小是1，接着是2，接着4....
	for (int i = 1; i < n; i += i) 
	{
		//进行数组进行划分
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;
		//进行合并，对数组大小为 i 的数组进行两两合并
		while (right < n) 
		{
			// 合并函数和递归式的合并函数一样
			merge(arr, left, mid, right);
			left = right + 1;
			mid = left + i - 1;
			right = mid + i;
		}
		// 还有一些被遗漏的数组没合并，千万别忘了
		// 因为不可能每个字数组的大小都刚好为 i
		if (left < n && mid < n) 
		{
			merge(arr, left, mid, n - 1);
		}
	}
}

void downAdjust(int arr[], int parent, int n);
// 堆排序
void headSort(int arr[],int n) 
{
	//构建大顶堆
	for (int i = (n - 2) / 2; i >= 0; i--) 
	{
		downAdjust(arr, i, n - 1);
	}
	//进行堆排序
	for (int i = n - 1; i >= 1; i--) 
	{
		// 把堆顶元素与最后一个元素交换
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		// 把打乱的堆进行调整，恢复堆的特性
		downAdjust(arr, 0, i - 1);
	}
}
void downAdjust(int arr[], int parent, int n) 
{
	//临时保存要下沉的元素
	int temp = arr[parent];
	//定位左孩子节点的位置
	int child = 2 * parent + 1;
	//开始下沉
	while (child <= n) 
	{
		// 如果右孩子节点比左孩子大，则定位到右孩子
		if (child + 1 <= n && arr[child] < arr[child + 1])
			child++;
		// 如果孩子节点小于或等于父节点，则下沉结束
		if (arr[child] <= temp)
			break;
		// 父节点进行下沉
		arr[parent] = arr[child];
		parent = child;
		child = 2 * parent + 1;
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
    int arr7[] = { 13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230 };
    int arr8[] = { 13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230 };
    int arr9[] = { 13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230 };
    int arr10[] = { 13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230 };
    int arr11[] = { 13,5,4,3,2,1,1200,901,205,301,12,0,9,8,7,6,5,1000,304,902,900,1230 };
    int k = 3;
    int maxknd = FindkndMaxValue(arr1, sizeof(arr1) / sizeof(int), k);
    cout << "\n===========================Sort===========================" << endl;
    printf("%d nd max value is:%d \n", k ,maxknd);

    InsertSort(arr1,sizeof(arr1) / sizeof(int));
    QuickSort(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
    ShellSort( arr3, sizeof(arr3) / sizeof(int));
    HeapSort(arr4, sizeof(arr4) / sizeof(int));
    specialsort(arr5, sizeof(arr5) / sizeof(int),arr6);
    SelectSort(arr7, sizeof(arr7) / sizeof(int));
    mergeSort(arr8, 0, sizeof(arr8) / sizeof(int) - 1);
    mergeSort2(arr9, sizeof(arr9) / sizeof(int));
    //headSort(arr10, sizeof(arr10) / sizeof(int));
    shellsort2(arr11,sizeof(arr3) / sizeof(int));
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
    printf("\narr7:");
	for (int i = 0; i < sizeof(arr7) / sizeof(int); i++)
	{
		printf("%d ", arr7[i]);
	}
	printf("\narr8:");
	for (int i = 0; i < sizeof(arr8) / sizeof(int); i++)
	{
		printf("%d ", arr8[i]);
	}
	printf("\narr9:");
	for (int i = 0; i < sizeof(arr9) / sizeof(int); i++)
	{
		printf("%d ", arr9[i]);
	}
	printf("\narr11:");
	for (int i = 0; i < sizeof(arr11) / sizeof(int); i++)
	{
		printf("%d ", arr11[i]);
	}
    printf("end.\n");
}

