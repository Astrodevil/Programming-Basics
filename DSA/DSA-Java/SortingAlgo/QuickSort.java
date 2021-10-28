// Program to sort an array using quicksort technique

import java.util.Scanner;

public class QuickSort {

    void quick(int a[], int first, int last) {
        if (first >= 0 && last >= 0 && first < last) {
            int pivot = divide(a, first, last);
            quick(a, first, pivot - 1);
            quick(a, pivot + 1, last);
        }
    }

    int divide(int a[], int first, int last) {
        int pivot = a[last];
        int i = first - 1;
        for (int j = first; j < last; j++) {
            if (a[j] <= pivot) {
                i = i + 1;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[i + 1];
        a[i + 1] = a[last];
        a[last] = temp;
        return i;
    }

    public static void main(String argv[]) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the size of the array: ");
        int size = sc.nextInt();
        int a[] = new int[size];

        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < size; i++) {
            a[i] = sc.nextInt();
        }

        QuickSort obj = new QuickSort();
        obj.quick(a, 0, size - 1);
        System.out.println("Array after applying quick sort");
        for (int i = 0; i < size; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
