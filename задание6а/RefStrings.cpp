#include <iostream>
#include "Str.h"

using namespace std;

int main()
{
	Str str1 = "123abc123456789abcabc123";
	Str str2 = "123abc123456789abcabc123abc";
	Str str3 = "a";
	Str substring1 = "abc";
	Str substring2 = "c";
	Str substring3 = "a";
	Str emptystr= "";

	cout << str1.find(emptystr, 8) << '\n';
	cout << emptystr.find(emptystr, 0) << '\n';
	cout << str1.find(substring1, -1) << '\n';
	cout << str3.find(substring1, 0) << '\n' << '\n';

	cout << str1.find(substring1, 0) << '\n';
	cout << str1.find(substring1, 15) << '\n';
	cout << str1.find(substring1, 19) << '\n';
	cout << str2.find(substring2, 21) << '\n';
	cout << str3.find(substring3, 0) << '\n';

}
