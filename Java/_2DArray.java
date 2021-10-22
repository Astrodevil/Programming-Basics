// package JAVA;
import java.util.Scanner;
public class _2DArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of Rows");
        int rows = sc.nextInt();

        System.out.println("Enter the number of Columns");
        int cols = sc.nextInt();

        int a[][] = new int[rows][cols];
        int b[][] = new int[rows][cols];

        System.out.println("Enter the elements of array A");
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                a[i][j]=sc.nextInt();
            }
        }

        System.out.println("Enter the elements of array B");
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                b[i][j]=sc.nextInt();
            }
        }

        int c[][] = new int[rows][cols];
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                c[i][j]=a[i][j]*b[i][j];
            }
        }

        System.out.println("The sum of array A and B is :");
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<cols;j++)
            {
                System.out.print(c[i][j]+" ");
            }System.out.println();
        }

         sc.close();
    }
}

