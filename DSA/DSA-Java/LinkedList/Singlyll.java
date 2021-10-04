class Singlyll
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
		if(head == null)
		{
			head = new Node(data);
			return;
		}
		Node new_node = new Node(data);
		new_node.next = head;
		head = new_node;
	}

    public void inBetween(Node prev_node, int data){
		if(head == null){
			head = new Node(data);
			return;
		}
		if(prev_node.next == null){
			System.out.println("cant insert because pre_node of next is null, try inserting at last.");
			return;
		}
		Node new_node = new Node(data);
		new_node.next = prev_node.next;
		prev_node.next = new_node;
	}

    public void atLast(int data){
		if(head == null){
			head = new Node(data);
			return;
		}
		Node new_node = new Node(data);
		new_node.next = null;
		Node last_node = head;
		while(last_node.next != null){
			last_node = last_node.next;
		}
		last_node.next = new_node;
		return;
	}

	public void deleteFirst()
	{
		if(head == null)
		{
			System.out.println("List is already empty.");
		}
		else if(head.next == null)
		{
			head = null;
		}
		else
		{
			head = head.next;
		}
	}

	public void deleteLast()
	{
		if(head == null)
		{
			System.out.println("List is already empty.");
		}
		else if(head.next == null)
		{
			head = null;
		}
		else
		{
			Node temp = head;
			while(temp.next.next != null)//[B]->[c]->[D]->[E]-x
			{
				temp = temp.next;
			}
			temp.next = null;

		}

	}

	public void deletePos(int pos)
	{
		if(head == null)
		{
			System.out.println("List is already empty.");
		}
		else if(head.next == null)
		{
			head = null;
		}
		else if(pos == 0)
		{
			head = head.next;
		}
		else
		{
			Node temp = head;
			int i = 0;
			while(i < pos-1)//refer this to understand the loop[A]->[B]->[c]->[D]->[E]-x
			{
				if(temp == null)
				{
					System.out.println("Given position is invalid.");
					return;
				}
				temp = temp.next;
				i++;
			}
			Node temp2 = temp.next.next;
			temp.next = temp2;
		}
	}

	public void deleteKey(int key)
	{
		if(head == null)
		{
			System.out.println("List is already empty.");
		}
		else if(head.data == key)
		{
			if(head.next == null)
			{
				head = null;
			}
			else
			{
				head = head.next;
			}
		}
		else
		{
			Node temp = head;
			Node prev = null;
			boolean check = false;
			while(temp != null)//[A]->[B]->[c]->[D]->[E]-x
			{
				if(temp.data == key){
					check = true;
					break;
				}
				prev = temp;
				temp = temp.next;
			}
			if(check)
			{
				prev.next = temp.next;
			}
			else
			{
				System.out.println("Key not found.");
			}
		
		}
	}

	public void display()
	{	
		if(head == null)
		{
			System.out.println("Your list is Empty.");
		}
		else
		{
			Node node = head;
			while(node != null)
			{
				System.out.print(node.data +" ");
				node = node.next;
			}
			System.out.print("\n");
		}
	}

	public static void main(String a[])
	{
		Singlyll list = new Singlyll();
		list.insert(10);
		list.insert(11);
		list.insert(12);
		list.insert(13);
		list.insert(14);
		list.insert(15);
		list.insert(16);
		list.insert(17);
		list.insert(18);

		list.display();

		list.deleteKey(10);
		list.display();

		list.deleteKey(12);
		list.display();
		
		list.deleteLast();
		list.display();
		
		list.deleteFirst();
		list.display();

		list.deletePos(1);
		list.display();

		list.deletePos(11);
		list.display();


	}
}
