// OOP345A3.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

template<typename T>
void bubble_sort(T arr[], int len)
{
	int i, j;  T temp;
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
	int arr1[len];
	int arr2[len];

	for (int i = 0; i < len; i++) {
		arr1[i] = arr[i];
	}

	for (int i = 0; i < len; i++) {
		arr2[i] = arr[i];
	}
}


int main()
{
	int sizeOfArrayTemp;
	int userNum;
	int searchNum;
	cout << "please enter size of array: " << endl;
	cin >> sizeOfArrayTemp;

	int sizeOfArray = sizeOfArrayTemp;
	int unsortedNumbers[sizeOfArray];

	cout << "please enter number to array" << endl;

	for (int i = 0; i < sizeOfArray; i++) {
		cin >> unsortedNumbers[i];
	}


	int len = (int) sizeof(unsortedNumbers) / sizeof(*unsortedNumbers);

	bubble_sort(unsortedNumbers, len);

	cout << "After using the Bubble sort to sort number: ";
	for (int i = 0; i < len; i++)
		cout << unsortedNumbers[i] << ' ';
		
	cout << endl << endl;
	cout << "The Minimum Number is: " << unsortedNumbers[0] << endl;
	cout << "The Maxinum Number is: " << unsortedNumbers[len-1] << endl;
	save(unsortedNumbers, len);

	int front;
	int end;
	int mid;
	
     cout<<"Please enter a search number:"<<endl;
     cin>>searchNum;
     front=0;
     end=len-1;
     mid=(front+end)/2;
     while(front<end&&unsortedNumbers[mid]!=searchNum)
     {
        if(unsortedNumbers[mid]<searchNum)front=mid+1;
        if(unsortedNumbers[mid]>searchNum)end=mid-1;
        mid=(front+end)/2;
     }
     if(unsortedNumbers[mid]!=searchNum)
          printf("It's Not Foud！\n");
     else
          printf("It's Foud",mid+1);

	system("pause");
	return 0;
}
