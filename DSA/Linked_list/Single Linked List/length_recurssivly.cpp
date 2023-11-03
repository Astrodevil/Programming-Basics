
//  input: 1 2 3 4 5 6 -1

//  output:

// 1 2 3 4  5 6 -1
// 1 2 3 4 5 6 
// the length of the linked list is:6

// code begin :

#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data ;
	node*next ;
	node (int data ){
		this->data = data ;
		next = NULL	;
	}
};

// used to take the input of the node 

node* takeinput(){
	int data ;
	cin>>data;
	node*head = NULL;
	while(data!=-1){
		node*newnode = new node(data);
		if(head==NULL){
			head = newnode;
		}
		else {
			node*temp = head;
			while(temp->next!=NULL){
				temp = temp->next;

			}
			temp->next =newnode;

		

		}
		cin>>data;
	}
	return head;
}

// used to print the full linked list 
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;

	}
}

int length(node*head ,int l){
	if(head==NULL) return l; // base case
	// int l;

	return length(head->next,l+=1); // recurrsive call 
}

int main(){
	// freopen("in.txt", "r", stdin);
 //    freopen("outp1.txt", "w", stdout);

	node*head = takeinput();
	print(head);
	cout<<endl;
	cout<<"the length of the linked list is:";
	cout<<length(head,0);
}