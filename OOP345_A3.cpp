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


	int len = sizeof(unsortedNumbers)+1;
	cout << len << "------------";
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


#include <iostream>  
using namespace std;  
  
struct Node  
{  
    int data;  
    struct Node* next;  
};  
  
class List  
{  
    Node* head;  
public:  
    List() { head = NULL;}  
    void Print();  
    int GetSize();  
    void Append(int addData);  
    void EraseOne(int eraseData);  
    void EraseOne_V2(int eraseData);  
};  
  
void List::Print()  
{  
    Node* tmp = head;  
  
    //list is empty  
    if (tmp == NULL)  
    {  
        cout << "Empty List!\n";  
        return;  
    }  
  
    //list is not empty  
    for(; tmp != NULL; tmp = tmp->next)  
    {  
        cout << tmp->data << " --> ";  
    }  
    cout << "NULL\n";  
}  
  
int List::GetSize()  
{  
    Node* tmp = head;  
  
    //list is empty  
    if(tmp == NULL)  
    {  
        return 0;  
    }  
  
    //list is not empty  
    int num(0);  
    for(; tmp != NULL; tmp = tmp->next)  
    {  
        ++num;  
    }  
    return num;  
}  
  
void List::Append(int addData)  
{  
    //create a new node  
    Node* newNode = new Node;  
    newNode->data = addData;  
    newNode->next = NULL;  
  
    Node* tmp = head;  
  
    //list is empty  
    if(tmp == NULL)  
    {  
        head = newNode; //有可能引入重复释放指针的问题，可以使用智能指针。  
        return;  
    }  
  
    //list is not empty, locate the last node  
    for(; tmp->next != NULL; tmp = tmp->next)  
    {  
    }  
  
    tmp->next = newNode;  
  
}  
  
void List::EraseOne_V2(int eraseData)  
{  
    Node* tmp = head;  
  
    //空链表  
    if (tmp == NULL)  
    {  
        return;  
    }  
  
    //只有一个节点的链表  
    if (tmp->next == NULL)  
    {  
        if (tmp->data == eraseData)  
        {  
            delete tmp;  
            head = NULL;  
        }  
        return;  
    }  
  
    //有两个及以上节点的链表，待删节点正是首节点  
    if (tmp->data == eraseData)  
    {  
        head = head->next;  
        delete tmp;  
        tmp = NULL;  
    }  
  
    //有两个及以上节点的链表，待删节点不是首节点  
    for (; tmp != NULL; tmp = tmp->next)  
    {  
        if ((tmp->next != NULL)  &&  (tmp->next->data == eraseData)) //找到待删节点的前一个节点  
        {  
            Node* tmp2 = tmp->next;  
            tmp->next = tmp->next->next;  
            delete tmp2;  
            break;  
        }  
    }  
}  
  
void List::EraseOne(int eraseData)  
{  
    Node* tmp = head;  
  
    ////////////////////  
    //list is empty  
    ////////////////////  
    if(tmp == NULL)  
    {  
        return;  
    }  
  
    ////////////////////  
    //list is not empty  
    ////////////////////  
    int locate(-1), idx(0);  
    for(; tmp != NULL; tmp = tmp->next)  
    {  
        ++idx;  
        if(tmp->data == eraseData)  
        {  
            locate = idx - 1;  
            break;  
        }  
    }  
  
    if(locate == -1) // eraseData not found  
    {  
        return;  
    }  
  
    int listSize = GetSize();  
  
    if(listSize == 1) // only one node in the list  
    {  
        delete head;  
        head = NULL;  
    }  
    else // more than one node in the list  
    {  
        // eraseData is the 0th node  
        if(locate == 0)  
        {  
            tmp = head;  
            head = head->next;  
            delete tmp; //注意这里释放tmp（并没有用new申请空间给tmp)的空间是可行的，我的理解是因为tmp是结构体指针（相对于基本数据类型指针）。但是不能重复释放。  
            tmp = NULL;  
        }  
  
        //eraseNode is the last node  
        if(locate == listSize - 1)  
        {  
            tmp = head;  
            int idx(0);  
            for(; tmp != NULL; tmp = tmp->next)  
            {  
                ++idx;  
                if(idx == locate - 1)  
                {  
                    Node* toDel = tmp->next;  
                    tmp->next = NULL;  
                    delete toDel;  
                }  
            }  
        }  
  
        // eraseData is intermediate node  
        if(locate > 0  &&  locate < listSize - 1)  
        {  
            tmp = head;  
            int idx(0);  
            for(; tmp != NULL; tmp = tmp->next)  
            {  
                ++idx;  
                if(idx == locate - 1)  
                {  
                    Node* toDel = tmp->next;  
                    tmp->next = tmp->next->next;  
                    delete toDel;  
                }  
            }  
        }  
    } // more than one node in the list  
}  
  
  
int main (int argc, char** argv)  
{  
      // New list  
        List list;  
        list.Print();  
  
        list.EraseOne_V2(100);  
  
        list.Append(2);  
        list.Print();  
        list.EraseOne_V2(2);  
        list.Print();  
  
        // Append nodes to the list  
        list.Append(100);  
        list.Print();  
        list.Append(200);  
        list.Print();  
        list.Append(300);  
        list.Print();  
        list.Append(300);  
        list.Print();  
        list.Append(500);  
        list.Print();  
  
        // Delete nodes from the list  
        list.EraseOne_V2(400);  
        list.Print();  
        list.EraseOne_V2(100);  
        list.Print();  
        list.EraseOne_V2(200);  
        list.Print();  
        list.EraseOne_V2(500);  
        list.Print();  
        list.EraseOne_V2(100);  
        list.Print();  
        list.EraseOne_V2(300);  
        list.Print();  
  
        return 0;  
}  
