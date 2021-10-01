#include <bits/stdc++.h>
using namespace std;

void rotate (int a[], int n)
{
    int i, temp;
    temp=a[0];
    for(i=0;i<n-1;i++)
        a[i]=a[i+1];
    a[i]=temp;

}
int main()
{
    int n,a[50],i;
    cout<<"Enter the no. of elements in an array: ";
    cin>>n;
    cout<<"Enter array: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    rotate(a,n);
    cout<<"Rotated array: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
