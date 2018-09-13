#ifndef _CLASS4_STRUCTOR_
#define _CLASS4_STRUCTOR_
#include <fstream>
#include <string>
#include "stdlib.h"
#include <time.h> 
#include <iostream>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

class Child;
class Parent;

//class Parent {
//private:
//	Child* myChild;
//public:
//	void setChild(Child* ch) {
//		this->myChild = ch;
//	}
//
//	void doSomething() {
//		if (this->myChild) {
//
//		}
//	}
//
//	~Parent() {
//		delete myChild;
//	}
//};
//
//class Child {
//private:
//	Parent* myParent;
//public:
//	void setPartent(Parent* p) {
//		this->myParent = p;
//	}
//	void doSomething() {
//		if (this->myParent) {
//
//		}
//	}
//	~Child() {
//		delete myParent;
//	}
//};

class Parent {
private:
	//std::shared_ptr<Child> ChildPtr;//memory leak
	std::weak_ptr<Child> ChildPtr;
public:
	void setChild(std::shared_ptr<Child> child) {
		this->ChildPtr = child;
	}

	void doSomething() {
		if (this->ChildPtr.use_count()) {

		}
	}

	~Parent() {
	}
};

class Child {
private:
	std::shared_ptr<Parent> ParentPtr;
public:
	void setPartent(std::shared_ptr<Parent> parent) {
		this->ParentPtr = parent;
	}
	void doSomething() {
		if (this->ParentPtr.use_count()) {

		}
	}
	~Child() {
	}
};

class Person
{
public:
	Person(int v) {
		value = v;
		std::cout << "Cons" << value << std::endl;
	}
	~Person() {
		std::cout << "Des" << value << std::endl;
	}
	int value;

};

void Class4Action();

#endif