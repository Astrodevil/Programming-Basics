import java.util.Scanner;
public class loops_practice {
    public static void main(String[] args) {
               /*int n = 4;
        for (int i=n; i>0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.print("\n");
        }    */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        /*int count =1;
        int sum=0;
        while(count<=n)
        {
            if(count%2==0)
            {
                sum=sum+count;
            }
            count++;
        }
        System.out.println(sum);*/
        /*for(int i=1;i<=10;i++)
        {
            System.out.println(i*n);
        }*/
        /*for(int i=10;i>=1;i--)
        {
            System.out.println(i*n);
        }*/
        int fact=1;
        for(int i=1;i<=n;i++)
        {
            fact=fact*i;
        }
        System.out.println(fact);
    }
}
