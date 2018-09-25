#include "stdafx.h"
#include "other5.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>
#include <fstream>
#include <functional>
#include <ctime>
#include <typeinfo>
#include <cstdlib>
#include <set>
#include <deque>
#include <list>
#include <iterator>
#include <stack>
#include <queue>
#include <bitset>
#include <sstream>
#include <bitset>
using namespace std;

template<class T, class Compare>
class PQV :public vector<T> {
	Compare comp;
	bool sorted;
	void assureHeap() {
		if (sorted)
		{
			make_heap(this->begin(), this->end(), comp);
			sorted = false;
		}
	}
public:
	PQV(Compare cmp = Compare()) :comp(cmp) {
		make_heap(this->begin(), this->end(), comp);
		sorted = false;
	}
	const T& top() { 
		assureHeap();
		return this->front(); 
	}
	void push(const T& x) {
		assureHeap();
		this->push_back(x);
		push_heap(this->begin(), this->end(), comp);
	}
	void pop() {
		assureHeap();
		pop_heap(this->begin(), this->end(), comp);
		this->pop_back();
	}
	void sort() {
		if (!sorted) {
			sort_heap(this->begin(),this->end(),comp);
			reverse(this->begin(),this->end());
			sorted = true;
		}
	}
};

void Other5Action1()
{
	cout << "\n===========================Other5Action1===========================" << endl;
	PQV<int, less<int> > pqi;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		pqi.push(rand() % 25);
		copy(pqi.begin(), pqi.end(), ostream_iterator<int>(cout, " "));
		cout <<"\n----------"<< endl;
	}
	pqi.sort();
	copy(pqi.begin(),pqi.end(),ostream_iterator<int>(cout," "));
	cout << "\n----------" << endl;
	while (!pqi.empty()) {
		cout << pqi.top() << ' ';
		pqi.pop();
	}
	cout << endl;
}
/////////////////////////////////
template<class T>
class PQV2 :public priority_queue<T> {
public:
	typedef vector<T> TVec;
	TVec getVector() {
		TVec r(this->c.begin(), this->c.end());
		sort_heap(r.begin(),r.end(),this->comp);
		reverse(r.begin(),r.end());
		return r;
	}
};
void Other5Action2()
{
	cout << "\n===========================Other5Action2===========================" << endl;
	PQV2<int> pqi;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		pqi.push(rand() % 25);
	}
	const vector<int>& v = pqi.getVector();
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << "\n---------" << endl;
	while (!pqi.empty()) {
		cout << pqi.top() << ' ';
		pqi.pop();
	}
}
//////////////////////////////////////////
const int SZ = 32;
typedef bitset<SZ> BS;
template<int bits>
bitset<bits> randBitset() {
	bitset<bits> r(rand());
	for (int i = 0; i < bits / 16 - 1; i++)
	{
		r <<= 16;
		r |= bitset<bits>(rand());
	}
	return r;
}
void Other5Action3()
{
	cout << "\n===========================Other5Action3===========================" << endl;
	srand(time(0));
	cout << "sizeof(bitset<16>)=" << sizeof(bitset<16>) << endl;
	cout << "sizeof(bitset<32>)=" << sizeof(bitset<32>) << endl;
	cout << "sizeof(bitset<48>)=" << sizeof(bitset<48>) << endl;
	cout << "sizeof(bitset<64>)=" << sizeof(bitset<64>) << endl;
	cout << "sizeof(bitset<65>)=" << sizeof(bitset<65>) << endl;
	BS a(randBitset<SZ>()),b(randBitset<SZ>());
	unsigned long ul = a.to_ulong();
	cout << a << endl;
	string cbits("111011010110111");
	cout << "as a string=" << cbits << endl;
}
/////////////////////
void Other5Action4()
{
	cout << "\n===========================Other5Action4===========================" << endl;
	vector<bool> vb(10,true);
	vector<bool>::iterator it;
	for (it = vb.begin(); it != vb.end(); it++)
		cout << *it;
	cout << endl;
	vb.push_back(false);
	ostream_iterator<bool> out(cout, "");
	copy(vb.begin(),vb.end(),out);
	cout << endl;
	bool ab[] = {true,false,false,true,true,true,true,false,false,true};
	vb.assign(ab,ab+sizeof(ab)/sizeof(bool));
	copy(vb.begin(),vb.end(),out);
	cout << endl;
	for (size_t i = 0; i < vb.size(); i++)
		vb[i] = 0;
	vb[4] = true;
	vb[5] = 1;
	vb[7].flip();
	copy(vb.begin(), vb.end(), out);
	cout << endl;
	ostringstream os;
	copy(vb.begin(),vb.end(),ostream_iterator<bool>(os,""));
	bitset<10> bs(os.str());
	cout << "Bitset:" << endl << bs << endl;
}
////////////////////////////
void Other5Action5()
{
    cout << "\n===========================Other5Action5===========================" << endl;
	vector<Security*> portfolio;
    portfolio.push_back(new Metal);
    portfolio.push_back(new Investment);
    portfolio.push_back(new Bond);
    portfolio.push_back(new Stock);
    for(vector<Security*>::iterator it=portfolio.begin();it!=portfolio.end();++it)
    {
        Investment* cm=dynamic_cast<Investment*>(*it);
        if(cm)
            cm->special();
        else
            cout<<"not a Investment"<<endl;
    }
    cout<<"cast from intermediate pointer:"<<endl;
    Security *sp=new Metal;
    Investment* cp= dynamic_cast<Investment*>(sp);
    if(cp)
        cout<<" it's an Investment"<<endl;

    Metal* mp=dynamic_cast<Metal*>(sp);

    if(mp)
        cout<<" it's a Metal too!"<<endl;

    purge(portfolio);
}
/////////////////////////
void Other5Action6()
{
    cout << "\n===========================Other5Action6===========================" << endl;
    Metal m;
    Security& s=m;
    try
    {
        Investment& c=dynamic_cast<Investment&>(s);
        cout<<"It's an Investment"<<endl;
    }
    catch(bad_cast&)
    {
        cout<<"s is not an Investment type"<<endl;
    }
    try
    {
        Bond&  b= dynamic_cast<Bond&>(s);
        cout<<"It's a Bond"<<endl;
    }
    catch(bad_cast&)
    {
        cout<<"It's not a Bond type"<<endl;
    }
}
///////////////////////////
class One{
    class Nested{};
    Nested* n;
public:
    One():n(new Nested){}
    ~One(){delete n;}
    Nested* nested(){return n;}
};
void Other5Action7()
{
    cout << "\n===========================Other5Action7===========================" << endl;
    One o;
    cout<<typeid(*o.nested()).name()<<endl;
}
//////////////////////////////
class B1{
public:
    virtual ~B1(){}
};
class B2{
public:
    virtual ~B2(){}
};
class MI:public B1,public B2{};
class Mi2:public MI{};
void Other5Action8()
{
    cout << "\n===========================Other5Action8===========================" << endl;
    B2 *b2=new Mi2;
    Mi2* mi2=dynamic_cast<Mi2*>(b2);

    MI* mi=dynamic_cast<MI*>(b2);
    B1* b1=dynamic_cast<MI*>(b2);

    assert(typeid(b2)!=typeid(Mi2*));
    assert(typeid(b2)==typeid(B2*));
    delete b2;
}

void Other5Action()
{
	cout << "\n===========================Other5Action===========================" << endl;
	Other5Action1();
	Other5Action2();
	Other5Action3();
	Other5Action4();
    Other5Action5();
    Other5Action6();
    Other5Action7();
    Other5Action8();
}
