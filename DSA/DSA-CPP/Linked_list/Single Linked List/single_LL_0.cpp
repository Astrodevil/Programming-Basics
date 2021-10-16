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
class Single_Linked_List
{
	node* head;
	public:
	Single_Linked_List(){head=NULL;}
	~Single_Linked_List();//destructor use to free the list
	void push(int val);//same as 'void addfront'
	void printlist();
	private:
	bool empty();//function use for destructor//to check link is empty or not
	void remove_front();//function use for destructor
};
void Single_Linked_List::push(int val)
{
	node* new_node=new node(val,head);
	//new_node->next=head; not used because constructor used
	head=new_node;
}
void Single_Linked_List::printlist()
{
	node* n=head;
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
}
Single_Linked_List::~Single_Linked_List()
{
	while(!empty())
	{
		remove_front();
	}
}
void Single_Linked_List::remove_front()
{
	node* n=head;
	head=head->next;
	delete n;
	n=NULL;
}
bool Single_Linked_List::empty()
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
	Single_Linked_List l1;
	l1.push(12);
	l1.push(42);
	l1.push(62);
	l1.push(67);
	l1.printlist();
	return 0;
}


