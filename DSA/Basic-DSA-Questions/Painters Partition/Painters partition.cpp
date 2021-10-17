

#include <bits/stdc++.h>
using namespace std;



class Solution
{
  public:
  
  
    long long minTime(int a[], int n, int k)
    {
         long long int s = 0;

    for(int i = 0; i < n; i++){
        s = s + a[i];
    }
    
    long long int hi = s, li = s/k;
    long long int ans = hi;
    while(li <= hi){
        long long mid = li + (hi - li)/2;
        long long int x = 1, y = 0, i = 0;
        //Now, we will check whether its possible to paint the boards in mid number of days
        while(i < n){
            if(y + a[i] <= mid){
                y = y + a[i];
            }
            else if(a[i] > mid){
                x = k + 1;
                break;
            }
            else{
                x++;
                y = a[i];
            }
            i++;
        }
        if(x <= k){
            hi = mid - 1;
            ans = mid;
        }
        else{
            li = mid + 1;
        }
    }
    return ans;
     
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  