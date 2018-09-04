#include "stdafx.h"
#include "template1.h"
#include <iostream>
using namespace std;

template<int n> struct Factorial{
    enum
    {
        val = Factorial<n - 1>::val * n
    };
};
template<> struct Factorial<0>{
    enum{ val = 1};
};

void TemplateAction1()
{
    cout<<Factorial<3>::val<<endl;
}
void TemplateAction()
{
    cout << "\n===========================Template1===========================" << endl;
    TemplateAction1();
}