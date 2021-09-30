#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
struct stackk
{
    int top = -1;

    int arr[10000];
};

char val;

int isEmpty(struct stackk *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct stackk *ptr, char val)
{
    ptr->top++;
    ptr->arr[ptr->top] = val;
}
char pop(struct stackk *ptr)
{
    if (isEmpty(ptr))
    {
        return 0;
    }
    val = ptr->arr[ptr->top];

    ptr->top--;
    // cout<<val;
    return val;
}
string isBalanced(string s)
{

    struct stackk *ar = new stackk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(ar, s[i]);
        }
        else
        {
            if (pop(ar) == 0)
            {

                return "NO";
            }

            else if (s[i] == ')' && val != '(')
            {
                cout << val;
                return "NO";
            }
            else if (s[i] == ']' && val != '[')
            {
                return "NO";
            }
            else if (s[i] == '}' && val != '{')
            {
                return "NO";
            }
        }
    }
    if (isEmpty(ar))
    {

        return "YES";
    }

    return "NO";
}

int main()
{
    string a;
    cin >> a;
    cout << isBalanced(a);
}
