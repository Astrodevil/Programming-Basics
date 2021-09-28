#include<bits/stdc++.h>
using namespace std;

int lcm(int a,int b,int c)
{
	return (a*b)/c;
}

int gcd(int a,int b)
{
	while(b!=0)
	{
		int rem=a%b;
		a=b;
		b=rem;	
	}
	return a;
}

int main(void)
{
	int a,b;
	cin>>a>>b;
	int c=gcd(a,b);
	int d=lcm(a,b,c);
	cout<<c<<" "<<d<<endl;
}

