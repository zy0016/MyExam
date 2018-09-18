#include "stdafx.h"
#include "template2.h"
#include <iostream>
#include <memory>
#include <vector>
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
template<class charT,size_t N>
basic_string<charT> bitsetToString(const bitset<N>& bs)
{
	return bs. template to_string<charT, char_traits<charT>, allocator, charT> > ();
}
void Template2Action4()
{
	cout << "\n===========================Template2Action3===========================" << endl;
	bitset<10> bs;
	bs.set(1);
	bs.set(5);
	cout << bs << endl;
	string s = bitsetToString<char>(bs);
	cout << s << endl;
}
void Template2Action()
{
	cout << "\n===========================Template2===========================" << endl;
	XX<int> x;
	Template2Action1();
	Template2Action2();
	Template2Action3();
	Template2Action4();
}
