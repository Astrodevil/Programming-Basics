#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void selectionSort(int arr[], int arrLen) {
    //   Selection sort: Divides an array into 2 portions, the left being sorted and right unsorted.
    //   Uses this segmentation to move the smallest item in each pass from the unsorted portion into the sorted portion.
    //   Each pass will always move the smallest value in the unsorted portion into the sorted portion.
    //   Time Complexity: Best - O(n2) Average - O(n2) Worst - O(n2)

    int i, j, minVal, temp;

    for (i = 0; i < arrLen; i++) {
        //   Assume index i to be the smallest for the first pass
        //   The for loop will increment this so all values below i should be sorted correctly
        minVal = i;

        //   Loop for i+1 as value at index i is being used for comparison and swap
        for (j = i + 1; j < arrLen; j++) {

            //   If the value at index j is less, update the index for minVal
            if (arr[j] < arr[minVal]) {
                minVal = j;
            }
        }

        //   Once the j loop terminates, min_val will hold the position of the smallest value
        //   Using this index, swap the values of index i and minVal
        temp = arr[i];
        arr[i] = arr[minVal];
        arr[minVal] = temp;
    }
}

//  Driver program for testing the selection sort
int main() {
    int arr[100], arrLen, i;

    printf("Enter number of elements in the array: ");
    scanf("%d", &arrLen);

    printf("Enter %d integers\n\r", arrLen);

    for (i = 0; i < arrLen; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, arrLen);

    printf("Printing the sorted array:\n\r");

    for (i = 0; i < arrLen; i++) {
        printf("%d\n\r", arr[i]);
    }

    return 0;
}
