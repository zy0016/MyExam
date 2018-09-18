#include "stdafx.h"
#include "template2.h"
#include <iostream>
#include <memory>
#include <vector>
#include <complex>
#include <cstddef>
using namespace std;

template<class T,template<class U,class = allocator<U> >class Seq>
class Container {
	Seq<T> seq;
public:
	void push_back(const T& t) { seq.push_back(t); }
	typename Seq<T>::iterator begin() { return seq.begin(); }
	typename Seq<T>::iterator end() { return seq.end(); }
};

void Template2Action1()
{
	cout << "\n===========================Template2Action1===========================" << endl;
	Container<int, vector> vContainer;
	vContainer.push_back(1);
	vContainer.push_back(2);
	vContainer.push_back(3);
	vContainer.push_back(4);
	for (vector<int>::iterator p = vContainer.begin(); p != vContainer.end(); p++)
	{
		cout << *p << endl;
	}
	Container<int, list> lContainer;
	lContainer.push_back(10);
	lContainer.push_back(11);
	lContainer.push_back(12);
	lContainer.push_back(13);
	for (list<int>::iterator p2 = lContainer.begin(); p2 != lContainer.end(); p2++)
	{
		cout << *p2 << endl;
	}
}
//////////////////////////////////////////////////////
template <class T>
class X {
	typename T::id i;
public:
	void f() { i.g(); }
};
class Y {
public:
	class id {
	public:
		void g() {}
	};
};
void Template2Action2()
{
	cout << "\n===========================Template2Action2===========================" << endl;
	X<Y> xy;
	xy.f();
}
///////////////////////////////////////
template<class T,template<class U,class = allocator<U> >class Seq>
void printSeq(Seq<T>& seq)
{
	for (typename Seq<T>::iterator b = seq.begin(); b != seq.end();)
		cout << *b++ << endl;
}
void Template2Action3()
{
	cout << "\n===========================Template2Action3===========================" << endl;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	printSeq(v);
	list<int> lst;
	lst.push_back(3);
	lst.push_back(4);
	printSeq(lst);
}
///////////////////////////////////////////////////////
template<typename T> class XX {};
/////////////////////////////////////////
//template<class charT,size_t N>
//basic_string<charT> bitsetToString(const bitset<N>& bs)
//{
//	return bs. template to_string<charT, char_traits<charT>, allocator, charT> > ();
//}
void Template2Action4()
{
	cout << "\n===========================Template2Action4===========================" << endl;
	/*bitset<10> bs;
	bs.set(1);
	bs.set(5);
	cout << bs << endl;
	string s = bitsetToString<char>(bs);
	cout << s << endl;*/
}
////////////////////////////////////////////////
template<class T>
class Outer {
public:
	template<class R>
	class Inner {
	public:
		void f();
	};
};
template<class T> template<class R>
void Outer<T>::Inner<R>::f() {
	cout << "Outer == " << typeid(T).name() << endl;
	cout << "Iuter == " << typeid(R).name() << endl;
	cout << "Full Inner == " << typeid(*this).name() << endl;
	cout << "Full Inner == " << typeid(this).name() << endl;
}
////////////////////////////////////////////
template<typename T> const T& mintemplate(const T&a, const T &b) {
	return (a < b) ? a : b;
}
const char* min(const char* a, const char* b)
{
	return (strcmp(a, b) < 0) ? a : b;
}

void Template2Action5()
{
	cout << "\n===========================Template2Action5===========================" << endl;
	Outer<int>::Inner<bool> inner;
	inner.f();
}
///////////////////////////////////////////////
template<typename T> T fromString(const std::string& s)
{
	std::istringstream is(s);
	T t;
	is >> t;
	return t;
}
template<typename T> std::string toString(const T& t)
{
	std::ostringstream s;
	s << t;
	return s.str();
}
void Template2Action6()
{
	cout << "\n===========================Template2Action6===========================" << endl;
	int i = 1234;
	cout << "i = \"" << toString(i) << "\"" << endl;
	float x = 567.89f;
	cout << "x = \"" << toString(x) << "\"" << endl;
	complex<float> c(1.0, 2.0);
	cout << "c = \"" << toString(c) << "\"" << endl;
	cout << endl;
	i = fromString<int>(string("1234"));
	cout << "i ==" << i << endl;
	x = fromString<float>(string("567.89"));
	cout << "x == " << x << endl;
	c = fromString<complex<float> >(string("(1.0,2.0)"));
	cout << "c == " << c << endl;
}
///////////////////////////////////////////////
template<typename R,typename P>
R implicit_cast(const P& p) { return p; }
void Template2Action7()
{
	cout << "\n===========================Template2Action7===========================" << endl;
	int i = 1;
	float x = implicit_cast<float>(i);
	int j = implicit_cast<int>(x);
	//char* p = implicit_cast<char*>(i);
}
/////////////////////////////////////////////
template<typename T> void f(T*) {}
void h(void(*pf)(int *)) {}
template<typename T> void g(void (*pf)(T*)) {}
void Template2Action8()
{
	cout << "\n===========================Template2Action8===========================" << endl;
	h(&f<int>);
	h(&f);
	g<int>(&f<int>);
	g(&f<int>);
	g<int>(&f);
}
///////////////////////////////////////////////////
template<class charT> charT strTolower(charT c) {
	return tolower(c);
}
void Template2Action9()
{
	cout << "\n===========================Template2Action9===========================" << endl;
	string s("LOWER");
	transform(s.begin(),s.end(),s.begin(),&strTolower<char>);
	cout << s << endl;
}
//////////////////////////////////////////////////
void Template2Action10()
{
	vector<Gromit*> dogs;
	for (size_t i = 0; i < 5; i++)
	{
		dogs.push_back(new Gromit(i));
	}
	//apply(dogs, &Gromit::speak, 1);
}
///////////////////////////////////
void Template2Action()
{
	cout << "\n===========================Template2===========================" << endl;
	XX<int> x;
	float i = 4.5;
	int z = mintemplate<int>(i, 4);
	Template2Action1();
	Template2Action2();
	Template2Action3();
	Template2Action4();
	Template2Action5();
	Template2Action6();
	Template2Action7();
	Template2Action8();
	Template2Action9();
}
