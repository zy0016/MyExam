#include "stdafx.h"
#include "class2.h"
#include <iostream>
using namespace std;

void PrintIt(string & StringToPrint)
{
    cout<<StringToPrint<<endl;
}
//const string ToothbrushCode("0003");
class IsAToothbrush 
{
public:  
    IsAToothbrush(string& InToothbrushCode) : 
      ToothbrushCode(InToothbrushCode) {}
    bool operator() ( string& SalesRecord ) 
    {
        return SalesRecord.substr(0,4)==ToothbrushCode;
    }     
private:
  string ToothbrushCode;    
};
class String
{
public:
    String(const char *str = NULL);
    String(const String &another);
    ~String();
    String & operator=(const String &rhs);
    int GetLength();
private:
    char *m_data;
};
String::String(const char *str)
{
    if (str == NULL)
    {
        m_data = new char[1];
        m_data[0] = '\0';
    }
    else
    {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data,str);
    }
}
String::String(const String &another)
{
    m_data = new char[strlen(another.m_data) + 1];
    strcpy(m_data,another.m_data);
}
String& String::operator=(const String &rhs)
{
    if (this == &rhs)
        return *this;
    delete[] m_data;
    m_data = new char[strlen(rhs.m_data) + 1];
    strcpy(m_data,rhs.m_data);
    return *this;
}
String::~String()
{
    delete[] m_data;
}
int String::GetLength()
{
    return strlen(m_data);
}
//////////////////////////
void Class2Action1()
{
    list<string> Milkshakes;
    list<string>::iterator itor;
    list<int> Scores;

    if (1)
    {
        cout<<"----------1------------"<<endl;
        vector<int> num;
        int element;
        while (cin >> element)
        {
            num.push_back(element);
        }
        num.insert(num.begin(),9999);
        sort(num.begin(),num.end());
        for (unsigned int i = 0;i < num.size();i++)
            cout << num[i]<<endl;
    }
    if (1)
    {
        cout<<"----------2------------"<<endl;
        typedef vector<int> int_vector;
        //typedef istream_iterator<int> istream_itr;
        //typedef ostream_iterator<int> ostream_itr;
        //typedef back_insert_iterator<int_vector> back_ins_itr;

        int_vector num;
        //copy(istream_itr(cin),istream_itr(),back_ins_itr(num));
        //sort(num.begin(),num.end());
        //copy(num.begin(),num.end(),ostream_itr(cout,"\n"));
    }
    Milkshakes.push_back("Chocolate");
    Milkshakes.push_back("Strawberry");
    Milkshakes.push_front("Lime");
    Milkshakes.push_front("Vanilla");
    Milkshakes.push_front("The Milkshake Menu");
    Milkshakes.push_back("*** Thats the end ***");
    //int j = Milkshakes.size();
    for (itor=Milkshakes.begin();itor != Milkshakes.end();itor++)
    {
        cout<<*itor<<endl;
    }
    
    //remove(Milkshakes.begin(),Milkshakes.end(),"Chocolate");
    cout<<"----------------------------------"<<endl;
    cout<<"begin >>>>>>>>>>>>>>>for_each"<<endl;
    for_each (Milkshakes.begin(),Milkshakes.end(),PrintIt);
    cout<<"end >>>>>>>>>>>>>>>>>for_each"<<endl;

    for (itor=Milkshakes.begin();itor != Milkshakes.end();++itor)
    {
        //delete *itor;
    }
    Scores.push_back(100); Scores.push_back(80);
    Scores.push_back(45); Scores.push_back(75);
    Scores.push_back(99); Scores.push_back(100);
    int NumberOf100Scores(0);
    NumberOf100Scores = count (Scores.begin(), Scores.end(), 100);
    cout << "There were " << NumberOf100Scores << " scores of 100" << endl;
    //vector<string> v;
    cout<<"----------------------------------"<<endl;
    list<string> SalesRecords;

    SalesRecords.push_back("0001 Soap");
    SalesRecords.push_back("0002 Shampoo");
    SalesRecords.push_back("0003 Toothbrush");
    SalesRecords.push_back("0004 Toothpaste");
    SalesRecords.push_back("0003 Toothbrush");
    
    int NumberOfToothbrushes(0);  
    string VariableToothbrushCode("0003");
    NumberOfToothbrushes = count_if (SalesRecords.begin(), SalesRecords.end(), 
        IsAToothbrush(VariableToothbrushCode));
    
    cout << "There were " 
        << NumberOfToothbrushes 
        << " toothbrushes sold" << endl;
    cout<<"----------------------------------"<<endl;
    list<string> Fruit;
    list<string>::iterator FruitIterator;

    Fruit.push_back("Apple");
    Fruit.push_back("Pineapple");
    Fruit.push_back("Star Apple");
    FruitIterator = find(Fruit.begin(),Fruit.end(),"Pineapple");
    if (FruitIterator == Fruit.end())
    {
        cout<<"Fruit not find in list"<<endl;
    }
    else
    {
        cout<<*FruitIterator<<endl;
    }
    cout<<"----------------------------------"<<endl;
    list<char> TargetCharacters;
    list<char> ListOfCharacters;
 
    TargetCharacters.push_back('\0');
    TargetCharacters.push_back('\0');
 
    ListOfCharacters.push_back('1');
    ListOfCharacters.push_back('2');
    ListOfCharacters.push_back('\0');
    ListOfCharacters.push_back('\0');
    list<char>::iterator PositionOfNulls = search(ListOfCharacters.begin(), ListOfCharacters.end(), TargetCharacters.begin(), TargetCharacters.end());
    if (PositionOfNulls!=ListOfCharacters.end())
        cout << "We found the nulls" << endl;

    cout<<"----------------------------------"<<endl;
    list<string> Staff;
    list<string>::iterator PeopleIterator;
 
    Staff.push_back("John");
    Staff.push_back("Bill");
    Staff.push_back("Tony");
    Staff.push_back("Fidel");
    Staff.push_back("Nelson");
 
    cout << "The unsorted list " << endl;
    for (PeopleIterator = Staff.begin();PeopleIterator != Staff.end();PeopleIterator++)
    {
        cout << *PeopleIterator<<endl;
    }
    Staff.sort();
    cout << "The sorted list " << endl;
    for (PeopleIterator = Staff.begin();PeopleIterator != Staff.end();PeopleIterator++)
    {
        cout << *PeopleIterator<<endl;
    }
    cout<<"----------------------------------"<<endl;
    list<int> list1;
    list<int>::iterator ListIterator;
    for (int i = 0; i < 10; ++i) list1.push_back(i);
    list1.insert(list1.begin(), -1);
    list1.insert(list1.end(), 10);
    int IntArray[2] = {11,12};
    list1.insert(list1.end(), &IntArray[0], &IntArray[2]);
    for (ListIterator = list1.begin();ListIterator != list1.end();ListIterator++)
    {
        cout<<*ListIterator<<endl;
    }
    cout<<"----------------------------------"<<endl;
}
void Class2Action()
{
    cout << "\n===========================Class2===========================" << endl;
    Class2Action1();
}