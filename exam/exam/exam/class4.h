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

class Child;
class Parent;

class Parent {
private:
	Child* myChild;
public:
	void setChild(Child* ch) {
		this->myChild = ch;
	}

	void doSomething() {
		if (this->myChild) {

		}
	}

	~Parent() {
		delete myChild;
	}
};

class Child {
private:
	Parent* myParent;
public:
	void setPartent(Parent* p) {
		this->myParent = p;
	}
	void doSomething() {
		if (this->myParent) {

		}
	}
	~Child() {
		delete myParent;
	}
};

void Class4Action();

#endif