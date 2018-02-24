#include <iostream>
using namespace std;
class Test
{
public:
	Test() { cout << "Test" << endl; }
	~Test() { cout << "~Test" << endl; }
	Test(const Test &right)
	{
		cout << "Test(const)" << endl;
		this->a = right.a;
	}
	Test & operator =(const Test & right)
	{
		cout << "operator=" << endl;
		if (&right == this) {
			return *this;
		}
		this->a = right.a;
		return *this;
	}

	Test & geta() { return *this; }
	int getdata() { return a; }
private:
	int a;
};

int main()
{
	Test a;
	cout << "#1#" << endl;
	Test s = a.geta();
	cout << "#2#" << endl;
	Test &p = a.geta();
	cout << "#3#" << endl;
	Test q;
	q = a.geta();
	return 0;
}
