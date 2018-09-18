#ifndef _TEMPLATE2_STRUCTOR_
#define _TEMPLATE2_STRUCTOR_
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

class Gromit {
	int arf;
	int totalBarks;
public:
	Gromit(int arf = 1) :arf(arf + 1), totalBarks(0) {}
	void speak(int) {
		for (int i = 0; i < arf; i++)
		{
			std::cout << "arf! ";
			++totalBarks;
		}
		std::cout << std::endl;
	}
	char eat(float) const {
		std::cout << "chomp!" << std::endl;
		return 'z';
	}
	int sleep(char, double) const {
		std::cout << "zzz..." << std::endl;
		return 0;
	}
	void sit() const {
		std::cout << "Sitting..." << std::endl;
	}
};

void Template2Action();

#endif
