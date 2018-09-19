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
	cout << "\n===========================TemplateAction1===========================" << endl;
    cout<<"Factorial:"<<Factorial<12>::val<<endl;
}
///////////////////////////////////////////
template<class T = int,size_t N = 100>
class Stack {
	T data[N];
	size_t count;
public:
	void push(const T&t) {}
};
Stack<> myStack;
//////////////////////////////////////////

//////////////////////////////////////////
template<class T>
class Array {
	enum {INIT = 10};
	T* data;
	size_t capacity;
	size_t count;
public:
	Array() {
		count = 0;
		data = new T[capacity = INIT];
	}
	~Array() { delete[]data; }
	void push_back(const T& t) {
		if (count == capacity) {
			size_t newCap = 2 * capacity;
			T * newData = new T[newCap];
			for (size_t i = 0; i < count; i++)
				newData[i] = data[i];
			delete[]data;
			data = newData;
			capacity = newCap;
		}
		data[count++] = t;
	}
	void pop_back() {
		if (count > 0)
			--count;
	}
	T* begin() { return data; }
	T* end() { return data + count; }
};
template<class T,template<class> class Seq>
class Container {
	Seq<T> seq;
public:
	void append(const T& t) { seq.push_back(t); }
	T* begin() { return seq.begin(); }
	T* end() { return seq.end(); }
};
void TemplateAction2()
{
	cout << "\n===========================TemplateAction2===========================" << endl;
	Container<int, Array> container;
	container.append(1);
	container.append(2);
	int *p = container.begin();
	while (p != container.end())
		cout << *p++ << endl;
}
void TemplateAction3()
{
	cout << "\n===========================TemplateAction3===========================" << endl;
	Urand<10> u;
	for (int i = 0; i < 20; i++)
		cout << u() << ' ';
}
////////////////////////////////////////
template<class T>
class Counted {
	static int count;
public:
	Counted() { ++count; }
	Counted(const Counted<T>&) { ++count; }
	~Counted() { --count; }
	static int getCount() { return count; }
};
template<class T> int Counted<T>::count = 0;
class CountedClass :public Counted<CountedClass> {};
class CountedClass2 :public Counted<CountedClass2> {};
void TemplateAction4()
{
	cout << "\n===========================TemplateAction4===========================" << endl;
	CountedClass a;
	cout << CountedClass::getCount() << endl;
	CountedClass b;
	cout << CountedClass::getCount() << endl;
	CountedClass2 c;
	cout << CountedClass2::getCount() << endl;
}
///////////////////////////
template<int n>struct Fib {
	enum{val = Fib<n-1>::val+Fib<n-2>::val};
};
template<> struct Fib<1> { enum { val = 1 }; };
template<> struct Fib<0> { enum { val = 0 }; };
void TemplateAction5()
{
	cout << "\n===========================TemplateAction5===========================" << endl;
	cout << Fib<5>::val << endl;
	cout << Fib<20>::val << endl;
}
void TemplateAction()
{
    cout << "\n===========================Template1===========================" << endl;
    TemplateAction1();
	TemplateAction2();
	TemplateAction3();
	TemplateAction4();
	TemplateAction5();
}
