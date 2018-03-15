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
		cout << endl << "*****************************************" << endl;
		cout << "**" << amountC << " Canadian Dollar is equal to " << solveC << " in Euro.**" << endl;
		cout << "*****************************************" << endl << endl << endl << endl << endl;
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
		cout << endl << "*****************************************" << endl;
		cout << "**" << amountE << " Euro is equal " << solveE << " in Canada Dollar.**" << endl;
		cout << "*****************************************" << endl << endl << endl << endl << endl;
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
	cout << "(3) Exit!!! bye..." << endl;
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
