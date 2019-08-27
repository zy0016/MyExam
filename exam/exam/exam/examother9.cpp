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
    int maxS = nums[0];
    for (int i = 1; i < numsSize; i++) 
    {
        if (nums[i] + nums[i - 1] > nums[i]) 
        {
            nums[i] = nums[i] + nums[i - 1];
        }
        if (nums[i] > maxS) 
            maxS = nums[i];
    }
        
    return maxS;
    /*if (numsSize == 1)
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
    return maxvalue;*/
}
void Other9Action()
{
    cout << "\n===========================Other9Action===========================" << endl;
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
}