// Sortirovka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	double* nums = new double[argc + 2];
	bool forward = true;
	int count = 0;
	double temp;
	for (size_t i = 0; i < argc; i++)
	{
		if (*argv[i] == 'p')
			forward = true;
		else if (*argv[i] == 'b')
			forward = false;
		if (isdigit(*argv[i]))
			nums[count++] = std::stoi(argv[i]);
	}
	for (size_t i = 0; i < count - 1; i++) 
		for (size_t j = 0; j < count - i - 1; j++)
			if (((forward) && (nums[j] > nums[j + 1])) || ((!forward) && (nums[j] < nums[j + 1])))
			{
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
	for (int i = 0; i < count; i++)
		cout << nums[i] << endl;
	delete [] nums;
}


