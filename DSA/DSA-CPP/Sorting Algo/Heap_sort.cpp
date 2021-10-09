#include <iostream>
using namespace std;
  
void heapsort(int arr[], int n, int root)
{
   int largest = root; 
   int l = 2*root + 1; 
   int r = 2*root + 2; 
  
   if (l < n && arr[l] > arr[largest])
   largest = l;

   if (r < n && arr[r] > arr[largest])
   largest = r;
  
   if (largest != root)
      {
      swap(arr[root], arr[largest]);
  
      heapsort(arr, n, largest);
      }
}
  
void heapSort(int arr[], int n)
{
   for (int i = n / 2 - 1; i >= 0; i--)
   heapsort(arr, n, i);
  
   for (int i=n-1; i>=0; i--)
   {
      swap(arr[0], arr[i]);
  
      heapsort(arr, i, 0);
   }
}
  
void showArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
int main()
{
   int heap_arr[] = {2,8,15,12,11,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   showArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   showArray(heap_arr, n);
}
