import java.util.*;
public class Temperature_Conversion
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        double c=0.0,k=0.0,f=0.0;
        int n;
        System.out.println("Enter the value of the temperature you wish to convert");
        double value=sc.nextDouble();
        System.out.println("In which unit do you have the temperature?");
        System.out.println("Enter 1 for Celsius to Fahrenheit and Kelvin");
        System.out.println("Enter 2 for Fahrenheit to Celsius and Kelvin");
        System.out.println("Enter 3 for Kelvin to Celsius and Fahrenheit");
        n=sc.nextInt();
        switch(n)
        {
            case 1:
            {
                System.out.println("The answer in Fahrenheit will be:");
                f=(value*9/5)+32;
                System.out.println(f);
                System.out.println("The answer in Kelvin will be:");
                k=value+273;
                System.out.println(k);
                break;
            }
            case 2:
            {
                System.out.println("The answer in Celsius will be:");
                c=(value*5/9)-32;
                System.out.println(c);
                System.out.println("The answer in Kelvin will be:");
                k=c+273;
                System.out.println(k);
                break;
            }
            case 3:
            {
                System.out.println("The answer in Celsius will be:");
                c=value-273;
                System.out.println(c);
                System.out.println("The answer in Fahrenheit will be:");
                f=(c*9/5)+32;
                System.out.println(f);
                break;
            }
            default:
            {
                System.out.println("Invalid choice");
            }
        }
    }
}