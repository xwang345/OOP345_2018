//OOP345_A3
// Student Name: Xiaochen Wang; Student ID:015297153

//Q1:
#include <iostream>
using namespace std;

template<typename T>
void bubble_sort(T arr[], int len)
{
	int i, j;
	T temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}


void save(int arr[], int len) {
	int* arr1 = new int[len];
	int* arr2 = new int[len];

	for (int i = 0; i < len; i++) {
		arr1[i] = arr[i];
	}

	for (int i = 0; i < len; i++) {
		arr2[i] = arr[i];
	}
}


int main()
{
	int front;
	int end;
	int mid;
	int sizeOfArrayTemp;
	int userNum;
	int searchNum;
	std::cout << "please enter size of array: " << endl;
	std::cin >> sizeOfArrayTemp;

	static const int sizeOfArray = sizeOfArrayTemp;

	int* unsortedNumbers = new int[sizeOfArray];

	std::cout << "please enter number to array" << endl;

	for (int i = 0; i < sizeOfArray; i++) {
		std::cin >> unsortedNumbers[i];
	}


	int len = (int) sizeof(unsortedNumbers) / sizeof(*unsortedNumbers);
	cout <<"The Size of array is " << len << endl;
	bubble_sort(unsortedNumbers, len);

	cout << "After using the Bubble sort to sort number: ";
	for (int i = 0; i < len; i++)
		std::cout << unsortedNumbers[i] << ' ';


	save(unsortedNumbers, len);

	std::cout << endl << endl;
	std::cout << "The Minimum Number is: " << unsortedNumbers[0] << endl;
	std::cout << "The Maxinum Number is: " << unsortedNumbers[len-1] << endl;


	std::cout << "Please enter a search number:" << endl;
	std::cin >> searchNum;
	front = 0;
	end = len;
	mid = (front + end) / 2;
	while (front<end&&unsortedNumbers[mid] != searchNum)
	{
		if (unsortedNumbers[mid]<searchNum)front = mid + 1;
		if (unsortedNumbers[mid]>searchNum)end = mid - 1;
		mid = (front + end) / 2;
	}
	if (unsortedNumbers[mid] != searchNum)
		printf("It's Not Foud！\n");
	else
		printf("It's Foud!\n");

	system("pause");
	return 0;
}
//-------------------------


//Q2
#include <iostream>
#include <stdlib.h>  
using namespace std;

class Node {
public:
	int data;
	Node *pNext;
};


class LinkList {
public:
	LinkList() {

		head = new Node;
		head->data = 0;
		head->pNext = NULL;
	}
	~LinkList() { delete head; }
	void CreateLinkList(int n);             //create Linked list  
	void InsertNode(int position, int d);   //insert node 
	void TraverseLinkList();                //go through linked list 
	bool IsEmpty();                         //check
	int GetLength();                        //length of linked list 
	void DeleteNode(int position);          //delete linked list
	void DeleteLinkList();                  //Delete whole linked list
	int Find(int number);
private:
	Node *head;
};

void LinkList::CreateLinkList(int n) {
	if (n < 0) {
		cout << "Enter a worry Link list number: " << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *pnew, *ptemp;
		ptemp = head;
		int i = n;
		while (n-- > 0) {
			pnew = new Node;
			cout << "Enter " << i - n << " link list number: ";
			cin >> pnew->data;
			pnew->pNext = NULL;
			ptemp->pNext = pnew;
			ptemp = pnew;
		}
	}
}
//node counts from 1 and adds 1 to the length of the list. The node after the head node is called the first node.
void LinkList::InsertNode(int position, int d) {
	if (position < 0 || position > GetLength() + 1) {
		throw  "this is node error！";
		exit(EXIT_FAILURE);
	}
	else {
		Node *pnew, *ptemp;
		ptemp = head;
		pnew = new Node;
		pnew->data = d;
		pnew->pNext = NULL;

		while (position-- > 1) {
			ptemp = ptemp->pNext;
		}
		pnew->pNext = ptemp->pNext;
		ptemp->pNext = pnew;
	}
}

void LinkList::TraverseLinkList() {
	Node *p = head->pNext;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}

bool LinkList::IsEmpty() {
	if (head->pNext == NULL) {
		return true;
	}
	else {
		return false;
	}

}

int LinkList::GetLength() {
	Node *p = head->pNext;
	int n = 0;
	while (p != NULL) {
		n++;
		p = p->pNext;
	}
	return n;
}

void LinkList::DeleteNode(int position) {
	if (position < 0 || position > GetLength()) {
		cout << "this is node error！" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *ptemp = head, *pdelete;
		while (position-- > 1)
			ptemp = ptemp->pNext;
		pdelete = ptemp->pNext;
		ptemp->pNext = pdelete->pNext;
		delete pdelete;
		pdelete = NULL;
	}
}

void LinkList::DeleteLinkList() {
	Node *pdelete = head->pNext, *ptemp;
	while (pdelete != NULL) {
		ptemp = pdelete->pNext;
		head->pNext = ptemp;
		delete pdelete;
		pdelete = ptemp;
	}
}

int LinkList::Find(int number) {
	Node *p = head->pNext;
	int res = 1;
	while (p != NULL)
	{
		if (p->data == number)
			return res;
	}
	return -1;//return -1 if not found
}

// Here is main file
int main() {
	LinkList Link;
	int position = 0, value = 0, n = 0, b=0;
	bool flag = false;
	int findNumber = 0;

	cout << "please size of linked list: ";
	cin >> n;
	Link.CreateLinkList(n);

	cout << "Print linked list: ";
	Link.TraverseLinkList();

	cout << "Please enter the node of the linked list that you want to insert: ";
	cin >> position;
	cout << "Value: ";
	cin >> value;
	try {
		Link.InsertNode(position, value);
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}


	cout << "Print linked list: ";
	Link.TraverseLinkList();

	cout << "Please enter which node that you want to delete: ";
	cin >> position;
	Link.DeleteNode(position);

	cout << "Print linked list: ";
	Link.TraverseLinkList();

	Link.DeleteLinkList();
	flag = Link.IsEmpty();
	if (flag) {
		cout << "Delete success!" << endl << endl << endl;
	}
	else {
		cout << "Delete failed!" << endl << endl << endl;
	}

	cout << "Please enter a number that you want to be search: ";
	cin >> findNumber;

	b = Link.Find(findNumber);
	if (Link.Find(findNumber) == 1) {
		cout << "it is found" << endl;
	}
	else {
		cout << "it is not found" << endl;
	}

	system("pause");

	return 0;
}
