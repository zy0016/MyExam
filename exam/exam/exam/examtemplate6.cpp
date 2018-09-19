#include "stdafx.h"
#include "template6.h"
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

template<class T> class Friendly;
template<class T> void f(const Friendly<T>&);
template<class T> class Friendly {
	T t;
public:
	Friendly(const T& theT) :t(theT) {}
	friend void f<>(const Friendly<T>&);
	void g() { f(*this); }
};

static void h() {
	f(Friendly<int>(1));
}
template<class T> void f(const Friendly<T>& fo) {
	cout << fo.t << endl;
}

void Template6Action1()
{
	cout << "\n===========================Template6Action1===========================" << endl;
	h();
	Friendly<int>(2).g();
}
void Template6Action()
{
	cout << "\n===========================Template6===========================" << endl;
	Template6Action1();
}
