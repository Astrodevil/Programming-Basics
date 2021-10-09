public class BucketSort {
  public void bucketSort(float[] arr, int n) {
    if (n <= 0)
      return;
    
    @SuppressWarnings("unchecked")
    ArrayList<Float>[] bucket = new ArrayList[n];

    for (int i = 0; i < n; i++) // Create empty buckets
      bucket[i] = new ArrayList<Float>();

    for (int i = 0; i < n; i++) { // Add elements into the buckets
      int bucketIndex = (int) arr[i] * n;
      bucket[bucketIndex].add(arr[i]);
    }
    
    for (int i = 0; i < n; i++) {
      Collections.sort((bucket[i])); // Sort the elements of each bucket
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0, size = bucket[i].size(); j < size; j++) {
        arr[index++] = bucket[i].get(j); // Getting the sorted array
      }
    }
  }
  
  public static void main(String[] args) {
    BucketSort object = new BucketSort();
    float[] arr = { (float) 0.82, (float) 0.62, (float) 0.15, (float) 0.22, (float) 0.37, (float) 0.92,
        (float) 0.53 };
    object.bucketSort(arr, 7);

    for (float i : arr)
      System.out.print(i + "  ");
  }
}
