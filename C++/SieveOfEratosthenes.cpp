#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int k){
	int i,count=0;
		for(i=2;i<=k/2;i++){
			if(k%i==0)
				count++;
		}
	if(count)
		return false;
	return true;
}

int main(void)
{
	int i,n;
	cin>>n;
	int arr[n-1];
	for(i=0;i<n-1;i++){
		arr[i]=i+2;
	}
	for(i=0;i<n-1;i++){
		if(arr[i]==0)
			continue;
		bool flag=false;
		int k=arr[i],el=i+arr[i];
		flag=checkPrime(k);
		if(flag){
			while(el<n){
				arr[el]=0;
				el+=arr[i];
			}
		}
	}
	for(i=0;i<n-1;i++){
		if(arr[i])
			cout<<arr[i]<<" ";
	}
}

