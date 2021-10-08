#include<bits/stdc++.h>
using namespace std;


int main(void)
{
	int n,sum,k;
	cin>>n;
	int a=n;
	while(n>0){
		k=n%10;
		sum+=pow(k,3);
		n=n/10;
	}
	if(a==sum)
		cout<<"armstrong number";
	else
		cout<<"not a armstrong number";

}

