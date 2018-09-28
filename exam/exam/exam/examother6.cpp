#include "stdafx.h"
#include "other6.h"
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
#include <functional>
using namespace std;

template<class Seq>
void purge(Seq& c)
{
	typename Seq::iterator i;
	for (i = c.begin(); i != c.end(); i++)
	{
		delete *i;
		*i = 0;
	}
}
template<class InpIt>
void purge(InpIt begin, InpIt end)
{
	while (begin != end)
	{
		delete *begin;
		*begin = 0;
		++begin;
	}
}

class Security
{
protected:
    enum{BASEID=0};
public:
    virtual ~Security(){}
    virtual bool isA(int id){return id==BASEID;}
};
class Stock:public Security{
    typedef Security Super;
protected:
    enum{OFFSET=1,TYPEID=BASEID+OFFSET};
public:
    bool isA(int id)
    {
        return id == TYPEID||Super::isA(id);
    }
    static Stock* dynacast(Security* s)
    {
        return (s->isA(TYPEID)) ? static_cast<Stock*>(s) : 0;
    }
};
class Bond:public Security{
    typedef Security Super;
protected:
    enum{OFFSET=2,TYPEID=BASEID+OFFSET};
public:
    bool isA(int id){
        return id == TYPEID||Super::isA(id);
    }
    static Bond* dynacast(Security* s)
    {
        return (s->isA(TYPEID)) ? static_cast<Bond*>(s) : 0;
    }
};
class Investment:public Security{
    typedef Security Super;
protected:
    enum{OFFSET=3,TYPEID=BASEID+OFFSET};
public:
    bool isA(int id){
        return id == TYPEID||Super::isA(id);
    }
    static Investment* dynacast(Security* s)
    {
        //return (s->isA(TYPEID)) ? static_cast<Investment*>(s) : 0;
        if (s->isA(TYPEID))
            return static_cast<Investment*>(s);
        else
            return 0;
    }
    void special(){
        cout<<"special Investment function"<<endl;
    }
};
class Metal:public Investment{
    typedef Security Super;
protected:
    enum{OFFSET=4,TYPEID=BASEID+OFFSET};
public:
    bool isA(int id){
        return id == TYPEID||Super::isA(id);
    }
    static Metal* dynacast(Security* s)
    {
        return (s->isA(TYPEID)) ? static_cast<Metal*>(s) : 0;
    }
};

void Other6Action1()
{
    cout << "\n===========================Other6Action1==========================" << endl;
    vector<Security*> portfolio;
    portfolio.push_back(new Metal);
    portfolio.push_back(new Investment);
    portfolio.push_back(new Bond);
    portfolio.push_back(new Stock);
    for(vector<Security*>::iterator it=portfolio.begin();it!=portfolio.end();++it)
    {
        Investment* cm=Investment::dynacast(*it);
        if(cm)
            cm->special();
        else
            cout<<"not a Investment"<<endl;
    }
    cout<<"cast from intermediate pointer:"<<endl;
    Security *sp=new Metal;
    Investment* cp= Investment::dynacast(sp);
    if(cp)
        cout<<" it's an Investment"<<endl;

    Metal* mp=Metal::dynacast(sp);

    if(mp)
        cout<<" it's a Metal too!"<<endl;

    purge(portfolio);
}
//////////////////////////////////////////
void Other6Action2()
{
	cout << "\n===========================Other6Action2==========================" << endl;
	// 匿名函数 - ->返回值类型 - lambda表达式
	//[capture](parameters)->return-type{body}
	int i = 0;
	auto fun = [&i](int a)->int { // 定义匿名函数 并引用
		cout << a << endl;
		i = 52;
		return 1;
	};
	int num = fun(10);// 调用
	cout << num << endl;// 测试返回值
	//[](int x, int y) { return x + y; } // 隐式返回类型
	//[](int& x) { ++x; }   // 没有return语句 -> lambda 函数的返回类型是'void'
	//[]() { ++global_x; }  // 没有参数,仅访问某个全局变量
	//[] { ++global_x; }     // 与上一个相同,省略了()
}
void Other6Action3()
{
	cout << "\n===========================Other6Action3==========================" << endl;
	std::vector<int> some_list;
	int total = 0;
	for (int i = 0; i<5; ++i) 
		some_list.push_back(i);

	std::for_each(begin(some_list), end(some_list), [&total](int x)
	{
		total += x;
	});
	cout << "total=" << total << endl;
}
int some_func()
{
	return 1;
}
void Other6Action4()
{
	cout << "\n===========================Other6Action4==========================" << endl;
	std::vector<int> some_list;
	int total = 0;
	int value = 5;
	int out = 0;
	for (int i = 0; i<5; ++i)
		some_list.push_back(i);

	std::for_each(begin(some_list), end(some_list), [&, value/*, this*/](int x)
	{
		out = total;
		total += x * value/* * this->some_func()*/;
	});
	cout << "total=" << total << endl;
	cout << "value=" << value << endl;
	cout << "out=" << out << endl;
}
void Other6Action5()
{
	cout << "\n===========================Other6Action5==========================" << endl;
	std::function<double(double)> f0 = [](double x) {return 1; };
	auto                          f1 = [](double x) {return x; };
	decltype(f0)                  fa[3] = { f0,f1,[](double x) {return x*x; } };
	std::vector<decltype(f0)>     fv = { f0,f1 };
	fv.push_back([](double x) {return x*x; });
	fv.push_back([](double x) {return x*x*x; });

	for (unsigned int i = 0; i<fv.size(); i++)
		std::cout << "fv["<<i<<"](3.0)=" <<fv[i](3.0) << endl;
	
	int len = sizeof(fa) / sizeof(fa[1]);
	cout << endl;
	for (int i = 0; i < len; i++)
		std::cout <<"fa["<<i<<"](2.0)="<< fa[i](2.0) << endl;
	
	cout << endl;
	for (auto &f : fv)
		std::cout <<"fv->f(2.0)="<< f(2.0) << endl;
	
	cout << endl;
	for (auto &f : fa)
		std::cout <<"fa->f(2.0)="<< f(2.0) << endl;

	cout << "end!" << endl;
}
void Other6Action6()
{
	cout << "\n===========================Other6Action6==========================" << endl;
	int i = 42, *p = &i, &r = i;
	int k=10;
	decltype(r + 0) b; // OK, 加法的结果是int，因此b是一个（未初始化）的int
	decltype(*p) c=k; // Error, c是int&， 必须初始化
	cout << "end." << endl;
}
void Other6Action7()
{
	cout << "\n===========================Other6Action7==========================" << endl;
	int a = 10;
	decltype(a) b = a;     //int
	b = 20;
	cout << a << " " << b << endl;   //10  20
	decltype((a)) c = a;       //int&
	c = 30;
	cout << a << " " << b << " " << c << endl; //30 20 30
}
constexpr int get_five() { return 5; }
int some_value[get_five() + 7];
void Other6Action8()
{
	cout << "\n===========================Other6Action8==========================" << endl;
	//const std::vector v(1);
	//auto a = v[0];        // a 是 int 类型
	//decltype(v[1]) b = 1; // b 是 const int& 类型, 是std::vector::operator[](size_type) const
						  // 的返回类型
	auto c = 0;           // c 是 int 类型
	auto d = c;           // d 是 int 类型
	decltype(c) e;        // e 是 int 类型, c变量的类型
	decltype((c)) f = c;  // f 是int&类型, 因为(c)是一个左值
	decltype(0) g;        // g 是 int 类型, 因为0是一个右值
	////////////////////////////////
	int my_array[5] = { 1, 2, 3, 4, 5 };
	for (int &x : my_array)
	{
		x *= 2;
		cout << x << endl;
	}
	cout << endl;
}
struct NoInt {
	void f(double i) {};
	void f(int) = delete;    // 不能调用这个函数
};
void Other6Action9()
{
	cout << "\n===========================Other6Action9==========================" << endl;
	NoInt ni;
	ni.f(1.0);
	//ni.f(2);
}
void Other6Action()
{
    cout << "\n===========================Other6Action===========================" << endl;
    Other6Action1();
	Other6Action2();
	Other6Action3();
	Other6Action4();
	Other6Action5();
	Other6Action6();
	Other6Action7();
	Other6Action8();
	Other6Action9();
}