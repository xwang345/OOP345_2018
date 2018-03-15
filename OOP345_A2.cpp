//-----------------------------------------
//            Student Name: Xiaochen Wang
//            Student ID  : 015297153
//            Professor   : Sukhbir Tatla
//            Course Name : OOP345S1A
//            Date        : 2018/3/14
//-----------------------------------------

//----------------------------------------------------------------------
// Question 2

#include <iostream>
using namespace std;

class Radius
{
	friend class Circle;   //declare Circle is Radius friend class
	friend class Sphere;
	friend void Show_r(Radius &n);     //declare Show_r is friend function

public:
	Radius(int x) {
		r = x;
	}

	~Radius() {

	}

private:
	int r;
};

void Show_r(Radius &n) { // using referece value here.
	cout << endl;
	cout << "Circle's radius   : " << n.r << endl;    //call Radius prviate data member
}


class Circle {
public:
	Circle() {}
	~Circle() {}

	double area(Radius a) {
		s = a.r * a.r * 3.1415926;
		return s;
	}

private:
	double s;
};

class Sphere {
public:
	Sphere() {}
	~Sphere() {}

	double volume(Radius a) {
		s = a.r * a.r * a.r *3.1415926 * 4 / 3;
		return s;
	}
private:
	double s;
};



void print(char* c) { // simple function overload here.
	cout << "((((((((((((((((((((((((((((((((((((((((((" << endl;
}

void print(int i) {
	cout << ")))))))))))))))))))))))))))))))))))))))))))" << endl;
}

int main(int argc, char *argv[]) {
	Radius objRadius(9);
	Circle objCircle;
	Sphere objSphere;

	print("ten");
	Show_r(objRadius);
	cout << "Circle's area     : " << objCircle.area(objRadius) << endl;
	cout << "Sphere's volume   : " << objSphere.volume(objRadius) << endl;
	cout << endl;
	print(1);

	system("pause");

	return 0;
}
// Question 2 end here.


//----------------------------------------------------------------------
// Question 3

#include <iostream>
#include <exception>

using namespace std;

class CanadaDollar {
public:

	CanadaDollar() {
		rateC = 0.62;
		solveC = 0;
		amountC = 0;
	};
	~CanadaDollar() {
		cout << "Object is being deleted" << endl;
	};
	void CanadaDollar1() {
		cout << "Enter the amount in Canada Dollar you want to covert to euro." << endl;
		cin >> amountC;
		solveC = amountC * rateC;
		cout << endl << "****************************************************" << endl << endl;
		cout << amountC << " Canadian Dollar is equal to " << solveC << " in Euro." << endl << endl;
		cout << "****************************************************" << endl << endl << endl << endl << endl;
		system("pause");
		system("CLS");
	};

private:
	double solveC;
	double rateC;
	double amountC;
};

class Euro {
public:

	Euro() {
		rateE = 1.60;
		solveE = 0;
		amountE = 0;
	};
	~Euro() {
		cout << "Object is being deleted" << endl;
	};
	void Euro1() {
		cout << "Enter the amount in Euro you want to covert to Canada Dollar." << endl;
		cin >> amountE;
		solveE = amountE * rateE;
		cout << endl << "****************************************************" << endl << endl;
		cout << amountE << " Euro is equal " << solveE << " in Canada Dollar." << endl << endl;
		cout << "****************************************************" << endl << endl << endl << endl << endl;
		system("pause");
		system("CLS");

	}

private:
	double solveE;
	double rateE;
	double amountE;
};

class myexception : public exception
{
	virtual const char* what() const throw()
	{
		system("CLS");
		return "Not a valid choice.Please enter again.";
	}
} myex;

void MenuMain() {
	cout << "*************************************" << endl << endl;
	cout << "What currency do you have? " << endl;
	cout << "(1)Euro" << endl;
	cout << "(2)Canadian Dollar" << endl;
	cout << "(3) Exit!!! bye..." << endl << endl;
	cout << "*************************************" << endl;
	cout << "Please type in number: ";
}


int main() {
	int choice;
	bool end = false;
	Euro euroMoney;
	CanadaDollar canadaMoney;


	for (;;) {
		MenuMain();
		cin >> choice;
		switch (choice) {
		case 1: {
			euroMoney.Euro1();
			break;
		}
		case 2: {
			canadaMoney.CanadaDollar1();
			break;
		}
		case 3: {
			exit(0);
		}
		default: {
			try {
				throw myex;
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
			system("pause");
		}

		}
	}
	return 0;
}

// Question 3 end here.
//----------------------------------------------------------------------
