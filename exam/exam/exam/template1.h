#ifndef _TEMPLATE1_STRUCTOR_
#define _TEMPLATE1_STRUCTOR_
#include <fstream>
#include <string>
#include "stdlib.h"
#include <time.h> 
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>

using std::size_t;
using std::bitset;
template<size_t UpperBound>
class Urand {
	bitset<UpperBound> used;
public:
	Urand() { srand(time(0)); }
	size_t operator()();
};
template<size_t UpperBound>
inline size_t Urand<UpperBound>::operator()() {
	int c = used.count();
	if (c == UpperBound)
		used.reset();
	size_t newval;
	while (used[newval = rand() % UpperBound])
		;
	used[newval] = true;
	return newval;
}

void TemplateAction();

#endif