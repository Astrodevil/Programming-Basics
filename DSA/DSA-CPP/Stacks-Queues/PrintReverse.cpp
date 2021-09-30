#include<bits/stdc++.h>
using namespace std;

void revereseSentence(string s){
    stack<string>st;
    for(int x=0;x<s.length();x++){
        string word="";
        while(s[x]!=' ' && x<s.size()){
            word+=s[x];
            x++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

int main(){
    
    string s="Hey, how are your doing?";
    revereseSentence(s);
    return 0;
}       