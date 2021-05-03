import java.util.Scanner;
public class conditionals_practice {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sub_1 = sc.nextInt();
        int sub_2 = sc.nextInt();
        int sub_3 = sc.nextInt();
        int avg = (sub_1+sub_2+sub_3)/3;
        if((avg>=40)&&(sub_1>=33)&&(sub_2>=33)&&(sub_3>=33))
        {
            System.out.println("STUDENT IS PASSED");
        }
        else
        {
            System.out.println("STUDENT IS FAILED");
        }
        long salary = sc.nextLong();
        if(salary<=250000)
        {
            System.out.println("NO TAX");
        }
        else if ((salary>250000)&&(salary<500000))
        {
            System.out.println("TAX IS "+5*salary/100);
        }
        else if((salary>500000)&&(salary<1000000))
        {
            System.out.println("TAX IS "+20*salary/100);
        }
        else
        {
            System.out.println("TAX IS "+30*salary/100);
        }
        int num = sc.nextInt();
        switch (num)
        {
            case 1:
                System.out.println("MONDAY");
                break;
            case 2:
                System.out.println("TUESDAY");
                break;
            case 3:
                System.out.println("WEDNESDAY");
                break;
            case 4:
                System.out.println("THURSDAY");
                break;
            case 5:
                System.out.println("FRIDAY");
                break;
            case 6:
                System.out.println("SATURDAY");
                break;
            case 7:
                System.out.println("SUNDAY");
                break;
            default:
                System.out.println("FUNDAY");
        }
       long year = sc.nextLong();
       if(year%400==0)
       {
           System.out.println("LEAP YEAR");
       }
       else
       {
           System.out.println("NOT A LEAP YEAR");
       }
     String s = sc.nextLine();
     if(s.endsWith(".org"))
        {
            System.out.println("Organization website");
        }
     else if(s.endsWith(".com"))
        {
            System.out.println("Commercial website");
        }
     else if(s.endsWith(".in"))
     {
         System.out.println("Indian website");
     }
     else
     {
         System.out.println("Invalid Domain");
     }
    }
}
