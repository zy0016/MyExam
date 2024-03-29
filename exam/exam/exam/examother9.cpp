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
    vector<int> ans;
	if (matrix.size() == 0)
		return ans;
	int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
	
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
    int start = 0;
    int end = nums[0];
                
    for (int i = 0; i <= end; i++) 
    {                    
        if (nums[i] + i > end)
            end = nums[i] + i;
            
        if (end >= nums.size() - 1) 
            return true;            
    }
    return false;
	/*int len = nums.size();
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
                break;
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
	return false;*/
}

int lengthOfLastWord(char * s)
{
    if (s == NULL)
        return 0;
    int len = strlen(s);
    if (len == 0)
        return 0;
    if (len == 1 && s[0] == ' ')
        return 0;

    s = Trim(s);
    len = strlen(s);

    if (len == 1 && s[0] != ' ')
        return 1;
    
    for (int i = len - 1;i >= 0;i--)
    {
        if (s[i] == ' ')
        {
            int r = len - i - 1;
            return r;
        }
    }
    return len;
}
void matrixOrder(vector<vector<int>>& matrix)
{
    int count = 1;
	if (matrix.size() == 0)
		return ;
	int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
	int dir = 0;
	while (l <= r && t <= b)
	{
		switch (dir)
		{
		case 0:
			for (int i = l; i <= r; i++)
			{
                matrix[t][i] = count++;
			}
			t++;
			break;
		case 1:
			for (int i = t; i <= b; i++) 
			{
                matrix[i][r] = count++;
			}
			r--;
			break;
		case 2:
			for (int i = r; i >= l; i--) 
			{
                matrix[b][i] = count++;
			}
			b--;
			break;
		case 3:
			for (int i = b; i >= t; i--) 
			{
                
                matrix[i][l] = count++;
			}
			l++;
			break;
		}
		dir = (dir + 1) % 4;
	}
}

vector<vector<int>> generateMatrix(int n) 
{
    vector<vector<int>> result;
    if (n == 0)
        return result;
    if (n == 1)
    {
        vector<int> r1;
        r1.push_back(1);
        result.push_back(r1);
        return result;
    }
    for (int i = 0;i < n;i++)
    {
        vector<int> r1;
        for (int j = 0;j < n;j++)
        {
            r1.push_back(-1);
        }
        result.push_back(r1);
    }
    matrixOrder(result);
    return result;
}

vector<int> mergetwo(vector<int> v1,vector<int> v2,bool *canmerge)
{
    vector<int> result;
	if (v1[0] == -1)
	{
		return v2;
	}
	if (v2[0] == -1)
	{
		return v1;
	}
    if ((v2[0] > v1[1]) || (v1[0] > v2[1]))
    {
        *canmerge = false;
        return result;
    }
	if (v1[0] == v2[0] && v1[1] == v2[1])
	{
		*canmerge = true;
		result.push_back(v1[0]);
		result.push_back(v1[1]);
		return result;
	}
	if ((v2[0] >= v1[0] && v2[0] <= v1[1]) || (v1[0] >= v2[0] && v1[0] <= v2[1]))
    {
        *canmerge = true;

        result.push_back((v1[0] < v2[0]) ? v1[0] : v2[0]);
        result.push_back((v1[1] > v2[1]) ? v1[1] : v2[1]);
    }
    else
    {
        *canmerge = false;
    }
    return result;
}
vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	int b = intervals.size();
	vector<int> m;
	if (b == 0)
	{
        vector<vector<int>> result;
		return result;
	}
	if (b == 1)
	{
		return intervals;
	}
	for (int i = b - 1; i >= 1; i--)
	{
		bool canmerge = false;
		for (int j = i - 1; j >= 0; j--)
		{
			m = mergetwo(intervals[i], intervals[j], &canmerge);
			if (canmerge)
			{
				intervals[j][0] = m[0];
				intervals[j][1] = m[1];
				intervals[i][0] = intervals[b - 1][0];
				intervals[i][1] = intervals[b - 1][1];
				intervals.resize(b - 1);
				b = intervals.size();
				break;
			}
		}
	}
	return intervals;
}
//string getPermutation(int n, int k) 
//{
//    string s = "";
//    for (int i = 0;i < n;i++)
//    {
//        
//    }
//
//    return s;
//}
vector<int> bfindvector;
bool bfind = false;
void backtrack_Permutation(vector<vector<int>>& res, vector<int>& nums, vector<int>& current,int k)
{
    if (bfind)
		return;
    if (current.size() == nums.size())
    {
        res.push_back(current);
        if (res.size() == k)
        {
            bfindvector = current;
            bfind = true;
        }
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (count(current.begin(), current.end(), nums[i]) == 0)
        {
            current.push_back(nums[i]);
            backtrack_Permutation(res, nums, current,k);
            current.pop_back();
        }
    }
}
vector<int> permute_Permutation(vector<int>& nums,int k) 
{
    vector<vector<int>> res;
    vector<int> current;
    backtrack_Permutation(res, nums, current,k);
    return bfindvector;
}
string getPermutation(int n, int k) 
{
    string res = "";
    vector<int> nums;
    for (int i = 0;i < n;i++)
    {
        nums.push_back(i + 1);
    }
    vector<int> result = permute_Permutation(nums,k);

    for (int i = 0;i < result.size();i++)
    {
        ostringstream oss;
        oss<< result[i];
        res = res + oss.str();
    }
    return res;
}
//char * getPermutation(int n, int k)
//{
//    char *res = (char*)malloc(sizeof(char) * (n + 1));
//    memset(res,0,(sizeof(char) * (n + 1)));
//    int i;
//    vector<int> nums;
//    for (i = 0;i < n;i++)
//    {
//        nums.push_back(i + 1);
//    }
//    vector<vector<int>> result = permute_Permutation(nums);
//    nums = result[k - 1];
//    for (i = 0;i < nums.size();i++)
//    {
//        char c[2] = "";
//        c[0] = nums[i] + '0';
//        strcat(res,c);
//    }
//    return res;
//}
void getPathSum(vector<vector<int>>& grid, int i, int j,int *count)
{
	int r = grid[0].size() - 1, b = grid.size() - 1;
	*count = *count + grid[i][j];
	if (i == b && j == r)
	{
		return;
	}
	if (j < r)
	{
		getPathSum(grid, i, j + 1, count);
	}
	if (j == r)
	{
		getPathSum(grid, i + 1, j, count);
		i = 0;
		j = 0;
	}
	getPathSum(grid, i + 1, j + 1, count);
}
int minPathSum(vector<vector<int>>& grid)
{
	/*int minval = INT_MAX, count = 0;
	int r = grid[0].size() - 1, b = grid.size() - 1;
	int i = 0, j = 0;
	int istep = 0, jstep = 1;
	while (true)
	{
		count = count + grid[i][j];
		if (count < minval)
		{
			minval = count;
		}
		if (j < r)
		{
			j += jstep;
			i += istep;
			continue;
		}
		jstep = 0;
		if (j == r && i < b)
		{
			i += istep;
			j += jstep;
			continue;
		}
		if (j == r && i == b)
		{

		}
	}
	return minval;*/
	return 0;
}
vector<int> plusOne(vector<int>& digits) 
{
	int len = digits.size();
	vector<int> result;
	if (len == 0)
		return result;
	char *pdigit = (char*)malloc(sizeof(char) * (len + 1));
	memset(pdigit, 0, sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
	{
		char dig[2] = { digits[i] + '0' ,'\0'};
		strcat(pdigit, dig);
	}
	char *res = multiplus(pdigit, "1");
	char reslen = strlen(res);
	for (int i = 0; i < reslen; i++)
	{
		int r = res[i] - '0';
		result.push_back(r);
	}
	free(res);
	return result;
}
int mySqrt(int x) 
{
    if (x == 0 || x == 1)
        return x;
    int middle = 46340;
    while(middle > 0)
    {
        if (middle * middle > x)
        {
            middle--;
            continue;
        }
        break;
    }
    return middle;
}
int climbStairs(int n) 
{
    if (n < 4)
        return n;

    int* dp = (int*)malloc(sizeof(int) * (n+1));
    memset(dp,0,sizeof(int)*(n+1));
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            dp[i]= 1;
        }
        else if(i==2)
        {
            dp[i]=2;
        }
        else
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
    }
    int res = dp[n];
    free(dp);
    return res;
}

void setZeroes(vector<vector<int>>& matrix) 
{
    int index = -1;
    int r = matrix[0].size() - 1,b = matrix.size() - 1;

    for (int iRow = 0;iRow <= b;iRow++)
    {
        for (int iCol = 0;iCol <= r;iCol++ )
        {
            if (matrix[iRow][iCol] < 0 && matrix[iRow][iCol] == index)
            {
                index--;
            }
        }
    }

    for (int iRow = 0;iRow <= b;iRow++)
    {
        for (int iCol = 0;iCol <= r;iCol++ )
        {
            if (matrix[iRow][iCol] == 0)
            {
                for (int i = 0;i <= r;i++)
                {
                    if (matrix[iRow][i] != 0)
                        matrix[iRow][i] = index;
                }
                for (int i = 0;i <= b;i++)
                {
                    if (matrix[i][iCol] != 0)
                        matrix[i][iCol] = index;
                }
            }
        }
    }
    for (int iRow = 0;iRow <= b;iRow++)
    {
        for (int iCol = 0;iCol <= r;iCol++ )
        {
            if (matrix[iRow][iCol] == index)
            {
                matrix[iRow][iCol] = 0;
            }
        }
    }
}
vector<vector<int>> subsets(vector<int>& nums) 
{
	int len = nums.size();
	vector<vector<int>> result;
	vector<int> vecnull;
	if (len == 0)
		return result;

	result.push_back(vecnull);
	result.push_back(nums);
	if (len == 1)
	{
		return result;
	}
	for (int i = 0; i < len; i++)
	{
		vector<int> vec;
		vec.push_back(nums[i]);
		result.push_back(vec);
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{

		}
	}
	return result;
}
vector<vector<int>> GetPairSum(vector<int>& nums, int k)
{
	vector<vector<int>> result;
	int size = nums.size();
	if (size < 2)
		return result;

	for (int i = size - 1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if ((nums[i] != INT_MIN) && (nums[j] != INT_MIN) && (nums[i] + nums[j] == k))
			{
				vector<int> single;
				single.push_back(nums[i]);
				single.push_back(nums[j]);
				result.push_back(single);
				nums[i] = INT_MIN;
				nums[j] = INT_MIN;
			}
		}
	}
	return result;
}
template<class T>
class StackTemplate
{
public:
	StackTemplate() :top(0) {}
	void push(const T & i)
	{
		assert(top<Stacksize);
		stack[top++] = i;
	}
	T pop()
	{
		assert(top>0);
		return stack[--top];
	}
	int size()
	{
		return top;
	}
private:
	enum { Stacksize = 100 };
	T stack[Stacksize];
	int top;
};
enum COLOR { RED, BLUE, WHITE, BLACK };//color for car
enum ENGINE { ENGINE1, ENGINE2 };//engine type for car
enum DIRECTION { 
	NONE,//no direction when car stop.
	FORWARD, 
	BACKWARD, 
	LEFT, 
	RIGHT 
};//move direction
class Car
{
public:
	Car(unsigned int len, unsigned int w, COLOR c, string model, ENGINE e, unsigned int seat) :Length(len), 
		Width(w), Color(c), Model(model), Engine(e), iSeats(seat)
	{
		iSpeed = 0;
		moving = false;
	}
	void ChangeEngine(ENGINE newengine)//change the engine for current car
	{
		Engine = newengine;
	}
	void ChangeColor(COLOR newcolor)//change the color for current car
	{
		Color = newcolor;
	}
	void SetSeats(unsigned int count)//set seat number for car
	{
		iSeats = count;
	}
	COLOR GetColor()//get color for car
	{
		return Color;
	}
	string GetModelNumber()//get the model number for car
	{
		return Model;
	}
	unsigned int GetSpeed()//get the speed of the car
	{
		return iSpeed;
	}
	void SetSpeed(unsigned int speed)//set speed for car
	{
		iSpeed = speed;
	}
	void SetDirection(DIRECTION d)// set direction
	{
		if (moving)
			Direction = d;
		else
			Direction = NONE;
	}
	DIRECTION GetDirection()//get direction.
	{
		return ((moving) ? Direction : NONE);
	}
	void ChangeDirection(DIRECTION newdirection)//change direction for car
	{
		if (moving)
			Direction = newdirection;
		else
			Direction = NONE;
	}
	void SetMoveStatus(bool b)//set the car is moving or not
	{
		moving = b;
	}
	virtual ~Car() {}
private:
	unsigned int Length;//The car length
	unsigned int Width;//The car width
	COLOR Color;//color of the car
	string Model;//model number for the car
	ENGINE Engine;//engine type
	unsigned int iSeats;//seat number in car
	unsigned int iSpeed;//current speed for car
	DIRECTION Direction;//move direction
	bool moving;//The car is moving or not
};
bool exist(vector<vector<char>>& board, string word) 
{
    int id = 0;
    char cbegin = word[0];
    int i = 0,j = 0,k=0;
    int r = board[0].size() - 1,b = board.size() - 1;
    bool bfindbegin = false;
    for (j = 0;j <= b;j++)
    {
        if (bfindbegin)
            break;
        for (i = 0;i <= r;i++)
        {
            if (cbegin == board[j][i])
            {
                id++;
                bfindbegin = true;
                break;
            }
        }
    }
    if (!bfindbegin)
        return false;
    i = 0;
    j = 0;
	bool bsame = false;
	while (i <= r && j <= b)
	{
		bsame = false;
		for (k = 0; k < word.length(); k++)
		{
			char c = word[k];
            char cmatrix = board[j][i];
		    if (c == cmatrix)
		    {
                if (k == word.length() - 1)
                {
                    if (((i > 0) && (c == board[j][i - 1])) || ((i < r) && (c == board[j][i + 1])) || 
                        ((j > 0) && (c == board[j - 1][i])) || ((j < b) && (c == board[j + 1][i])))
                    {
                        bsame = true;
                    }
                    else
                    {
                        bsame = false;
                    }
                    break;
                }
                char cnext = word[k + 1];
			    if ((i > 0) && (cnext == board[j][i - 1]))
			    {
				    i--;
				    bsame = true;
				    continue;
			    }
			    if ((i < r) && (cnext == board[j][i + 1]))
			    {
				    i++;
				    bsame = true;
				    continue;
			    }
			    if ((j > 0) && (cnext == board[j - 1][i]))
			    {
				    j--;
				    bsame = true;
				    continue;
			    }
			    if ((j < b) && (cnext == board[j + 1][i]))
			    {
				    j++;
				    bsame = true;
				    continue;
			    }
		    }
		    else
		    {
                bsame = false;
			    break;
		    }
		}
		if (k == word.length() - 1)
		{
            //if (bsame)
            //    return true;
            return bsame;
		}
		if (i <= r)
		{
			i++;
            if (i > r)
            {
                i = 0;
                j++;
            }
			continue;
		}
		if (j <= b)
		{
			i = 0;
			j++;
		}
	}
    return false;
}
static int removeDuplicates(int* nums, int numsSize)
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
        int idup = 0;
        while(j < numsSize)
        {
            if ((nums[i] == nums[j]) && (idup == 1))
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
            else if ((nums[i] == nums[j]) && (idup == 0))
            {
                idup = 1;
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
bool search(vector<int>& nums, int target) 
{
    for (int i = 0;i < nums.size();i++)
    {
        if (target == nums[i])
        {
            return true;
        }
    }
    return false;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int j = 0;
    for (int i = m;j < nums2Size;i++,j++)
    {
        nums1[i] = nums2[j];
    }
    InsertSort(nums1,nums1Size);
}
int numDecodings(char * s)
{
    if (s == NULL)
        return 0;
    int len = strlen(s);
    if (len == 0)
        return 0;
    int icount = len;
    for (int i = 0;i < len;i++)
    {
        if (s[i] == '0')
        {
            icount--;
        }
    }

    return icount;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    if (matrix.size() == 0)
        return false;
    int l = 0, r = matrix[0].size(), t = 0, b = matrix.size();
    for (int t = 0; t < b;t++)
    {
        for (int l = 0; l < r;l++)
        {
            if (matrix[t][l] == target)
                return true;
        }
    }
    return false;
}
int singleNumber(vector<int>& nums) 
{
    int len = nums.size();
    for (int i = 0;i < len - 1;i++)
    {
        int m = nums[i];
        for (int j = i + 1;j < len;j++)
        {
            int n = nums[j];
            if (m == n)
            {
                nums[i] = 0;
                nums[j] = 0;
                break;
            }
        }
    }
    for (int i = 0;i < len;i++)
    {
        if (nums[i] != 0)
            return nums[i];
    }
    return 0;
}
int singleNumber(vector<int>& nums,int) 
{
    int len = nums.size();
    for (int i = 0;i < len - 1;i++)
    {
        bool bfind = false;
        int m = nums[i];
        for (int j = i + 1;j < len;j++)
        {
            int n = nums[j];
            if (m == n)
            {
                nums[j] = 0;
                bfind = true;
            }
        }
        if (bfind)
        {
            nums[i] = 0;
        }
    }
    for (int i = 0;i < len;i++)
    {
        if (nums[i] != 0)
            return nums[i];
    }
    return 0;
}
bool isChar(char c)
{
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}
bool isNumber(char c)
{
    return (c >= '0' && c <= '9');
}
char *remove_no_char(char *s)
{
    int len = strlen(s),j;
    for (int i = 0;i < len;)
    {
        if (s[i] == '\0')
            break;
        if (isChar(s[i]) || isNumber(s[i]))
        {
            i++;
        }
        else
        {
            if (i == len - 1)
            {
                s[i] = '\0';
                break;
            }
            else
            {
                for (j = i;j < len;j++)
                {
                    s[j] = s[j + 1];
                }
                s[j] = '\0';
                len--;
            }
        }
    }
    char *pEnd=s+len-1;    
    while((*pEnd==' ')&&(len-- > 0))
        *pEnd-- = '\0';
    return s;
}

bool isPalindrome(char * s)
{
    if (s == NULL)
        return true;
    int len = strlen(s);
    if (len == 0)
        return true;
    int i = 0,j = len - 1;
    while(i <= j)
    {
        char c1 = s[i];
        char c2 = s[j];
        if (isChar(c1)||isNumber(c1))
        {
            if (c1 >= 'A' && c1 <= 'Z')
                c1 = c1 - 'A' + 'a';
        }
        else
        {
            i++;
            continue;
        }
        if (isChar(c2)||isNumber(c2))
        {
            if (c2 >= 'A' && c2 <= 'Z')
                c2 = c2 - 'A' + 'a';
        }
        else
        {
            j--;
            continue;
        }
        if (c1 == c2)
        {
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}
bool findmych(string s)
{
    for(int i = 0;i < s.length();i++)
    {
        if (s[i] != '-')
            return true;
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) 
{
    string sbak = s;
    vector<string> wordDictbak = wordDict;
    while(wordDict.size() > 0)
    {
        s = sbak;
        int len = wordDict.size();
        for (int i = len - 1;i >=0 && s.length() > 0;)
        {
            int ifind = s.find(wordDict[i]);
            if (ifind >= 0 )
            {
                s.replace(ifind,wordDict[i].length(),"-");
            }
            else
            {
                i--;
            }
        }
        if (findmych(s) == false)
            return true;
        wordDict.pop_back();
    }
    s = sbak;
    wordDict = wordDictbak;
    int len = wordDict.size();
    for (int i = 0;i < len && s.length() > 0;i++)
    {
        int ifind = s.find(wordDict[i]);
        if (ifind >= 0)
        {
            s.replace(ifind,wordDict[i].length(),"-");
        }
    }
    if (findmych(s) == false)
        return true;
    else
        return false;
}
vector<vector<int>> generate(int numRows) 
{
    vector<vector<int>> res;
    for(int i = 0; i < numRows; i++)
    {
        vector<int> temp;
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || i == j)
            {
                temp.push_back(1);
            }
            else
            {
                temp.push_back(res[i-1][j] + res[i-1][j-1]);  
            }
        }
        res.push_back(temp);
    }
    return res;
}
vector<int> getRow(int rowIndex) 
{
    vector<vector<int>> res;
    vector<int> temp;
    rowIndex++;
    for(int i = 0; i < rowIndex; i++)
    {
        temp.clear();
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || i == j)
            {
                temp.push_back(1);
            }
            else
            {
                temp.push_back(res[i-1][j] + res[i-1][j-1]);  
            }
        }
        res.push_back(temp);
    }
    return temp;
}
int maxProfit(vector<int>& prices) 
{
    int len = prices.size();
    int max = 0;
    for (int i = 0;i < len - 1;i++)
    {
        for (int j = i + 1;j < len;j++)
        {
            int gap = 0;
            if (prices[i] < prices[j])
            {
                gap = prices[j] - prices[i];
                if (gap > max)
                {
                    max = gap;
                }
            }
        }
    }
    return max;
}
void trim(string &s)
{
    if (!s.empty())
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
}
string reverseWords(string s) 
{
    int len;
    string result = "";
    trim(s);
    while(true)
    {
        int ispace = s.rfind(" ");
        if (ispace == -1)
        {
            trim(s);
            result = result + " " + s;
            break;
        }
        string single = s.substr(ispace);
        trim(single);
        result = result + " " +  single;
        trim(result);
        len = s.length();
        string snew = s.substr(0,len - single.length());
        trim(snew);
        s = snew;
    }
    trim(result);
    return result;
}
int findPeakElement(vector<int>& nums) 
{
    int len = nums.size();
    if (len == 0 || len == 1)
        return 0;
    for (int i = 1;i < len - 1;i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return i;
    }
    return (nums[len - 1] > nums[len - 2]) ? (len - 1) : 0;
}

int maxProfit(vector<int>& prices, int)
{
	int len = prices.size();
	int max = 0;
	int id = 0;
	while (id < len)
	{
		if (id == len - 1)
		{
			break;
		}
		int v1 = prices[id];
		int v2 = prices[id + 1];
		if (v1 < v2)
		{
			max = max + v2 - v1;
		}
		id++;
	}
	return max;
}

int gapCountTwoWords(string word1, string word2)
{
	int len1 = word1.length();
	int len2 = word2.length();
	if (len1 != len2)
		return -1;
	int icount = 0;
	for (int i = 0; i < len1; i++)
	{
		if (word1[i] = word2[i])
			icount++;
	}
	return icount;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	int id = 0;
	wordList.insert(wordList.begin(), beginWord);
	int len = wordList.size();
	while (id < len)
	{
		if (id == len - 1)
			break;
		if (wordList[id] == endWord)
			break;
		int ires = gapCountTwoWords(wordList[id], wordList[id + 1]);
		if (ires != 1)
		{
			return 0;
		}
		id++;
	}
	return id;
}
int findMin(vector<int>& nums)
{
	int len = nums.size();
	switch (len)
	{
	case 0:
		return 0;
	case 1:
		return nums[0];
	default:
		if (nums[0] < nums[1] && nums[0] > nums[len - 1])
		{
			int j;
			for (int i = len - 1; i >= 0; i--)
			{
				j = i - 1;
				if (nums[j] > nums[i])
					return nums[i];
			}
		}
		else if (nums[0] > nums[1] && nums[0] > nums[len - 1])
		{
			return nums[1];
		}
		else
		{
			return nums[0];
		}
		break;
	}
	return 0;
}
string fractionToDecimal(int numerator, int denominator) 
{
	if (numerator % denominator == 0)
	{
		int ires = numerator / denominator;
		char cresult[256] = "";
		myitoa(ires, cresult);
		string sresult(cresult);
		return sresult;
	}
	else
	{
		string result = "";
		return result;
	}
}
vector<int> twoSum(vector<int>& numbers, int target) 
{
	int len = numbers.size();
	vector<int> result;
	if (len < 2)
		return result;
	
	int i = 0, j = i + 1;
	if (target == 0)
	{
		for (i = 0; i < len - 1; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if (numbers[i] + numbers[j] == target)
				{
					result.push_back(i + 1);
					result.push_back(j + 1);
				}
			}
		}
	}
	else
	{
		for (i = 0; i < len - 1; i++)
		{
			if (numbers[i] == 0)
				continue;
			for (j = i + 1; j < len; j++)
			{
				if (numbers[i] + numbers[j] == target)
				{
					result.push_back(i + 1);
					result.push_back(j + 1);
				}
			}
		}
	}
	return result;
}

int majorityElement(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int len = nums.size();
	if (len == 0)
		return 0;
	if (len == 1)
		return nums[0];

	int id = 0, half = len / 2, vcount = 0, oldvalue = 0, value = 0, realvalue = 0, maxvcount = 0;
	bool bfind = false;
	while (id < len)
	{
		value = nums[id];
		if (value != oldvalue)
		{
			vcount = 0;
			bfind = false;
			for (int i = 0; i < nums.size(); i++)
			{
				if (value == nums[i])
				{
					vcount++;
					if (vcount > half)
					{
						bfind = true;
						maxvcount = vcount;
						realvalue = value;
						break;
					}
				}
			}
			if (bfind)
			{
				break;
			}
			if (vcount > maxvcount)
			{
				maxvcount = vcount;
				realvalue = value;
			}
			if (vcount > half)
			{
				break;
			}
			oldvalue = value;
		}
		id++;
	}
	return realvalue;
}
int trailingZeroes(int n)
{
	int zeros = 0;
	while (n > 0)
	{
		n /= 5;
		zeros += n;
	}
	return zeros;
}

void reorder(vector<string>& array)
{
	int j,nNum = array.size();
	string temp;
	unsigned int i;
	for (i = 1; i < nNum; ++i)
	{
		if (array[i - 1] + array[i] > array[i] + array[i - 1])
		{
			temp = array[i];
			array[i] = array[i - 1];
			for (j = i - 1; j >= 0 && array[j] + temp > temp + array[j]; --j)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = temp;
		}
	}
	for (i = 0,j = nNum - 1; i < nNum / 2; i++,j--)
	{
		string t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
}
string largestNumber(vector<int>& nums) 
{
	string result = "";
	int len = nums.size();
	vector<string> numstring;
	for (int i = 0; i < len; i++)
	{
		numstring.push_back(to_string(nums[i]));
	}
	/*sort(numstring.begin(), numstring.end(), [&](const string x, const string y) {
		return x + y > y + x;
	});*/
	reorder(numstring);
	for (int i = 0; i < numstring.size(); i++)
	{
		result = result + numstring[i];
	}
	return result;
}
void rotate(vector<int>& nums, int k) 
{
	int len = nums.size();
	vector<int> result;
	k = k % len;
	if (k == 0)
		return;
	
	for (int i = len - k; i < len; i++)
	{
		result.push_back(nums[i]);
	}
	for (int i = 0; i < len - k; i++)
	{
		result.push_back(nums[i]);
	}
	for (int i = 0; i < result.size(); i++)
	{
		nums[i] = result[i];
	}
}
void Other9Action()
{
    cout << "\n===========================Other9Action===========================" << endl;
	{
		int a1[] = { 1,2,3,4,5,6,7 };
		vector<int> numbers;
		for (int i = 0; i < sizeof(a1) / sizeof(int); i++)
		{
			numbers.push_back(a1[i]);
		}
		rotate(numbers,3);

		int a2[] = { -1,-100,3,99 };
		vector<int> numbers2;
		for (int i = 0; i < sizeof(a2) / sizeof(int); i++)
		{
			numbers2.push_back(a2[i]);
		}
		rotate(numbers2, 2);
	}
	{
		int a1[] = { 10,2 };
		vector<int> numbers;
		for (int i = 0; i < sizeof(a1) / sizeof(int); i++)
		{
			numbers.push_back(a1[i]);
		}
		string res = largestNumber(numbers);

		int a2[] = { 3,30,34,5,9 };
		vector<int> numbers2;
		for (int i = 0; i < sizeof(a2) / sizeof(int); i++)
		{
			numbers2.push_back(a2[i]);
		}
		string res2 = largestNumber(numbers2);

		int a3[] = { 128,12 };
		vector<int> numbers3;
		for (int i = 0; i < sizeof(a3) / sizeof(int); i++)
		{
			numbers3.push_back(a3[i]);
		}
		string res3 = largestNumber(numbers3);

		int a4[] = { 0,9,8,7,6,5,4,3,2,1 };
		vector<int> numbers4;
		for (int i = 0; i < sizeof(a4) / sizeof(int); i++)
		{
			numbers4.push_back(a4[i]);
		}
		string res4 = largestNumber(numbers4);
	}
	{
		int a1[] = { 2,7,11,15 };
		vector<int> numbers;
		vector<int> res;
		for (int i = 0; i < sizeof(a1) / sizeof(int); i++)
		{
			numbers.push_back(a1[i]);
		}
		res = twoSum(numbers, 9);
	}
    {
        string s = "the sky is blue";
        string sr = reverseWords(s);
        cout<<sr<<endl;
        ////////////////
        string s1 = "  hello world!  ";
        sr = reverseWords(s1);
        cout<<sr<<endl;
        ////////////////
        string s2 = "a good   example";
        sr = reverseWords(s2);
        cout<<sr<<endl;
    }
	{
		generate(5);
		/////////////////
		int a1[] = { 7,1,5,3,6,4 };
		vector<int> prices;
		for (int i = 0; i < sizeof(a1) / sizeof(int); i++)
		{
			prices.push_back(a1[i]);
		}
		int res = maxProfit(prices, 1);
		///////////////////
		string s1[] = { "hot","dot","dog","lot","log","cog" };
		vector<string> wordList;
		for (int i = 0; i < 6; i++)
		{
			wordList.push_back(s1[i]);
		}
		res = ladderLength("hit", "cog", wordList);
	}
    {
        vector<string> wordDict;
        wordDict.push_back("apple");
        wordDict.push_back("pen");
        bool b1 = wordBreak("applepenapple",wordDict);
        cout<<b1<<endl;
        //////////////
        wordDict.clear();
        wordDict.push_back("leet");
        wordDict.push_back("code");
        b1 = wordBreak("leetcode",wordDict);
        cout<<b1<<endl;
        //////////////
        wordDict.clear();
        wordDict.push_back("cats");
        wordDict.push_back("dog");
        wordDict.push_back("sand");
        wordDict.push_back("and");
        wordDict.push_back("cat");
        b1 = wordBreak("catsandog",wordDict);
        cout<<b1<<endl;
        //////////////
        wordDict.clear();
        wordDict.push_back("car");
        wordDict.push_back("ca");
        wordDict.push_back("rs");
        b1 = wordBreak("cars",wordDict);
        cout<<b1<<endl;
        //////////////
        wordDict.clear();
        wordDict.push_back("aaaa");
        wordDict.push_back("aaa");
        b1 = wordBreak("aaaaaaa",wordDict);
        cout<<b1<<endl;
        //////////////
        wordDict.clear();
        wordDict.push_back("bc");
        wordDict.push_back("cb");
        b1 = wordBreak("ccbb",wordDict);
        cout<<b1<<endl;
    }
    {
        char s1[] = "A man, a plan, a canal: Panama";
        bool b1 = isPalindrome(s1);
        cout<<b1<<endl;
        ///////////
        char s2[] = "race a car";
        bool b2 = isPalindrome(s2);
        cout<<b2<<endl;
        ///////////
        char s3[] = "0p";
        bool b3 = isPalindrome(s3);
        cout<<b3<<endl;
        ///////////
        ///////////
        char s4[] = "ab2a";
        bool b4 = isPalindrome(s4);
        cout<<b4<<endl;
    }
    {
        int a1[] = {1,2,3,0,0,0};
        int a2[] = {2,5,6};
        merge(a1,sizeof(a1)/sizeof(int),3,a2,sizeof(a2)/sizeof(int),3);
    }
    {
        int ar[] = {1,1,1,2};
        int ir = removeDuplicates(ar,sizeof(ar)/sizeof(int));
        cout<<ir<<endl;
    }
    {
        vector<vector<char>> board;
        vector<char> v1,v2,v3;
        char c1[] = "ABCE";
        char c2[] = "SFCS";
        char c3[] = "ADEE";
        for (int i = 0;i < sizeof(c1)/sizeof(char);i++)
            v1.push_back(c1[i]);

        for (int i = 0;i < sizeof(c2)/sizeof(char);i++)
            v2.push_back(c2[i]);

        for (int i = 0;i < sizeof(c3)/sizeof(char);i++)
            v3.push_back(c3[i]);

        board.push_back(v1);
        board.push_back(v2);
        board.push_back(v3);

        /*bool b3 = exist(board,"ABCB");
        bool b1 = exist(board,"ABCCED");
        bool b2 = exist(board,"SEE");*/
    }
	{
		StackTemplate<int> is;
		for (int i = 0; i < 100; i++)
		{
			is.push(i);
		}
		StackTemplate<int> is1;
		for (int i = 0; i < 100; i++)
			is1.push(i);

		cout << "==================end==================" << endl;
	}
	{
		vector<int> v1, v2, v3,v4;
		vector<vector<int>> matrix;
		int arr[] = { 10,5,6,7,2,8,1,9,14 };
		for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			v1.push_back(arr[i]);
		}
		matrix = GetPairSum(v1, 15);
		//////////////////////////
		matrix.clear();
		matrix = GetPairSum(v2, 15);
		/////////////////
		matrix.clear();
		v3.push_back(2);
		v3.push_back(13);
		matrix = GetPairSum(v3, 15);
		//////////////////////////
		matrix.clear();
		v1.clear();
		for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			v1.push_back(arr[i]);
		}
		matrix = GetPairSum(v1, 13);
		//////////////////
		matrix.clear();
		v4.push_back(12);
		matrix = GetPairSum(v4, 15);
	}

	{
		vector<int> v1, v2, v3;
		vector<vector<int>> matrix;
		v1.push_back(1);
		v1.push_back(1);
		v1.push_back(1);
		v2.push_back(1);
		v2.push_back(0);
		v2.push_back(1);
		v3.push_back(1);
		v3.push_back(1);
		v3.push_back(1);
		matrix.push_back(v1);
		matrix.push_back(v2);
		matrix.push_back(v3);
		setZeroes(matrix);
		/////////////////
		v1.clear();
		v2.clear();
		v3.clear();
		matrix.clear();
		v1.push_back(0);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(0);

		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		v2.push_back(2);

		v3.push_back(1);
		v3.push_back(3);
		v3.push_back(1);
		v3.push_back(5);
		matrix.push_back(v1);
		matrix.push_back(v2);
		matrix.push_back(v3);
		setZeroes(matrix);
	}
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		vector<int> v2 = plusOne(v1);
	}
    {
        string p = getPermutation(3,3);
        cout<<p<<endl;
        
        p = getPermutation(4,9);
        cout<<p<<endl;
    }
    {
        vector<int> v1,v2,v3,v4;
        v1.push_back(1);
        v1.push_back(3);
        v2.push_back(2);
        v2.push_back(6);
        v3.push_back(8);
        v3.push_back(10);
        v4.push_back(15);
        v4.push_back(18);
        vector<vector<int>> intervals,vres;
        intervals.push_back(v1);
        intervals.push_back(v2);
        intervals.push_back(v3);
        intervals.push_back(v4);
        vres = merge(intervals);
		////////////////////////////////
		v1.clear();
		v2.clear();
		v3.clear();
		v4.clear();
		intervals.clear();
		vres.clear();
		////////////////////////////////
		v1.push_back(1);
		v1.push_back(4);
		v2.push_back(0);
		v2.push_back(2);
		v3.push_back(3);
		v3.push_back(5);
		intervals.push_back(v1);
		intervals.push_back(v2);
		intervals.push_back(v3);
		vres = merge(intervals);
		//////////////////////////////
		v1.clear();
		v2.clear();
		v3.clear();
		v4.clear();
		intervals.clear();
		vres.clear();
		v1.push_back(1);
		v1.push_back(4);
		v2.push_back(4);
		v2.push_back(5);
		intervals.push_back(v1);
		intervals.push_back(v2);
		vres = merge(intervals);
    }
    
    char arr[] = " a";
    int i = lengthOfLastWord(arr);

    vector<vector<int>> result = generateMatrix(3);

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

    nums.clear();
	int n3[] = { 5,4,0,2,0,1,0,1,0 };
	for (int i = 0; i < sizeof(n3) / sizeof(int); i++)
	{
		nums.push_back(n3[i]);
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