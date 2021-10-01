/*
 *The program calculates GCD of two numbers 
 *also known as HCF of two numbers
 *for example 25,45
 *have a GCD of 5
 */


package kshitizjava;
import java.util.*;
public class GCD {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int a,b,i,p,gcd=0;
		System.out.println("enter two numbers");
		a=in.nextInt();
		b=in.nextInt();
		p=a*b;
		for(i=1;i<p;i++)
		{
			if(a%i==0 && b%i==0)
				gcd=i;
		}
		System.out.println("The GCD Is "+gcd);

	}

}
