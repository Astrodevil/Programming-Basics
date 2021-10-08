#include<bits/stdc++.h>
using namespace std;


int main(void)
{
	int n,i,count=0;
	cin>>n;
	for(i=2;i<=(n/2);i++){
		if(n%i==0)
			count+=1;
	}
	if(count>0)
		cout<<"Not a prime number";
	else
		cout<<"A prime number";

}

