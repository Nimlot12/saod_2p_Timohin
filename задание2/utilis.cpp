using namespace std;
#include <iostream>

void string_copy(char* s, char* t)
{
	for (char* p = s, *d = t; *d++ = *p++; );

}
int len(const char* s)
{
	const char* pr;
	for (pr = s; *pr; pr++);
	return pr - s;
}

int compare(const char *s, const char *t)
{
	const char* p, * d;
	for (p = s,d = t; (*d == *p) && *p; d++, p++);
	return *p - *d;
}