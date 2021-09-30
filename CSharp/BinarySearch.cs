namespace CSharp
{
    public class BinarySearchAlgo
    {
    
        /// <summary>
        /// Recursive function calls itself to perform the binary searchinhg operation
        /// Once the search item is found the function returns it index or 
        /// it'll iterate untill all the items have been searched which is 'low >= high'
        /// </summary>
        /// <param name="array">Array to be searched</param>
        /// <param name="num">Item to be searched</param>
        
        public static int RecursiveBinarySearch(int[] array, int num)
        {
            return RecursiveBinarySearch(0, array.Length);
            
            int RecursiveBinarySearch(int low, int high)
            {
                if(low >= high)
                    return -1;

                int mid = (low + high) / 2;

                if(array[mid] == num)
                    return mid;

                if(array[mid] < value)
                    return RecursiveBinarySearch(mid + 1, high);

                return RecursiveBinarySearch(low, mid);
            }
        }

        /// <summary>
        /// The functionality is same as the RecursiveBinarySearch but instead of the
        /// recursion it utilizes a while loop to derive the same behaviour
        /// Once the search item is found the function returns it index or 
        /// it'll iterate untill all the items have been searched which is 'low >= high'
        /// </summary>
        /// <param name="array">Array to be searched</param>
        /// <param name="num">Item to be searched</param>
        
        public static int BinarySearch(int[] array , int num)
        {
            int low = 0;
            int high = array.Length;

            while(low < high)
            {
                int mid = (low + high) / 2;

                if(array[mid] == num)
                    return mid;

                if(array[mid] < value)
                    low = mid + 1;
                    
                else
                    high = mid;
            }

            return -1;
        }
    }
