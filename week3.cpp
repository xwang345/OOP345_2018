// ProcessDescription.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"



/*struct email {
	char emailAdd[50];
	int userId;
	char password[20];
};


struct discount {
	
};*/

int countPrice(int totalPrice) {
	
}

int menu() {
	std::cout << "Are you new customer?" << std::endl
		<< "1- Yes" << std::endl
		<< "2- No" << std::endl
		<< "0- Exit program" << std::endl
		<< "> ";
	int option = -1;
	std::cin >> option;
	std::cout << std::endl;
	if (option > 2 || option < 0 || std::cin.fail()) {
		option = -1;
	}
	std::cin.clear();
	//cin.ignore(std::numeric_limits < std::streamsize > max(), '\n');
	return option;
};

int main()
{
	//cout << "Please enter an email address that you want send to person: " << endl;
	int menu_selection;
	int price = 80;

	do {
		menu_selection = menu();
		if (menu_selection == 1) {
			std::cout << "Get a 20% discount" << std::endl;
			countPrice(price);
		} else if (menu_selection == 2) {
			std::cout << "Get a 10% discount" << std::endl;
			countPrice(price);
		} else if (menu_selection == 0) {
			return 0;
		}
	} while (menu_selection != 0);

    return 0;
}
