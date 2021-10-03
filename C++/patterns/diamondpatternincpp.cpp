#include<iostream>
using namespace std;
int main()
{
    int l,c,sp;
    for (l=1;l<=5;l++)
    {
        for (sp=5;sp>=l;sp--)
            cout<<" ";
        for (c=1;c<=l;c++)
            cout<<c;
        for(c=l-1;c>=1;c--)
             cout<<c; 
         cout<<"\n";
    }
    for (l=1;l<=4;l++)
    {
        for (sp=0;sp<=l;sp++)
            cout<<" ";
        for (c=1;c<=5-l;c++)
            cout<<c;
        for (c=c-2;c>=1;c--)
            cout<<c;
        cout<<"\n";
    }
    return 0;
}