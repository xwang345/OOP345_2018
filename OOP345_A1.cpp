// OOP345A1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void change(int m[])
{
	int k = 0, a[30], b[30];
	int c = 0;
	for (int i = 0, length = sizeof(m)+1; i < length; ++i) {
		while (m[i] != 0) {
			a[k] = m[i] % 8;
			k++;
			m[i] = m[i] / 8;
			while (m[i] == 0) {
				
			}
		}
		
	}
	
	cout << "The decimal number m is equal ";

	for (int i = k - 1; i >= 0; i--) {
		cout <<  b[i];
	}

	cout << "in Otcal number" << endl;
}

int main() {
	int m[5] = { 85, 25, 152, 251, 458 };
	cout << "The decimal numbers are 85,25, 152,251, 458 ";
	change(m);
	system("pause");
	return 0;
}

/*
void printArray(int data[])
{
	for (int i = 0, length = sizeof(data); i < length; ++i)
	{
		std::cout << data[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	int data[] = { 5, 7, 8, 9, 1, 2 };
	printArray(data);
	return 0;
}*/
