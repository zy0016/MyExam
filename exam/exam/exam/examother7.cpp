#include "stdafx.h"
#include "other7.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>
#include <fstream>
#include <functional>
#include <ctime>
#include <typeinfo>
#include <cstdlib>
#include <set>
#include <deque>
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <bitset>
#include <sstream>
#include <bitset>
#include <functional>
using namespace std;

// 此函数将得到r的引用,并将r的值加1.
void f(int &r) { r++; }

// 模板函数
template<class F, class P> void g(F f, P t) { f(t); }

void Other7Action1()
{
	cout << "\n===========================Other7Action1===========================" << endl;
	int i = 0;
	g(f, i);  // 实例化 'g<void (int &r), int>' 
			  // 'i' 不会被修改
	std::cout << i << std::endl;  // 输出 0

	g(f, std::ref(i));  // 实例化 'g<void(int &r),reference_wrapper<int>>'
						// 'i' 会被修改
	std::cout << i << std::endl;  // 输出 1
}

void Other7Action2()
{
	int n = 10;
	vector<int>v;//创建一个空的容器
	for (int i = 0; i < n; ++i)
	{
		v.push_back(i);
	}
	cout << "size:" << v.size() << endl;
	int m = 20;
	v.resize(m);
	cout << "resize:" << v.size() << endl;
	v.reserve(30);
	cout << "reserve:" << v.size() << endl;
	for (int i = 0; i < m; ++i)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}


#define OUTPUT(f)	cout << #f << "\t: " << typeid(f).name() << endl;
class BaseA {};
class DeriveA: public BaseA {};
 
class BaseB 
{
	virtual void f(){} 
};
class DeriveB: public BaseB {};
void Other7Action8()
{
    cout << "-------直接处理类名-------" <<endl;
 
	OUTPUT(BaseA);
	OUTPUT(DeriveA);
	OUTPUT(BaseB);
	OUTPUT(DeriveB);
 
	cout << endl << "-------基类不含虚函数-------" <<endl;
 
	BaseA baseA;
	DeriveA deriveA;
	OUTPUT(baseA);
	OUTPUT(deriveA);
	
	BaseA* pa;
	pa = &baseA;
	OUTPUT(*pa);
	OUTPUT(pa);
	pa = &deriveA;
	OUTPUT(*pa);
	OUTPUT(pa);
 
	cout << endl << "-------基类含有虚函数-------" <<endl;
 
	BaseB baseB;
	DeriveB deriveB;
	OUTPUT(baseB);
	OUTPUT(deriveB);
 
	BaseB* pb;
	pb = &baseB;
	OUTPUT(*pb);
	OUTPUT(pb);
	pb = &deriveB;
	OUTPUT(*pb);
	OUTPUT(pb);
}
char* longestPalindrome_2(const char* s,int ilen)
{
	char* result2 = (char*)malloc(ilen + 1);
	char* left = (char*)malloc(ilen + 1);
	char* right = (char*)malloc(ilen + 1);
	memset(result2, 0x00, ilen + 1);
	for (int i = 0; i < ilen; i++)
	{
		bool b = false;
		int j, k,m;
		memset(left, 0x00, ilen + 1);
		memset(right, 0x00, ilen + 1);
		for (j = i, k = i + 1; j >= 0 && k < ilen; j--, k++)
		{
			if (s[j] == s[k])
			{
				for (m = ilen - 1; m > 0; m--)
				{
					if (left[m - 1] != 0)
						left[m] = left[m - 1];
				}
				left[0] = s[j];
				strncat(right, &s[k], 1);
				b = true;
				continue;
			}
			else
			{
				break;
			}
		}
		if (b && (strlen(left) + strlen(right) > strlen(result2)))
		{
			strcpy(result2, left);
			strcat(result2, right);
		}
	}
	free(left);
	free(right);
	return result2;
}
char* longestPalindrome_1(const char* s,int ilen)
{
	char* result1 = (char*)malloc(ilen + 1);
	memset(result1, 0x00, ilen + 1);
	char* left = (char*)malloc(ilen + 1);
	char* right = (char*)malloc(ilen + 1);
	char middle = 0;
	for (int i = 0; i < ilen; i++)
	{
		if (i == 0 || i == ilen - 1)
		{
			continue;
		}
		bool b = false;
		int j, k, m;
		memset(left, 0x00, ilen + 1);
		memset(right, 0x00, ilen + 1);
		
		for (j = i - 1, k = i + 1; j >= 0 && k < ilen; j--, k++)
		{
			middle = s[i];
			if (s[j] == s[k])
			{
				for (m = ilen - 1; m > 0; m--)
				{
					if (left[m - 1] != 0)
						left[m] = left[m - 1];
				}
				left[0] = s[j];
				strncat(right, &s[k], 1);
				b = true;
				continue;
			}
			else
			{
				break;
			}
		}
		if (b && (strlen(left) + 1 + strlen(right) > strlen(result1)))
		{
			strcpy(result1, left);
			strncat(result1, &middle,1);
			strcat(result1, right);
		}
	}
	free(left);
	free(right);
	return result1;
}
char* longestPalindrome(char* s)
{
	char* result1 = NULL, * result2 = NULL;
	int len = 0, i = 0,i1 = 0,i2 = 0;
	bool allsame = true;
	while (s[len] != '\0')
	{
		len++;
		if (s[len] != '\0' && s[0] != s[len] && allsame)
		{
			allsame = false;
		}
	}
	if (len == 1 || len == 0 || allsame)
		return s;

	if (len % 2 == 0)
	{
		result2 = longestPalindrome_2(s,len);
		i2 = strlen(result2);
		if (i2 == len)
			return result2;
		result1 = longestPalindrome_1(s, len);
		i1 = strlen(result1);
	}
	else
	{
		result1 = longestPalindrome_1(s, len);
		i1 = strlen(result1);
		if (i1 == len)
			return result1;
		result2 = longestPalindrome_2(s, len);
		i2 = strlen(result2);
	}
	if (i1 == 0 && i2 == 0)
	{
		char* buf = (char*)malloc(sizeof(char) * 2);
		buf[0] = s[0];
		buf[1] = '\0';
		return buf;
	}
	if (i1 >= i2)
		return result1;
	else
		return result2;
}
int merge(int* input_a, int length_a, int* input_b, int length_b, int* result)
{
	int i = 0, j = 0, k = 0;
	if ((length_a == 0 || input_a == NULL) && length_b > 0)
	{
		for (i = 0; i < length_b; i++)
		{
			result[i] = input_b[i];
		}
		return length_b;
	}
	else if ((length_b == 0 || input_b == NULL) && length_a > 0)
	{
		for (j = 0; j < length_a; j++)
		{
			result[j] = input_a[j];
		}
		return length_a;
	}
	else if ((length_a == 0 || input_a == NULL) && (length_b == 0 || input_b == NULL))
	{
		return 0;
	}
	for (; ; )
	{
		if (input_a[i] <= input_b[j]) // 输入数组a的当前元素更小
		{
			result[k++] = input_a[i++];
			if (i >= length_a)    //输入数组a结束
			{
				//把输入数组b的剩余数值全部放入result
				while (j < length_b)
				{
					result[k++] = input_b[j++];
				}
				break; //结束循环
			}
		}
		else // 输入数组b的当前元素更小
		{
			result[k++] = input_b[j++];
			if (j >= length_b)    //输入数组b结束
			{
				//把输入数组a的剩余数值全部放入result
				while (i < length_a)
				{
					result[k++] = input_a[i++];
				}
				break; //结束循环
			}
		}
	}
	return  k;
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int* newarr = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
	int k = merge(nums1, nums1Size, nums2, nums2Size, newarr);
	double result = 0.0;
	if (k == 0)
	{
		free(newarr);
		return result;
	}
	if (k % 2 == 0)
	{
		result = (double)(newarr[k / 2 - 1] + newarr[k / 2]) / 2;
	}
	else
	{
		result = (double)(newarr[k / 2]);
	}
	free(newarr);
	return result;
}

void Other7Action()
{
	cout << "\n===========================Other7Action===========================" << endl;
	Other7Action1();
	Other7Action2();
    Other7Action8();
	char s1[] = "babad";
	char* sp1 = longestPalindrome(s1);
	char s2[] = "cbbd";
	char* sp2 = longestPalindrome(s2);
	char s3[] = "ac";
	char* sp3 = longestPalindrome(s3);
	char s4[] = "abb";
	char* sp4 = longestPalindrome(s4);
	char s5[] = "aaaa";
	char* sp5 = longestPalindrome(s5);
	////////////////////////////
	int nums01[] = {0 }, nums02[] = { 2 };
	double k01 = findMedianSortedArrays(NULL, 0, nums02, 0);
	int nums1[] = {1, 3}, nums2[] = {2};
	double k1 = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int));
	int nums3[] = { 1, 2 }, nums4[] = { 3 ,4};
	double k2 = findMedianSortedArrays(nums3, sizeof(nums3) / sizeof(int), nums4, sizeof(nums4) / sizeof(int));
}
