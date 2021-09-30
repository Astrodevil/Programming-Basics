#include<iostream>
using namespace std;

int* insertatbeginning(int arr[] ,int val ,int s)
{
    s++;
    for(int i=s ; i>=0 ; i--){
        arr[i+1]=arr[i];
    }
    arr[0]=val;
}
int delelement(int arr[] ,int val ,int s)
{
    int i;
for (i=0; i<s; i++)
    if (arr[i] == val)
        break;


if (i < s)
{
    s = s - 1;
    for (int j=i; j<s; j++)
        arr[j] = arr[j+1];
}

return s;
}

int main()
{
    cout<<"Enter size of array : ";
    int s;cin>>s;
    int arr[s];
    cout<<"Enter elements of array-\n";
    for(int i=0 ; i<s ; i++){
        cin>>arr[i];
    }
    cout<<"*****MENU*****\n1.Insert at begnning\n2.Delete given element\nEnter your choice : ";
    int ch;cin>>ch;
    if(ch==1){
        cout<<"Enter element : ";
        int val;cin>>val;
        insertatbeginning(arr, val, s);
        cout<<"Array after inserting-\n";
        for(int i=0 ; i<=s ; i++){
            cout << arr[i] << " ";
        }
    }
    if(ch==2){
        cout<<"Enter element to be deleted : ";
        int val;cin>>val;
        int n=delelement(arr, val, s);
        for(int i=0 ; i<n ; i++){
            cout << arr[i] << " ";
        }

    }
}


