public class BubleSort {
   public static void main(String args[]){
       int array[]={10,25,4,2,1,3};
       int length=6;
       for(int i=0;i<length-1;i++){
           for(int j=0;j<length-i-1;j++){
                if (array[j] > array[j+1]){
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
           }
       }
       System.out.println("Sorted Array is : ");
       for(int  i=0;i<length;i++){
            System.out.println(array[i]);
       }
   } 
}
