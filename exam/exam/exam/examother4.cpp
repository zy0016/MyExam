#include "stdafx.h"
#include "other4.h"
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
#include <list>
#include <iterator>
#include <stack>
#include <queue>
using namespace std;

typedef stack<string> Stack1;

void Other4Action1()
{
	cout << "\n===========================Other4Action1===========================" << endl;
	ifstream in("ints.out");
	Stack1 textlines;
	string line;
	while (getline(in, line))
		textlines.push(line + "\n");
	while (!textlines.empty())
	{
		cout << textlines.top();
		textlines.pop();
	}
}
void Other4Action2()
{
	cout << "\n===========================Other4Action2===========================" << endl;
	ifstream in("ints.out");
	vector<string> textlines;
	string line;
	while (getline(in, line))
		textlines.push_back(line + "\n");
	while (!textlines.empty())
	{
		cout << textlines.back();
		textlines.pop_back();
	}
}
////////////////////////////////
void Other4Action3()
{
	cout << "\n===========================Other4Action3===========================" << endl;
	priority_queue<int> pqi;
	srand(time(0));
	for (int i = 0; i < 100; i++)
		pqi.push(rand() % 25);
	while (!pqi.empty())
	{
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}
void Other4Action4()
{
	cout << "\n===========================Other4Action4===========================" << endl;
	priority_queue<int,vector<int>,greater<int> > pqi;
	srand(time(0));
	for (int i = 0; i < 100; i++)
		pqi.push(rand() % 25);
	while (!pqi.empty())
	{
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}
///////////////////////////////////////
class PQI :public priority_queue<int> {
public:
	vector<int>& impl() { return c; }
};
void Other4Action5()
{
	cout << "\n===========================Other4Action5===========================" << endl;
	PQI pqi;
	srand(time(0));
	for (int i = 0; i < 100; i++)
		pqi.push(rand()%25);
	copy(pqi.impl().begin(),pqi.impl().end(),ostream_iterator<int>(cout," "));
	cout << endl;
	while (!pqi.empty()) {
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}
//////////////////////////////////////////
template<class T,class Compare>
class PQV :public vector<T> {
	Compare comp;
public:
	PQV(Compare cmp = Compare()) :comp(cmp) {
		make_heap(this->begin(),this->end(),comp);
	}
	const T& top() { return this->front(); }
	void push(const T& x) {
		this->push_back(x);
		push_heap(this->begin(),this->end(),comp);
	}
	void pop() {
		pop_heap(this->begin(), this->end(), comp);
		this->pop_back();
	}
};
void Other4Action6()
{
	cout << "\n===========================Other4Action6===========================" << endl;
	PQV<int, less<int> > pqi;
	srand(time(0));
	for (int i = 0; i < 100; i++)
		pqi.push(rand()%25);
	copy(pqi.begin(),pqi.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	while (!pqi.empty()) {
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}
void Other4Action()
{
	cout << "\n===========================Other4Action===========================" << endl;
	Other4Action1();
	Other4Action2();
	Other4Action3();
	Other4Action4();
	Other4Action5();
	Other4Action6();
}