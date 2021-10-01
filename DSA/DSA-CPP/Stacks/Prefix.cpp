#include<bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s){
    stack<int>st;

    for(int x=s.length()-1;x>=0;x--){
        if(s[x]>='0' && s[x]<='9'){
            st.push(s[x]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[x]){
                case '+':
                st.push(op1+op2);
                break;
                case '-':
                st.push(op1-op2);
                break;
                case '*':
                st.push(op1*op2);
                break;
                case '/':
                st.push(op1/op2);
                break;
                case '^':
                st.push(op1^op2);
                break;
            }
        }
    }
    return st.top();
}

int main(){
    
    
    cout<<prefixEvaluation("-+7*45+20");
    return 0;
}