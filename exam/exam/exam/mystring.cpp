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
	MyString(MyString&& a);
	~MyString();
	MyString & operator=(const MyString &rhs);
	friend MyString operator+(const MyString &a, const MyString &b);
	int GetLength();

	friend ostream& operator<<(ostream& os, const MyString& a) {
		return os << a.m_data<<endl;
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
	if (another.m_data == NULL)
	{
		m_data = new char[1];
		m_data[0] = '\0';
	}
	else
	{
		m_data = new char[strlen(another.m_data) + 1];
		strcpy(m_data, another.m_data);
	}
}
MyString::MyString(MyString&& a)
{
	this->m_data = a.m_data;
	a.m_data = NULL;
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

MyString operator+(const MyString &a, const MyString &b)
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
/////////////////////////////////////////////////////////////////////////////////
class CString {
private:
	char* m_pdata;
public:
	CString(const char* ptr = nullptr) 
	{
		if (ptr == nullptr) 
			m_pdata = nullptr;

		m_pdata = new char[strlen(ptr) + 1];
		strcpy(m_pdata, ptr);
	}
	CString(const CString& a) 
	{
		if (a.m_pdata == nullptr) 
			this->m_pdata = nullptr;

		this->m_pdata = new char[strlen(a.m_pdata) + 1];
		strcpy(this->m_pdata, a.m_pdata);
	}
	CString(CString&& a) 
	{
		this->m_pdata = a.m_pdata;
		a.m_pdata = nullptr;
	}
	~CString() 
	{
		if (this->m_pdata)
		{
			delete[] this->m_pdata;
		}
	}
	CString& operator=(const CString& a) 
	{
		if (this == &a)
			return *this;

		if (this->m_pdata)
			delete[] this->m_pdata;
		this->m_pdata = new char[strlen(a.m_pdata) + 1];
		strcpy(this->m_pdata, a.m_pdata);
		return *this;
	}
	CString operator+=(const CString& a) 
	{
		if (a.m_pdata == nullptr) 
		{
			return *this;
		}
		else if (this->m_pdata == nullptr) 
		{
			return a;
		}
		else 
		{
			char* tmp = this->m_pdata;
			this->m_pdata = new char[strlen(this->m_pdata) + strlen(a.m_pdata) + 1];
			strcpy(this->m_pdata, tmp);
			strcat(this->m_pdata, a.m_pdata);
			delete[] tmp;
			return *this;
		}
	}
	friend CString operator+(const CString& a, const CString& b) 
	{
		char* res = new char[strlen(a.m_pdata) + strlen(b.m_pdata) + 1];
		strcpy(res, a.m_pdata);
		strcat(res, b.m_pdata);
		CString cs(res);
		delete[] res;
		return cs;
	}
	friend ostream& operator<<(ostream& os, const CString& a) 
	{
		os << a.m_pdata;
		return os;
	}
};

////////////////////////////
void teststring()
{
	cout << "\n===========================teststring===========================" << endl;
	MyString a("abc");
	MyString b(a);
	MyString d;
	a = b;
	//a += b;
	MyString c = a;
	MyString e = a + b;
	cout << c << std::endl;
	cout << a << std::endl;
	cout << e << endl;
}
void teststring2()
{
	cout << "\n===========================teststring2===========================" << endl;
	CString a("abc");
	CString b(a);
	a = b;
	a += b;
	CString c = a + b;
	std::cout << c << std::endl;
	std::cout << a << std::endl;
}
void testmystring()
{
	cout << "\n===========================testmystring===========================" << endl;
	teststring();
	teststring2();
}


