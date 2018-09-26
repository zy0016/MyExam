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

void Other6Action()
{
    cout << "\n===========================Other6Action===========================" << endl;
    Other6Action1();
}