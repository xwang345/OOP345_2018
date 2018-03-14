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
