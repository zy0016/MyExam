#include "stdafx.h"
#include "template4.h"
#include <iostream>
#include <memory>
#include <vector>
#include <complex>
#include <cassert>
#include <cstddef>
using namespace std;
using std::cout;
using std::endl;
void f(double) { 
	cout << "f(double)" << endl; 
}

template<class T>
class X {
public:
	void g() { 
		f(1); 
	}
};
void f(int) { 
	cout << "f(int)" << endl; 
}

void Template4Action1()
{
	cout << "\n===========================Template4Action1===========================" << endl;
	X<int>().g();
}
void Template4Action()
{
	cout << "\n===========================Template4===========================" << endl;
	Template4Action1();
}
