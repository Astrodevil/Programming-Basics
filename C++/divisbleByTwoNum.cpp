#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int a,b,c;
	cin>>c>>a>>b;
	int c1=c/a;
	int c2=c/b;
	int c3=c/(a*b);
	cout<<c1+c2-c3;
}

