// WAP TO MERGE TWO SORTED LL


// input : 1 2 3 4 -1
// 6  7 8 9 -1


// output : 
// 1234
// 6789
// 12346789


// begin of the code :
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};

node*takeinput(){
	int cnt = 0;
	int data;
	cin>>data;
	node*head = NULL;
	node*tail = NULL;
	while(data!=-1){
		// cnt is used to chek the lenght of the linked list...
		cnt++;
		node*newnode = new node(data);
		if(head == NULL){
			tail = newnode;
			head = newnode;
		}
		else{
			tail->next = newnode;
			tail = newnode;
		}
		cin>>data;

	}
	if(cnt<1){
		head = NULL;
		return head;
	}
	return head;
}

// merging of the two linked list code is started

node*merging(node*h1 , node*h2){
	node*tf = NULL; // tf  is for first linked list tail pointing to the last node
	node*hf = NULL;  //  hf  is for first linked list tail pointing to the first node
	if((h1->data) <(h2->data)){
		// h1 = h1->next;
		tf = h1;hf = h1;
		h1 = h1->next;
	}
	else {

		tf = h2;hf = h2;  // h2  is  for the second l l pointing to the first node 
		h2 = h2->next; // t2 stands for the last node in the linked list 
	}
	while(h1!=NULL && h2!=NULL){
		if(h1->data <= h2->data){
			tf->next = h1;
			tf = h1;
			h1 = h1->next;
		}
		else {
			tf->next = h2;
			tf = h2;
			h2 = h2->next;

		}
	}
	if(h1!=NULL){
		tf->next =h1;
	}
	else{
		tf ->next = h2;
	}
	return hf;
}

// used to print the whole l l 

void print(node*head){
	while(head!=NULL){
		cout<<head->data ;
		head = head->next;
	}
}
int main(){
	node*h1 = takeinput();
	node*h2 = takeinput();
	print(h1);cout<<endl;print(h2);cout<<endl;
	node*hf = merging(h1,h2);
	print(hf);
}