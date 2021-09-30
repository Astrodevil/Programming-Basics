#include <bits/stdc++.h>
//implementing stack using array all operation
using namespace std;
class Stack
{
    
public:
    int size;
    int top;
    int *arr;
    
    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        return 0;
    }
    int isEmpty()
    {

        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow cannot push " << val << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow cannot push " << endl;
            return -1;
        }
        else
        {

            return arr[top--];
        }
    }

    int peek(int i){
        if(top-i+1<0){
            cout<<"invalid position\n";
            return -1;
        }
        else{
            return arr[top-i+1];
        }
    }
    int stacktop(){
        return arr[top];
    }
    int stackbottom(){
        return arr[0];
    }
    
};

int main()
{
    Stack *sp = new Stack;
    sp->size = 10;
    sp->top = -1;
    sp->arr = new int[sp->size];
    cout << "stack has been created successfully" << endl;
    cout << "BEFORE PUSHING isfull " << sp->isFull() << endl;
    cout << "BEFORE PUSHING isempty " << sp->isEmpty() << endl;

    sp->push(56);
    sp->push(5);
    sp->push(76);
    sp->push(59);
    sp->push(60);
    sp->push(56);
    sp->push(52);
    sp->push(80);
    sp->push(90);
    sp->push(70); //-->10 value added
    

    cout << "\nAFTER PUSHING isfull " << sp->isFull() << endl;
    cout << "\nAFTER PUSHING isEMPTY " << sp->isEmpty() << endl;

    

    for (int i = 1; i <=sp->top + 1; i++)
    {
        cout<<sp->peek(i)<<" ";
    }
    cout<<endl<<"stack top"<<sp->stacktop();
    cout<<endl<<"stack bottom"<<sp->stackbottom();
    
    
    

    return 0;
}