//queue
#include<bits/stdc++.h>
using namespace std;

class Queue
{
	int sz;
	int front,end;
	int arr[1000];
	public:
		Queue(int a)
		{
			//a is size of array
			sz=a;
			front=-1;
			end=-1;
		}
		
		bool isFull()
		{
			if(end==sz-1)
			{
				return true;
			}
			return false;
		}
		
		bool isEmpty()
		{
			if(end==front)
			{
				return true;
			}
			return false;
		}
		
		void push(int x)
		{
			arr[++end]=x;
		}
		
		void pop()
		{
			front++;
		}
		
		int peek()
		{
			return arr[front+1];
		}
		
		int size()
		{
			return end-front;
		}
		
};

int main(void)
{
	Queue q(10);
	int ch=1;
	while(ch != 5)
	{
		cout<<"\nEnter your choice:\n1.Push\n2.Pop\n3.Peek\n4.Size\n5.Quit\nChoice : ";
		cin>>ch;
		if(ch==1)
		{
			if(q.isFull())
			{
				cout<<"\nOVERFLOW!!";
			}
			else
			{
				int a;
				cout<<"\nEnter a value: ";
				cin>>a;
				q.push(a);
			}
		}
		else if(ch==2)
		{
			if(q.isEmpty())
			{
				cout<<"\nUNDERFLOW!!";
			}
			else
			{
				q.pop();
			}
		}
		else if(ch==3)
		{
			if(q.isEmpty())
			{
				cout<<"\nEmpty Queue";
			}
			else
			{
				cout<<q.peek();
			}
		}
		else if(ch==4)
		{
			cout<<q.size();
		}
	}
}

