#include "stdafx.h"
#include "other3.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>
#include <fstream>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <set>
#include <deque>
using namespace std;

void Other3Action1()
{
	cout << "\n===========================Other3Action1===========================" << endl;
	set<int> intset;
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 10; j++)
			intset.insert(j);
	cout << intset.size() << endl;
	assert(intset.size() == 10);
}
/////////////////////////
class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() {};
};
class Circle :public Shape {
public:
	void draw() { cout << "Circle::draw" << endl; }
	~Circle() { cout << "~Circle" << endl; }
};
class Triangle :public Shape {
public:
	void draw() { cout << "Triangle::draw" << endl; }
	~Triangle() { cout << "~Triangle" << endl; }
};

class Square :public Shape {
public:
	void draw() { cout << "Square::draw" << endl; }
	~Square() { cout << "~Square" << endl; }
};
void Other3Action2()
{
	cout << "\n===========================Other3Action2===========================" << endl;
	typedef std::vector<Shape*> Container;
	typedef Container::iterator Iter;
	Container shapes;
	shapes.push_back(new Circle);
	shapes.push_back(new Square);
	shapes.push_back(new Triangle);
	for (Iter i = shapes.begin(); i != shapes.end(); i++)
		(*i)->draw();
	for (Iter j = shapes.begin(); j != shapes.end(); j++)
		delete *j;
}
////////////////////////////////////
template<class Cont,class PtrMemFun>
void apply(Cont &c, PtrMemFun f) {
	typename Cont::iterator it = c.begin();
	while (it != c.end()) {
		((*it).*f)();
		it++;
	}
}
class Z {
	int i;
public:
	Z(int ii) :i(ii) {}
	void g() { ++i; }
	friend ostream& operator<<(ostream& os, const Z& z) {
		return os << z.i;
	}
};
void Other3Action3()
{
	cout << "\n===========================Other3Action3===========================" << endl;
	ostream_iterator<Z> out(cout, " ");
	vector<Z> vz;
	vz.reserve(12);
	for (int i = 0; i < 10; i++)
		vz.push_back(Z(i));
	copy(vz.begin(),vz.end(),out);
	cout << endl;
	apply(vz,&Z::g);
	copy(vz.begin(),vz.end(),out);
}
//////////////////////////////////////////////////
void Other3Action4()
{
	cout << "\n===========================Other3Action4===========================" << endl;
	deque<int> ideq(20); //Create a deque ideq with 20 elements of default value 0
	deque<int>::iterator pos;
	int i;

	//使用assign()赋值  assign在计算机中就是赋值的意思
	for (i = 0; i < 20; ++i)
		ideq[i] = i;

	//输出deque
	printf("output deque data:\n");
	for (i = 0; i < 20; ++i)
		printf("%d ", ideq[i]);
	putchar('\n');

	//在头尾加入新数据
	printf("\nadd data in top and tail...\n");
	ideq.push_back(100);
	ideq.push_front(i);

	//输出deque
	printf("\noutput deque data:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');

	//查找
	const int FINDNUMBER = 19;
	printf("\nfind%d\n", FINDNUMBER);
	pos = find(ideq.begin(), ideq.end(), FINDNUMBER);
	if (pos != ideq.end())
		printf("find %d success\n", *pos);
	else
		printf("find failed\n");

	//在头尾删除数据
	printf("\ndelete data from top and tail...\n");
	ideq.pop_back();
	ideq.pop_front();

	//输出deque
	printf("\noutput deque data:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');
}
void Other3Action()
{
	cout << "\n===========================Other3Action===========================" << endl;
	Other3Action1();
	Other3Action2();
	Other3Action3();
	Other3Action4();
}
