#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of rows:"<<"\n";
    cin>>n;
    int l,c,sp;
    for (l=1;l<=n;l++)
    {
        for (sp=n;sp>=l;sp--)
            cout<<" ";
        for (c=1;c<=l;c++)
            cout<<c;
        for(c=l-1;c>=1;c--)
            cout<<c; 
         cout<<"\n";
    }
    for (l=1;l<=n-1;l++)
    {
        for (sp=0;sp<=l;sp++)
            cout<<" ";
        for (c=1;c<=n-l;c++)
            cout<<c;
        for (c=c-2;c>=1;c--)
            cout<<c;
        cout<<"\n";
    }
    return 0;
}