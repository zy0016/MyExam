#include "stdafx.h"
#include "class4.h"
#include <iostream>
#include <memory>
using namespace std;

void Class4Action1()
{
	int a = 10;
	std::shared_ptr<int> ptra = std::make_shared<int>(a);
	std::shared_ptr<int> ptra2(ptra); //copy
	std::cout << "ptra.use_count" << ptra.use_count() << std::endl;

	int b = 20;
	int *pb = &a;
	//std::shared_ptr<int> ptrb = pb;  //error
	std::shared_ptr<int> ptrb = std::make_shared<int>(b);
	ptra2 = ptrb; //assign
	pb = ptrb.get(); //获取原始指针

	std::cout << "ptra.use_count" << ptra.use_count() << std::endl;
	std::cout << "ptrb.use_count" << ptrb.use_count() << std::endl;
}
void Class4Action2()
{
	std::unique_ptr<int> uptr(new int(10));  //绑定动态对象
											 //std::unique_ptr<int> uptr2 = uptr;  //不能賦值
											 //std::unique_ptr<int> uptr2(uptr);  //不能拷貝
	std::unique_ptr<int> uptr2 = std::move(uptr);//轉換所有權
	uptr2.release();//释放所有权
}
void Class4Action3()
{
	std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
	std::cout << sh_ptr.use_count() << std::endl;

	std::weak_ptr<int> wp(sh_ptr);
	std::cout << wp.use_count() << std::endl;

	if (!wp.expired()) {
		std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
		*sh_ptr = 100;
		std::cout << wp.use_count() << std::endl;
	}
}
void Class4Action4()
{
	Parent* p = new Parent;
	Child* c = new Child;
	p->setChild(c);
	c->setPartent(p);
	delete c;  //only delete one
}
void Class4Action()
{
	cout << "\n===========================Class4===========================" << endl;
	Class4Action1();
	Class4Action2();
	Class4Action3();
	Class4Action4();
}
