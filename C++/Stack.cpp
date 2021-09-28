//Stack implementation
#include <bits/stdc++.h>
using namespace std;

class Stack
{
	int top;
	int arr[10000];
	int sze;

public:
	Stack(int sz)
	{
		top = -1;
		sze = sz;
	}

	void push(int x)
	{
		arr[++top] = x;
	}

	void pop()
	{
		top--;
	}

	int tos()
	{
		return arr[top];
	}

	int size()
	{
		return (top + 1);
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		return false;
	}

	bool isFull()
	{
		if (top == sze - 1)
		{
			return true;
		}
		return false;
	}
	void show()
	{
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
	}
};

int main(void)
{
	Stack s(10);
	int ch = 1;
	while (ch != 7)
	{
		cout << "\nEnter your choice:\n1.Push\n2.Pop\n3.Show top\n4.Size\n5.Is empty\n6.Show\n7.Quit\nChoice: ";
		cin >> ch;
		if (ch == 1)
		{
			if (s.isFull())
			{
				cout << "\nOVERFLOW!!";
			}
			else
			{
				int x;
				cout << "\nEnter value: ";
				cin >> x;
				s.push(x);
			}
		}
		else if (ch == 2)
		{
			if (s.isEmpty())
			{
				cout << "\nUNDERFLOW!!";
			}
			else
			{
				s.pop();
			}
		}
		else if (ch == 3)
		{
			if (s.isEmpty())
			{
				cout << "\nEmpty Stack!!";
			}
			else
			{
				cout << "\nTop os Stack is: " << s.tos();
			}
		}
		else if (ch == 4)
		{
			cout << "\nSize: " << s.size();
		}
		else if (ch == 5)
		{
			cout << "\n Is empty: " << s.isEmpty();
		}
		else if (ch == 6)
		{
			if (s.isEmpty())
			{
				cout << "\nEmpty Stack!!";
			}
			else
			{
				cout << "\nStack is :";
				s.show();
			}
		}
	}
}
