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

void myitoa(int n,char *str)
{
    char buf[20] = "";
    int flag = 1;
    if (n == 0)
    {
        strcpy(str,"0");
        return;
    }
    if (n < 0)
    {
        flag = -1;
    }
    int temp = n;
    int id = 0;
    while(temp != 0)
    {
        buf[id++] = (temp % 10) * flag + '0';
        temp = temp / 10;
    }
    int ilen = strlen(buf);
    int i = 0;
    int j = 0;

    if (n < 0)
    {
        str[0] = '-';
        j = 1;
    }
    for (i = ilen - 1;i >= 0;i--,j++)
    {
        str[j] = buf[i];
    }
    str[j] = '\0';
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
//void handleRoman(int *i, int *count, char lastch,char ch,int num1,int num2)
//{
//	*count = *count + num1;
//	if (*i > 0 && lastch == ch)
//	{
//		count = count - num2;
//		(*i)--;
//	}
//}
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

static void InsertSort(int nums[] , unsigned int nNum)
{
    int temp,j;
    unsigned int i;
    for (i = 1; i < nNum; ++i)
    {
        if (nums[i] < nums[i - 1])
        {
            temp = nums[i];
            nums[i] = nums[i - 1];
            for (j = i - 1;j >= 0 && temp < nums[j]; --j)
            {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
        }
    }
}
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int numsSize = nums.size();
    int m;
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = numsSize - 1; j > 0; j--)
        {
            /*if (i + j == numsSize)
            {
                break;
            }*/
            m = i + 1;
            while(m < j)
            {
                if (nums[i] + nums[j] + nums[m] == 0)
                {
                    bool bfind = false;
                    for (int m = 0; m < res.size(); m++)
                    {
                        vector<int> v = res.at(m);
                        int a[] = { nums[i],nums[j],nums[m] };
                        InsertSort(a, 3);
                        if (v[0] == a[0] && v[1] == a[1] && v[2] == a[2])
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
                        sort(vec.begin(),vec.end());
                        res.push_back(vec);
                    }
                }
                m++;
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
                    if ((n < m)&&(m + n == numsSize))
                    {
                        break;
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

bool isValid(char * s)
{
    charnode *p = NULL;
    bool res = true;
    if (s == NULL || strlen(s) == 0)
        return true;

    for (int i = 0;i < strlen(s);i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            p = pushNode(s[i],p);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            char ctop = '\0';
            int itop = getTopNode(p,&ctop);
            if (itop == 0)
            {
                res = false;
                break;
            }
            if (ctop == '(' && s[i] == ')' || ctop == '[' && s[i] == ']' || ctop == '{' && s[i] == '}')
            {
                p = popupNode(p,&ctop);
            }
            else
            {
                res = false;
                break;
            }
        }
    }
    if (getNodeCount(p) > 0)
        res = false;
    releaseNode(p);
    return res;
}

char *getParenthesis1(int n)
{
    charnode *p1 = NULL;
    for (int i = 0;i < n;i++)
    {
        p1 = pushNode('(',p1);
    }
    for (int i = 0;i < n;i++)
    {
        p1 = pushNode(')',p1);
    }
    int len = getNodeCount(p1);
    char *s1 = (char*)malloc(sizeof(char) * (len + 1));
    memset(s1,0,sizeof(char) * (len + 1));
    getNodeCharAll(p1,s1,len);
    releaseNode(p1);
    return s1;
}
char *getParenthesis2(int n)
{
    charnode *p1 = NULL;
    for (int i = 0;i < n;i++)
    {
        p1 = pushNode('(',p1);
        p1 = pushNode(')',p1);
    }
    int len = getNodeCount(p1);
    char *s1 = (char*)malloc(sizeof(char) * (len + 1));
    memset(s1,0,sizeof(char) * (len + 1));
    getNodeCharAll(p1,s1,len);
    releaseNode(p1);
    return s1;
}

int removeDuplicates(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0)
        return 0;
    bool bfind = false;
    int all = 0,numsSizebak = numsSize;
    int i = 0,j = 1;
    while(i < numsSize)
    {
        j = i + 1;
        bfind = false;
        while(j < numsSize)
        {
            if (nums[i] == nums[j])
            {
                all++;
                for (int m = j;m < numsSize;m++)
                {
                    nums[m - 1] = nums[m];
                }
                bfind = true;
                numsSize--;
                break;
            }
            j++;
        }
        if (bfind)
        {
            continue;
        }
        i++;
    }
    return numsSizebak - all;
}
int removeElement(int* nums, int numsSize, int val)
{
    if (nums == NULL || numsSize == 0)
        return 0;
    bool bfind = false;
    int all = 0,numsSizebak = numsSize;
    int i = 0;
    while(i < numsSize)
    {
        bfind = false;
        if (nums[i] == val)
        {
            all++;
            for (int m = i;m < numsSize - 1;m++)
            {
                nums[m] = nums[m + 1];
            }
            bfind = true;
            numsSize--;
        }
        if (bfind)
            continue;
        i++;
    }
    return numsSizebak - all;
}
int divide(int dividend, int divisor)
{
    bool positive = true;
    int div = 0;
    if (dividend == 0)
        return 0;
    if (dividend == divisor || divisor == 1)
        return 1;
    if (divisor == -1)
    {
        return (dividend == INT_MIN) ? INT_MAX : -dividend;
    }
    if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
    {
        positive = false;
    }
    if (positive)
    {
        if (dividend > 0 && divisor > 0)
        {
            while(dividend >= 0 /*&& dividend > divisor*/)
            {
                div++;
                dividend -= divisor;
            }
            div--;
        }
        else
        {
            while(dividend <= 0 && dividend < divisor)
            {
                div++;
                dividend -= divisor;
            }
            //div--;
        }
        return div;
    }
    else
    {
        if (dividend > 0 && divisor < 0)
        {
            while(dividend >= 0)
            {
                div++;
                dividend += divisor;
            }
            div--;
        }
        else
        {
            while(dividend <= 0)
            {
                div++;
                dividend += divisor;
            }
            div--;
        }
        return -div;
    }
}
bool decreaseOrder(int *nums,int n)
{
    for(int i = 0;i < n - 1;i++)
    {
        if (nums[i] < nums[i + 1])
            return false;
    }
    return true;
}
void generateNextOrder(int *nums,int numsSize)
{
    int temp,j;
    unsigned int i;
    bool bfind = false;
    for (int i = numsSize - 1;i > 0;i--)//last
    {
        for (int j = i - 1;j >= 0;j--)//previous
        {
            if (nums[i] > nums[j])
            {
                int k = nums[i];
                nums[i] = nums[j];
                nums[j] = k;
                return;
            }
        }
    }
}
void nextPermutation(int* nums, int numsSize)
{
    if (nums == NULL || numsSize == 0 || numsSize == 1)
        return;
    if (numsSize == 2)
    {
        int i = nums[0];
        nums[0] = nums[1];
        nums[1] = i;
        return;
    }
    if (decreaseOrder(nums,numsSize))
    {
        InsertSort(nums,numsSize);
        return;
    }
    generateNextOrder(nums,numsSize);
    InsertSort(nums + 1, numsSize - 1);
}
int * getRange(int start, int end)
{
    int *p = (int*)malloc(sizeof(int) * 2);
    p[0] = start;
    p[1] = end;
    return p;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int start = -1, end = -1, i, j;
    if (nums == NULL || numsSize == 0)
    {
        *returnSize = 2;
        return getRange(start,end);
    }
    if (numsSize == 1)
    {
        if (nums[0] == target)
        {
            start = 0;
            end = 0;
        }
        *returnSize = 2;
        return getRange(start, end);
    }
    if (numsSize == 2)
    {
        if (nums[0] == target && nums[1] != target)
        {
            start = 0;
            end = 0;
        }
        else if (nums[0] != target && nums[1] == target)
        {
            start = 1;
            end = 1;
        }
        else if (nums[0] == target && nums[1] == target)
        {
            start = 0;
            end = 1;
        }
        *returnSize = 2;
        return getRange(start, end);
    }
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == target && nums[i + 1] == target)
        {
            if (start == -1)
            {
                start = i;
            }
            for (j = i + 1; j < numsSize; j++)
            {
                if (nums[j] != target)
                    break;
            }
            end = j - 1;
        }
    }
    if (start == -1 && end == -1)
    {
        for (i = 0; i < numsSize; i++)
        {
            if (nums[i] == target)
            {
                start = i;
                end = i;
                break;
            }
        }
    }
    *returnSize = 2;
    return getRange(start, end);
}
int searchInsert(int* nums, int numsSize, int target) 
{
    if (nums == NULL || numsSize == 0 || target < nums[0] || numsSize == 1 && nums[0] == target)
        return 0;
    if (target == nums[numsSize - 1])
        return numsSize - 1;
    if (target > nums[numsSize - 1])
        return numsSize;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == target)
            return i;
        if (nums[i] < target && target < nums[i + 1])
            return i + 1;
    }
    return 0;
}
#ifdef CPLUSPLUS_11
string countAndSay(int n) {
    string inputString = "1";
    int nCount = 1;
    string output = inputString;
    char currString = '0';
    while (nCount < n) 
    {
        output = "";
        int count = 0;
        currString = inputString[0];
        for (const auto &chr : inputString) 
        {
            if (chr == currString) 
            {
                count++;
            }
            else 
            {
                output += (std::to_string(count) + currString);
                currString = chr;
                count = 1;
            }
        }
        output += (std::to_string(count) + currString);
        inputString = output;
        nCount++;
    }

    std::cout << output << std::endl;
    return output;
}
#endif

vector<int> m_curr;
vector<vector<int>> m_ans;
void search(const vector<int>& candidates, int idx, int target)
{
	if (target == 0) return m_ans.push_back(m_curr);
	else if (idx == candidates.size()) return;
	else if (candidates[idx] > target) return;

	int count = target / candidates[idx];
	int num = candidates[idx];

	for (int i = count; i >= 0; --i)
	{
		m_curr.insert(m_curr.end(), i, num);
		search(candidates, idx + 1, target - num * i);
		m_curr.resize(m_curr.size() - i);
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
	m_curr.reserve(candidates.size());
	sort(candidates.begin(), candidates.end());
	search(candidates, 0, target);
	return move(m_ans);
}

void dfs(vector<vector<int>>& sum, const vector<int>& candidates, int idx, int val, int target, vector<int>& res) 
{
    if (val == target) 
    {
        sum.push_back(res);
        return;
    }
    if (idx == candidates.size() || val > target) {
        return;
    }
        
    for (int i = idx; i < candidates.size(); i++) 
    {
        if (val + candidates[i] > target || i > idx && candidates[i] == candidates[i - 1]) continue;
        res.push_back(candidates[i]);
        dfs(sum, candidates, i + 1, val + candidates[i], target, res);
        res.pop_back();
            
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> sum;
    if (candidates.size() == 0) return sum;
    vector<int> res;
    dfs(sum, candidates, 0, 0, target, res);
    return sum; 
}

int firstMissingPositive(int* nums, int numsSize) 
{
    if (nums == NULL || numsSize == 0)
        return 1;
    if (numsSize == 1)
    {
        if (nums[0] <= 0 || nums[0] == INT_MAX || nums[0] > 1)
            return 1;
        else
            return ++nums[0];
    }
    int id = 1;
    InsertSort(nums, numsSize);
    if (nums[0] > 1 || nums[numsSize - 1] < 0)
        return 1;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0 || nums[i] == id)
            continue;
        if (nums[i] == 0)
        {
            id = 1;
            continue;
        }
        if (i == 0)
        {
            id = nums[i];
            continue;
        }
        if (nums[i] > id)
        {
            if (nums[i] > nums[i - 1])
            {
                if (nums[i] - nums[i - 1] >= 2)
                {
                    if (nums[i - 1] <= 0)
                    {
                        id = 1;
                    }
                    else
                    {
                        id = nums[i - 1] + 1;
                    }
                    return id;
                }
            }
            id = nums[i];
        }
    }
    return id + 1;
}
char *multi10(char *num ,int mul)
{
    if (mul == 0)
        return num;
    int ilen1 = strlen(num) + mul;
    char *pres = (char*)malloc(sizeof(char)*(ilen1+2));
    memset(pres,0,sizeof(char)*(ilen1+2));
    strcpy(pres,num);
    for (int i = 0;i < mul;i++)
    {
        strcat(pres,"0");
    }
    return pres;
}
char *multiplus(char *num1, char *num2)
{
    int ilen1 = strlen(num1);
    int ilen2 = strlen(num2);
    int id1 = ilen1 - 1;
    int id2 = ilen2 - 1;
    int ilenres = 0, decade = 0;
    int id = 0;
    if (ilen1 > ilen2)
        ilenres = ilen1 * 2 + 1;
    else
        ilenres = ilen2 * 2 + 1;

    char *pres = (char*)malloc(sizeof(char)*(ilenres + 2));
    memset(pres, 0, sizeof(char)*(ilenres + 2));
    memset(pres, 32, sizeof(char)*(ilenres + 1));
    id = ilenres;
    while (id1 >= 0 && id2 >= 0)
    {
        int singlesingleres = (num1[id1] - '0') + (num2[id2] - '0');
        if (decade + singlesingleres >= 10)
        {
            pres[id] = (decade + singlesingleres - 10) + '0';
            decade = 1;
        }
        else
        {
            pres[id] = (decade + singlesingleres) + '0';
            decade = 0;
        }
        id--;
        id1--;
        id2--;
    }
    while (id1 >= 0)
    {
        int singlesingleres = num1[id1] - '0';
        if (decade + singlesingleres >= 10)
        {
            pres[id] = (decade + singlesingleres - 10) + '0';
            decade = 1;
        }
        else
        {
            pres[id] = (decade + singlesingleres) + '0';
            decade = 0;
        }
        id--;
        id1--;
    }
    while (id2 >= 0)
    {
        int singlesingleres = num2[id2] - '0';
        if (decade + singlesingleres >= 10)
        {
            pres[id] = (decade + singlesingleres - 10) + '0';
            decade = 1;
        }
        else
        {
            pres[id] = (decade + singlesingleres) + '0';
            decade = 0;
        }
        id--;
        id2--;
    }
    if (decade > 0)
    {
        pres[id] = '1';
    }
    Trim(pres);
    return pres;
}
char *multisingle(char *num1,char ch)
{
    int ilen1 = strlen(num1);
    int m = ch - '0';
    char *pres = (char*)malloc(sizeof(char)*(ilen1+2));
    memset(pres,0,sizeof(char)*(ilen1+2));
    memset(pres,32,sizeof(char)*(ilen1+1));
    int id = 0;
    bool improve = false;
    int decade = 0;
    for (int i = ilen1 - 1,id = ilen1;i >= 0 && id >= 0;i--,id--)
    {
        int num = num1[i] - '0';
        int singlesingleres = num * m;
        char str[3] = {0};
        sprintf(str,"%d",singlesingleres);
        int n1,n2;
        if (singlesingleres >= 10)
        {
            n1 = str[0] - '0';
            n2 = str[1] - '0';
            if (improve)
            {
                if (decade + n2 >= 10)
                {
                    pres[id] = (decade + n2 - 10) + '0';
                    decade = (singlesingleres + decade) / 10;
                }
                else
                {
                    pres[id] = (decade + n2) + '0';
                    decade = n1;
                }
            }
            else
            {
                decade = n1;
                pres[id] = str[1];
            }
            improve = true;
        }
        else
        {
            n2 = str[0] - '0';
            if (improve)
            {
                if (decade + n2 >= 10)
                {
                    pres[id] = (decade + n2 - 10) + '0';
                    decade = (singlesingleres + decade) / 10;
                    improve = true;
                }
                else
                {
                    pres[id] = (decade + n2) + '0';
                    decade = 0;
                    improve = false;
                }
            }
            else
            {
                pres[id] = singlesingleres + '0';
                decade = 0;
                improve = false;
            }
        }
    }
    if (decade != 0)
    {
        pres[0] = decade + '0';
    }
    Trim(pres);
    return pres;
}
char *returnzero()
{
    char *p = (char*)malloc(sizeof(char)*2);
    memset(p,0,sizeof(char)*2);
    strcpy(p,"0");
    return p;
}

char * multiply(char * num1, char * num2)
{
    if (num1 == NULL || num2 == NULL)
        return NULL;
    int ilen1 = strlen(num1);
    int ilen2 = strlen(num2);
    if (ilen1 == 0 || ilen2 == 0)
        return NULL;
    if ((ilen1 == 1 && num1[0] == '0') || (ilen2 == 1 && num2[0] == '0'))
        return returnzero();
    if (ilen1 == 1 && num1[0] == '1')
        return num2;
    if (ilen2 == 1 && num2[0] == '1')
        return num1;
    if (ilen1 == 1)
    {
        return multisingle(num2,num1[0]);
    }
    if (ilen2 == 1)
    {
        return multisingle(num1,num2[0]);
    }
    int id = ilen2 - 1;
    int index = 0;
    int size = 256;
    char *pcount = (char*)malloc(sizeof(char)*size);
    memset(pcount, 0, sizeof(char)*size);
    strcpy(pcount, "0");
    while (id >= 0)
    {
        char *p = multisingle(num1, num2[id]);
        char *pplus = multi10(p, index);
        char *plus = multiplus(pcount, pplus);
        strcpy(pcount, plus);
        if (p != pplus)
        {
            free(p);
        }
        free(pplus);
        free(plus);
        index++;
        id--;
    }
    return pcount;
}
void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& current)
{
	if (current.size() == nums.size())
	{
		res.push_back(current);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (count(current.begin(), current.end(), nums[i]) == 0)
		{
			current.push_back(nums[i]);
			backtrack(res, nums, current);
			current.pop_back();
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) 
{
	vector<vector<int>> res;
	vector<int> current;
	backtrack(res, nums, current);
	return res;
}
///////////////////////////////////////////////////
void helper(vector<vector<int>> &pRes, vector<int> &pNums, vector<int> &pTemp, vector<bool> pUsed) 
{
	if (pTemp.size() == pNums.size()) 
	{
		pRes.push_back(pTemp);
		return;
	}
	for (int i = 0; i<pNums.size(); i++) 
	{
		if (pUsed[i]) 
			continue;
		if (i > 0 && pNums[i] == pNums[i - 1] && pUsed[i - 1] == false) 
			continue;

		pTemp.push_back(pNums[i]);
		pUsed[i] = true;

		helper(pRes, pNums, pTemp, pUsed);

		pTemp.pop_back();
		pUsed[i] = false;
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) 
{
	sort(nums.begin(), nums.end());

	vector<vector<int>> aRes;
	vector<int> aTemp;
	vector<bool> aUsed(nums.size() + 1, false);

	helper(aRes, nums, aTemp, aUsed);

	return aRes;
}
void move4(int *i1, int *i2, int *i3, int *i4)
{
    int temp = *i4;*i4 = *i3;*i3 = *i2;*i2 = *i1;*i1 = temp;
}
void rotate(vector<vector<int>>& matrix) 
{
    int j = 0;
    bool oddmatrix = (matrix.size() % 2 != 0);
    int imiddleid_odd = 0, imiddleid_even = 0;
    if (matrix.size() == 1)
        return;
    if (matrix.size() == 2)
    {
        move4(&matrix[0][0],&matrix[0][1],&matrix[1][1],&matrix[1][0]);
        return;
    }
    if (oddmatrix)
        imiddleid_odd = matrix.size() / 2;
    else
        imiddleid_even = matrix.size() / 2 - 1;

    int stepx1 = 0,stepx2 = matrix.size() - 1,stepx3 = matrix.size() - 1,stepx4 = 0;
    int stepy1 = 0,stepy2 = 0,stepy3 = matrix.size() - 1,stepy4 = matrix.size() - 1;
    int stepx2_bak = stepx2;
    while(true)
    {
        move4(&matrix[stepy1][stepx1],&matrix[stepy2][stepx2],&matrix[stepy3][stepx3],&matrix[stepy4][stepx4]);
        stepx1++;
        stepy2++;
        stepx3--;
        stepy4--;
        if (oddmatrix && stepx1 == imiddleid_odd && stepy1 == imiddleid_odd)
            break;
        if (!oddmatrix && stepx1 == imiddleid_even && stepy1 == imiddleid_even)
        {
            move4(&matrix[stepy1][stepx1],&matrix[stepy2][stepx2],&matrix[stepy3][stepx3],&matrix[stepy4][stepx4]);
            break;
        }
        if (stepx1 == stepx2_bak)
        {
            j++;
            stepx1 = j;
            stepy1 = j;
            stepx2 = matrix.size() - 1 - j;
            stepy2 = j;
            stepx3 = matrix.size() - 1 - j;
            stepy3 = matrix.size() - 1 - j;
            stepx4 = j;
            stepy4 = matrix.size() - 1 - j;
            stepx2_bak = stepx2;
            if (oddmatrix && stepx1 == imiddleid_odd && stepy1 == imiddleid_odd)
                break;
            if (!oddmatrix && stepx1 == imiddleid_even && stepy1 == imiddleid_even)
            {
                move4(&matrix[stepy1][stepx1],&matrix[stepy2][stepx2],
                        &matrix[stepy3][stepx3],&matrix[stepy4][stepx4]);
                break;
            }
        }
    }
}
void stringsort(string &str)
{
    int len = str.length();
    for (int i = 0;i < len - 1;i++)
    {
        for (int j = i + 1;j < len;j++)
        {
            if (str[i] > str[j])
            {
                char tmp = str[i];
                str[i]=str[j];
                str[j]=tmp;
            }
        }
    }
}
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<vector<string>> result;
    int len = strs.size();
    vector<string> sortedstrs;
	nodem *p = NULL;
    for (int i = 0;i < len;i++)
    {
		string str_ori = strs[i];
        string sorted = strs[i];
        stringsort(sorted);
        p = AddNode(str_ori.c_str(), sorted.c_str(), p);
    }
    vector<string> single;
	nodem *pbak = p;
	while (p != NULL)
	{
        single.clear();
        cnode * pc = p->pcnode;
        while(pc!= NULL)
        {
            string s(pc->val);
            single.push_back(s);
            pc = pc->next;
        }
        result.push_back(single);
		p = p->next;
	}
    while(pbak != NULL)
    {
        nodem *pb = pbak;
        cnode * pc = pbak->pcnode;
        while(pc != NULL)
        {
            cnode *tmp = pc;
            pc = pc->next;
            free(tmp);
        }
        pbak = pbak->next;
        free(pb);
    }
    return result;
}
void Other8Action()
{
    cout << "\n===========================Other8Action===========================" << endl;
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(7);
    vector<vector<int>> vv1 = combinationSum(v1,7);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(5);
    vector<vector<int>> vv2 = combinationSum(v2,8);

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(7);
    v3.push_back(6);
    v3.push_back(1);
    v3.push_back(5);
    vector<vector<int>> vv3 = combinationSum2(v3,7);
    //string s1 = "aje";
    //stringsort(s1);
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    vector<vector<string>> s2 = groupAnagrams(strs);
    ///////////////////////
    vector<vector<int>> matrix;
    vector<int> matrix1;
    matrix1.push_back(1);
    matrix1.push_back(2);
    matrix1.push_back(3);

    vector<int> matrix2;
    matrix2.push_back(4);
    matrix2.push_back(5);
    matrix2.push_back(6);

    vector<int> matrix3;
    matrix3.push_back(7);
    matrix3.push_back(8);
    matrix3.push_back(9);
    matrix.push_back(matrix1);
    matrix.push_back(matrix2);
    matrix.push_back(matrix3);
    rotate(matrix);
    //////////////////////

	vector<int> numsp;
	numsp.push_back(1);
	numsp.push_back(1);
	numsp.push_back(2);
	vector<vector<int>> permuteUniqueres = permuteUnique(numsp);
	for (int i = 0; i < permuteUniqueres.size(); i++)
	{
		vector<int> p = permuteUniqueres.at(i);
		for (int j = 0; j < p.size(); j++)
		{
			cout << p[j];
		}
		cout << endl;
	}

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

    char m1[15];
    myitoa(-2147483648,m1);
    cout<<m1<<endl;

    char m2[15];
    myitoa(2147483647,m2);
    cout<<m2<<endl;

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
    //vector<vector<int>> res2 = threeSum(num2);
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
    ////////////////////////////
    bool br = false;
    char arrstrign1[] = "()";
    br = isValid(arrstrign1);
    cout<<br<<endl;

    char arrstrign2[] = "()[]{}";
    br = isValid(arrstrign2);
    cout<<br<<endl;

    char arrstrign3[] = "(]";
    br = isValid(arrstrign3);
    cout<<br<<endl;

    char arrstrign4[] = "([)]";
    br = isValid(arrstrign4);
    cout<<br<<endl;

    char arrstrign5[] = "{[]}";
    br = isValid(arrstrign5);
    cout<<br<<endl;

    char arrstrign6[] = "]";
    br = isValid(arrstrign6);
    cout<<br<<endl;

    char arrstrign7[] = "[";
    br = isValid(arrstrign7);
    cout<<br<<endl;
    ///////////////
    int ar[] = {1,1,2};
    int ir = removeDuplicates(ar,sizeof(ar)/sizeof(int));
    cout<<ir<<endl;

    int ar2[] = {0,0,1,1,1,2,2,3,3,4};
    int ir2 = removeDuplicates(ar2,sizeof(ar2)/sizeof(int));
    cout<<ir2<<endl;

    int ar3[] = {0,0,1,1,1,2,2,3,3,4,4,5};
    int ir3 = removeDuplicates(ar3,sizeof(ar3)/sizeof(int));
    cout<<ir3<<endl;

    int arm1[] = {3,2,2,3};
    int armm1 = removeElement(arm1,sizeof(arm1)/sizeof(int),3);
    cout<<armm1<<endl;

    int arm2[] = {0,1,2,2,3,0,4,2};
    int armm2 = removeElement(arm2,sizeof(arm2)/sizeof(int),2);
    cout<<armm2<<endl;
    //////////////
    int id = divide(-10,-3);
    cout<<id<<endl;

    id = divide(7,-3);
    cout<<id<<endl;

    id = divide(2147483647,2);
    cout<<id<<endl;

    int n1[] = {1,2,3};
    nextPermutation(n1,3);

    int n2[] = {3,2,1};
    nextPermutation(n2,3);

    int n3[] = {1,1,5};
    nextPermutation(n3,3);

    int n4[] = {1,3,2};
    nextPermutation(n4,3);
    ///////////////
    int r1[] = {5,7,7,8,8,10};
    int r2 = 0;
    int *rp1 = searchRange(r1,sizeof(r1)/sizeof(int),8,&r2);

    int r22[] = {5,7,7,8,8,10};
    int *rp2 = searchRange(r22,sizeof(r22)/sizeof(int),6,&r2);

    int r33[] = { 3,3,3 };
    int *rp3 = searchRange(r33, sizeof(r33) / sizeof(int), 3, &r2);
    //////////////
#ifdef CPLUSPLUS_11
    string ra = countAndSay(5);
#endif
    /////////////////
    int count[] = { 1,2,0 };
    int ic = firstMissingPositive(count, sizeof(count) / sizeof(int));
    cout << ic << endl;

    int count1[] = { 7,8,9,11,12 };
    int ic1 = firstMissingPositive(count1, sizeof(count1) / sizeof(int));
    cout << ic1 << endl;

    int count2[] = { 3,4,-1,1 };
    int ic2 = firstMissingPositive(count2, sizeof(count2) / sizeof(int));
    cout << ic2 << endl;

    int count3[] = { -1,-2 };
    int ic3 = firstMissingPositive(count3, sizeof(count3) / sizeof(int));
    cout << ic3 << endl;

    int count4[] = { 1,1 };
    int ic4 = firstMissingPositive(count4, sizeof(count4) / sizeof(int));
    cout << ic4 << endl;

    int count5[] = { 2,1 };
    int ic5 = firstMissingPositive(count5, sizeof(count5) / sizeof(int));
    cout << ic5 << endl;

    int count6[] = { 1000,-1 };
    int ic6 = firstMissingPositive(count6, sizeof(count6) / sizeof(int));
    cout << ic6 << endl;

    int count7[] = { 1000,1 };
    int ic7 = firstMissingPositive(count7, sizeof(count7) / sizeof(int));
    cout << ic7 << endl;
    /////////////////
    char *ms1 = multisingle("99",'9');
    cout<<ms1<<endl;
    free(ms1);

    ms1 = multisingle("123456789", '3');
    cout << ms1 << endl;
    free(ms1);

    ms1 = multisingle("123456789", '4');
    cout << ms1 << endl;
    free(ms1);

    ms1 = multisingle("1296", '5');
    cout << ms1 << endl;
    free(ms1);

    ms1 = multisingle("999", '9');
    cout << ms1 << endl;
    free(ms1);

    ms1 = multisingle("999", '3');
    cout << ms1 << endl;
    free(ms1);

    ms1 = multisingle("23",'3');
    cout<<ms1<<endl;
    free(ms1);

    ms1 = multisingle("23",'4');
    cout<<ms1<<endl;
    free(ms1);

    ms1 = multisingle("9",'9');
    cout<<ms1<<endl;
    free(ms1);

    ms1 = multisingle("3",'3');
    cout<<ms1<<endl;
    free(ms1);

    ms1 = multi10("3",3);
    cout<<ms1<<endl;
    free(ms1);

    ms1 = multiplus("999", "29");
    cout << ms1 << endl;
    free(ms1);

    ms1 = multiplus("999", "0");
    cout << ms1 << endl;
    free(ms1);

    ms1 = multiplus("999", "0");
    cout << ms1 << endl;
    free(ms1);

    ms1 = multiply("123", "456");
    cout << ms1 << endl;
    free(ms1);

    ms1 = multiply("1236", "45");
    cout << ms1 << endl;
    free(ms1);

    ms1 = multiply("123456789", "987654321");
    cout << ms1 << endl;
    free(ms1);
}
