#include <iostream>
#include <iomanip>
using namespace std;

ostream & unit(ostream &output) {
	output << "inches";

	return output;
};

ostream & currency(ostream & output) {
	output << "$";
	return output;
}

ostream & form(ostream& output)
{
	output.setf(ios::showpos);
	output.setf(ios::showpoint);
	output.fill('*');
	output.precision(2);
	output <<setiosflags(ios::fixed) <<setw(10);
	return output;
}

struct student {
	char name[50];
	int stid;
	float marks;
}s[10];

int main()
{
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout.precision(3);
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::internal, ios::adjustfield);
	cout.width(10);
	cout << 275.5 << endl; 

	cout << setw(5) << setprecision(2) << 1.2345 << setw(10)
		<< setprecision(4) << sqrt(2) << setw(15) << setiosflags(ios::scientific)
		<< sqrt(3) << endl;

	cout << fixed << setprecision(2) << 123.456 << endl;

	//-----------------------------------------------------------
	cout.precision(2);     // previous state

	int p = cout.precision(4);     // current state

	cout.precision(p);    // p = 2

	cout << p << endl;
	//---------------------------------------------------------

	

	cout << 36 << unit << endl;


	//------------------------------------------------------------

	cout << currency << 17 << endl << endl;
	//---------------------------------------------------------------

	cout << "Enter information of students: " << endl;
	// Storing information
	for (int i = 0; i < 10; ++i) {
		s[i].stid = i + 1;
		cout << "For Student ID: " << s[i].stid << "," << endl;
		cout << "Enter Student Name: ";
		cin >> s[i].stid;
		cout << "Enter Student Marks: ";
		cin >> s[i].marks;
		cout << endl;
	}

	cout << "Displating Information: " << endl;
	// Displaying information
	for (int i = 0; i < 10; ++i) {
		cout << "\n Student ID: " << i + 1 << endl;
		cout << "Student Name: " << s[i].name << endl;
		cout << "Student Marks: " << s[i].marks << endl;
	}
	return 0;
}
