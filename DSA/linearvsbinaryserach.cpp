#include <bits/stdc++.h>
using namespace std;
int linearSearch(int arr[],int size,int element){
    int i;
    for (i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
        return -1;
}

int binarySearch(int arr[],int size,int element){
    int low=0,mid,high=size-1;  
    // Keep searching until low <= high
    while(low<=high)
    {mid=(low+high)/2;
    if(arr[mid]==element)
        return mid;
    else if(arr[mid]<element)
        low=mid+1;
    else 
        high=mid-1;}
    return -1;

}

int main()
{
    // Unsorted array for linear search
    int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    int size = sizeof(arr)/sizeof(int);
    int element=4;
    int searchindex=linearSearch(arr,size,element);
    cout<<"The element "<<element<<" found at index "<<endl<<searchindex<<endl;
    
    // sorted array for binary search
    // int arr[] = {1,3,5,56,64,73,123,225,444};
    // int size = sizeof(arr)/sizeof(int);
    // int element=225;
    // int searchindex=binarySearch(arr,size,element);
    // cout<<"The element "<<element<<" found at index "<<endl<<searchindex<<endl;


    return 0;
}
