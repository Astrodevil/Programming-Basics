#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int x=0;x<n;x++){
        cin>>ar[x];
    }
    int counter=1;
    while(counter<n){
        for(int x=0;x<n-counter;x++){
            if(ar[x]>ar[x+1]){
                int temp=ar[x];
                ar[x]=ar[x+1];
                ar[x+1]=temp;
            }
        }
        counter++;
    }
    for(int x=0;x<n;x++){
        cout<<ar[x]<<" ";
    }
}