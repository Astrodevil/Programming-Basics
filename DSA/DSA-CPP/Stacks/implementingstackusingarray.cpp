#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int size;
    int top;
    int *arr;

    int isempty(){
        if(top==-1){
            return 1;
        }
        return 0;
    }
    int isfull(){
        if(top==size-1){
            return 1;
        }
        return 0;
    }
};

int main()
{
    // Stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=new int[s.size];

    Stack *s=new Stack;
    s->size=4; 
    s->top=-1;
    s->arr=new int[s->size];

    s->arr[++s->top]=4;
    s->arr[++s->top]=5;
    s->arr[++s->top]=8;
    s->arr[++s->top]=9;
     
    if(s->isempty()){
        cout<<"The stack is empty";
    }
    else{
        cout<<"The stack is not empty";
    }

    return 0;
}