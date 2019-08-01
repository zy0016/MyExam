#ifndef _OTHER_STRUCTOR_
#define _OTHER_STRUCTOR_
#include <fstream>
#include <string>
#include "stdlib.h"
#include <time.h> 
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

struct str1{
    int len;
#if 1
    char s[1];
#else
    char s[0];
#endif
    //char *s;
};
struct foo {
    struct str1 *a;
};
struct test
{
    int i;
    short c;
    char *p;
    char s[10];
};
struct Test
{
    Test(int){}
    Test(){}
    void func(){}
};

//union
//{
//    int i;
//    char x[2];
//}au;
char * Trim(char * pStr);
void OtherAction();
//int solution(int A[], int N);
#endif 