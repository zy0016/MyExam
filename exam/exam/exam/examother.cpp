#include "stdafx.h"
#include "other.h"
#include <iostream>
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
    printf("&s = %x\n", pt->s); 
    printf("&i = %x\n", &pt->i); 
    printf("&c = %x\n", &pt->c);
    printf("&p = %x\n", &pt->p);
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
}
void OtherAction13()
{
	int f = 30;
	double i = fibonacci(50);
	cout << "fibonacci(" <<f<< ")=" << i << endl;
}
void OtherAction()
{
    cout << "\n===========================Other===========================" << endl;
	
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
}

//int solution(int A[], int N) {
//    // write your code in C99
//    int i,j,temp,ib;
//    int bSwap = 0;
//    for (i = 1;i < N;i++)
//    {
//        if (A[i - 1] > A[i])
//        {
//            if (bSwap == 0)
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
//                bSwap = 1;
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
