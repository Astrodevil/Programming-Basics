/*The program below checks if a number is Niven or not
  A number is said to be Niven if it is divisible by the
  sum of it's digits
  Example: 126
  sum of its digits=1+2+6 = 9 
  and 126 is divisble by 9
  hence its Niven
 */


package kshitizjava;
import java.util.*;
public class Niven {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int num,sum=0,d,p;
		System.out.println("Enter A Number");
		num=in.nextInt();
		p=num;
		while(p!=0)
		{
			d=p%10;
			sum+=d;
			p/=10;
		}
		if(num%sum==0)
			System.out.println("Its Niven Number");
		else
			System.out.println("Its Not Niven Number");

	}

}
