#include <iostream>

//Structure of the Tree
struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(const int& data): data(data), left(nullptr), right(nullptr){}
};

void Insert(TreeNode*& root, const int& data){
	/**
	 * Create and Insert the node in the appropriate place of the tree
	 *
	 * @params: `root` root/parent node of the tree
	 * @params: `data` data to be inserted in the tree
	 * @return: void
	 *
	 * Average case Time Complexity: O(log(n))
	 * Worst case Time Complexity: O(n)
	 *
	 */

	if(root == nullptr) 	    { root = new TreeNode(data); }
	else if(root->data == data) { throw std::runtime_error("The node already exist. Duplicates not allowed"); }
	else if(root->data < data)  { Insert(root->right, data); }
	else 			    { Insert(root->left, data); }
}

void Pre_Order(TreeNode* root){
	/**
	 * Print the tree in an pre-order fashion
	 * 
	 * @params: `root` root/parent node of the tree
	 */
	if(root != nullptr){
		std::cout << root->data << " ";
		Pre_Order(root->left);
		Pre_Order(root->right);
	}	
}

void In_Order(TreeNode* root){
	/**
	 * Print the tree in an in-order fashion
	 * 
	 * @params: `root` root/parent node of the tree
	 */
	if(root != nullptr){
		In_Order(root->left);
		std::cout << root->data << " ";
		In_Order(root->right);
	}	
}

void Post_Order(TreeNode* root){
	/**
	 * Print the tree in an post-order fashion
	 * 
	 * @params: `root` root/parent node of the tree
	 */
	if(root != nullptr){
		Post_Order(root->left);
		Post_Order(root->right);
		std::cout << root->data << " ";
	}	
}

void free(TreeNode* root){
	/*
	 * Free up the memory in the heap
	 *
	 * @params: `root` root/parent node of the tree
	 */

	if(root != nullptr){
		free(root->left);
		free(root->right);
		delete root;
		root = nullptr;
	}
}

int main(){
	TreeNode* root = nullptr;
	Insert(root, 37);
	Insert(root, 19);
	Insert(root, 4);
	Insert(root, 2);
	Insert(root, 11);
	Insert(root, 22);
	Insert(root, 20);
	Insert(root, 51);
	Insert(root, 55);
	Insert(root, 42);
	
	In_Order(root);
	std::cout << std::endl;
	Pre_Order(root);
	std::cout << std::endl;
	Post_Order(root);
	std::cout << std::endl;
	/* 
	Tree structure
		37
	       /  \
	      19  51
	     / \   / \
	    4  22 42 55
	   /\	/ 	
	  2 11  20

	  In_Order: 2 4 11 19 22 20 37 42 51 55 
	  Post_Order: 2 11 4 20 22 19 42 55 51 37
	  Pre_Order: 37 19 4 2 11 22 20 51 42 55

	*/

	
	// free the memory
	free(root);
	return 0;
}
