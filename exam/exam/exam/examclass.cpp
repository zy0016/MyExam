#include "stdafx.h"
#include <iostream>
using namespace std;

#if 0
class Pet1
{
public:
    virtual ~Pet1(){}
};
class Dog1 : public Pet1{};
class Cat : public Pet1{};
#endif
class Pet1
{
public:
    virtual ~Pet1() = 0;
};
Pet1::~Pet1()
{
    cout << "~Pet1()\n";
}
class Dog1 : public Pet1
{
public:
    ~Dog1()
    {
        cout << "~Dog1()\n";
    }
};
class Cat : public Pet1
{
    
};
//////////////////////////////////////////////
class Base
{
private:
    int i;
protected:
    int k;
public:
    int j;
    Base()
    {
        cout << "Base constructor" << endl;
    }
    Base(Base &b)
    {
        cout << "Base copy constructor" << endl;
    }
    inline int geti(int j)
    {
        return i;
    }
    virtual ~Base()
    {
        cout << "Base destructor" << endl;
    }
    virtual void id ()
    {
        cout << "id() In base" << endl;
    }
};
class D : public Base
{
public:
    void testi()
    {
//        i = 0;
        j = 0;
        k = 0;
    }
    D ()
    {
        cout << "D constructor" << endl;
    }
    D (D &d)
    {
        cout << "D copy constructor" << endl;
    }
    virtual ~D()
    {
        cout << "D destructor" << endl;
    }
    virtual void id ()
    {
        cout << "id() In D" << endl;
    }
    /*virtual void Dfunction()
    {
    }*/
};

void foo(Base b)
{
    cout << "foo" << endl;
    b.id();
}
void bar (Base &b)
{
    cout << "bar" << endl;
    b.id();
}
/////////////////////////////////////////////
class BB
{
    int i;
public:
    //virtual ~BB(){ out <<"BB::~BB()"<<endl; }
};

class BB2
{
    int i;
public:
    virtual ~BB2(){ cout <<"BB::~BB()"<<endl; }
};
 
class DD : public BB2
{
    int i;
    int j;
public:
    virtual ~DD() { cout <<"DD::DD~()"<<endl; }
};
/////////////////////////////////////////////
class Base_const
{
    int m;
public:
    Base_const(int a) { m = a; }
 
    void SetValue(int a) { m = a; }
 
    int GetValue() const { cout<<"const\n"; return m; }
    int GetValue() { cout<<"non-const\n"; return m; }
};

class Base_1
{
public:
    int m_nPublic;    // can be accessed by anybody
//    void fun(Base &c) { };
private:
    int m_nPrivate;   // can only be accessed by Base member 
protected:
    int m_nProtected; // can be accessed by Base member or derived
};

class D2 : protected Base_1 {
public:
    D2() {
        m_nPublic = 1;
        m_nProtected = 2;
//        m_nPrivate = 3; // error: ‘int Base::m_nPrivate?is private
    };
};
/////////////////////////////////////////////
void Action1()
{
    Pet1 *p = new Dog1;
    delete p;
}
void Action2()
{
    Pet1 *b = new Cat;
    Dog1 *d1 = dynamic_cast<Dog1*>(b);
    Cat *d2 = dynamic_cast<Cat*>(b);
    cout << "d1= " <<(long)d1 <<endl;
    cout << "d2= " <<(long)d2 <<endl;
}
void Action3()
{
    const Base_const b1(19); 
    b1.GetValue(); 
    //b1.SetValue(6); //error C2662: 'SetValue' : cannot convert 'this' pointer from 'const class Base_const' to 'class Base_const &'

    Base_const b22(42); 
    b22.GetValue(); 
    b22.SetValue(6); 
}
void Action4()
{
    cout << endl << "------------->>>>>>>>>>>>>>>>>>>>" << endl;
    D d;
    cout << "1"<< endl;
    foo(d);
    cout << "2"<< endl;
    bar(d);
    cout << "end!" << endl;
}
void Action5()
{
    cout << endl << "------1-------" << endl;
    D d;
    Base *p1 = &d;
    Base &p2 = d;
    Base *pd = new D;
    Base p3;

    p1->id();
    p2.id();
    p3.id();
    //pd->Dfunction();
}
void Action6()
{
    cout << endl << "----2---------" << endl;
    D d;
    Base *pb = new D();
    delete pb;
    cout << "end!" << endl;
}
void Action7()
{
    cout << endl << "----3---------" << endl;
    Base *p = new D();
    delete p;
}
void Action8()
{
    Pet1 * bp = new Cat;
    //Dog1 * d1 = dynamic_cast<Dog1*>(bp);
    Cat * d2 = dynamic_cast<Cat*>(bp);

    cout << endl;
    //cout << "d1=" << (long)d1 <<endl;
    cout << "d2=" << (long)d2 <<endl;
}
void Action9()
{
    int i = sizeof(BB);
    cout << i << endl;
}
void Action10()
{
    cout << "sizeBB2:" << sizeof(BB2) << " sizeDD:"<< sizeof(DD) <<endl;
    BB2* pb = new DD[2];
    delete[] pb;
}
void Action11()
{
    Base base;
    D2 d2;
}
void ClassAction()
{
    cout << "\n===========================Class===========================" << endl;
    Action1();
    Action2();
    Action3();
    Action4();
    Action5();
    Action6();
    Action7();
    Action8();
    Action9();
    Action10();
}
