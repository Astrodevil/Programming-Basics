import java.util.Scanner;
public class cbse_result {
    public static void main(String[] args) {
        Scanner result = new Scanner(System.in);
        System.out.println("Enter the marks in first subject : ");
        float a = result.nextFloat();
        System.out.println("Enter the marks in second subject : ");
        float b = result.nextFloat();
        System.out.println("Enter the marks in third subject : ");
        float c = result.nextFloat();
        System.out.println("Enter the marks in fourth subject : ");
        float d = result.nextFloat();
        System.out.println("Enter the marks in fifth subject : ");
        float e = result.nextFloat();
        float total_marks = a+b+c+d+e;
        float per = total_marks/5;
        System.out.println("Total percentage : "+per);
    }
}
