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
    int i = 0,j = 0;
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
    for(int k = 0;k < word.length();k++)
    {
        char c = word[k];
        char cnext = '\0';
        if (k < word.length() - 1)
            cnext = word[k + 1];
        if (c == board[j][i])
        {
            if (i > 0)
            {
                if (cnext == board[j][i - 1])
                {
                    i--;
                    continue;
                }
            }
            if (i < r)
            {
                if (cnext == board[j][i + 1])
                {
                    i++;
                    continue;
                }
            }
            if (j > 0)
            {
                if (cnext == board[j - 1][i])
                {
                    j--;
                    continue;
                }
            }
            if (j < b)
            {
                if (cnext == board[j + 1][i])
                {
                    j++;
                    continue;
                }
            }
        }
    }
    while(true)
    {
        
    }
    return false;
}
void Other9Action()
{
    cout << "\n===========================Other9Action===========================" << endl;
    {
        vector<vector<char>> board;
        vector<char> v1,v2,v3;
        char c1[] = "ABCE";
        char c2[] = "SFCS";
        char c3[] = "ADEE";
        for (int i = 0;i < sizeof(c1)/sizeof(char);i++)
            v1.push_back(c1[i]);

        for (int i = 0;i < sizeof(c2)/sizeof(char);i++)
            v1.push_back(c2[i]);

        for (int i = 0;i < sizeof(c3)/sizeof(char);i++)
            v1.push_back(c3[i]);

        board.push_back(v1);
        board.push_back(v2);
        board.push_back(v3);

        exist(board,"ABCCED");
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