import java.util.*;

class LeftRotate {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		int a[]={7,8,9,1,2,3};//can be replaced by the arry as input
		int n=sc.nextInt();//Number of left rotations
		reverse(a,0,n-1);
		reverse(a,n,a.length-1);
		reverse(a,0,a.length-1);
        //Printing the updated array
		for(int i=0;i<a.length;i++)
		System.out.print(a[i]+" ");
	}
	static void reverse(int a[],int l,int r){
	    while(l<r){
	        int t=a[l];a[l]=a[r];a[r]=t;
	        l++;r--;
	    }
	}
}