#include<bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s)
{
	stack<int> st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			st.push(s[i]-'0');
		}
		else
		{
			int a=st.top();
			st.pop();
			int b=st.top();
			st.pop();
			switch(s[i])
			{
				case '+':
					st.push(b+a);
					break;
				case '-':
					st.push(b-a);
					break;	
				case '*':
					st.push(a*b);
					break;
				case '/':
					st.push(b/a);
					break;
				case '^':
					st.push(pow(b,a));
					break;
			}
		}
	}
	return st.top();
}

int main(void)
{
	string s;
	cin>>s;
	cout<<prefixEvaluation(s);
}

