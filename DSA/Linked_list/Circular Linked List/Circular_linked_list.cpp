//circular linked list is same as single lnked list but in circle type
//as the last node points to head node not null as in single linked list
#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node* next;
	node():data(0),next(NULL){}
	node(int x):data(x),next(NULL){}
	node(int x,node* n):data(x),next(n){}
	friend class Single_Linked_list;
};
class Circular_Linked_List
{
	node* head;
	public:
	Circular_Linked_List(){head=NULL;}
	~Circular_Linked_List();
	void push(int val);//same as 'void addfront'
	void printlist();
	private:
	//both function used by destructor
	bool empty();//to check link is empty or not
	void remove_front();

};
void Circular_Linked_List::push(int val)
{
	node* new_node=new node(val);
	node* n=head;
	if(n!=NULL)
		while(n->next!=head){n=n->next;} 
	if(head==NULL)
	{
		head=new_node;
		new_node->next=head;
	}
	else
	{
		new_node->next=head;
		head=new_node;
		n->next=head;
	}
}
void Circular_Linked_List::printlist()
{
	node* n=head;
	do
	{
		cout<<n->data<<" ";
		n=n->next;
	} 
	while(n!=head);
	cout<<endl;
}
Circular_Linked_List::~Circular_Linked_List()
{
	while(!empty())
	{
		remove_front();
	}
}
void Circular_Linked_List::remove_front()
{
	node* n=head;
	head=head->next;
	n->next=NULL;
	delete n;
	n=NULL;
}
bool Circular_Linked_List::empty()
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
	Circular_Linked_List c1;
	c1.push(12);		
	c1.push(52);		
	c1.push(892);		
	c1.push(99);		
	c1.push(100);
	c1.printlist();		
	return 0;
}


