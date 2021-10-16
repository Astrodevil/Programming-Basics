# Program to implement merge sort

import math     # to use math.inf

# function for merge sort
# arr[l..r] is the array that needs to be sorted
# l and r are the left and right indices of arr
def mergeSort(arr, l, r):
    
    if l < r:
        # find mid index of arr
        m = (l + r) // 2

        # sort left half using merge sort
        mergeSort(arr, l, m)

        # sort right half using merge sort
        mergeSort(arr, m + 1, r)

        # merge the two half
        merge(arr, l, m, r)


# function for merging two sub arrays of arr[l..r]
def merge(arr, l, m, r):
    # length of left half of arr
    nL = m - l + 1

    # length of right half of arr
    nR = r - m

    # create two empty arrays L[0..nL] and R[0..nR]
    L = [0] * (nL + 1)
    R = [0] * (nR + 1)

    # copy left half of arr in L[0..nL-1]
    for i in range(0, nL):
        L[i] = arr[l + i]

    # copy right half of arr in R[0..nR-1]
    for j in range(0, nR):
        R[j] = arr[m + 1 + j]

    # put infinity as sentinel value at the end of Both L and R
    L[nL] = math.inf
    R[nR] = math.inf

    # iterate over L and R
    # and copy the smallest of L[i] and R[j] to arr[k]
    i = 0
    j = 0
    for k in range(l, r + 1):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1


# driver code to test the implementation
A = [2, 3, 5, 1, 5, 9, 7, 2, 8]

mergeSort(A, 0, len(A) - 1)

print(A)    # output: [1, 2, 2, 3, 5, 5, 7, 8, 9]