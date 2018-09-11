#include "stdafx.h"
#include "class5.h"
#include <iostream>
#include <memory>
using namespace std;

class Top
{
    int x;
public:
    Top(int n)
    {
        x = n;
    }
};
class Left:public Top
{
    int y;
public:
    Left(int m,int n):Top(m)
    {
        y = n;
    }
};
class Right:public Top
{
    int z;
public:
    Right(int m,int n):Top(m)
    {
        z = n;
    }
};
class Bottom:public Left,public Right
{
    int w;
public:
    Bottom(int i,int j,int k,int m):Left(i,k),Right(j,k)
    {
        w = m;
    }
};

void Class5Action1()
{
    Bottom b(1,2,3,4);
    cout << sizeof b <<endl;
}

class Top2
{
protected:
    int x;
public:
    Top2(int n)
    {
        x = n;
    }
    virtual ~Top2(){}
    friend ostream& operator<<(ostream& os,const Top2& t)
    {
        return os << t.x;
    }
};
class Left2:virtual public Top2
{
protected:
    int y;
public:
    Left2(int m,int n):Top2(m)
    {
        y = n;
    }
};
class Right2:virtual public Top2
{
protected:
    int z;
public:
    Right2(int m,int n):Top2(m)
    {
        z = n;
    }
};
class Bottom2:public Left2,public Right2
{
    int w;
public:
    Bottom2(int i,int j,int k,int m):Top2(i),Left2(0,k),Right2(0,k)
    {
        w = m;
    }
    friend ostream& operator<<(ostream& os,const Bottom2& b)
    {
        return os <<b.x<<",s"<<b.y<<","<<b.z<<","<<b.w<<endl;
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