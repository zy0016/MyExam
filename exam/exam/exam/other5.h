#ifndef _OTHER5_STRUCTOR_
#define _OTHER5_STRUCTOR_
#include <fstream>
#include <string>
#include "stdlib.h"
#include <time.h> 
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

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
//////////////////////////////
class Security{
public:
    virtual ~Security(){}
};
class Stock:public Security{};
class Bond:public Security{};
class Investment:public Security{
public:
    void special(){std::cout<<"special Investment function"<<std::endl;}
};
class Metal:public Investment{};


void Other5Action();
#endif