class CountSort {
  
  void countSort(int array[], int size) {
    int[] output = new int[size + 1];

    int max = array[0];  
    for (int i = 1; i < size; i++) {  // Find the largest element in the array
      if (array[i] > max)
        max = array[i];
    }
    int[] count = new int[max + 1];

    for (int i = 0; i < max; ++i) {
      count[i] = 0;
    }

    for (int i = 0; i < size; i++) {  // Store the count of each element in count[]
      count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {   // Store the cummulative count of each array
      count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {  // Find index of each element of array[] in count[] and place the elements in output[]
      output[count[array[i]] - 1] = array[i];
      count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
      array[i] = output[i];  // Copying the sorted elements into original array
    }
  }

  public static void main(String args[]) {
    int[] arr = { 6, 2, 2, 8, 3, 4, 4 };
    int size = arr.length;
    CountSort object = new CountSort();
    object.countSort(arr, size);
    System.out.println("Sorted Array in Ascending Order : ");
    System.out.println(Arrays.toString(arr));
  }
}
