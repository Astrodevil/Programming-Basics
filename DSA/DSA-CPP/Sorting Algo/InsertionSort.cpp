// C++ pgm to sort the given numbers using insertion sort algorithm!
#include <iostream>
using namespace std;
 
template <class T>
// Function to print (sorted) array. 
// Pass by referrence method used.
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

// Insertion sort logic/algo. 
void InsertionSort(int A[], int n){
    for (int i=1; i<n; i++){
        int j = i-1;
        int x = A[i];
        while (j>-1 && A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}
 
int main() {
 
    int *A,n,s;
    cout<<"Enter the size of an array: "<<endl;
    cin>>s;
    A = new int[s];
    cout<<"Enter the no. of elements to enter: ";
    cin>>n;
    cout<<"Enter the elements: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    
    Print(A, n, "       A");
 
    InsertionSort(A, n);
    Print(A, n, "Sorted A");
 
    return 0;
}