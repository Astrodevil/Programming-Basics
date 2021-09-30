#include<bits/stdc++.h>
using namespace std;
#define n 100

class stackk{
    int* ar;
    int top;

    public:
    stackk(){
        ar=new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<'\n';
            return;
        }
        top++;
        ar[top]=x;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack is empty"<<'\n';
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"No element in stack"<<'\n';
            return -1;
        }
        return ar[top];
    }

    bool empty(){
        return top==-1;
    }
};


int main(){
    stackk st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout<<st.Top()<<'\n';
    cout<<st.empty()<<'\n';

    return 0;
}       