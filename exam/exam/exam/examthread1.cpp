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
#include <thread>
#include <mutex>
#include <future>
using namespace std;
std::mutex mtx;
//pthread_mutex_t flock = PTHREAD_MUTEX_INITIALIZER;
int g_i = 0;
std::mutex g_i_mutex;

void output(int i)
{
	cout << i << endl;
}
void Thread1Action1()
{
	cout << "\n===========================Thread1Action1===========================" << endl;
	for (uint8_t i = 0; i < 4; i++)
	{
		thread t(output, i);
		t.detach();
		//t.join();
	}
}
/////////////////////
//线程函数
void func(int a, int b, int c)
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << "func:" << a << " " << b << " " << c << endl;
}
void Thread1Action2()
{
	cout << "\n===========================Thread1Action2===========================" << endl;
	//创建线程对象t1,绑定线程函数为func
	std::thread t1(func, 1, 2, 3);
	//输出t1的线程ID
	std::cout << "t1 ID:" << t1.get_id() << std::endl;
	//等待t1线程函数执行结束
	t1.join();
	std::thread t2(func, 2, 3, 4);
    std::cout << "t2 ID:" << t2.get_id() << std::endl;
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
}
////////////////////////////////////////////////////////////////////////////
//初始化互斥锁，互斥锁只能同时被一个对象访问，如果同时有两个对访问，其中一个会被阻塞
void hello(char c)
{
	for (int i = 0; i<10; i++) {
		//pthread_mutex_lock(&flock);//上锁
        mtx.lock();
		//cout << c << " " << i << endl;
		cout << "hello:" << c << " " << i << endl;
		//pthread_mutex_unlock(&flock);//解锁
        mtx.unlock();
	}
}
void Thread1Action3()
{
	cout << "\n===========================Thread1Action3===========================" << endl;
	thread t0(hello, 'a');
	thread t1(hello, 'b');
	t0.join();
	t1.join();
	//t0.detach();
	//t1.detach();  
}
////////////////////////////////////////////
int mythread() //线程入口函数
{
	cout << "mythread start" << "threadid= " << std::this_thread::get_id() << endl; //打印线程id
 
	std::chrono::milliseconds dura(5000); //定一个5秒的时间
	std::this_thread::sleep_for(dura);  //休息一定时常
 
	cout << "mythread end" << "threadid= " << std::this_thread::get_id() << endl; //打印线程id
 
	return 7;
}
void Thread1Action4()
{
    cout << "\n===========================Thread1Action4===========================" << endl;
    cout << "main" << "threadid= " << std::this_thread::get_id() << endl;
	std::future<int> result = std::async(mythread);//流程并不卡在这里
	cout << "continue....." << endl;
    //枚举类型
	//std::future_status status = result.wait_for(std::chrono::seconds(0));//等待一秒
    std::future_status::future_status status = result.wait_for(std::chrono::seconds(0));
    if (status == std::future_status::deferred)
	{
		//线程被延迟执行了，系统资源紧张
		cout << "线程被延迟执行了，系统资源紧张 result.get():" << result.get() << endl; //此时采取调用mythread()
	}
	else if (status == std::future_status::timeout)//
	{
		//超时：表示线程还没执行完；我想等待你1秒，希望你返回，你没有返回，那么 status = timeout
		//线程还没执行完
		cout << "超时：表示线程还没执行完!" << endl;
	}
	else if (status == std::future_status::ready)
	{
		//表示线程成功返回
		cout << "线程成功执行完毕，返回 result.get():" << result.get() << endl;
	}
}
void safe_increment()
{
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
    cout << "safe_increment:" << std::this_thread::get_id() << ":" << g_i << endl;
}

void Thread1Action5()
{
    cout << "\n===========================Thread1Action5===========================" << endl;
    std::cout << "Thread1Action5 id: " <<std::this_thread::get_id()<<std::endl;
    std::cout << "Thread1Action5 g_i: " << g_i << '\n';

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();

    std::cout << "Thread1Action5 end g_i: " << g_i << '\n';
}
void Thread1Action()
{
	cout << "\n===========================Thread1Action===========================" << endl;
	Thread1Action1();
	Thread1Action2();
	Thread1Action3();
    Thread1Action4();
    Thread1Action5();
    cout << "end" << endl;
}
