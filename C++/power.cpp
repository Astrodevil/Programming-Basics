#include<bits/stdc++.h>
using namespace std;

int power(int n,int k){
	if(n==0)
		return 1;
	int prevPower=power(n-1,k);
	return prevPower*k;
}

int main(void)
{
	int n,k;
	cin>>n>>k;
	cout<<power(n,k);

}

