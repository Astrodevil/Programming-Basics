//Write a Program to Count Smaller Numbers after self:

//You are given an integer array and you have to return a new count array. 
//The counts array has the property where count[i] is the number of smaller elements to the right of nums[i].
//eg. INPUT: arr:[6,2,5,8]
// OUTPUT: [2,0,0,0]


import java.util.*;

class Main {
	public static void main (String[] args) {
		int[] nums={6,2,5,8};
		int[] res=new int[nums.length];
		int[] count=new int[nums.length];
		int[] indexes=new int[nums.length];
		for(int i=0;i<nums.length;i++){
		    indexes[i]=i;
		}
		mergesort(nums,indexes,count,0,nums.length-1);
		for(int i=0;i<count.length;i++){
		    res[i]=count[i];
		}
		System.out.print(Arrays.toString(res));
	}
	
	static void mergesort(int[] nums,int[] indexes,int[] count,int start,int end){
	    if(start>=end) return;
	    int mid=start+(end-start)/2;
	    mergesort(nums,indexes,count,start,mid);
	    mergesort(nums,indexes,count,mid+1,end);
	    merge(nums,indexes,count,start,mid,end);
	}
	
	static void merge(int[] nums,int[] indexes,int[] count,int start,int mid,int end){
	    int left_ind=start;
	    int right_ind=mid+1;
	    int[]tempInd=new int[end-start+1];
	    int ind=0;
	    int cnt=0;
	    while(left_ind<=mid && right_ind<=end){
	        if(nums[indexes[left_ind]]>nums[indexes[right_ind]]){
	            tempInd[ind]=indexes[right_ind];
	            cnt++;
	            right_ind++;
	        }
	        else{
	            tempInd[ind]=indexes[left_ind];
	            count[indexes[left_ind]]+=cnt;
	            left_ind++;
	        }
	        ind++;
	    }
	    while(left_ind<=mid){
	        tempInd[ind++]=indexes[left_ind];
	        count[indexes[left_ind]]+=cnt;
	        left_ind++;
	    }
	    while(right_ind<=end){
	        tempInd[ind++]=indexes[right_ind++];
	    }
	    int k=start;
	    for(int i:tempInd){
	        indexes[k++]=i;
	    }
	}
}
