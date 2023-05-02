#include <iostream>
#include <memory>
#include "Test.h"
using namespace std;

shared_ptr<Test> foo()
{
	Test *test = new Test;
	test->Val = 1;

	return shared_ptr<Test>(test);
}


Test *goo()
{
	Test *gest = new Test;
	gest->Val = 2;
	cout << gest->Val << endl;

	return gest;
}


int main()
{
	//auto p = foo();


	shared_ptr<Test> t;
	{
		auto p = foo();
		t = p;
		cout << p->Val << endl;
	}

	cout << "after block" << endl;
	 
	Test pp = *goo();
	 


}
