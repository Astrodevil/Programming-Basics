/*The program below is used to reverse an array 
 * for example an array of {1,2,3,4,5}
 * will become {5,4,3,2,1} upon reversing
 */

package kshitizjava;
import java.util.*;
public class reverse {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int size,i;
		System.out.println("enter size of array");
		size=in.nextInt();
		int arr[]=new int[size];
		System.out.println("enter values in the array");
		for(i=0;i<size;i++)
		{
			arr[i]=in.nextInt();
		}
		int temp;
		for(i=0;i<size/2;i++)
		{
			//swapping elements to obtain reversed array
			temp=arr[i];
			arr[i]=arr[size-i-1];
			arr[size-i-1]=temp;
		}
		System.out.println("array after reversing is");
		for(i=0;i<size;i++)
		{
			System.out.print(arr[i]+" ");
		}
	}

}
