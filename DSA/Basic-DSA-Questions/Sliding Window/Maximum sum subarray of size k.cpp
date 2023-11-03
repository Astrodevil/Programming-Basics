// This is the code for finding maximum sum of a subarray of size k using sliding
// window approach. Time complexity: O(n)

#include<bits/stdc++.h>
using namespace std;
#define fast              ios::sync_with_stdio(false);cin.tie(0);

int findmaxsum(vector<int>& arr, int k)
{
    int sum=0, maxsum=INT_MIN;
    int i=0, j=0;
    int n= arr.size();

    while(j<n)
    {
        sum+= arr[j];  //add element to sum

        if(j-i+1 <k)   //check if window size reached
        {
            j++;
        }
        else if((j-i+1)==k)
        {
            maxsum= max(maxsum, sum);
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return maxsum;
}

int main()
{
    fast
    vector<int> arr{1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k=4;
    // output will be 39

    cout<<"maximum sum of a subarray of size "<<k<<" is "<< findmaxsum(arr, k);

    return 0;
}
