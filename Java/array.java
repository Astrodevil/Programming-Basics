import java.util.Scanner;
public class array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of students");
        int n =sc.nextInt();
        int [] marks = new int[n];
        int sum=0;
        float avg;
        for(int i=0;i<n;i++)
        {
            marks[i]=sc.nextInt();
        }
        for(int j=0;j<n;j++)
        {
            sum=sum+marks[j];
        }
        avg=sum/n;
        System.out.println(avg);




    }
}
