#include "stdafx.h"
#include "class3.h"
#include <iostream>
using namespace std;

class HowMany2
{
    string name;
    static int objectCount;
public:
    HowMany2(const string& id = "") : name(id)
    {
        ++objectCount;
        //print("HowMany2()");
        cout << "HowMany2()" << endl;
    }
    ~HowMany2()
    {
        --objectCount;
        //print("~HowMany2()");
        cout << "~HowMany2()" << endl;
    }
    HowMany2(const HowMany2& h) : name(h.name)
    {
        name += " Copy";
        ++objectCount;
        //print("HowMany2(const HowMany2&");
        cout << "HowMany2(const HowMany2&" << endl;
    }
    void print(const string& msg = "") const
    {
        if (msg.size() != 0)
            cout << msg <<endl;
        cout << '\t' << name << ": " << "objectCount = " << objectCount << endl;
    }
};
int HowMany2::objectCount = 0;

HowMany2 f(HowMany2 x)
{
    //x.print("x argument inside f()");
    cout << "Returning from f()" << endl;
    return x;
}
void Class3Action1()
{
    HowMany2 h("h");
    cout << "Entering f()" << endl;
    HowMany2 h2 = f(h);
    //h2.print("h2 after call to f()");
    cout << "h2 after call to f()" << endl;
    cout << "Call f(),no return value" << endl;
    f(h);
    cout << "After call to f()" << endl;
}
/////////////////////////
class WithCC
{
public:
    WithCC() {}
    WithCC(const WithCC&)
    {
        cout << "WithCC(WithCC&" << endl;
    }
};
class WoCC
{
    string id;
public:
    WoCC(const string& ident = "") : id(ident)
    {
        cout << id << endl;
    }
    void print(const string& msg = "") const
    {
        if (msg.size() != 0)
            cout << msg << ": ";
        cout << id << endl;
    }
};

class Composite
{
    WithCC withcc;
    WoCC wocc;
public:
    Composite() : wocc("Composite()") {}
    void print(const string& msg = "") const
    {
        wocc.print(msg);
    }
};
void Class3Action2()
{
    Composite c;
    c.print("Contents of c");
    cout << "Calling composite copy-constructor" << endl;
    Composite c2=c;
    c2.print("Contents of c2");
}

/////////////////////////////////////////
class Base
{
public:
    int f() const
    {
        cout << "Base::f()\n";
        return 1;
    }
    int f(string) const
    {
        return 1;
    }
    int f(int) const
    {
        cout << "Base::f()\n";
        return 4;
    }
    void g()
    {
        cout << "Base::g()\n";
    }
};

class Derived1 : public Base
{
public:
    void g() const
    {
        cout << "Derived1::g()\n";
    }
};

class Derived2 : public Base
{
public:
    int f() const
    {
        cout << "Derived2::f()\n";
        return 2;
    }
};

class Derived3 : public Base
{
public:
    void f() const
    {
        cout << "Derived3::f()\n";
    }
};

class Derived4 : public Base
{
public:
    int f(int) const
    {
        cout << "Derived4::f()\n";
        return 4;
    }
};
void Class3Action3()
{
    string s("hello");
    Derived1 d1;
    int x = d1.f();
    d1.f(s);
    Derived2 d2;
    x = d2.f();
//    d2.f(s);
    Derived3 d3;
//    x = d3.f();
    Derived4 d4;
//    x = d4.f();
    x = d4.f(1);
}
//////////////////////////////
class Pet
{
    string pname;
public:
    Pet(const string& petName) : pname(petName)
    {
        cout << "Pet::PetName=" << pname << endl;
    }
    virtual string name() const
    {
        return pname;
    }
    virtual string speak() const
    {
        return "Pet speak";
    }
    /*virtual string sit() const
    {
        return pname + " sits";
    }*/
};
class Dog : public Pet
{
    string name;
public:
    Dog(const string& petName) : Pet(petName)
    {
        cout << "Dog::PetName=" << petName << endl;
    }
    string sit() const
    {
        return Pet::name() + " sits";
    }
    string speak() const
    {
        return Pet::name() + " says 'Bark!'" ;
    }
};
void Class3Action4()
{
    Pet *p[] = {new Pet("generic") , new Dog("bob")};
    cout << "p[0]->speak()=" << p[0]->speak() << endl;
    cout << "p[1]->speak()=" << p[1]->speak() << endl;
    cout << "p[1]->sit()=" << ((Dog*)p[1])->sit() << endl;
    //cout << "p[1]->sit()=" << p[1]->sit() << endl;

    //delete p;
    delete p[0];
    delete p[1];
}
///////////////////////////////////////////////
class Base1
{
public:
    ~Base1()
    {
        cout << "~Base1()\n";
    }
};
class Derived11 : public Base1
{
public:
    ~Derived11()
    {
        cout << "~Derived11()\n";
    }
};
class Base2
{
public:
    virtual ~Base2()
    {
        cout << "~Base2()\n";
    }
};
class Derived22 : public Base2
{
public:
    ~Derived22()
    {
        cout << "~Derived22()\n";
    }
};
void Class3Action5()
{
    Base1 *bp = new Derived11;
    delete bp;
    Base2 *b2p = new Derived22;
    delete b2p;
}
void Class3Action()
{
    cout << "\n===========================Class3===========================" << endl;
    Class3Action1();
    Class3Action2();
    Class3Action3();
    Class3Action4();
    Class3Action5();
	cout << "\n===========================Class3 over===========================" << endl;
}
///////////////////////////////
