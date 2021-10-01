#include <iostream>
using namespace std;

class node                                       //node class is created
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(node *&head, int val)                //function to insert data in the linked list
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

int sum(node *p)                                 //function to calulate the sum of data of all the nodes of the linked list(wihtout recursion)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

void display(node *head)                        //function to display the data of the linked list
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    int n;
    cout << "Enter the number of elements you want to insert in linked list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter " << i + 1 << " of the linked list: ";
        cin >> x;
        insert(head, x);
    }
    cout << "The linked list formed is: " << endl;
    display(head);
    cout << "Sum of all the elements of the linked list is: " << sum(head);
    return 0;
}