
#include <iostream>
using namespace std;
#include "utilis1.h"


int main()
{
    /*int x = 3;
    int* p = &x;
    cout << x << ' ' << *p << ' ' << p << endl;
    p++; 
    cout << p << endl;
    cout << p - &x << endl;
    typedef unsigned char byte; 	// Нет встроенного byte
    byte* pb = (byte*)--p;		// вернули указатель на x и преобразовали
    for (byte* pt = pb; pt - pb < sizeof(int); pt++)
        cout << (int)*pt << ' ';	// выводим как int
    cout << endl;*/

    int a = 3, b = 5;
    cout << a << ' ' << b << endl;
    int* pa = &a; 
    int* pb = &b;
    /*int c = 0;
    c = b;
    b = a;
    a = c;
    cout << a << ' '<< b << endl;*/
    Swap(*pa, *pb);
    cout << a << ' ' << b << endl;
}
