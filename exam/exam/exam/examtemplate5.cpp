#include "stdafx.h"
#include "template5.h"
#include <iostream>
#include <memory>
#include <vector>
#include <complex>
#include <cassert>
#include <cstddef>
#include <typeinfo>
#include <algorithm>
using namespace std;
using std::cout;
using std::endl;

void g() { 
	cout << "global g()" << endl;
}
template<class T> class Y {
public:
	void g() {
		cout << "Y<" << typeid(T).name() << ">::g()" << endl;
	}
	void h() {
		cout << "Y<" << typeid(T).name() << ">::h()" << endl;
	}
	typedef int E;
};
typedef double E;
template<class T> void myswap(T& t1, T& t2) {
	cout << "global myswap" << endl;
	T temp = t1; t1 = t2; t2 = temp;
}
template<class T>class X :public Y<T> {
public:
	E f() {
		g();
		this->h();
		T t1 = T(), t2 = T(1);
		cout << t1 << endl;
		myswap(t1, t2);
		cout << typeid(E).name() << endl;
		return E(t2);
	}
};

void Template5Action1()
{
	cout << "\n===========================Template5Action1===========================" << endl;
	X<int> x;
	cout << x.f() << endl;
}
///////////////////////////////////
class Friendly {
	int i;
public:
	Friendly(int theInt) { i = theInt; }
	friend void f(const Friendly&k);
	void g() { 
		f(*this); 
	}
};
void h() {
	f(Friendly(1));
}
void f(const Friendly& fo) {
	cout << fo.i << endl;
}
void Template5Action2()
{
	cout << "\n===========================Template5Action2===========================" << endl;
	h();
	Friendly(2).g();
}
void Template5Action()
{
	cout << "\n===========================Template5===========================" << endl;
	Template5Action1();
	Template5Action2();
}
