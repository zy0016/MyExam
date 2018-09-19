#include "stdafx.h"
#include "template3.h"
#include <iostream>
#include <memory>
#include <vector>
#include <complex>
#include <cassert>
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
///////////////////////////////////////////////
template<class T>
class Stack {
	T * data;
	std::size_t count;
	std::size_t capacity;
	enum {INIT = 5};
public:
	Stack() {
		count = 0;
		capacity = INIT;
		data = new T[INIT];
	}
	void push(const T& t) {
		if (count == capacity) {
			std::size_t newCapcity = 2 * capacity;
			T * newData = new T[newCapcity];
			for (size_t i = 0; i < count; i++)
				newData[i] = data[i];
			delete[]data;
			data = newData;
			capacity = newCapcity;
		}
		assert(count < capacity);
		data[count++] = t;
	}
	void pop(){
		assert(count > 0);
		--count;
	}
	T top() const {
		assert(count > 0);
		return data[count - 1];
	}
	std::size_t size() const { return count; }
};
template<> class Stack<void *> {
	void** data;
	std::size_t count;
	std::size_t capacity;
	enum{INIT=5};
public:
	Stack() {
		count = 0;
		capacity = INIT;
		data = new void*[INIT];
	}
	void push(void* const &t) {
		if (count == capacity) {
			std::size_t newCapacity = 2 * capacity;
			void** newData = new void*[newCapacity];
			std::memcpy(newData, data, count * sizeof(void*));
			delete[]data;
			data = newData;
			capacity = newCapacity;
		}
		assert(count < capacity);
		data[count++] = t;
	}
	void pop() {
		assert(count > 0);
		--count;
	}
	void* top() const {
		assert(count > 0);
		return data[count - 1];
	}
	std::size_t size()const { return count; }
};
template<class T> class Stack<T*> :private Stack<void *> {
	typedef Stack<void *> Base;
public:
	void push(T* const & t) { Base::push(t); }
	void pop() { Base::pop(); }
	T* top() const { return static_cast<T*>(Base::top()); }
	std::size_t size() { return Base::size(); }
};
template<class StackType>
void emptyTheStack(StackType& stk) {
	while (stk.size() > 0) {
		cout << stk.top() << endl;
		stk.pop();
	}
}
template<class T>
void emptyTheStack(Stack<T*>& stk) {
	while (stk.size() > 0) {
		cout << *stk.top() << endl;
		stk.pop();
	}
}
void Template3Action4()
{
	cout << "\n===========================Template3Action4===========================" << endl;
	Stack<int> s1;
	s1.push(1);
	s1.push(2);
	emptyTheStack(s1);
	Stack<int*> s2;
	int i = 3;
	int j = 4;
	s2.push(&i);
	s2.push(&j);
	emptyTheStack(s2);
}
void Template3Action()
{
	cout << "\n===========================Template3===========================" << endl;
	Template3Action1();
	Template3Action2();
    Template3Action3();
	Template3Action4();
}