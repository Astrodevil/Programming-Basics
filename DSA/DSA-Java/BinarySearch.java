import java.io.*;
import java.util.*;

public class BinarySearch{
	public static void main(String[] args) {
		// Make sure that given array is sorted 
		int[] arr = {1,2,3,4,5,6,7,8,9,10};
		Scanner in = new Scanner(System.in);
		System.out.print("Enter The Element To be Search :");
		int target = in.nextInt();
		int ans =binarySearch(arr,target);
		System.out.println("The element '"+target+"' is Present at "+ans+" th Location");
	}

	static int binarySearch(int[] arr, int target){
		//initializing start=0 and end=arr.length - 1
		int start = 0;
		int end  = arr.length - 1;
		
		while(start <= end){
			
			int mid = (start + end)/2;
			//if target element is less than middle element 
			if(target < arr[mid] ){
				end = mid -1;
			}
			//target element is greater than mid element
			else if(target > arr[mid]){
				start = mid +1;
			}
			//target element is equal to mid element
			else{	
				return mid;
			}
		}
		return -1;
	}
}