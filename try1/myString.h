#pragma once
#define _CRT_SECURE_NO_WARNINGS
//using namespace std;
#include <iostream>

class MyString
{
    char* m_pStr;	//строка-член класса
	//friend class BD;
public:
//MyString();

explicit MyString(const char* str="");
MyString(char*&& str);
MyString(const MyString& n_str);
MyString(MyString&& n_str);
const char* GetString()const;
const char* GetString();
char* GetSetString();
void SetNewString(const char* str);
void AddString(const char* str);
friend MyString concat(const char*, ...);// !! посл.аргумент - 0
void Swap(MyString&);


 char* operator= (const char*);
 MyString& operator= (const MyString&);
 MyString& operator= (MyString&&);
 friend std::ostream& operator<< (std::ostream&, const MyString&);
 //ostream& operator<< (ostream&);
 MyString& operator+= (const MyString&);
 MyString operator+ (const MyString&)const;

~MyString();
};

//ostream& operator<< (ostream&, MyString&);
//MyString concat(const char*, ...);