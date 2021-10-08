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
	void delete_node(int key);
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
		cout<<n->data<<" -> ";
		n=n->next;
	}
	cout<<endl;
}
void Single_Linked_List::delete_node(int key)
{
	node* n=head;
	node* c=NULL;//used to store previous node
	while(n!=NULL)
	{
		if(n->data==key && c==NULL)
		{
			head=n->next;
			delete n;
			break;
		}
		else if(n->data==key)
		{
			c->next=n->next;
			delete n;
			break;
		}
		c=n;
		n=n->next;
	}
	if(n==NULL)
	{
	 cout<<"no data entry regarding the key entered:"<<key<<endl;
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
	//output: 12 42 62 89 93 67
	l1.delete_node(12);//delete last

	l1.delete_node(82);//to see wrong input 

	l1.delete_node(89);//node between head and last
	l1.delete_node(67);//deleting head
	l1.printlist();
	//output: 93 62 42
	return 0;
}


