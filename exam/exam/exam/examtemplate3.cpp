#include "stdafx.h"
#include "template3.h"
#include <iostream>
#include <memory>
#include <vector>
#include <complex>
#include <cstddef>
using namespace std;

template<class T> void f(T) {
	cout << "T" << endl;
}
template<class T> void f(T*) {
	cout << "T*" << endl;
}
template<class T> void f(const T*) {
	cout << "const T*" << endl;
}
void Template3Action1()
{
	cout << "\n===========================Template3Action1===========================" << endl;
	f(0);
	int i = 0;
	f(&i);
	const int j = 0;
	f(&j);
}
/////////////////////////////////////////
template<class T,class U>
class C {
public:
	void f() { cout << "Primary Template" << endl; }
};
template<class U> class C<int, U> {
public:
	void f() { cout << "T== int" << endl; }
};
template<class T> class C<T, double> {
public:
	void f() { cout << "U==double" << endl; }
};
template<class T, class U> class C<T*, U> {
public:
	void f() { cout << "T* used" << endl; }
};
template<class T, class U> class C<T, U*> {
public:
	void f() { cout << "U* used" << endl; }
};
template<class T, class U> class C<T*, U*> {
public:
	void f() { cout << "T* and U* used" << endl; }
};
template<class T> class C<T, T> {
public:
	void f() { cout << "T == U" << endl; }
};
void Template3Action2()
{
	cout << "\n===========================Template3Action2===========================" << endl;
	C<float, int>().f();
	C<int, float>().f();
	C<float, double>().f();
	C<float, float>().f();
	C<float*, float>().f();
	C<float, float*>().f();
	C<float*, int*>().f();
}
/////////////////////////////////////
class X{
public:
    void f(){}
};
class Y{
public:
    void g(){}
};
template<typename T> class Z{
    T t;
public:
    void a(){t.f();}
    void b(){t.g();}
};
void Template3Action3()
{
    cout << "\n===========================Template3Action3===========================" << endl;
    Z<X> zx;
    zx.a();
    Z<Y> zy;
    zy.b();
}


void Template3Action()
{
	cout << "\n===========================Template3===========================" << endl;
	Template3Action1();
	Template3Action2();
    Template3Action3();
}