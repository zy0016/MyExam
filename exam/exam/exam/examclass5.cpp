#include "stdafx.h"
#include "class5.h"
#include <iostream>
#include <memory>
using namespace std;

class testclass {
public:
	testclass() = default;
};

class Top
{
    int t;
public:
    Top(int n)
    {
        t = n;
    }
};
class Left:public Top
{
    int l;
public:
    Left(int m,int n):Top(m)
    {
        l = n;
    }
};
class Right:public Top
{
    int r;
public:
    Right(int m,int n):Top(m)
    {
        r = n;
    }
};
class Bottom:public Left,public Right
{
    int b;
public:
    Bottom(int i,int j,int k,int m):Left(i,k),Right(j,k)
    {
        b = m;
    }
};

void Class5Action1()
{
    Bottom b(1,2,3,4);
    cout << sizeof b <<endl;
}
///////////////////////////////////////////////////////////
class Top2
{
protected:
    int t;
public:
    Top2(int n)
    {
        t = n;
    }
    virtual ~Top2(){}
    friend ostream& operator<<(ostream& os,const Top2& t)
    {
        return os << t.t;
    }
};
class Left2:virtual public Top2
{
protected:
    int l;
public:
    Left2(int m,int n):Top2(m)
    {
        l = n;
    }
};
class Right2:virtual public Top2
{
protected:
    int r;
public:
    Right2(int m,int n):Top2(m)
    {
        r = n;
    }
};
class Bottom2:public Left2,public Right2
{
    int b;
public:
    Bottom2(int i,int j,int k,int m):Top2(i),Left2(0,k),Right2(0,k)
    {
        b = m;
    }
    friend ostream& operator<<(ostream& os,const Bottom2& b)
    {
        return os <<b.t<<","<<b.l<<","<<b.r<<","<<b.b<<endl;
    }
};
void Class5Action2()
{
    cout<<"===========Class5Action2=========="<<endl;
    Bottom2 b(1,2,3,4);
    cout<<sizeof b<<endl;
    cout<<b<<endl;
    cout<<static_cast<void*>(&b)<<endl;
    Top2 *p = static_cast<Top2*>(&b);
    cout<<*p<<endl;
    cout<<static_cast<void*>(p)<<endl;
    cout<<dynamic_cast<void*>(p)<<endl;
}
void Class5Action()
{
	cout << "\n===========================Class5===========================" << endl;
	Class5Action1();
    Class5Action2();
}