/*Example
n = 5
            1
          1     1
        1    2    1
      1    3   3     1
   1    4     6    4    1
1   5   10     10    5    1 
*/
public class PascalTriangle {
    static int factorial(int n) {// Function to calculate factorial of n
        int f;

        for (f = 1; n > 1; n--) {
            f *= n;
        }
        return f;
    }

    static int ncr(int n, int r) {// Calculating nCr
        return factorial(n) / (factorial(n - r) * factorial(r));
    }

    public static void main(String args[]) {
        System.out.println();
        int n, i, j;
        n = 5;

        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n - i; j++) {
                System.out.print(" ");
            }
            for (j = 0; j <= i; j++) {
                System.out.print(" " + ncr(i, j));
            }
            System.out.println();
        }
    }
}