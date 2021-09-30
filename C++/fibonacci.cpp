#include<bits/stdc++.h>
using namespace std;


int main(void)
{
	int n,first=0,second=1,sum;
	cin>>n;
	cout<<first<<" "<<second<<" ";
	while(n>2){
		sum=first+second;
		first=second;
		second=sum;
		cout<<sum<<" ";
		n--;
	}

}

