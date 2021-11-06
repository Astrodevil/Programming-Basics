class BubbleSort {
    public static void main(String[] args) {
        int [] arr = {2, 5, 1, 7};
        sort(arr);
        for (int el: arr) {
            System.out.print(el + " ");
        }
    }

    public static void sort(int [] array) {
        boolean sorted = false;
        int temp;
        while(!sorted) {
            sorted = true;
            for (int i = 0; i < array.length - 1; i++) {
                if (array[i] > array[i+1]) {
                    temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                    sorted = false;
                }
            }
        }
    }
}