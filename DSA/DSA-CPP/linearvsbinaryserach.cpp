#include <bits/stdc++.h>
using namespace std;

void linearSearch(vector<int>&ar, int n, int x)
{
	int comp = 0;
	int idx = -1;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		comp++;
		if (x == ar[i])
		{
			idx = i;
			flag = true;
			break;
		}
	}
	cout << "Comparisons Done: " << comp << '\n';
	if (flag)
	{
		cout << "Element found at index: " << idx << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}
}

void binarySearch(vector<int>&ar, int n, int x)
{
	int left = 0;
	int right = n - 1;
	bool flag = false;
	int comp = 0, idx = -1;
	while (left <= right)
	{
		comp++;
		int middle = (left + right) / 2;
		if (x == ar[middle])
		{
			flag = true;
			idx = middle;
			break;
		}
		else if (x > ar[middle])
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	cout << "Comparisons Done: " << comp << '\n';
	if (flag)
	{
		cout << "Element Found at index: " << idx << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}
}

int main()
{
    // Unsorted array for linear search
    // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    // int size = sizeof(arr)/sizeof(int);
    // int element=4;
    // int searchindex=linearSearch(arr,size,element);
    // cout<<"The element "<<element<<" found at index "<<endl<<searchindex<<endl;
    
    // sorted array for binary search
    // int arr[] = {1,3,5,56,64,73,123,225,444};
    // int size = sizeof(arr)/sizeof(int);
    // int element=225;
    // int searchindex=binarySearch(arr,size,element);
    // cout<<"The element "<<element<<" found at index "<<endl<<searchindex<<endl;

    int n;
    cin>>n; // input size from user
    vector<int>ar(n);
    for(auto &it:ar){   // input array elements
        cin>>it;  
    }

    cout << "Enter element to be search\n";
	int ele;
	cin >> ele;

	int choice;
	cout << "Enter 1 for Linear Search\n";
	cout << "Enter 2 for Binary Search\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		linearSearch(ar, n, ele);
		break;
	case 2:
        sort(ar.begin(),ar.end()); // to sort array for binary search
		binarySearch(ar, n, ele);
		break;
    default:
        cout<<"Invalid Choice\n";
	}

    return 0;
}
