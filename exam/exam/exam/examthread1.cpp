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
#ifdef CPLUSPLUS_11
#include <thread>
#endif
using namespace std;

void output(int i)
{
	cout << i << endl;
}
void Thread1Action1()
{
	cout << "\n===========================Thread1Action1===========================" << endl;
#ifdef CPLUSPLUS_11
	for (uint8_t i = 0; i < 4; i++)
	{
		thread t(output, i);
		t.detach();
	}
#endif
}
/////////////////////
//线程函数
void func(int a, int b, int c)
{
#ifdef CPLUSPLUS_11
	std::this_thread::sleep_for(std::chrono::seconds(3));
#endif
	cout << a << " " << b << " " << c << endl;
}
void Thread1Action2()
{
#ifdef CPLUSPLUS_11
	cout << "\n===========================Thread1Action2===========================" << endl;
	//创建线程对象t1,绑定线程函数为func
	std::thread t1(func, 1, 2, 3);
	//输出t1的线程ID
	std::cout << "ID:" << t1.get_id() << std::endl;
	//等待t1线程函数执行结束
	t1.join();
	std::thread t2(func, 2, 3, 4);
	//后台执行t2的线程函数,并且不会因为main函数结束时,线程函数未执行完而产生异常
	t2.detach();
	cout << "after t2 ,main is runing" << endl;
	//以lambda表达式作为被帮顶的线程函数
	std::thread t4([](int a, int b, int c)
	{
		//线程休眠5秒
		std::this_thread::sleep_for(std::chrono::seconds(5));
		cout << a << " " << b << " " << c << endl;
	}, 4, 5, 6);
	t4.join();

	//获取CPU的核数
	cout << "CPU: " << thread::hardware_concurrency() << endl;
	//当添加下面注释掉的语句会抛出异常,因为线程对象先于线程函数结束了,应该保证线程对象的生命周期在线程函数执行完时仍然存在.
	//std::thread t3(func, 3, 4, 5);
#endif
}
void Thread1Action()
{
	cout << "\n===========================Thread1Action===========================" << endl;
	Thread1Action1();
	Thread1Action2();
}