#include "stdafx.h"
#include <string>
unsigned RLEDeflate(const unsigned char* src, unsigned len, unsigned char* dst, string sFOutName) {
	int count = 0; //int c = 0;
	string str;
	//unsigned char* ps = dst; 
	for (int i = 0; i < len; i++) {
		if (src[i] == src[i + 1] && src[i + 1] == src[i + 2] && src[i + 2] == src[i + 3]) {
			count = 4;
			i += 3;
			while (src[i] == src[i + 1]) {
				i++;
				count++;
			}
			str += char(0);
			str += to_string(count); 
			str += src[i];
		}
		else  str += src[i];//cout << src[i];
	
			
	}
	int c = str.length();
	//cout << str << endl;

	unsigned char* pd = (unsigned char*)(str.c_str());;
	unsigned char* ps = dst;
	for (int i = 0; i < str.length(); i++) {
		*ps++ = *pd++;
	}
	return c;
}
unsigned RLEInflate(const unsigned char* src, unsigned len, unsigned char* dst) {
	string  str1;
	int c = 0;
	for (int i = 0; i < len; i++) {
		if (int(src[i]) == 0) {
			string num;
			string buf;
			i++;
			while (int(src[i]) >= 48 && int(src[i]) <= 57) {
				num += src[i];
				i++;
			}
			int n = stoll(num);	
			for (int j = 0; j < n; j++) {
				buf += src[i];
			}
			str1.append(buf);
		}
		else {
			str1 += src[i];
		}
		
	}
	//cout << str1 << endl;
	c = str1.length();
	unsigned char* pd = (unsigned char*)(str1.c_str());;
	unsigned char* ps = dst;
	for (int i = 0; i < c; i++) {
		*ps++ = *pd++;
	}
	return c;
}