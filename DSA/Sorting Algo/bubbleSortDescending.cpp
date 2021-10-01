#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int bubbleSort(int arr[], int n)
{
	int i, j, counter = 0;
	for (i = 0; i < n-1; i++){	
	
	
		for (j = 0; j < n-i-1; j++)
			if (arr[j] < arr[j+1])
				swap(&arr[j], &arr[j+1]);
				counter++;
	}
	return counter;

}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = {7, 1, 4, 12, 67, 33, 45};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Total comparisons - "<<bubbleSort(arr, n)<<endl;
	// bubbleSort(arr, n);
	cout<<"Sorted array: \n";
	printArray(arr, n);

	return 0;
}


