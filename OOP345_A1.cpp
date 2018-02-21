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


//---------------------------------

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class person{
public:
    void set_name(string s){name=s;}
    void set_ID(float a){id=a;}
    void set_dateOfBrith(int a){dateOfBrith =a;}
    string show_name(){return name;}
    float show_ID(){return id;}
    int show_dateOfBrith(){return dateOfBrith;}
private:
    string name;
    int id;
    int dateOfBrith;
};
void join(vector<person>&vecp){
    int n;
    string name;
    int id;
    int dateOfBrith;
    cout<<"How many people you want add?";
        cin>>n;
        cin.clear();
        system("cls");
        for(int i=0;i<n;i++){
            person p;

            cout<<"This is"<<i+1<<"'s name:";
            cin>>name;
            p.set_name(name);
            cout<<"ID";
            cin>>id;
            p.set_ID(id);
            cout<<"Date of brith";
            cin>>dateOfBrith;
            p.set_dateOfBrith(dateOfBrith);
            vecp.push_back(p);
        }
    system("cls");
}
void sort_height(vector<person>&vecp){
    system("cls");
    sort(vecp.begin(),vecp.end(),[](person p1,person p2){return p1.show_ID()<p2.show_ID();});
    cout<<"All students info."<<endl;
    if(vecp.empty())
        cout<<"No anyone record"<<endl;
    for(auto c:vecp){
        cout << "Sr. No.                     Name                    Date of Birth" << endl;
        cout<< c.show_ID() <<" +++  " << c.show_name() << "  +++  " << c.show_dateOfBrith() << endl;
    }
}
void find_name(vector<person>&vecp){
    system("cls");
    string name;
    bool bo=true;
    cout<<"Please enter the student's name："<<endl;
    cin>>name;
    system("cls");
    for(auto c:vecp)
        if(c.show_name()==name){
            bo=false;
            cout << "Sr. No.                     Name                    Date of Birth" << endl;
            cout<< c.show_ID() <<" +++  " << c.show_name() << "  +++  " << c.show_dateOfBrith() << endl;
        }
        if(bo){
            cout<<"No found people"<<endl;
        }
}
int main(){
vector<person>vecp;
char c;
bool end=false;
cout<<"1.Add student，2.Sort by ID，3.Serach by name，4.Exits"<<endl;;
while(cin>>c){
    switch(c){
    case'1':join(vecp);break;
    case'2':sort_height(vecp);break;
    case'3':find_name(vecp);break;
    case'4':end=true;break;
    default:cout<<"input wrony：\n";
    }
    if(end)
        break;
    cout<<"1.Add student，2.Sort by ID，3.Serach by name，4.Exits"<<endl;;
}
}
