// Exception Handling
#include <iostream>
using namespace std;

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}

int main () {
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
      z = division(x, y);
      cout << z << endl;
   } catch (const char* msg) {
     cout << msg << endl;
   }

   return 0;
}

//Using *this pointer
#include <iostream>
 
using namespace std;

class Box {
   public:
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0) {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume() {
         return length * breadth * height;
      }
      int compare(Box box) {
         return this->Volume() > box.Volume();
      }
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

int main(void) {
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   if(Box1.compare(Box2)) {
      cout << "Box2 is smaller than Box1" <<endl;
   } else {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   
   return 0;
}

//Bubble Sort 
#include<iostream>
 
using namespace std;
 
int main()
{
    int a[50],n,i,j,temp;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the array elements: "; 
    
    for(i=0;i<n;++i)
        cin>>a[i];
        
    for(i=1;i<n;++i)
    {
        for(j=0;j<(n-i);++j)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
    
    cout<<"Array after bubble sort:";
    for(i=0;i<n;++i)
        cout<<" "<<a[i];
        
    return 0;
}

//selection Sort
#include<iostream>
 
using namespace std;
 
int main()
{
    int i,j,n,loc,temp,min,a[30];
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<"\nEnter the elements\n";
 
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
 
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 
    return 0;
}

//Linear Search
#include<iostream>
 
using namespace std;
 
int main()
{
    int a[20],n,x,i,flag=0;
    cout<<"How many elements?";
    cin>>n;
    cout<<"\nEnter elements of the array\n";
    
    for(i=0;i<n;++i)
        cin>>a[i];
    
    cout<<"\nEnter element to search:";
    cin>>x;
    
    for(i=0;i<n;++i)
    {
        if(a[i]==x)
        {
            flag=1;
            break;
        }
    }
    
    if(flag)
        cout<<"\nElement is found at position "<<i+1;
    else
        cout<<"\nElement not found";
        
    return 0;
}

//Binary Search
#include<iostream>
 
using namespace std;
 
int main()
{
    int search(int [],int,int);
    int n,i,a[100],e,res;
    cout<<"How Many Elements:";
    cin>>n;
    cout<<"\nEnter Elements of Array in Ascending order\n";
    
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
    
    cout<<"\nEnter element to search:";
    cin>>e;
    
    res=search(a,n,e);
    
    if(res!=-1)
        cout<<"\nElement found at position "<<res+1;
    else
        cout<<"\nElement is not found....!!!";
 
    return 0;
}
 
int search(int a[],int n,int e)
{
    int f,l,m;
    f=0;
    l=n-1;
    
    while(f<=l)
    {
        m=(f+l)/2;
        if(e==a[m])
            return(m);
        else
            if(e>a[m])
                f=m+1;
            else
                l=m-1;
    }
    
    return -1;
}

//Linked List
#include <iostream>
using namespace std;

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        int x;
        Node *next;
    };

// public member
public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
    }

    // destructor
    ~LinkedList(){
        Node *next = head;

        while(next) {              // iterate over all elements
            Node *deleteMe = next;
            next = next->next;     // save pointer to the next element
            delete deleteMe;       // delete the current entry
        }
    }

    // This prepends a new value at the beginning of the list
    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->x = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
    }

    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    int popValue(){
        Node *n = head;
        int ret = n->x;

        head = head->next;
        delete n;
        return ret;
    }
   // https://github.com/xwang345/OOP345_2018/blob/master/OOP345_W10_Reality_Check_Programs.pdf
   // https://blog.csdn.net/a130737/article/details/37532271
   // https://blog.csdn.net/starstar1992/article/details/59808706

// private member
private:
    Node *head; // this is the private member variable. It is just a pointer to the first Node
};

int main() {
    LinkedList list;

    list.addValue(5);
    list.addValue(10);
    list.addValue(20);

    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    // because there is no error checking in popValue(), the following
    // is undefined behavior. Probably the program will crash, because
    // there are no more values in the list.
    // cout << list.popValue() << endl;
    return 0;
}

//IO wirte
#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
//read
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
//Random Access File I/O in c++
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


class hardwareData
{
public:

    string getNameOfTools()
    {
        return nameOfTools;
    }//end funtion getNameOfTools

    void setNameOfTools (string nameOfToolsValue)
    {
        nameOfTools = nameOfToolsValue;
    }//end function setNameOfTools

    int getQtyOfTools()
    {
        return qtyOfTools;
    }//end funtion getQtyOfTools

    void setQtyOfTools (int qtyOfToolsValue)
    {
        qtyOfTools = qtyOfToolsValue;
    }//end of function setQtyOfTools

    double getCostOfTools()
    {
        return costOfTools;
    }//end function getCostOfTools

    void setCostOfTools (double costOfToolsValue)
    {
        costOfTools = costOfToolsValue;
    }//end function setCostOfTools

    int getRecNum()
    {
        return recNum;
    }//end function getRecNum

    void setRecNum (int recNumValue)
    {
        recNum = recNumValue;
    }//end function setRecNum


private:
    string nameOfTools;
    int qtyOfTools;
    double costOfTools;
    int recNum;
};//end class hardwareData


int main ()
{
    string nameOfTools;
    int qtyOfTools;
    double costOfTools;
    int recNum;
    int recsize = sizeof(string) + sizeof(int) + sizeof(double) + sizeof(int);

    fstream outHardware("hardware.dat", ios::in | ios::out);

//exit program if ofstream could not open file
    if (!outHardware)
    {
        cerr << "File could not be opened." << endl;
        exit (1);
    }//end if

    hardwareData hardware;


    cout << "Enter Record Number. (Enter 0 to end input.)" << endl;
    cin >> recNum;
    cout << endl;



    while (recNum > 0 && recNum <=100)
    {
        hardware.setRecNum(recNum);

        cout << "Tool Name" << setw(15) << "Quantity" << setw(10)
             << "Cost/Unit" << endl;

        cin >> nameOfTools >> setw(14) >> qtyOfTools
            >> setw(5) >> costOfTools;
        cout << endl << endl;

//setting the values of tool names, quantity, cost, and record number
        hardware.setNameOfTools (nameOfTools);
        hardware.setQtyOfTools (qtyOfTools);
        hardware.setCostOfTools (costOfTools);

//seek position in file of user-specified record
        outHardware.seekp ( (hardware.getRecNum() -1) * sizeof (hardware));

//write user-specified information in file
        outHardware.write (reinterpret_cast<char*> (&nameOfTools),
                           sizeof (string) );
        outHardware.write (reinterpret_cast<char*> (&qtyOfTools),
                           sizeof (int) );
        outHardware.write (reinterpret_cast<char*> (&costOfTools),
                           sizeof (double) );

//enables the user to enter another item.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Record Number. (Enter 0 to end input.)" << endl;
        cin >> recNum;
    }//end while

    outHardware.close();


    return 0;
}//end funtion main

