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

void Other8Action()
{
	cout << "\n===========================Other8Action===========================" << endl;
	char * p = "abcabcbb";
	int i = lengthOfLongestSubstring(p);
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
}
