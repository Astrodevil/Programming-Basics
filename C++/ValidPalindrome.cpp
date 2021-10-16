class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')||(s[i]>='A'&&s[i]<='Z'))
            temp+=tolower(s[i]);
        }
        int n=temp.size();
        for(int i=0;i<(n+1)/2;i++)
            if(temp[i]!=temp[n-1-i])
                return false;
        return true;
    }
};