
using namespace std;
#include <iostream>
#include "utilis.h"


int main()
{
	char str[] = "Hello!";
	cout << str << endl;
	cout << strlen(str) << ' ' << sizeof(str) << endl;
	char t[32];
	string_copy(str, t);
	cout << t << endl;
	cout << len(str) << endl;
	cout << compare(str, t) << endl;
}