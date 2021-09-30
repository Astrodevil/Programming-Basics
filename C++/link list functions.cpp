#include<iostream>
using namespace std;

class node//creating list
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void InsertatHead(node* &head , int val)  //insert at beginning
{
    node* dev = new node(val);
    node*p;
    p = head;
    dev->next = p;
    head = dev;
}

void InsertatTail(node* &head , int val)  //insert at tail
{
    node* dev = new node(val);
    node* temp=head;
    if(head == NULL)
    {
        head = dev;
        return;
    }
    while(temp->next != NULL)
    {
        temp  =temp->next;
    }
    temp->next = dev;
}
void InsertatIndex(node* &head , int data , int position)  //insert at specific position
{
    node* dev = new node(data);
    int pos=1;
    node* temp = head;node* temp1;
    while(pos != position)
    {
        pos++;
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next=dev;
    dev->next = temp;
}

void DeletefromStart(node* &head)  //delete from start
{
   node* temp = head;
   head = head->next;
   delete(temp);//freeing up the memory
}

void DeletefromEnd(node* &head)  //delete from end
{
    node* temp = head;node* temp1;
    while(temp->next != NULL)
    {
        temp1=temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    delete(temp);
}

void DeletefromIndex(node* &head , int position)  //delete from specific position
{
    int pos=1;
    node* temp = head;
    node* temp1;
    while(pos != position)
    {
        pos++;
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = temp->next;
    delete(temp);
}

int LengthofList(node* head)  //length of link list
{
    node* dev = head;
    int c=0;
    while(dev != NULL)
    {
        c++;
        dev = dev->next;
    }
    return c;
}
void display(node* head)  //displaying of link list
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int SearchForElement(node* head,int key) //if element found return position else -1
{
    node* temp=head;int c=1;
    while(temp != NULL){
        if(temp->data == key){
            return c;
            break;
        }
        c++;
    }
    return -1;
}
