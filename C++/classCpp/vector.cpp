#include<bits/stdc++.h>
using namespace std;

 vector<int> addToArrayForm(vector<int>& num, int k) {
        int i,j=num.size()-1,sum=0;
        for(i=0;i<num.size();i++){
            sum+=num[i]*pow(10,j);
            j--;
        }
        int n=sum+k;
        vector<int> v1;
        while(n>=0){
            int a=n%10;
            n=n/10;
            v1.push_back(a);
        }
        reverse(v1.begin(),v1.end());
        return v1;
    }

int main(void)
{
	vector<int> num;
	num.push_back(1);
	num.push_back(8);
	num.push_back(8);
	num.push_back(9);
	num.push_back(2);
	num.push_back(0);
	num.push_back(1);
	num.push_back(9);
	vector<int> v2;
	v2=addToArrayForm(num,8792);
	for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
}

