﻿#include "stdafx.h"
#include "other.h"
#include <iostream>
#include <set>
#include <list>
#include <map>
using namespace std;

void testpoint()
{
    struct test
    {
        int i;
        short c;
        char *p;
        char s[10];
    };
    struct test *pt=NULL;
    printf("\n");
    printf("&i = %x\n", &pt->i); //??????????????&(pt->i)
    printf("&c = %x\n", &pt->c);
    printf("&p = %x\n", &pt->p);
    printf("&s = %x\n", &pt->s); //??? printf("%x\n", &(pt->s) );
	printf("&s = %x\n", pt->s); //??? printf("%x\n", &(pt->s) );
}

void solve(char *source, char * des,int n)
{
    int sour_len = strlen(source);
    int i;
    
    if (sour_len == n)
    {
        strcpy(des,source);
        return;
    }
    if (sour_len > n)
    {
        strncpy(des,source, n);
        return;
    }
    strcpy(des,source);
    for (i = 0;i < n - sour_len ;i++)
    {
        strcat(des,"0");
    }
}
void SpecialOutput()
{
    int line = 10;
    int i,j,k;
    for (i = 0;i < line;i++)
    {
        for (j = line - i;j >= 0;j--)
        {
            printf(" ");
        }
        for (j = 0;j < i;j++)
        {
            printf("*");
        }
        for (k = 1; k < j;k++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    
    char lets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0;i < line;i++)
    {
        for (j = line - i;j >= 0;j--)
        {
            printf(" ");
        }
        for (j = 0;j < i;j++)
        {
            printf("%c", lets[j]);
        }
        for (k = 1; k < j;k++)
        {
            printf("%c", lets[j - k - 1]);
        }
        printf("\n");
    }
}

char * Trim(char * pStr)
{
    char * pBegin = NULL,* pSetp = NULL,* pEnd = NULL;
    unsigned int iLen,i = 0;

    if (pStr == NULL)
        return NULL;

    iLen = strlen(pStr);
    if (0 == iLen)
        return pStr;

    pBegin = pStr;
    if (* pBegin == ' ')
    {
        pSetp = pStr;
        while ((* pSetp == ' ') && (i < iLen))
        {
            pSetp++;
            i++;
        }
        if (i == iLen)
        {
            * pBegin = '\0';
            return pStr;
        }
        
        while (* pSetp != '\0')
        {
            * pBegin++ = * pSetp;
            * pSetp++ = ' ';
        }
    }
    pEnd = pStr + iLen - 1;
    while ((* pEnd == ' ') && (iLen-- > 0))
        * pEnd-- = '\0';

    return pStr;
}

int bitcount(unsigned int x)
{
    int b;
    for (b = 0;x != 0 ; x>>=1)
    {
        if (x & 01)
            b ++;
    }
    return b;
}
void reserve(char a[])
{
    int len = strlen(a);
    int i,j;
    for (i = 0,j = len - 1;i < len / 2;i++,j--)
    {
        char temp;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
double fibonacci(int n)
{
	double temp[2];
	double tp;
    temp[0] = 1;
    temp[1] = 1;
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i < n; i ++)
        {
			/*if (LONG_MAX - temp[0] < temp[1])
			{
				double longmax = LONG_MAX;
				cout << "temp[0]=" << temp[0] << ",temp[1]=" << temp[1] << ",LONG_MAX="<< longmax << endl;
				return -1;
			}*/
            tp = temp[0] + temp[1];
            temp[1] = temp[0];
            temp[0] = tp;
        }
        return temp[0];
    }
}
int symetry(char * str)
{
    char *pbegin,*pend;
    int middle = strlen(str) / 2 - 1;
    int i = 0;
    pbegin = str;
    pend = str + strlen(str) - 1;
    while (i < middle && *pbegin != '\0')
    {
        if (*pbegin != *pend)
            return 0;
        pbegin++;
        pend--;
        i++;
    }
    return 1;
}
void testreference()
{
    int i = 10,k = 21;
    int &j1 = i;
    j1 = k;
    j1 = 3;

    printf("i:%d,j1:%d,k:%d\n",i,j1,k);
    //////////////////////////////////////////////////////////////////////////
    int it = 0,it2 = 9;
    int& j = it;
    printf("j:%d\n",j);
    j = it2;
    printf("j:%d\n",j);
    j = 1000;
    printf("it2:%d\n",it2);
    printf("it:%d\n",it);
}
void outputpair(int arr[],int size,int sum)
{
    int i,j;
    for (i = 0;i < size - 1;i++)
    {
        for (j = i + 1;j < size;j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                printf("%d+%d=%d\n",arr[i],arr[j],sum);
            }
        }
    }
}
int &put(int n);  
int vals[10];  
int error=-1;  
int &put(int n)  
{  
    if (n>=0 && n<=9 ) 
        return vals[n];  
    else 
    { 
        cout<<"subscript error"; 
        return error; 
    }  
}  
void reverence()
{
    put(0)=10; //?put(0)???????,???vals[0]=10;  
    put(9)=20; //?put(9)???????,???vals[9]=20;
}
void OtherAction1()
{
    char des[20] = "";
    solve("9", des,8);
    printf("des:%s", des);
}

void OtherAction2()
{
    int k = symetry("1122131");
    printf("\nk=%d\n",k);
}
void OtherAction3()
{
    char string[] = "    3    ";
    Trim(string);
    printf("trim:%s!\n",string);
}
void OtherAction4()
{
    int bcount = bitcount(3);
    cout << "bcount:" << bcount << endl;
}
void OtherAction5()
{
    char astr[] = "1234567890";
    reserve(astr);
    printf("%s\n",astr);
}
void OtherAction6()
{
    int x = 1, k = 4;
    if(*(char *)&x == 1) 
        printf("little-endian\n"); 
    else 
        printf("big-endian\n");  
}
void OtherAction7()
{
    testreference();
}
void OtherAction8()
{
    static int a[] = {0,1,2,3};
    int *ptr[] = {a,a+1,a+2,a+3};
    int **pptr = ptr;
    pptr++;
    printf("%d %d %d, ", pptr-ptr, *pptr - a, **pptr);
    pptr++;
    printf("%d %d %d, ", pptr-ptr, *pptr - a, **pptr);
    pptr++;
    printf("%d %d %d, ", pptr-ptr, *pptr - a, **pptr);
}
void OtherAction9()
{
    struct foo f={0};
    if (f.a->s) 
    {
        //printf( f.a->s);
    }
    /////////////////////
    struct test *pt=NULL;
	printf("\n");
    printf("&s = %x\n", pt->s); 
    printf("&i = %x\n", &pt->i); 
    printf("&c = %x\n", &pt->c);
    printf("&p = %x\n", &pt->p);
	//printf("&i = %x\n", pt->p);
    ////////////////////
    Test a1(1);
    a1.func();
    Test a2;
    a2.func();
}
void OtherAction10()
{
    int arr[] = {1,2,3,4,7,9,12,8,0};
    int size = sizeof(arr)/sizeof(int);
    int sum = 9;
    outputpair(arr,size,sum);
}
void OtherAction11()
{
    reverence();
}
void OtherAction12()
{
    /*au.x[0] = 10;
    au.x[1] = 1;
    printf("au.i:%d\n",au.i);*/

    //int a[] = {1, 3, 5, 3, 4};
    //solution(a,sizeof(a)/sizeof(a[0]));
    
    int *pt;
    int (*pa)[3];
    int a1[2][3];
    int a2[3][2];
    int **p2;
    pt = a2[0];
    p2 = &pt;
    {
        int a[5];
        printf("%x\n", a);
        printf("%x\n", a+1);
        printf("%x\n", &a);
        printf("%x\n", &a+1);
    }
    int a4[5] = {1,2,3,4,5};
    int *ptr = (int*)(&a4 + 1);
    {
        int a = 247, b = 4;
        int const c = 21;
        const int *d = &a;

        int * const e = &b;
        //int const *f const = &a;

        a = 12;
        d = NULL;
    }
    {
        int N = 11;
        int s = 0;
        for (int i = 2; i <= N;i++)
        {
            s = (s + 3) % i;
        }
        printf("s:%d\n",s);
    }
    {
        unsigned short A = 10;
        printf("~A=%u\n", ~A);
        char c = 128;
        printf("c=%d\n",c);
    }
    {
        float a3 = 1.0f; 
        cout << endl;
        cout << (int)a3 << endl; 
        cout << (int&)a3 << endl;
    }
#ifdef CPLUSPLUS_11
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "begin" << endl;
	for (auto i : a) 
	{
		cout << i << endl;
	}
	cout <<"end"<< endl;
#endif
}
void OtherAction13()
{
	cout << "\n===========================OtherAction13===========================" << endl;
	int f = 30;
	double i = fibonacci(50);
	cout << "fibonacci(" <<f<< ")=" << i << endl;
	////////////////////////////////
	vector<int> vec;
	vec.push_back(20);
	vec.push_back(10);
#ifdef CPLUSPLUS_11
	for (int &i : vec)
	{
		cout << i << endl;
	}
#endif
}
void OtherAction14()
{
	cout << "\n===========================OtherAction14===========================" << endl;
#ifdef CPLUSPLUS_11
	vector<string> v6 = { "hi","my","name","is","lee" };
	for (vector<string>::iterator iter = v6.begin(); iter != v6.end(); iter++)
	{
		cout << *iter << endl;
		//下面两种方法都行
		cout << (*iter).empty() << endl;
		cout << iter->empty() << endl;
	}
	for (vector<string>::reverse_iterator iter = v6.rbegin(); iter != v6.rend(); iter++)
	{
		cout << *iter << endl;
	}
#endif
}
template <typename T>
void showvector(vector<T> v)
{
	for (vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
}
void OtherAction15()
{
	cout << "\n===========================OtherAction15===========================" << endl;
#ifdef CPLUSPLUS_11
	vector<string> v6 = { "hi","my","name","is","lee" };
	v6.resize(3);  //重新调整vector容量大小
	showvector(v6);

	vector<int> v5 = { 1,2,3,4,5 }; //列表初始化,注意使用的是花括号
	cout << v5.front() << endl; //访问第一个元素
	cout << v5.back() << endl; //访问最后一个元素

	showvector(v5);
	v5.pop_back(); //删除最后一个元素
	showvector(v5);
	v5.push_back(6); //加入一个元素并把它放在最后
	showvector(v5);
	v5.insert(v5.begin() + 1, 9); //在第二个位置插入新元素
	showvector(v5);
	v5.erase(v5.begin() + 3);  //删除第四个元素
	showvector(v5);
	v5.insert(v5.begin() + 1, 7, 8); //连续插入7个8
	showvector(v5);
	v5.clear(); //清除所有内容
	showvector(v5);

	//system("pause");
#endif
}

template <typename T>
void showset(set<T> v)
{
	for (set<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
}
void OtherAction16()
{
	cout << "\n===========================OtherAction16===========================" << endl;
#ifdef CPLUSPLUS_11
	set<int> s1{ 9,8,1,2,3,4,5,5,5,6,7,7 }; //自动排序，从小到大,剔除相同项
	showset(s1);
	set<string> s2{ "hello","sysy","school","hello" }; //字典序排序
	showset(s2);
	s1.insert(9); //有这个值了，do nothing
	showset(s1);
	s2.insert("aaa"); //没有这个字符串，添加并且排序
	showset(s2);
#endif
}

template <typename T>
void showlist(list<T> v)
{
	for (list<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl;
}
void OtherAction17()
{
	cout << "\n===========================OtherAction17===========================" << endl;
#ifdef CPLUSPLUS_11
	list<int> l1{ 1,2,3,4,5,5,6,7,7 ,0};
	showlist(l1);
	l1.sort();
	list<double> l2;
	list<char> l3(10);
	list<int> l4(5, 10); //将元素都初始化为10
	showlist(l4);
#endif
}

void showmap(map<string, int> v)
{
	for (map<string, int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;  //注意用法，不是用*it来访问了。first表示的是key，second存的是value
	}
	cout << endl;
}
void OtherAction18()
{
	cout << "\n===========================OtherAction18===========================" << endl;
	map<string, int> m1; //<>里的第一个参数表示key的类型,第二个参数表示value的类型
	m1["Kobe"] = 100;
	m1["James"] = 99;
	m1["Curry"] = 98;

	string s("Jordan");
	m1[s] = 90;

	cout << m1["Kobe"] << endl;
	cout << m1["Jordan"] << endl;
	cout << m1["Durant"] << endl; //不存在这个key，就显示0

	m1.erase("Curry");//通过关键字来删除
	showmap(m1);
	m1.insert(pair<string, int>("Harris", 89)); //也可以通过insert函数来实现增加元素
	showmap(m1);
	m1.clear(); //清空全部
}

void OtherAction()
{
    cout << "\n===========================OtherAction===========================" << endl;
	int *p = NULL;
	int i = sizeof(void*);
    auto a = 10;
    decltype(i) b = 2;

    testpoint();
    OtherAction1();
    SpecialOutput();
    OtherAction2();
    OtherAction3();
    OtherAction4();
    OtherAction5();
    OtherAction6();
    OtherAction7();
    OtherAction8();
    OtherAction9();
    OtherAction10();
    OtherAction11();
    OtherAction12();
	OtherAction13();
	OtherAction14();
	OtherAction15();
	OtherAction16();
	OtherAction17();
	OtherAction18();
}

//int solution(int A[], int N) {
//    // write your code in C99
//    int i,j,temp,ib;
//    int bmyswap = 0;
//    for (i = 1;i < N;i++)
//    {
//        if (A[i - 1] > A[i])
//        {
//            if (bmyswap == 0)
//            {
//                for (j = i + 1;j < N;j++)
//                {
//                    if (A[i] > A[j])
//                        continue;
//                    else
//                    {
//                        ib = i;
//                        i = j;
//                        break;
//                    }    
//                }
//                temp = A[i - 1];
//                A[i - 1] = A[i];
//                A[i] = temp;
//                bmyswap = 1;
//                i = ib;
//            }
//            else
//            {
//                return 0;
//            }
//        }
//    }
//    return 1;
//}
//#if 0
//int solution(int A[], int N) {
//    // write your code in C99
//    int i,j;
//    int sum = 0,sumbak = -1;
//    for (i = 0;i < N;i++)
//    {
//        if (A[i] >= 0)
//        {
//           for (j = i;j < N && A[j] >= 0;j++)
//           {
//                sum = sum + A[j];
//           }
//           if (sum > sumbak)
//                sumbak = sum;
//           sum = 0;
//           i = j;
//        }
//    }
//    return sumbak;
//}
//#endif
