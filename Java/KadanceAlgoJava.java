public class KadaneAlgoJava {

	public static void main(String[] args) {
	
		int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	    int currSum = 0;
	    int maxSum = 0;
	    for(int i=0;i<a.length;i++){
	        currSum=currSum+a[i];
	        if(currSum>maxSum){
	            maxSum=currSum;
	        }
	        if(currSum<0){
	            currSum=0;
	        }
	    }
	    System.out.println(maxSum);
		
	}

}
