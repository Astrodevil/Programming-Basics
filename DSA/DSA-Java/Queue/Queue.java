//Array implementation Of Queue
// For implementing queue, we need to keep track of two indices, front and rear. We enqueue an item at the rear and dequeue an item from the front. If we simply increment front and rear indices, then there may be problems, the front may reach the end of the array. The solution to this problem is to increase front and rear in circular manner (See this for details)
class Queue{
	int front,rear,size;
	int capacity;
	int array[];

	public Queue(int capacity){
		this.capacity = capacity;
		front = this.size = 0;
		rear = capacity - 1;  
		array = new int[this.capacity];
	}

	boolean isFull(Queue q){
		return (q.size == q.capacity);
	}

	boolean isEmpty(Queue q){
		return (q.size == 0);
	}
	void insert(int data){
		if(isFull(this)){
			System.out.println("Queue is full.");
		}
		else{
			this.rear = (this.rear + 1) % this.capacity;
			this.array[this.rear] = data;
			this.size++;
		}
	}

	void delete(){
		if(isEmpty(this)){
			System.out.println("Queue is Empty.");
		}
		else{
			int item = this.array[this.front];
			this.front = (front + 1) % this.capacity;
			this.size--;
		}
	}

	void front() 
	{ 
		if (isEmpty(this)){
			System.out.println("Queue is Empty"); 
		}
		else{
			System.out.println(this.array[this.front]);
		}
	} 

	void rear() 
	{ 
		if (isEmpty(this)){
			System.out.println("Queue is Empty"); 
		}
		else{
			System.out.println(this.array[this.rear]);
		}
	} 

	void show(){
		if(isEmpty(this)){
			System.out.println("Queue is Empty");
		}
		else{
			for(int i = front; i <=this.rear; i++){
				System.out.print(this.array[i]+" ");
			}
			System.out.print("\n");
		}
	}

	public static void main(String[] args){
		Queue q = new Queue(3);
		q.insert(2);
		q.insert(3);
		q.insert(4);
		q.front();
		q.show();
		q.delete();
		q.show();
		q.delete();
		q.show();
		q.delete();
		q.front();
		q.show();
		q.insert(1);
		q.show();
		q.insert(3);
		q.show();
		q.insert(5);
		q.show();
		q.rear();
	}
}