//Representation of stack using array

import java.util.Scanner;

class StackArray
{
	final int MAX = 10;
	int data[] = new int[MAX];
	int top;
	StackArray()
	{
		top = -1;
	}

	public boolean isEmpty()
	{
		return (top <= -1);
	}

    //Inserting an element into stack
	public void push(int d)
	{
		if(top == MAX-1)
		{
			System.out.println("Stack is full.");
		}
		else
		{
			top++;
			this.data[top] = d;
		}
	}

    //Checking top most element in a Stack (Peeking)
	public void peek()
	{
		if(top <= -1)
		{
			System.out.println("Stack is Empty");
		}
		else
		{
			System.out.println(data[top]);
		}
	}

    //deleting an element from stack
	public void pop()
	{
		if(top <= -1)
		{
			System.out.println("Stack is Empty");
		}
		else
		{
			int a = this.data[top];
			top--;
		}
	}

	public void watch()
	{
		int i = 0;
		if(top <= -1)
		{
			System.out.println("Stack is Empty");
		}
		else
		{
			while(i <= this.top)
			{
				System.out.print(this.data[i] +" ");
				i++;
			}
		}
		
	}
	public static void main(String a[])
	{
		StackArray s = new StackArray();
		s.push(1);
		s.push(3);
		s.push(4);
		s.push(5);
		s.peek();
		s.pop();
		s.peek();
		s.watch();
	}
}