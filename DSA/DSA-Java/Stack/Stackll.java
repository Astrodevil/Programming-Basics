//Stack using Linked List
class Stackl
{
	Node top;

	static class Node
	{
		int data;
		Node next;

		Node(int data)
		{
			this.data = data;
			this.next = null;
		}
	}

	public boolean isEmpty()
	{
		if(top == null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

    //Inserting an element into stack
	public void push(int item)
	{
		if(top == null)
		{
			top = new Node(item);
		}
		else
		{
			Node new_node = new Node(item);
			new_node.next = top;
			top = new_node;
		}
	}	

    //deleting an element from stack
	public void pop()
	{
		if(top == null)
		{
			System.out.println("Stack is empty.");
		}
		else if(top.next == null)
		{
			top = null;
		}
		else
		{
			top = top.next;
		}
	}

    //Checking top most element in a Stack (Peeking)
	public void peek()
	{
		if(top == null)
		{
			System.out.println("Stack is empty.");
		}
		else
		{
			System.out.println(top.data);
		}
	}

	public void watch()
	{
		Node temp = top;
		while(temp != null)
		{
			System.out.print(temp.data +" ");
			temp = temp.next;
		}
	}
	public static void main(String a[])
	{
		Stackl s = new Stackl();
		//// if(s.isEmpty())
		// 	System.out.println("yes");
		// }
		 	s.push(1);
		 	s.push(2);
		 	s.push(3);
		 	s.push(4);
		 	s.push(5);
		 	s.peek();
		 	s.pop();
		 	s.peek();
		 	s.watch();
		 	
	}
}