class BST{
	Node root;

	static class Node{
		int data;
		Node left;
		Node right;
		Node(int data){
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}

	void insert(int data){
		root = ins(root, data);
	}
	Node ins(Node root, int data){
		if(root == null){
			root = new Node(data);
			return root;
		}
		if(data < root.data){
			root.left = ins(root.left, data);
		}
		else if(data > root.data){
			root.right = ins(root.right, data);
		}
		// return unchanged Node pointer
		return root;
	}

	void search(int key){
		Node temp = root;
		searchKey(temp,key);
	}
	void searchKey(Node root, int key){
		if(key == root.data){
			System.out.println("key found.");
			return;
		}
		if(key < root.data){
			searchKey(root.left, key);
		}
		else if(key > root.data){
			searchKey(root.right, key);
		}
		
	}
	void show(){
		Node temp = root;
		inorder(temp);
	}
	void inorder(Node temp){
		if(temp == null){
			return;
		}
		else{
			inorder(temp.left);
			System.out.print(temp.data+" ");
			inorder(temp.right);
		}
	}

	public static void main(String argd[]){
		BST tree = new BST();
		tree.insert(50); 
        tree.insert(30); 
        tree.insert(20); 
        tree.insert(40); 
        tree.insert(70); 
        tree.insert(60); 
        tree.insert(80);
        tree.search(80);
		tree.show();
	}	
}