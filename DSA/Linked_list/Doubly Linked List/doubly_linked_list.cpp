#include<iostream>
using namespace std;
class node
{
	public:
	node* prev;
	int data;
	node* next;
	node():data(0),next(NULL){}
	node(int x):data(x),next(NULL){}
	node(int x,node* n):data(x),next(n){}
	node(int x,node* n,node* n1):data(x),next(n),prev(n1){}
	friend class Single_Linked_list;
};
class Doubly_Linked_List
{
	node* head;
	public:
	Doubly_Linked_List(){head=NULL;}
	~Doubly_Linked_List();
	void push(int val);//same as 'void addfront'
	void printlist();
	private:
	bool empty();//to check link is empty or not
	void remove_front();
};
void Doubly_Linked_List::push(int val)
{
	node* new_node=new node(val);
	new_node->prev=NULL;
	new_node->next=head;
	if(head!=NULL)
	{
		head->prev=new_node;
	}
	head=new_node;
}
void Doubly_Linked_List::printlist()
{
	node* n=head;
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
}
Doubly_Linked_List::~Doubly_Linked_List()
{
	while(!empty())
	{
		remove_front();
	}
}
void Doubly_Linked_List::remove_front()
{
	node* n=head;
	head=head->next;
	delete n;
	n=NULL;
}
bool Doubly_Linked_List::empty()
{
	if(head!=NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main() 
{
	Doubly_Linked_List d1;
	d1.push(12);
	d1.push(52);
	d1.push(32);
	d1.push(69);
	d1.printlist();
	return 0;
}


