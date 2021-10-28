// Program to transpose a matrix

import java.util.Scanner;

public class transpose {

  public static void main(String argv[]) {

    Scanner sc = new Scanner(System.in);

    System.out.println("Enter the size of matrix: ");
    int size = sc.nextInt();
    int matrix[][] = new int[size][size];

    System.out.println("Enter the elements of the matrix: ");
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        matrix[i][j] = sc.nextInt();
      }
      System.out.println();
    }

    int transpose_matrix[][] = new int[size][size];

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        transpose_matrix[i][j] = matrix[j][i];
        System.out.print(transpose_matrix[i][j]);
      }
      System.out.println();
    }
  }
}
