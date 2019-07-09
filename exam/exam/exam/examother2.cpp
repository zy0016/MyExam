#include "stdafx.h"
#include "other2.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>
#include <fstream>
#include <functional>
#include <ctime>
#include <cstdlib>
using namespace std;

template<typename T> void copy(T* begin, T* end, T* dest) {
	while (begin != end)
		*dest++ = *begin++;
}
void Other2Action1()
{
	cout << "\n===========================Other2Action1===========================" << endl;
	int a[] = { 10,20,30 };
	const size_t SIZE = sizeof a / sizeof a[0];
	vector<int> v1(a, a + SIZE);
	vector<int> v2(SIZE);
	copy(v1.begin(), v1.end(), v2.begin());
    ///////////////////////
    vector<int> v3;
    copy(v1.begin(),v1.end(),back_inserter(v3));
    assert(equal(v1.begin(),v1.end(),v3.begin()));
}
bool gt15(int x) { return 15 < x; }
void Other2Action2()
{
	cout << "\n===========================Other2Action2===========================" << endl;
	int a[] = { 1,2,3,4,10,20,30 };
	const size_t SIZE = sizeof a / sizeof a[0];
	int b[SIZE];
	int* endb = remove_copy_if(a,a+SIZE,b,gt15);
	int* beginb = b;
	while (beginb != endb)
		cout << *beginb++ << endl;
}
/////////////////////////////////
bool contains_e(const string& s) {
	return s.find('e') != string::npos;
}
void Other2Action3()
{
	cout << "\n===========================Other2Action3===========================" << endl;
	string a[] = {"read","my","lips"};
	const size_t SIZE = sizeof a / sizeof a[0];
	if (0)
	{
		string b[SIZE];
		string* endb = replace_copy_if(a, a + SIZE, b, contains_e, string("kiss"));
		string* beginb = b;
		while (beginb != endb)
			cout << *beginb++ << endl;
	}
	else
	{
		replace_if(a,a+SIZE, contains_e,string("kiss"));
		string* p = a;
		while (p != a + SIZE)
			cout << *p++ << endl;
	}
}
////////////////////////////////////
void Other2Action4()
{
	cout << "\n===========================Other2Action4===========================" << endl;
	int a[] = {1,2,3,4, 10,20,30 };
	const size_t SIZE = sizeof a / sizeof a[0];
	remove_copy_if(a,a+SIZE,ostream_iterator<int>(cout," "),gt15);
	/////////////////
	ofstream outf("ints.out");
	remove_copy_if(a, a + SIZE, ostream_iterator<int>(outf, " "), gt15);
}
void Other2Action5()
{
	cout << "\n===========================Other2Action5===========================" << endl;
	ofstream ints("someInts.dat");
	ints << "1 3 47 5 84 9 2";
	ints.close();
	ifstream inf("someInts.dat");
	//assure(inf, "someInts.dat");
	remove_copy_if(istream_iterator<int>(inf),istream_iterator<int>(),
		ostream_iterator<int>(cout,"\n"),gt15);
}
///////////////////////////////////////
class gt_n {
	int value;
public:
	gt_n(int val) :value(val) {}
	bool operator()(int n) { return n > value; }
};
void Other2Action6()
{
	cout << "\n===========================Other2Action6===========================" << endl;
	gt_n f(4);
	cout << f(3) << endl;
	cout << f(5) << endl;
}
/////////////////////////////////////
void Other2Action7()
{
	cout << "\n===========================Other2Action7===========================" << endl;
	int a[] = {10,20,30};
	const size_t SIZE = sizeof a / sizeof a[0];
	remove_copy_if(a,a+SIZE,ostream_iterator<int>(cout,"\n"),bind2nd(greater<int>(),15));
}
////////////////////////////////////////
void Other2Action8()
{
	cout << "\n===========================Other2Action8===========================" << endl;
	int a[] = { 10,20,30 };
	const size_t SIZE = sizeof a / sizeof a[0];
	cout << count_if(a,a+ SIZE,not1(bind1st(equal_to<int>(),20))) << endl;
}
////////////////////////////////
int boundedRand() { return rand() % 100; }
void Other2Action9()
{
	cout << "\n===========================Other2Action9===========================" << endl;
	const int SZ = 20;
	int a[SZ], b[SZ] = { 0 };
	generate(a,a+SZ,boundedRand);
	int val = boundedRand();
	int * end = remove_copy_if(a,a+SZ,b,bind2nd(greater<int>(),val));
	sort(a,a+SZ);
	sort(b,end);
	ostream_iterator<int> out(cout," ");
	cout << "Orignal Sequence:" << endl;
	copy(a,a+SZ,out);
	cout << "Values <= " << val << endl;
	copy(b,end,out);
	cout << endl;
	/*ostream_iterator<int> out(cout," ");
	vector<int> v(15);
	srand(time(0));
	generate(v.begin(),v.end(),URandGen(20));
	copy(v.begin(),v.end(),out);
	transform(v.begin(),v.end(),v.begin(),
		bind2nd(multiplies<int>(),10));
	copy(v.begin(),v.end(),out);*/
}
/////////////////////////////////////
class Angle {
	int degrees;
public:
	Angle(int deg) :degrees(deg) {}
	int mul(int times) { return degrees *= times; }
};
void Other2Action10()
{
	cout << "\n===========================Other2Action10===========================" << endl;
	vector<Angle> va;
	for (int i = 0; i < 50; i += 10)
		va.push_back(Angle(i));

	int x[] = {1,2,3,4,5};
	transform(va.begin(),va.end(),x,
		ostream_iterator<int>(cout," "),
		mem_fun_ref(&Angle::mul));
	cout << endl;
}
void Other2Action()
{
	cout << "\n===========================Other2Action===========================" << endl;
	Other2Action1();
	Other2Action2();
	Other2Action3();
	Other2Action4();
	Other2Action5();
	Other2Action6();
	Other2Action7();
	Other2Action8();
	Other2Action9();
	Other2Action10();
}
