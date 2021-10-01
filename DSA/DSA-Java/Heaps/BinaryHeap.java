import java.util.Scanner;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class BinaryHeap{

        private static final int d = 2;
        private int heapSize;
        private int[] heap;

        public BinaryHeap(int capacity){
            heapSize = 0;
            heap = new int[capacity + 1];
            Arrays.fill(heap, -1);
        }

        public boolean isEmpty(){
            return heapSize==0;
        }

        public boolean isFull(){
            return heapSize == heap.length;
        }

        public boolean makeEmpty(){
            return heapSize == 0;
        }

        public int parent(int i){
            return (i - 1)/d;
        }

        /**get index of k th child of i **/
        private int kthChild(int i, int k){
            return d * i + k;
        }
    
        public void insert(int x){
            if (isFull()){
                throw new NoSuchElementException("Overflow Exception");
            }
            heap[heapSize++] = x;
            heapifyUp(heapSize - 1);
        }

        public int deleteMin(){
            int keyItem = heap[0];
            delete(0);
            return keyItem;
        }

        public int delete(int ind){
            if(isEmpty()){
                throw new NoSuchElementException("Underflow Exception");
            }
            int keyItem = heap[ind];
            heap[ind] = heap[heapSize - 1];
            heapSize--;
            heapifyDown(ind);
            return keyItem;
        }

        private void heapifyUp(int i) {
            int temp = heap[i];
            while(i>0 && temp > heap[parent(i)]){
                heap[i] = heap[parent(i)];
                i = parent(i);
            }
            heap[i] = temp;
        }

        private void heapifyDown(int i){
            int child;
            int temp = heap[i];
            while(kthChild(i, 1) < heapSize){
                child = maxChild(i);
                if(temp < heap[child]){ heap[i] = heap[child]; }else break; i = child; } heap[i] = temp; } private int maxChild(int i) { int leftChild = kthChild(i, 1); int rightChild = kthChild(i, 2); return heap[leftChild]>heap[rightChild]?leftChild:rightChild;
        }
        public void printHeap(){
            System.out.print("nHeap = ");
            for (int i = 0; i < heapSize; i++)
                System.out.print(heap[i] +" ");
            System.out.println();
        }
        

    public static void main(String args[]){
        BinaryHeap b = new BinaryHeap(10);
        b.insert(1);
        b.insert(2);
        b.insert(3);
        b.insert(4);
        b.insert(5);
        b.printHeap();
        b.deleteMin();
        b.printHeap();
        b.insert(0);
        b.delete(2);
        b.printHeap();
    }
}