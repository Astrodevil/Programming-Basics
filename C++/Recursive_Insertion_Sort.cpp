// Recursive C++ program for insertion sort

// TIME COMPLEXITY
//      1. Best complexity: n
//      2. Average complexity: n^2
//      3. Worst complexity: n^2

#include <iostream>
using namespace std;

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	insertionSortRecursive( arr, n-1 );

	int last = arr[n-1];
	int j = n-2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
}

void display(int arr[], int n)
{
	for (int i=0; i < n; i++)
		cout << arr[i] <<" ";
}

int main()
{
	int n;
    cout<<"Enter number of elements : ";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements :\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"\nBefore Sort the array is :\n";
    display(arr,n);

	insertionSortRecursive(arr, n);

    cout<<"\nAfter Insertion Sort the array is :\n";
	display(arr, n);

	return 0;
}
