#include <iostream>
using namespace std;

class Radius
{
	friend class Circle;   //declare Circle is Radius friend class
	friend class Sphere;
	friend void Show_r(Radius &n);     //declare Show_r is friend function

public:
	Radius(int x){
		r = x;
	}
	~Radius(){

	}

private:
	int r;
};

void Show_r(Radius &n){
	cout << "Circle's radius: " << n.r << endl;    //call Radius prviate data member
}

class Circle{
public:
	Circle() {}
	~Circle() {}

	double area(Radius a){
		s = a.r * a.r * 3.1415926;             
		return s;
	}

private:
	double s;
};

class Sphere{
    public:
    Sphere(){}
    ~Sphere(){}
    
    double volume(Radius a){
        s = a.r * a.r * a.r *3.1415926 * 4/3;
        return s;
    }
    private:
    double s;
};

int main(int argc, char *argv[]){
	Radius objRadius(9);
	Circle objCircle;
	Sphere objSphere;
	

	Show_r(objRadius);
	
	cout << "Circle area is：" << objCircle.area(objRadius) << endl;
	cout << "Sphere volume is: " << objSphere.volume(objRadius) << endl;

	return 0;
}
//----------------------------------------------------------------------

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

class CanadaDollar {
public:

	CanadaDollar() {
		rateC = 0.01;
		solveC = 0;
		amountC = 0;
	};
	~CanadaDollar() {

	};
	void CanadaDollar1() {
		cout << "Enter the amount in Canada Dollar you want to covert to euro." << endl;
		cin >> amountC;
		solveC = amountC * rateC;
		cout << solveC << "Euro." << endl;
	};

private:
	double solveC;
	double rateC;
	double amountC;
};

class Euro {
public:

	Euro() {
		rateE = 0.02;
		solveE = 0;
		amountE = 0;
	};
	~Euro() {

	};
	void Euro1() {
		cout << "Enter the amount in Euro you want to covert to Canada Dollar." << endl;
		cin >> amountE;
		solveE = amountE * rateE;
		cout << solveE << "Canada Dollar." << endl;
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
		return "Not a valid choice.Please enter again.";
	}
} myex;


int main() {
	int choice;
	Euro euroMoney;
	CanadaDollar canadaMoney;
	cout << "What currency do you have? " << endl;
	cout << "Euro(1)? Canadian Dollar(2)" << endl;
	cin >> choice;

	

	if (choice == 1) {
		euroMoney.Euro1();
		system("pause");
	}
	else if (choice == 2) {
		canadaMoney.CanadaDollar1();
		system("pause");
	}
	else {
		try {
			throw myex;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		system("pause");
	}

	return 0;
}

