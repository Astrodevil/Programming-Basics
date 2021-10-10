#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cout<<"Enter the size of the Array "<<endl;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long m=0,s=0;
    for(int i=0;i<n;i++){
        s=max(a[i],a[i]+s);
        m=max(m,s);
    }
    cout<<m<<endl;
}