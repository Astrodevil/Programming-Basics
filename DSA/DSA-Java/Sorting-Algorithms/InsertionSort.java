public class InsertionSort {
    public static void main(String[] args) {
        int [] arr = {1, 5, 2, 7};
        sort(arr);
        for (int el: arr) {
            System.out.print(el + " ");
        }
    }

    public static void sort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int current = array[i];
            int j = i - 1;
            while(j >= 0 && current < array[j]) {
                array[j+1] = array[j];
                j--;
            }

            array[j+1] = current;
        }
    }
}
