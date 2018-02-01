#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout.precision(3);
	cout.setf(ios::fixed, ios::floatfield);
	/*cout.setf(ios::internal, ios::adjustfield);
	cout.width(10);*/
	cout << 275.5 << endl;
	
	cout << setw(5) << setprecision(2) << 1.2345 << setw(10)
		<< setprecision(4) << sqrt(2) << setw(15) << setiosflags(ios::scientific)
		<< sqrt(3) << endl;

	cout << fixed << setprecision(2) << 123.456 << endl;
    return 0;
}
