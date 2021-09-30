#include <bits/stdc++.h>
#include<string.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
vector<int> ans;
for(int i=0;i<queries.size();i++){
    int val=0;
    for(int j=0;j<strings.size();j++){
        int res=strcmp(&queries[i][0], &strings[j][0]);
        if(res==0){
            val++;
        }
    }
    ans.push_back(val);
}
return ans;
}

int main()
{
    vector<string> strings;
    vector<string> queries;
    strings={"abcde","sdaklfj","asdjf","na","basdn","sdaklfj","asdjf","na","asdjf","na","basdn","sdaklfj","asdjf"};
    queries={"abcde","sdaklfj","asdjf","na","basdn"};
    for(int i=0;i<queries.size();i++){
       cout<< matchingStrings(strings,queries)[i]<<endl;
        
    }
}
