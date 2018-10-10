﻿#include "stdafx.h"
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

// 此函数将得到r的引用,并将r的值加1.
void f(int &r) { r++; }

// 模板函数
template<class F, class P> void g(F f, P t) { f(t); }

void Other7Action1()
{
	cout << "\n===========================Other7Action1===========================" << endl;
	int i = 0;
	g(f, i);  // 实例化 'g<void (int &r), int>' 
			  // 'i' 不会被修改
	std::cout << i << std::endl;  // 输出 0

	g(f, std::ref(i));  // 实例化 'g<void(int &r),reference_wrapper<int>>'
						// 'i' 会被修改
	std::cout << i << std::endl;  // 输出 1
}


void Other7Action()
{
	cout << "\n===========================Other7Action===========================" << endl;
	Other7Action1();
}