// KMP.cpp : Defines the entry point for the console application.
//
// 
//Лазаренко Николай 3011 Вариант 1
#include "stdafx.h"
#include "PF.h"
#include <ctime>
unsigned SSCount(const char* s) {
	
	int count = 0;
	const int l = strlen(s);

	
	int sum = 0;
	
	for (int i = l; i > 0; i--) {
		PF prefix;
		int max = 0;

		char* sz = new char[l];
		char* s_copy = new char[l - i + 1];
		
		strcpy_s(sz, l + 1, s);
		strcpy_s(s_copy, l - i + 2, sz += i - 1);
		

		prefix.Init(s_copy);
		for (int ip = 0; ip < prefix; ip++) {
			if (max <= prefix[ip]) max = prefix[ip];
		}
		sum += i - max;
	}
	return sum;
}

unsigned SimpleSSCount(const char* s) {
	string str(s);
	string mas[10000];
	int sum = 0;

	for (int i = 1; i < str.size() + 1; i++) {
		for (int j = 0; j < str.size(); j++) {
			string str_buf = str.substr(j, i);
			for (int k = 0; k < 10000; k++) {
				if (mas[k] == str_buf)
					break;
				else if (mas[k] != str_buf && mas[k].length() == 0) {
					mas[k] = str_buf;
					sum++;
					break;
				}
			}
			
		}

	}
	return sum;
}


int main()
{
	cout << 6 % 7 + 1 << endl;
	// Пример использования класса PF.
	char s[] = "ghfhgfghfhfhgfhfhgfhghghghgf";
	PF pf;
	pf.Init(s);
	cout << s << endl;
	for (int i = 0; i < pf; i++)
		cout << pf[i];
	cout << endl;
	
	cout << "SSCount: " << SSCount(s) << endl; 
	cout << "SimpleSSCount: " << SimpleSSCount(s) << endl;
	cout << "---------------------" << endl;
	
	cout << "Generate: 128" << endl;
	const int N = 128;
	char t[N]{ 0 };
	for (int i = 0; i < N - 1; i++)
		t[i] = rand() % ('z' - 'a') + 'a';
	cout << t << endl;
	unsigned int start_time = clock();

	cout << "SSCount: " << SSCount(t) << endl; 
	unsigned int end_time = clock();
	cout << "Time (ms): "<< end_time - start_time << endl;
	unsigned int start_time1 = clock();
	cout << "SimpleSSCount: " << SimpleSSCount(t) << endl;
	unsigned int end_time1 = clock();
	cout << "Time (ms): " << end_time1 - start_time1 << endl;
	cout << "---------------------" << endl;
		
	cout << "Generate: 1024" << endl;
	const int Nm = 1024;
	char t1[Nm]{ 0 };
	for (int i = 0; i < Nm - 1; i++)
		t1[i] = rand() % ('z' - 'a') + 'a';
	//cout << t1 << endl;
	unsigned int start_time2 = clock();
	cout << "SSCount: " << SSCount(t1) << endl;
	unsigned int end_time2 = clock();
	cout << "Time (ms): " << end_time2 - start_time2 << endl;
	cout << "---------------------" << endl;
	// Тестирование 
	/*char test1[] = "abc";
	char test2[] = "abcabc";
	char test3[] = "abcabcsac";

	pf.Init(test1);
	cout << test1 << endl;
	for (int i = 0; i < pf; i++)
		cout << pf[i];
	cout << endl;

	pf.Init(test2);
	cout << test2 << endl;
	for (int i = 0; i < pf; i++)
		cout << pf[i];
	cout << endl;

	pf.Init(test3);
	cout << test3 << endl;
	for (int i = 0; i < pf; i++)
		cout << pf[i];
	cout << endl;*/

	
	// Пример перебора всех подстрок s длины 8, используя класс string.
	/*cout << endl;
	string str(s);
	for (int i = 0; i < str.length() - 7; i++)
		cout << str.substr(i, 8) << endl;*/

	// Пример генерации случайной строки длины N.
	/*cout << endl;
	const int N = 50;
	char t[N]{ 0 };
	for (int i = 0; i < N - 1; i++)
		t[i] = rand() % ('z' - 'a') + 'a';
	cout << t << endl;*/

	return 0;
}
