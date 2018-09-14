#include "stdafx.h"
#include "mystring.h"
#include <iostream>
#include <memory>
using namespace std;

class MyString
{
public:
	MyString(const char *str = NULL);
	MyString(const MyString &another);
	~MyString();
	MyString & operator=(const MyString &rhs);
	friend MyString & operator+(const MyString &a, const MyString &b);
	int GetLength();

	friend ostream& operator<<(ostream& os, const MyString& a) {
		os << a.m_data;
		return os;
	}
private:
	char* m_data;
};
MyString::MyString(const char*str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}
}
MyString::MyString(const MyString &another)
{
	m_data = new char[strlen(another.m_data) + 1];
	strcpy(m_data, another.m_data);
}

MyString& MyString::operator=(const MyString &rhs)
{
	if (this == &rhs)
		return*this;
	delete[]m_data;
	m_data = new char[strlen(rhs.m_data) + 1];
	strcpy(m_data, rhs.m_data);
	return*this;
}

MyString& operator+(const MyString &a, const MyString &b)
{
	char* res = new char[strlen(a.m_data) + strlen(b.m_data) + 1];
	strcpy(res, a.m_data);
	strcat(res, b.m_data);
	MyString cs(res);
	delete[] res;
	return cs;
}

MyString::~MyString()
{
	delete[]m_data;
}
int MyString::GetLength()
{
	return strlen(m_data);
}

////////////////////////////
void teststring()
{
	MyString a("abc");
	MyString b(a);
	MyString d;
	a = b;
	//a += b;
	//MyString c = a + b;
	MyString c = a;
	MyString e = a + b;
	cout << c << std::endl;
	cout << a << std::endl;
	cout << e << endl;
}
void testmystring()
{
	cout << "\n===========================testmystring===========================" << endl;
	teststring();
}


