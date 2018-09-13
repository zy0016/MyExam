#include "stdafx.h"
#include "class4.h"
#include <iostream>
#include <memory>
using namespace std;

void Class4Action1()
{
	int a = 10;
	std::shared_ptr<int> ptra = std::make_shared<int>(a);
	int bcount = ptra.use_count();
	std::shared_ptr<int> ptra2(ptra); //copy
	bcount = ptra.use_count();
	std::cout << "ptra.use_count" << bcount << std::endl;

	int b = 20;
	int *pb = &a;
	//std::shared_ptr<int> ptrb = pb;  //error
	std::shared_ptr<int> ptrb = std::make_shared<int>(b);
	ptra2 = ptrb; //assign
	pb = ptrb.get(); //获取原始指针

	bcount = ptra.use_count();

	std::cout << "ptra.use_count" << ptra.use_count() << std::endl;
	std::cout << "ptrb.use_count" << ptrb.use_count() << std::endl;
}
void Class4Action2()
{
	std::unique_ptr<int> uptr(new int(10));  //绑定动态对象
	//std::unique_ptr<int> uptr2 = uptr;  //不能賦值
	//std::unique_ptr<int> uptr2(uptr);  //不能拷貝
	
	std::unique_ptr<int> uptr2 = std::move(uptr);//轉換所有權
	//uptr.reset();
	uptr2.release();//释放所有权
}
void Class4Action3()
{
	std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
	int count = sh_ptr.use_count();
	std::cout << count << std::endl;

	std::weak_ptr<int> wp(sh_ptr);
	int i = wp.use_count();
	std::cout << i << std::endl;

	if (!wp.expired()) {
		std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
		*sh_ptr = 100;
		i = wp.use_count();
		std::cout << i << std::endl;
	}
}
void Class4Action4()
{
	//Parent* p = new Parent;
	//Child* c = new Child;
	//p->setChild(c);
	//c->setPartent(p);
	//delete c;  //only delete one
}
void Class4Action5()
{
	cout << "\n===============Class4Action5===============" << endl;
	std::weak_ptr<Parent> wpp;
	std::weak_ptr<Child> wpc;
	{
		std::shared_ptr<Parent> p(new Parent);
		std::shared_ptr<Child> c(new Child);
		p->setChild(c);
		c->setPartent(p);
		wpp = p;
		wpc = c;
		std::cout << p.use_count() << std::endl; // 2
		std::cout << c.use_count() << std::endl; // 2
	}
	std::cout << wpp.use_count() << std::endl;  // 1
	std::cout << wpc.use_count() << std::endl;  // 1
}
/////////////////////////////////////////////////////
template<typename T>
class SmartPointer {
private:
	T* _ptr;
	size_t* _count;
public:
	SmartPointer(T* ptr = nullptr) :
		_ptr(ptr) {
		if (_ptr) {
			_count = new size_t(1);
		}
		else {
			_count = new size_t(0);
		}
	}

	SmartPointer(const SmartPointer& ptr) {
		if (this != &ptr) {
			this->_ptr = ptr._ptr;
			this->_count = ptr._count;
			(*this->_count)++;
		}
	}

	SmartPointer& operator=(const SmartPointer& ptr) {
		if (this->_ptr == ptr._ptr) {
			return *this;
		}

		if (this->_ptr) {
			(*this->_count)--;
			if (this->_count == 0) {
				delete this->_ptr;
				delete this->_count;
			}
		}

		this->_ptr = ptr._ptr;
		this->_count = ptr._count;
		(*this->_count)++;
		return *this;
	}

	T& operator*() {
		assert(this->_ptr == nullptr);
		return *(this->_ptr);

	}

	T* operator->() {
		assert(this->_ptr == nullptr);
		return this->_ptr;
	}

	~SmartPointer() {
		(*this->_count)--;
		if (*this->_count == 0) {
			delete this->_ptr;
			delete this->_count;
		}
	}

	size_t use_count() {
		return *this->_count;
	}
};
void Class4Action6()
{
	cout << "\n===============Class4Action6===============" << endl;
	SmartPointer<int> sp(new int(10));
	SmartPointer<int> sp2(sp);
	SmartPointer<int> sp3(new int(20));
	sp2 = sp3;
	std::cout << sp.use_count() << std::endl;
	std::cout << sp3.use_count() << std::endl;
}
/////////////////////////////////////
void Class4Action7()
{
	cout << "\n===============Class4Action7===============" << endl;
	std::shared_ptr<Person> p1(new Person(1));// Person(1)的引用计数为1

	std::shared_ptr<Person> p2 = std::make_shared<Person>(2);

	p1.reset(new Person(3));// 首先生成新对象，然后引用计数减1，引用计数为0，故析构Person(1)
							// 最后将新对象的指针交给智能指针

	std::shared_ptr<Person> p3 = p1;//现在p1和p3同时指向Person(3)，Person(3)的引用计数为2

	p1.reset();//Person(3)的引用计数为1
	p3.reset();//Person(3)的引用计数为0，析构Person(3)
}
void Class4Action8()
{
	cout << "\n===============Class4Action8===============" << endl;
	//std::shared_ptr<int> p4 = new int(1);// error
	std::shared_ptr<int> p4(new int(5));
	int *pInt = p4.get();
	/////////////////////////
	//char *p5 = new char[10];
	//strncpy(p5,"123456789",10);
	//std::shared_ptr<char> p6(p5);
	//std::shared_ptr<char> p7(p5);// logic error
}
void Class4Action()
{
	cout << "\n===========================Class4===========================" << endl;
	Class4Action1();
	Class4Action2();
	Class4Action3();
	Class4Action4();
	Class4Action5();
	Class4Action6();
	Class4Action7();
	Class4Action8();
}
