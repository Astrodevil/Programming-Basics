#include<bits/stdc++.h>
using namespace std;
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            if((i)%15==0)
            {
                string str="FizzBuzz";
                ans.push_back(str);
            }
            else if((i)%5==0){
                string str="Buzz";
                ans.push_back(str);
            }
            else if((i)%3==0){
               string str="Fizz";
                ans.push_back(str);
            }
            else
                ans.push_back(to_string(i));
        } 
        return ans;
    }
int main()
{
    vector<string> answer= fizzBuzz(5);
}