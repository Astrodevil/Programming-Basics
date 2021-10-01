#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void createLinkedlist(int A[], int n){
    int i;
    struct Node *t;
    struct Node *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int sum(struct Node *p){
    int sum = 0;
    while(p->next){
        sum = sum + p->data;
        p=p->next;
    }
    return sum+p->data;
}

int main(){
    int A[]={1,2,3,4,5,6,7,8,9};
    int n = sizeof(A)/sizeof(A[0]);
    createLinkedlist(A, n);
    cout<<sum(first);
    return 0;
}