#include <iostream>

using namespace std;

class Days2Year {
	int days, years, weeks, num1;
public:
	Days2Year() {
		days, years, weeks, num1 = 0;
	}

	void input() {
		cout << "Enter the number of days: " << endl;
		cin >> days;
	}

	void convert() {
		years = days / 365;
		num1 = days - (years * 365);
		weeks = days / 7;
		num1 = days - (weeks * 7);
	}

	void show() {
		cout << endl << days << "Days = ";
		cout << weeks << "Weeks OR ";
		cout << years << "Years...!!" << endl;
	}
};

int main() {
	Days2Year days2year;
	days2year.input();
	days2year.convert();
	days2year.show();
	system("pasue");
	return 0;
}
