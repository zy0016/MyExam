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
void OtherAction1()
{
    char des[20] = "";
    solve("9", des,8);
    printf("des:%s", des);
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
}