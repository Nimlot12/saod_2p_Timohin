// RLE.cpp : Defines the entry point for the console application.
//
 
#include "stdafx.h"
#include "COBS.h"
#include "RLE.h"
#include <string>;
unsigned int Size(const unsigned char* src, int len) {
	int count = 0;
	for (int i = 0; i < len; i++) {

		if (int(src[i]) == 0) {
			string num;
			i++;
			
			while (int(src[i]) >= 48 && int(src[i]) <= 57) {
				num += src[i];
				i++;
			}
			int n = stoll(num);

			count += n;
		}
		else count++;
	}
	return count;
}

int main()
{
	char cOperation;
	cout << "Enter the first letter of the operation (c - compression; d - decompression):";
	cin >> cOperation; cin.get();

	if (cOperation != 'c' && cOperation != 'd') {
		printf("Error: can't recognize this operation!...\n");
		return -1;
	}

	string sFInName, sFOutName;

	cout << "Enter name of Input File:" << endl;
	getline(cin, sFInName);
	cout << "Enter name of Output File:" << endl;
	getline(cin, sFOutName);

	//  Определим размер файла в байтах
	struct stat stat_buf;
	int rc = stat(sFInName.c_str(), &stat_buf);
	if (rc == -1)
		cout << "can't open '" << sFInName << "'" << endl;
	unsigned int inLen = stat_buf.st_size;

	// Выделим буфер под чтение файла
	char *buf = new char[inLen];
	//cout << inLen << endl;

	// Прочтем файл в бинарной моде в буфер.
	ifstream ifs;
	ifs.open(sFInName, ios_base::binary);
	if (ifs.is_open())
	{
		ifs.read(buf, inLen);
		ifs.close();
	}

	// Объявим буфер под выходные данные

	
	char *outBuf = 0;
	int len;
	int len1;
	if (cOperation == 'c') {
		// Займемся кодированием буфера
		// Здесь подготовка и вызов функции кодирования
		char* tmp1 = new char[inLen * 1.04];
		char* tmp2 = new char[inLen];
		cout << "COBS: " << endl;
		cout << "coding length: " << inLen  << endl;
		len = COBSEncode((const unsigned char*)buf, inLen, (unsigned char*)tmp1);
		cout << "coded length: " << len << endl;
		cout << "RLE: " << endl;
		len1 = RLEDeflate((const unsigned char*)tmp1, len, (unsigned char*)tmp2, sFOutName);
		cout << "coded length: " << len1 << endl;
		outBuf = tmp2;
		cout << Size((const unsigned char*)outBuf, len1) << endl;
	}
	else {
		char* tmp1 = new char[Size((const unsigned char*)buf, inLen)];
		cout << "RLE: " << endl;
		cout << Size((const unsigned char*)buf, inLen) << endl;
		len = RLEInflate((const unsigned char*)buf,  inLen, (unsigned char*)tmp1);
		cout << "decoded length: " << len << endl;
		char* tmp2 = new char[len];
		// Займемся декодированием буфера
		cout << "COBS: " << endl;
		len1 = COBSDecode((const unsigned char*)tmp1, len, (unsigned char*) tmp2);
		cout << "decoded length: " << len1 << endl;
		outBuf = tmp2;
	}
	ofstream ofs;
	ofs.open(sFOutName, ios_base::binary);
	if (ofs.is_open())
	{
		ofs.write(outBuf, len1);
		ofs.close();
	}
	//
	// Освободим буфера за ненадобностью.
	delete[] outBuf;
	delete[] buf;

	return 0;
}


