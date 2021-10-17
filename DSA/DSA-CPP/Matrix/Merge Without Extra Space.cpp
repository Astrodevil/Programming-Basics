// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted
// in non-decreasing order. Merge the two arrays into one sorted
// array in non-decreasing order without using any extra space.


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    
int j = 0, i = n-1;
while(j < m && i > -1 && arr2[j] < arr1[i])
swap(arr2[j++],arr1[i--]);
sort(arr1,arr1+n);
sort(arr2,arr2+m);
        
         
	}
};


int main(){
  
  int t;
  cin>>t;
  while(t--){
    int n, m,i;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(i=0;i<n;i++){
      cin>>arr2[i];
    }
    Solution ob;
    ob.merge(arr1,arr2,n,m);
    for(i=0;i<n;i++){
      cout<<arr1[i]<<" ";
    }
     for(i=0;i<m;i++){
      cout<<arr2[i]<<" ";
    }
    cout<<"\n";
  }return 0;
}
    
    
