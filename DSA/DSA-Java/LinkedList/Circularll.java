class Circularll
{
	Node head;

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

	public void insert(int data)
	{
		Node new_node = new Node(data);
		if(head == null)
		{
			head = new_node;
			new_node.next = head;
		}
		else
		{
			Node temp = head;
			while(temp.next != head)
			{
				temp = temp.next;
			}
			temp.next = new_node;
			new_node.next = head;
			head = new_node;
		}
	}

	public void inBetween(Node prev_node, int data)
	{
		if(head == null)
		{
			Node new_node = new Node(data);
			head = new_node;
			new_node.next = head;
			return;
		}
		Node new_node = new Node(data);
		new_node.next = prev_node.next;
		prev_node.next = new_node;
	}
	public void delete()
	{
		if(head == null)
		{
			System.out.println("List is empty.");
		}
		else if(head.next == head)
		{
			head = null;
		}
		else
		{
			Node temp = head;
			while(temp.next != head)
			{
				temp = temp.next;
			}
			temp.next = head.next;
			head = head.next;
		}
	}

	public void show()
	{
		Node temp = head;
		if(head == null)
		{
			System.out.println("List is empty.");
		}
		else
		{
			while(temp.next != head)
			{
				System.out.print(temp.data +" ");
				temp = temp.next;
			}
			System.out.print(temp.data +" ");

			System.out.print("\n");

		}
	}

	public static void main(String a[])
	{
		Circularll l = new Circularll();
		l.insert(10);
		l.inBetween(l.head.next, 11);
		// System.out.print(l.head.data +" ");
		l.insert(12);
		l.insert(13);
		l.insert(14);
		l.insert(15);
		l.insert(16);
		l.insert(17);
		l.show();
		l.delete();
		l.show();
		l.delete();
		l.show();
		// System.out.print(l.head.data +" ");
	}
}