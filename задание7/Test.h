#pragma once
#include <iostream>
#include <clocale>
using namespace std;

class Test
{
public:
	int Val;

	Test()
	{ 
		cout << "Test start" << endl;
		Val = 0;
	}

	~Test()
	{ 
		cout << "Test end" << endl;
	}

};

