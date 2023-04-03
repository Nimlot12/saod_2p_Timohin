#include <iostream>
#include "Test.h";

using namespace std; 

//Test global_test; 

void Foo(Test t)
{
    cout << "Foo Function is running!" << endl; 
}

int main()
{
    //cout << "String before creation of object" << endl; 
    //Test test;
    AgregateT<Child> agr;
    //Child child; 
    //Foo(test);
    //Test test1;
    //Test* p = new Test(); 
    //delete p; // непосредственно здесь и удалился динамический объект класса Test 
    //Test* array = new Test[2]{ Test(), Test() };
    //delete[] array; 
    //cout << "String after creation of object" << endl; 
    return 0; 
}
