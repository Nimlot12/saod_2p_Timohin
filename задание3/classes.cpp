
#include <iostream>
#include <cmath>
using namespace std;
#include "Complex.h"
int main()
{
    Complex c;
    Complex a(1, 2), b = 3;
    cout << a << ", " << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a.Conjugate() << endl;
    cout << a.Mod() << endl;
    cout << a.Arg() << endl;
    Complex v[4]{ 1,2, Complex(2,3) };
    for (Complex* p = v; p - v < 4; ++p)
        cout << *p << endl;
    Complex* pc1 = new Complex(1);
    cout << endl << *pc1 << endl;
    delete pc1;
    Complex* pc2 = new Complex;
    cout << *pc2 << endl;
    delete pc2;
    Complex* pc3 = new Complex(1,2);
    cout << *pc3 << endl;
    double re = pc3->Re;
    cout << endl << re << endl;
    double im = pc3->Im;
    cout << endl << im << endl;
    delete pc3;
    Complex* pc = new Complex[3]{1,2,3};
    cout << endl << pc[0].Re << endl;
    delete[] pc;
}

