import java.util.Scanner;
public class sum{
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the first number : ");
        int a = s.nextInt();
        System.out.println("Enter the second number : ");
        int b = s.nextInt();
        int c = a+b;
        System.out.println("The sum is : "+c);
    }
}
