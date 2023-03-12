#include <iostream>
using namespace std;
#include "Str.h";
#include <string>

void Test(Str st) {
    cout << endl << st << endl;
    cout << endl << strlen(st) << endl;
}

int main()
{
    Str s = "123";
    Test(s);
    Str t = "432";
    s += t;
    Test(s);
    Str(e) = "5171";
    Test(e + t);
}