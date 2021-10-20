// Program to check if a number is palindrome number or not

import java.util.Scanner;

public class palindrome {

    public static void main(String argv[]) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number: ");

        int number = sc.nextInt();

        int duplicate_number = number, remainder = 0, reverse = 0;

        while (duplicate_number > 0) {
            remainder = duplicate_number % 10;
            reverse = reverse * 10 + remainder;
            duplicate_number /= 10;
        }

        if (reverse == number)
            System.out.println(number + " is a palindrome number ");
        else
            System.out.println(number + " is not a palindrome number ");
    }
}
