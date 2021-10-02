#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& array, int startL, int endL, int startR, int endR) {
  vector<int> left(array.begin() + startL, array.begin() + endL + 1);
  vector<int> right(array.begin() + startR, array.begin() + endR + 1);
  int mergeArrayStart = startL, leftIndex = 0, rightIndex = 0;

  while (leftIndex < left.size() && rightIndex < right.size()) {
    if (left[leftIndex] >= right[rightIndex]) {
      array[mergeArrayStart++] = right[rightIndex++];
    } else if (left[leftIndex] < right[rightIndex])
      array[mergeArrayStart++] = left[leftIndex++];
  }

  while (leftIndex < left.size()) array[mergeArrayStart++] = left[leftIndex++];
  while (rightIndex < right.size())
    array[mergeArrayStart++] = right[rightIndex++];
}
void mergeSort(vector<int>& array, int start, int end) {
  if (start >= end) return;
  int mid = start + (end - start) / 2;

  mergeSort(array, start, mid);
  mergeSort(array, mid + 1, end);
  merge(array, start, mid, mid + 1, end);
}

int main() {
  vector<int> a = {0, 0};
  mergeSort(a, 0, a.size() - 1);
  for (int i : a) cout << i << " ";
  return 0;
}
