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
		}
		w[index++] = s[i];
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
					return (n == 1) ? INT_MIN : INT_MAX;
				}
				count = count * 10 + p[i] - '0';
				if (id == 10)
				{
					if (strcmp(pbegin, pmax) > 0)
					{
						free(p);
						return (n == 1) ? INT_MIN : INT_MAX;
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

char * intToRoman(int num) {
	if (num <= 0) 
		return "";
	char ret[100] = {0};
	int number[] = { 1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1 };
	char *flags[] = { "M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	for (int i = 0; i < 13 && num > 0; i++)
	{
		if (num < number[i])
			continue;
		while (num >= number[i])
		{
			num -= number[i];
			strcat(ret, flags[i]);
		}
	}
	char *pres = (char*)malloc(strlen(ret) + 1);
	strcpy(pres, ret);
	return pres;
}
int romanToInt(char * s) 
{
	int count = 0,len = strlen(s);
	for (int i = len - 1; i >= 0 ; i--)
	{
		switch (s[i])
		{
		case 'M'://1000
			count = count + 1000;
			if (i > 0 && s[i - 1] == 'C')
			{
				count = count - 100;
				i--;
			}
			break;
		case 'D'://500
			count = count + 500;
			if (i > 0 && s[i - 1] == 'C')
			{
				count = count - 100;
				i--;
			}
			break;
		case 'C'://100
			count = count + 100;
			if (i > 0 && s[i - 1] == 'X')
			{
				count = count - 10;
				i--;
			}
			break;
		case 'L'://50
			count = count + 50;
			if (i > 0 && s[i - 1] == 'X')
			{
				count = count - 10;
				i--;
			}
			break;
		case 'X'://10
			count = count + 10;
			if (i > 0 && s[i - 1] == 'I')
			{
				count--;
				i--;
			}
			break;
		case 'V'://5
			count = count + 5;
			if (i > 0 && s[i - 1] == 'I')
			{
				count--;
				i--;
			}
			break;
		case 'I'://1
			count = count + 1;
			break;
		}
	}
	return count;
}

char * longestCommonPrefix(char ** strs, int strsSize) 
{
    char **bak = strs;
	bool finddiff = false;
	int index = 0,id;
	char c;
	if (strs == NULL || strsSize == 0 || *strs == NULL)
		return "";
	if (strsSize == 1)
	{
		index = strlen(*strs);
        if (index == 0)
            return "";

        char *res = (char*)malloc(sizeof(char) * (index + 1));
	    memset(res, 0, sizeof(char) * (index + 1));
	    strncpy(res, *strs, index);
	    return res;
	}
	else
	{
		while (1)
		{
			char *str = *bak;
			if (str == NULL || strlen(str) == 0)
			{
				break;
			}
			c = '\0';
			id = 0;
			finddiff = false;
            bool bstudy = false;
			while (id < strsSize && index < strlen(str))
			{
                bstudy = true;
				if (c == '\0')
				{
					c = *(str + index);
					id++;
					str = strs[id];
					continue;
				}
				else
				{
					if (c == *(str + index))
					{
						id++;
						if (id == strsSize)
                        {
                            break;
                        }
                        str = strs[id];
						continue;
					}
					else
					{
						finddiff = true;
						break;
					}
				}
			}
			if (finddiff || !bstudy || index == strlen(str))
			{
				break;
			}
			index++;
		}
	}
	
	if (index == 0)
		return "";
	char *res = (char*)malloc(sizeof(char) * (index + 1));
	memset(res, 0, sizeof(char) * (index + 1));
	strncpy(res, *strs, index);
	return res;
}

static void InsertSort(int array[] , unsigned int nNum)
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
vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> res;
	vector<int> l2;
	sort(nums.begin(), nums.end());
	int numsSize = nums.size();
	for (int i = 0; i < numsSize - 2; i++)
	{
		if (i > 0 && (nums.at(i) == nums.at(i - 1))) {
			continue;
		}
		for (int j = i + 1; j < numsSize - 1; j++)
		{
			for (int k = j + 1; k < numsSize; k++)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					int a[] = { nums[i],nums[j],nums[k] };
					bool bfind = false;

					for (int m = 0; m < res.size(); m++)
					{
						vector<int> l22 = res[m];
						if (l22[0] == a[0] && l22[1] == a[1] && l22[2] == a[2])
						{
							bfind = true;
							break;
						}
					}
					if (!bfind)
					{
						vector<int> vec;
                        vec.push_back(nums.at(i));
                        vec.push_back(nums.at(j));
                        vec.push_back(nums.at(k));
						res.push_back(vec);
					}
					l2.clear();
				}
			}
		}
	}
	return res;
}
int abs(int x)
{
    return ((x >= 0)?(x):(-x));
}
int threeSumClosest(int* nums, int numsSize, int target)
{
    InsertSort(nums,numsSize);
    int step1 = -1;
    int step2 = -1;
    int step3 = -1;
    int minstep = INT_MAX;
    int m = 0;
    for (int i = 0;i < numsSize - 2;i++)
    {
        for (int j = numsSize - 1;j > i;j--)
        {
            m = i + 1;
            while(m < j)
            {
                int count = nums[i] + nums[j] + nums[m];
                if (abs(count - target) < minstep)
                {
                    minstep = abs(count - target);
                    step1 = nums[i];
                    step2 = nums[j];
                    step3 = nums[m];
                }
                m++;
            }
        }
    }
    return (step1 + step2 + step3);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
char ** letterCombinations(char * digits, int* returnSize){
    char dig[] = {'2','3','4','5','6','7','8','9'};
    char *ch[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char **result = NULL;
    if (digits == NULL)
        return NULL;
    int len = strlen(digits);
    if (len == 0)
        return NULL;
    for (int i = 0;i < len;i++)
    {
        char singleall[10] = {0};
        char c = digits[i];
        int index = c - '2';
        char *p = ch[index];
        for (int j = 0;j < strlen(p);j++)
        {
        }
    }
    return result;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    vector<vector<int>> res;
	vector<int> l2;
	sort(nums.begin(), nums.end());
	int numsSize = nums.size();
    int m = 0,n = 0;
	
    for (int i = 0;i < numsSize - 2;i++)
    {
        for (int j = numsSize - 1;j > 1;j--)
        {
            m = i + 1;
            while(m < j)
            {
				n = j - 1;
                while(n > i)
                {
                    if (m == n)
                    {
                        n--;
                        continue;
                    }
                    int count = nums[i] + nums[j] + nums[m] + nums[n];
                    if (count == target)
                    {
						bool bfind = false;
						for (int l = 0; l < res.size(); l++)
						{
							vector<int> v = res.at(l);
							int a[4] = { nums[i] ,nums[j],nums[m],nums[n] };
							InsertSort(a, 4);
							//if (v[0] == nums[i] && v[1] == nums[j] && v[2] == nums[m] && v[3] == nums[n] )
							if (v[0] == a[0] && v[1] == a[1] && v[2] == a[2] && v[3] == a[3])
							{
								bfind = true;
								break;
							}
						}
						if (!bfind)
						{
							vector<int> vec;
							vec.push_back(nums.at(i));
							vec.push_back(nums.at(j));
							vec.push_back(nums.at(m));
							vec.push_back(nums.at(n));
							sort(vec.begin(), vec.end());
							res.push_back(vec);
						}
                    }
                    n--;
                }
				m++;
            }
        }
    }
    return res;
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

	//////////////
	i = romanToInt("III");
	cout << i << endl;

	i = romanToInt("IV");
	cout << i << endl;

	i = romanToInt("IX");
	cout << i << endl;

	i = romanToInt("LVIII");
	cout << i << endl;

	i = romanToInt("MCMXCIV");
	cout << i << endl;
	/////////////////
	char *pp[] = { "flower","flow","flight" };
	char *pp2 = longestCommonPrefix(pp, 3);
	cout << pp2 << endl;

	char *pparr[] = { "dog","racecar","car" };
	char *ppr = longestCommonPrefix(pparr, 3);
	cout << ppr << endl;

	char *pparr2[] = { "a" };
	char *ppr2 = longestCommonPrefix(pparr2, 1);
	cout << ppr2 << endl;

	char *pparr3[] = { NULL };
	char *ppr3 = longestCommonPrefix(pparr3, 1);
	cout << ppr3 << endl;

	char *pparr4 = NULL;
	char *ppr4 = longestCommonPrefix(&pparr4, 1);
	cout << ppr4 << endl;

	char *pparr5[] = { NULL,NULL };
	char *ppr5 = longestCommonPrefix(NULL, 1);
	cout << ppr5 << endl;

	char *pparr6[] = { 0};
	char *ppr6 = longestCommonPrefix(pparr6, 1);
	cout << ppr6 << endl;
    //////////////////////////
    
    vector<int> num;
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(-1);
    num.push_back(-4);
    vector<vector<int>> res = threeSum(num);

    int a2[] = {3,-9,3,9,-6,-1,-2,8,6,-7,-14,-15,-7,5,2,-7,-4,2,-12,-7,-1,-2,1,-15,-13,-4,0,-9,-11,7,4,7,13,14,-7,-8,-1,-2,7,-10,-2,1,-10,6,-9,-1,14,2,-13,9,10,-7,-8,-4,-14,-5,-1,1,1,4,-15,13,-12,13,12,-11,12,-12,2,-3,-7,-14,13,-9,7,-11,5,-1,-2,-1,-7,-7,0,-7,-4,1,3,3,9,11,14,10,1,-13,8,-9,13,-2,-6,1,10,-5,-6,0,1,8,4,13,14,9,-2,-15,-13};
    vector<int> num2;
    for (int i = 0;i < sizeof(a2)/sizeof(int);i++)
    {
        num2.push_back(a2[i]);
    }
    vector<vector<int>> res2 = threeSum(num2);
    /////////////////////
    int arr3[] = {-1, 2, 1, -4};
    int a3 = threeSumClosest(arr3,sizeof(arr3)/sizeof(int),1);
    cout<<a3<<endl;
    /////////////////////
    vector<int> a4;
    a4.push_back(1);
    a4.push_back(0);
    a4.push_back(-1);
    a4.push_back(0);
    a4.push_back(-2);
    a4.push_back(2);
    vector<vector<int>> res4 = fourSum(a4,0);
}
