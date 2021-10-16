//insertion of node at a specific position
//between the list, on head and on last
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
	~Single_Linked_List();
	void push(int val);//same as 'void addfront'
	void printlist();
	void insert_after_node(int val,int key);//not able to change 'head'
	void insert_at_head(int val);//able to change 'head'
	void insert_before_node(int val,int key);//insert given the before node but not for 'head' node
	bool empty();//to check link is empty or not
	void remove_front();

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
	cout<<endl;
}
void Single_Linked_List::insert_after_node(int val,int key)
{
	node* n=head;
	while(n!=NULL)
	{
		if(n->data==key){break;}
		n=n->next;
	}
	node* new_node=new node(val,n->next);
	n->next=new_node;
}
void Single_Linked_List::insert_at_head(int val)
{
	node* new_node=new node(val,head);
	head=new_node;	
}
void Single_Linked_List::insert_before_node(int val,int key)
{
	node* n=head;
	node* c=NULL;
	while(n!=NULL)
	{ 
		if(n->data==key){break;}
		c=n;
		n=n->next;
	}
	if(c==NULL)//for changingand inserting head
	{
		cout<<"wrong input, use function insert_at_head for the input value: "<<key<<endl;
	}
	else
	{
		node* new_node=new node(val,n);
		c->next=new_node;
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
	l1.push(89);
	l1.push(93);
	l1.push(67);
	l1.printlist();
	//output: 67 93 89 62 42 12
	l1.insert_after_node(100,42);
	l1.printlist();

	l1.insert_before_node(34,67);//inserting and changing head it will give error
	l1.printlist();
	l1.insert_at_head(60);//for changing head
	l1.printlist();
	return 0;
}
