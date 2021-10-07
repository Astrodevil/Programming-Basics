#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int x=0;x<n;x++){
        cin>>ar[x];
    }
    for(int x=0;x<n;x++){
        for(int y=x+1;y<n-1;y++){
            if(ar[x]>ar[y]){
                int temp=ar[x];
                ar[x]=ar[y];
                ar[y]=temp;
            }
        }
    }
    for(int x=0;x<n;x++){
        cout<<ar[x]<<" ";
    }
    return 0;
}