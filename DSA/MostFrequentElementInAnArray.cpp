#include <bits/stdc++.h>
using namespace std;
 
int mostFrequent(int arr[], int n)
{
    
    sort(arr, arr + n);
 
    
    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }
 
    
    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }
 
    return res;
}
 

int main()
{
	int num;
	cout<<"Enter array size:";
	cin>>num;
    int arr[num];
    cout<<"Enter array elements:\n";
    for(int i=0; i<num; ++i)
    {
    	cin>>arr[i];
	}
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Most frequent element:"<<mostFrequent(arr, n);
    return 0;
}
