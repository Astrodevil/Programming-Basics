import java.util.Scanner;
 
public class matInv{

    public static void main(String argv[]){

        Scanner sc = new Scanner(System.in);

        // get the dimensions of the matrix

        System.out.println("Enter the size of square matrix ( 'n' of an 'nxn' matrix): ");

        int n = sc.nextInt();

        double a[][]= new double[n][n];

        System.out.println("\nStart entering the elements sequentially: ");

        // populate the matrix

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j] = sc.nextDouble();
 
        // call for inverting the matrix and storing the returned output in matrix 'd'
        double ans[][] = matrixInversion(a);
 
        System.out.println("\nInverse of the given "+n+"x"+n+" matrix is: ");
        
        for (int i=0; i<n; ++i){

            for (int j=0; j<n; ++j){
                System.out.print(ans[i][j]+"  ");
            }

            System.out.println();
        }
    }   
 
    public static double[][] matrixInversion(double a[][]){

        int n = a.length;

        double x[][] = new double[n][n];
        double b[][] = new double[n][n];

        int index[] = new int[n];

        for (int i=0; i<n; ++i){
            b[i][i] = 1;
        }
 
        // matrix is coverted to an upper triangle matrix ( all elements are zeroes below the diagonal)
        gaussian(a, index);
 
        // update the matrix

        for (int i=0; i<n-1; ++i)
            for (int j=i+1; j<n; ++j)
                for (int k=0; k<n; ++k)
                    b[index[j]][k]-= a[index[j]][i]*b[index[i]][k];
 
        // back substitution

        for (int i=0; i<n; ++i) {

            x[n-1][i] = b[index[n-1]][i]/a[index[n-1]][n-1];
            
            for (int j=n-2; j>=0; --j){

                x[j][i] = b[index[j]][i];

                for (int k=j+1; k<n; ++k){
                    x[j][i] -= a[index[j]][k]*x[k][i];
                }

                x[j][i] /= a[index[j]][j];
            }
        }

        return x;
    }

    public static void gaussian(double a[][], int index[]){

        int n = index.length;
        double c[] = new double[n];
 
        for (int i=0; i<n; ++i) 
            index[i] = i;
 
        for (int i=0; i<n; ++i){

            double c1 = 0;

            for (int j=0; j<n; ++j){

                double c0 = Math.abs(a[i][j]);
                if (c0 > c1) c1 = c0;
            }

            c[i] = c1;
        }

        int k = 0;

        for (int j=0; j<n-1; ++j){

            double pi1 = 0;

            for (int i=j; i<n; ++i){

                double pi0 = Math.abs(a[index[i]][j]);
                pi0 /= c[index[i]];

                if (pi0 > pi1){
                    pi1 = pi0;
                    k = i;
                }
            }
 
            int itmp = index[j];
            index[j] = index[k];
            index[k] = itmp;
            for (int i=j+1; i<n; ++i){

                double pj = a[index[i]][j]/a[index[j]][j];
 
                a[index[i]][j] = pj;
 
                for (int l=j+1; l<n; ++l)
                    a[index[i]][l] -= pj*a[index[j]][l];
            }
        }
    }
}