import java.util.Queue;
import java.util.LinkedList; 
import java.util.*;

class BinaryTree{
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
	// Node temp = root;
	//inserting the data into the binary tree at first position available in level order.
	void insert(int data){
		Queue<Node> q = new LinkedList<>();
		Node temp = root;
		q.add(temp);
		// if(root == null){
		// 	root = new Node(data);
		// 	return;
		// }
		while(!q.isEmpty()){
			temp = q.peek();
			q.remove();

			if(temp.left == null){
				temp.left = new Node(data);
				break;
			}
			else{
				q.add(temp.left);	
			}
			if(temp.right == null){
				temp.right = new Node(data);
				break;
			}
			else{
				q.add(temp.right);
			}
		}
	}

	void delete_deepest(Node root, Node d_node){
		Queue<Node> q = new LinkedList<>();
		q.add(root);
		Node temp;

		while(!q.isEmpty()){
			temp = q.peek();
			q.remove();
			if(temp == d_node){
				temp = null;
				break;
			}
			if(temp.right != null)
			{
				if(temp.right == d_node) {
				temp.right = null;
				break;
			}
			else
				q.add(temp.right);
			}
			if(temp.left != null)
			{
				if(temp.left == d_node) {
				temp.left = null;
				break;	
			}
			else
				q.add(temp.left);
			}
		}
	}
// 1. Starting at root, find the deepest and rightmost node in binary tree and node which we want to delete.
// 2. Replace the deepest rightmost node’s data with node to be deleted.
// 3. Then delete the deepest rightmost node.
	void del(Node root, int key){
		if(root == null){
			return;
		}
		if(root.left == null && root.right == null){
			if(root.data == key){
				root = null;
				return;
			}
			else{
				return;
			}
		}
		Queue<Node> q = new LinkedList<>();
		Node temp = root;
		Node key_node = null; 
		q.add(root);

		while(!q.isEmpty()){
			temp = q.peek();
			q.remove();
			if(temp.data == key){
				key_node = temp;//even we find the key traverse util we get the deepest node.
			}
			if(temp.right != null){
				q.add(temp.right);
			}
			if(temp.left != null){
				q.add(temp.left);
			}
		}
		if(key_node != null){
			int x = temp.data; //temp will be our deepest node.
			delete_deepest(root, temp);
			key_node.data = x;
		}
	} 


	public static void main(String args[]){
		BinaryTree b = new BinaryTree();
		// b.root = new Node(9);
		b.root = new Node(10);
		// b.root.left = new Node(11); 
        // b.root.left.left = new Node(7); 
        // b.root.right = new Node(9); 
        // b.root.right.left = new Node(15); 
        // b.root.right.right = new Node(8); 
		// b.show();
		// b.insert(12);
		// System.out.println("\n");
		// b.show();
		// b.del(b.root, 11);
		// System.out.println("\n");
		// b.show();
		b.insert(11);
		b.insert(7);
		b.insert(12);
		b.insert(9);
		b.insert(15);
		b.insert(8);
        b.show();
        System.out.println();
		b.del(b.root, 11);
        b.show();
        System.out.println();
		// System.out.println(b.root.data);
		// System.out.println(b.root.left.data);
		// System.out.println(b.root.right.data);
	}
}