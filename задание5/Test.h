#pragma once
#include <iostream> 

using namespace std; 

class Test 
{
	static int nCount; 

public:

	Test() //  говорящие конструктор класса 
	{
		nCount++; 
		cout << "Constuctor of class Test has worked! Number of objects = " << nCount << endl;
	}

	Test(const Test& other) // говорящий конструктор копирования 
	{
		nCount++;
		cout << "Copy constructor of class Test has worked!" << endl; 
	}

	~Test() // говорящий деструктор класса  
	{
		nCount--; 
		cout << "Destructor of class Test has worked! Number of objects = " << nCount<< endl;
	}
};

class Child: public Test
{
public:

	Child()
	{
		cout << "Constructor of class Child has worked!" << endl; 
	}

	~Child()
	{
		cout << "Destructor of class Child has worked!" << endl; 
	}
};

class Agregate
{
	Test m_objTest;

public:

	Agregate()
	{
		cout << "Constructor of class Agregate has worked!" << endl; 
	}

	~Agregate()
	{
		cout << "Destructor of class Agregate has worked!" << endl; 
	}
};

template <typename T> 
class AgregateT
{
	T m_objTest;

public:

	AgregateT()
	{
		cout << "Constructor of AgregateT class has worked!" << endl; 
	}

	~AgregateT()
	{
		cout << "Destructor of AgregateT class has worked!" << endl; 
	}
};
