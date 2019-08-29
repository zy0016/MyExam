#include "stdafx.h"
#include "other9.h"
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

int maxSubArray(int* nums, int numsSize)
{
    /*int maxS = nums[0];
    for (int i = 1; i < numsSize; i++) 
    {
        if (nums[i] + nums[i - 1] > nums[i]) 
        {
            nums[i] = nums[i] + nums[i - 1];
        }
        if (nums[i] > maxS) 
            maxS = nums[i];
    }
        
    return maxS;*/
    if (numsSize == 1)
        return nums[0];

    int maxvalue = INT_MIN;
    int startid = 0;
    int endid = startid + 1;
    int i = startid;
    int count = 0;
    for (int j = 0;j < numsSize;j++)
    {
        if (nums[j] > maxvalue)
            maxvalue = nums[j];
    }
    while(true)
    {
        count = 0;
        for (i = startid;i <= endid;i++)
        {
            if (nums[i] > 0 && count > INT_MAX - nums[i])
            {
                return INT_MAX;
            }
            count = count + nums[i];
        }
        if (count > maxvalue)
        {
            maxvalue = count;
        }
        if (endid < numsSize - 1)
        {
            endid++;
            continue;
        }
        if (startid < numsSize - 2)
        {
            startid++;
            endid = startid + 1;
            continue;
        }
        break;
    }
    return maxvalue;
}
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	if (matrix.size() == 0)
		return{};
	int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
	vector<int> ans;
	int dir = 0;
	while (l <= r && t <= b)
	{
		switch (dir)
		{
		case 0:
			for (int i = l; i <= r; i++)
			{
				ans.push_back(matrix[t][i]);
			}
			t++;
			break;
		case 1:
			for (int i = t; i <= b; i++) 
			{
				ans.push_back(matrix[i][r]);
			}
			r--;
			break;
		case 2:
			for (int i = r; i >= l; i--) 
			{
				ans.push_back(matrix[b][i]);
			}
			b--;
			break;
		case 3:
			for (int i = b; i >= t; i--) 
			{
				ans.push_back(matrix[i][l]);
			}
			l++;
			break;
		}
		dir = (dir + 1) % 4;
	}
	return ans;
}
bool canJump(vector<int>& nums) 
{
	int len = nums.size();
	if (len == 0)
		return false;
	if (len == 1)
	{
		return (nums[0] == 1 || nums[0] == 0) ? true : false;
	}
	if (nums[0] == 0)
		return false;
	int i = 0, id = 1;
	bool beyondzero = false;
	int zeroid = -1;
	while (true)
	{
		int value = nums[i];
		if (value == 0 && i < len - 1)
		{
			zeroid = i;
			if (id == i && !beyondzero)
				return false;
			if (id == i && beyondzero)
			{
				beyondzero = false;
			}
			i = id;
			if (id < len - 1)
			{
				id++;
			}
			else
			{

			}
			continue;
		}
		if (i + value >= len - 1)
		{
			return true;
		}
		if (zeroid != -1)
		{
			for (int k = i; k <= i + value; k++)
			{
				if (k > zeroid && nums[k] > 0)
				{
					beyondzero = true;
					break;
				}
			}
		}
		i = i + value;
	}
	return false;
}

void Other9Action()
{
    cout << "\n===========================Other9Action===========================" << endl;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	bool b1 = canJump(nums);
	nums.clear();
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	b1 = canJump(nums);

	nums.clear();
	nums.push_back(2);
	nums.push_back(0);
	b1 = canJump(nums);

	nums.clear();
	nums.push_back(0);
	nums.push_back(1);
	b1 = canJump(nums);

	nums.clear();
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	b1 = canJump(nums);

	nums.clear();
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(0);
	nums.push_back(0);
	b1 = canJump(nums);

	nums.clear();
	int n1[] = { 5,9,3,2,1,0,2,3,3,1,0,0 };
	for (int i = 0; i < sizeof(n1) / sizeof(int); i++)
	{
		nums.push_back(n1[i]);
	}
	b1 = canJump(nums);

	nums.clear();
	int n2[] = { 2,0,1,0,1 };
	for (int i = 0; i < sizeof(n2) / sizeof(int); i++)
	{
		nums.push_back(n2[i]);
	}
	b1 = canJump(nums);
	////////////////
    int a1[] = {-2,1,-3,4,-1,2,1,-5,4};
    int a1r = maxSubArray(a1,sizeof(a1)/sizeof(int));
    cout<<a1r<<endl;

    int a2[] = {-2,1};
    int a2r = maxSubArray(a2,sizeof(a2)/sizeof(int));
    cout<<a2r<<endl;

    int a3[] = {2,1};
    int a3r = maxSubArray(a3,sizeof(a3)/sizeof(int));
    cout<<a3r<<endl;

    int a4[] = {-1,0,-2};
    int a4r = maxSubArray(a4,sizeof(a4)/sizeof(int));
    cout<<a4r<<endl;
	//////////////////////////////////////
	vector<vector<int>> matrix1;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	matrix1.push_back(v1);
	vector<int> v2;
	v2.push_back(5);
	v2.push_back(6);
	v2.push_back(7);
	v2.push_back(8);
	matrix1.push_back(v2);
	vector<int> v3;
	v3.push_back(9);
	v3.push_back(10);
	v3.push_back(11);
	v3.push_back(12);
	matrix1.push_back(v3);

	vector<int> v4 = spiralOrder(matrix1);
}