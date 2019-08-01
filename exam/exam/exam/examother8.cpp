#include "stdafx.h"
#include "other8.h"
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

int ch_contain(char * str,char c)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (c == str[i])
		{
			return 1;
		}
	}
	return 0;
}

int lengthOfLongestSubstring(char * s) 
{
	char w[100] = { 0 }, res[100] = {0};
	int index = 0,j = 0,i = 0;
	for (i = 0; i < strlen(s) && j < strlen(s); i++)
	{
		if (ch_contain(w, s[i]))
		{
			j++;
			if (strlen(w) > strlen(res))
			{
				strcpy(res, w);
			}
			memset(w, 0x00, sizeof(w));
			index = 0;
			i = j;
			w[index++] = s[i];
		}
		else
		{
			w[index++] = s[i];
		}
	}
	if (strlen(w) > strlen(res))
		return strlen(w);
	else
		return strlen(res);
}

long reverse(int x) {
	long bak = x;
	long res = 0;
	char num[50] = {0};
	if (x == 0)
		return 0;
	int id = 0,i,j,index = 1;
	if (x < 0)
	{
		index = -1;
	}
	while (1)
	{
		i = index * (x % 10);
		j = index * (x / 10);
		num[id++] = '0' + i;
		x = x / 10;
		if (j == 0)
		{
			break;
		}
	}
	char * pmax = "2147483647";
	if (strlen(num) == 10)
	{
		if (strcmp(num, pmax) > 0)
			return 0;
	}
	res = atol(num);
	if (bak < 0)
		res = -res;

	return res;
}

int myAtoi(char * str)
{
	if (strlen(str) == 0)
		return 0;
	char *p = (char*)malloc(strlen(str) + 1);
	memset(p, 0x00, strlen(str) + 1);
	strcpy(p, str);
	char * s = Trim(p);
	if (p[0] == '-' || p[0] == '+' || p[0] >= '0' && p[0] <= '9')
	{
		char *pbegin = p;
		int i = 0, id = 0;
		int n = 0;
		if (p[0] == '-')
		{
			n = 1;
			i++;
			pbegin++;
		}
		else if (p[0] == '+')
		{
			i++;
			pbegin++;
		}
		long count = 0;
		char * pmax = "2147483647";

		for (; i < strlen(p); i++)
		{
			if (p[i] >= '0' && p[i] <= '9')
			{
				id++;
				if (INT_MAX / 10 < count)
				{
					free(p);
					if (n == 1)
					{
						return INT_MIN;
					}
					else
					{
						return INT_MAX;
					}
				}
				count = count * 10 + p[i] - '0';
				if (id == 10)
				{
					if (strcmp(pbegin, pmax) > 0)
					{
						free(p);
						if (n == 1)
						{
							return INT_MIN;
						}
						else
						{
							return INT_MAX;
						}
					}
				}
			}
			else
			{
				break;
			}
		}
		if (n == 1)
		{
			count = -count;
		}
		free(p);
		return count;
	}
	else
	{
		free(p);
		return 0;
	}
}

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	if (x == 0)
		return true;
	char num[50] = { 0 };
	int i, j,id = 0;
	while (1)
	{
		i = (x % 10);
		j = (x / 10);
		num[id++] = '0' + i;
		x = x / 10;
		if (j == 0)
		{
			break;
		}
	}
	int len = strlen(num);
	for (i = 0, j = len - 1; i < len && j >= 0 && i < j; i++, j--)
	{
		char c = num[i];
		num[i] = num[j];
		num[j] = c;
	}
	for (i = 0,j = len - 1; i < len && j >= 0; i++,j--)
	{
		if (i == j || i > j)
		{
			break;
		}
		if (num[i] == num[j])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

#define MIN(x,y) (((x)<(y))?(x):(y))

int maxArea(int* height, int heightSize) {
	int i, j;
	long maxarea = 0;
	for (i = 0; i < heightSize - 1; i++)
	{
		for (j = i + 1; j < heightSize; j++)
		{
			int area = (MIN(height[i], height[j])) * (j - i);
			if (area > maxarea)
			{
				maxarea = area;
			}
		}
	}
	return maxarea;
}
void Other8Action()
{
	cout << "\n===========================Other8Action===========================" << endl;
	char * p = "abcabcbb";
	long i = lengthOfLongestSubstring(p);
	cout << i << " for " << p <<endl;
	char * p1 = "bbbbb";
	i = lengthOfLongestSubstring(p1);
	cout << i << " for " << p1 << endl;

	char * p2 = "pwwkew";
	i = lengthOfLongestSubstring(p2);
	cout << i << " for " << p2 << endl;

	char * p3 = " ";
	i = lengthOfLongestSubstring(p3);
	cout << i << " for " << p3 << endl;

	char *p4 = "dvdf";
	i = lengthOfLongestSubstring(p4);
	cout << i << " for " << p4 << endl;

	char *p5 = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	i = lengthOfLongestSubstring(p5);
	cout << i << " for " << p5 << endl;
	/////////////////////
	/*char *p6 = "babad";
	char *p = longestPalindrome(p6);
	cout << p << endl;*/
	i = reverse(123);
	cout << i << endl;

	i = reverse(-123);
	cout << i << endl;

	i = reverse(120);
	cout << i << endl;

	i = reverse(INT_MIN);
	cout << i << endl;

	i = reverse(1534236469);
	cout << i << endl;

	i = reverse(-2147483648);
	cout << i << endl;

	i = myAtoi("123");
	cout << i << endl;

	i = myAtoi("-123");
	cout << i << endl;

	char arr[] = "     42";
	i = myAtoi("    -42");
	cout << i << endl;

	i = myAtoi("4193 fhdsk fjsdf");
	cout << i << endl;

	i = myAtoi("fsde 123");
	cout << i << endl;

	i = myAtoi("-91283472332");
	cout << i << endl;

	i = myAtoi("-91283472332");
	cout << i << endl;

	bool b = isPalindrome(121);
	cout << b << endl;

	b = isPalindrome(-121);
	cout << b << endl;

	b = isPalindrome(12);
	cout << b << endl;

	int a[] = { 1,8,6,2,5,4,8,3,7 };
	i = maxArea(a, sizeof(a) / sizeof(int));
	cout << i << endl;
}
