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

#include "stdafx.h"
#include <iostream>

using namespace std;

void change(int m)
{
	int k = 0, a[30], b[30];
	int c = 0;
	for (int i = 0, length = sizeof(m) + 1; i < length; ++i) {
		while (m != 0) {
			a[k] = m % 8;
			k++;
			m = m / 8;
		}

	}

	cout << "The decimal number m is equal ";

	for (int i = k - 1; i >= 0; i--) {
		cout << a[i];
	}

	cout << " in Otcal number" << endl;
}

int main() {
	int m;
	cout << "Please enter a decimal number: ";
	cin >> m;
	change(m);
	system("pause");
	return 0;
}


//---------------------------------

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <iomanip>
using namespace std;
class person {
private:
	string name;
	int id;
	int dateOfBrith_year;
	int dateOfBrith_month;
	int dateOfBrith_day;
public:
	void set_name(string s) { name = s; }
	void set_ID(float a) { id = a; }
	void set_dateOfBrith_year(int a) { dateOfBrith_year = a; }
	void set_dateOfBrith_month(int a) { dateOfBrith_month = a; }
	void set_dateOfBrith_day(int a) { dateOfBrith_day = a; }
	string show_name() { return name; }
	float show_ID() { return id; }
	int show_dateOfBrith_year() { return dateOfBrith_year; }
	int show_dateOfBrith_month() { return dateOfBrith_month; }
	int show_dateOfBrith_day() { return dateOfBrith_day; }
};

void join(vector<person>&vecp) {
	int n;
	string name;
	int id;
	int dateOfBrith_year;
	int dateOfBrith_month;
	int dateOfBrith_day;
	cout << "How many people you want add? : ";
	cin >> n;
	cin.clear();
	system("cls");
	for (int i = 0; i<n; i++) {
		person p;

		cout << "Enter No." << i + 1 << " student's name:";
		cin >> name;
		p.set_name(name);
		cout << "ID: ";
		cin >> id;
		p.set_ID(id);
		cout << "Date of brith for year: ";
		cin >> dateOfBrith_year;
		p.set_dateOfBrith_year(dateOfBrith_year);
		cout << "Date of brith for month: ";
		cin >> dateOfBrith_month;
		p.set_dateOfBrith_month(dateOfBrith_month);
		cout << "Date of brith for day: ";
		cin >> dateOfBrith_day;
		p.set_dateOfBrith_day(dateOfBrith_day);
		cout << endl;
		
		vecp.push_back(p);
	}
	system("cls");
}
void sort_ID(vector<person>&vecp) {
	system("cls");
	sort(vecp.begin(), vecp.end(), [](person p1, person p2) {return p1.show_ID()<p2.show_ID(); });
	cout << "All students info." << endl;
	cout << "==========================" << endl;
	if (vecp.empty())
		cout << "No anyone record" << endl;
	cout << "Sr. No.                     Name                    Date of Birth" << endl;
	for (auto c : vecp) {
		cout << std::setfill('.') << setw(28) << left << c.show_ID() << std::setfill('.') << setw(24) << left << c.show_name() << c.show_dateOfBrith_day()
			<< left << "/" << c.show_dateOfBrith_month() << left << "/" << c.show_dateOfBrith_year() << endl;
	}
	cout << endl << endl << endl;
}
void find_name(vector<person>&vecp) {
	system("cls");
	string name;
	bool bo = true;
	cout << "Please enter the student's name：" << endl;
	cin >> name;
	system("cls");
	cout << "All students info." << endl;
	cout << "==========================" << endl;
	cout << "Sr. No.                     Name                    Date of Birth" << endl;
	for (auto c : vecp)
		if (c.show_name() == name) {
			bo = false;
			cout << std::setfill('.') << setw(28) << left << c.show_ID() << std::setfill('.') << setw(24) << left << c.show_name() << c.show_dateOfBrith_day()
				<< left << "/" << c.show_dateOfBrith_month() << left << "/" << c.show_dateOfBrith_year() << endl;
		}
	if (bo) {
		cout << "No found people" << endl;
	}
	cout << endl << endl << endl;
}
int main() {
	vector<person>vecp;
	char c;
	bool end = false;
	cout << "==========================" << endl;
	cout << "1.Add student " << endl << "2.Sort by ID" << endl << "3.Serach by name " << endl << "4.Exits" << endl;
	cout << "==========================" << endl;
	cout << "Please choose option from the list: ";
	while (cin >> c) {
		switch (c) {
		case'1':join(vecp); break;
		case'2':sort_ID(vecp); break;
		case'3':find_name(vecp); break;
		case'4':end = true; break;
		default:cout << "input wrony：\n";
		}
		if (end)
			break;
		cout << "1.Add student " << endl << "2.Sort by ID" << endl << "3.Serach by name " << endl << "4.Exits" << endl;
	}
}
//https://wenku.baidu.com/view/af2daa9851e79b8968022659.html

//-------------------------------------------------------
// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <iomanip>

#define N 10

struct items {
	int id;
	int item_code;
	float price;
	int quantity;
	float total_price;
};

items item[N] = { 0, 0, 0, 0 };
int count = 0;

void addItem();
void listItem();

void MenuMain() {
	system("cls"); //clean screen
	std::cout << "=============== Welcome to items managment system ===============" << std::endl;
	std::cout << "                1. Add Item                                      " << std::endl;
	std::cout << "                2. List Item                                     " << std::endl;
	std::cout << "                3. Exit                                          " << std::endl;
	std::cout << "=================================================================" << std::endl;
	std::cout << "Please choose the option: ";
}

void main() {
	int options;
	for (;;) {
		MenuMain();
		std::cin >> options;
		switch (options)
		{
			case 1: {
				addItem();
				break;
			}
			case 2: {
				listItem();
				break;
			}
			case 3: {
				std::cout << "Thanks fo using!!!" << std::endl;
				return;
			}
		}
	}
}

void addItem() {
	char str;
	for (int i = 0; i < N; i++) {
		std::cout << "Please enter Sr.No. ";
		std::cin >> item[i].id;
		std::cout << "Please enter Item Code: ";
		std::cin >> item[i].item_code;
		std::cout << "Please enter Quantity: ";
		std::cin >> item[i].quantity;
		std::cout << "Please enter Price: ";
		std::cin >> item[i].price;
		item[i].total_price = item[i].quantity * item[i].price;
		count++;
		std::cout << "Do you want add more? (y/n)" << std::endl;
		std::cin >> str;
		if (str == 'n') {
			std::cin.ignore();
			break;
		}
	}
}

void listItem() {
	std::cout << "***************************************************" << std::endl;
	std::cout << std::setw(10) << std::left << "Sr. No." 
			  << std::setw(10) << std::left << "Item Code" 
			  << std::setw(10) << std::left<< "Quantity"
			  << std::setw(10) << std::left << "Price" 
			  << std::setw(10) << std::left<< "Amount" 
			  << std::setw(10) << std::left << std::endl;
	std::cout << std::setw(10) << std::left<< "=======" 
			  << std::setw(10) << std::left<< "=========" 
			  << std::setw(10) << std::left << "========"
		      << std::setw(10) << std::left << "=====" 
			  << std::setw(10) << std::left<< "======" 
			  << std::setw(10) << std::left << std::endl;
	for (int i = 0; i < count; ++i) {
		std::cout << std::setw(10) << std::left << item[i].id
			<< std::setw(10) << std::left << item[i].item_code
			<< std::setw(10) << std::left << item[i].quantity
			<< std::setw(5) << std::right << item[i].price;
			std::cout << std::fixed << std::setw(11) << std::right << std::setprecision(3) << item[i].total_price << std::endl;

	}
	std::cout << "***************************************************" << std::endl;
	system("pause");
}
