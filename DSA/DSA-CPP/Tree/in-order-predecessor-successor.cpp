#include <iostream>
#include <stdexcept>

struct TreeNode{
	TreeNode* right;
	TreeNode* left;
	int data;
	TreeNode(const int& data): data(data), right(nullptr), left(nullptr){}
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

        if(root == nullptr)         { root = new TreeNode(data); }
        else if(root->data == data) { throw std::runtime_error("The node already exist. Duplicates not allowed"); }
        else if(root->data < data)  { Insert(root->right, data); }
        else                        { Insert(root->left, data); }
}

int rightmost(TreeNode* root){
	/**
	 * Find and return the rightmost value of the sub-tree
	 *
         * @params: `root` root/parent node of the tree
	 *
	 * @return: value of the node at the rightmost end of the sub tree
	 */

	if(root->right == nullptr){ return root->data;}
	return rightmost(root->right);
}

int prevSmallerAncester(TreeNode* root, const int& data, int ancestor){	
	/**
	 * Find and return the previous smaller value to data
	 *
         * @params: `root` root/parent node of the tree
	 * @params: `data` data to compare with
	 * @params: `ancestor` holds the previous smaller value to data
	 * 
	 * @return: previous smaller value to data
	 */

	if(root->data < data){ return prevSmallerAncester(root->right, data, root->data); }
	else if(root->data > data){ return prevSmallerAncester(root->left, data, ancestor); }
	return ancestor;

}

int inorderpred(TreeNode* cur, const int& data, TreeNode* root){
	/**
	 * Find the in-order predecessor of the given data
	 *
	 * @params: `cur` root/parent node of the tree
	 * @params: `data` data where it's predecessor to be found
	 * @params: `root` root of the tree for the prevSmallerAncester function
	 *
	 * @return: in-order predecessor for the given data
	 */

	if(cur == nullptr){ throw std::runtime_error("Nullptr"); }
	else if(cur->data == data){
		if(cur->left != nullptr){ return rightmost(cur->left); }
		return prevSmallerAncester(root, data, 0);
	}
	else if(cur->data < data){ return inorderpred(cur->right, data, root); }
	else { return inorderpred(cur->left, data, root); }
}

int leftmost(TreeNode* cur){
	/**
	 * Find and return the leftmost value of the sub-tree
	 *
         * @params: `root` root/parent node of the tree
	 *
	 * @return: value of the node at the leftmost end of the sub tree
	 */
	
	if(cur->left != nullptr){ return leftmost(cur->left); }
	return cur->data;
}

int successor(TreeNode* root, const int& data, int suc){
	/**
	 * Find and return the lowest greatest value to data
	 *
         * @params: `root` root/parent node of the tree
	 * @params: `data` data to compare with
	 * @params: `ancestor` holds the previous smaller value to data
	 * 
	 * @return: lowest greatest value to data
	 */
	
	if(root->data < data){ return successor(root->right, data, suc); }
	else if(root->data > data){ return successor(root->left, data, root->data); }
	return suc;
}

int inordersuc(TreeNode* cur, const int& data, TreeNode* root){
	/**
	 * Find the in-order successor of the given data
	 *
	 * @params: `cur` root/parent node of the tree
	 * @params: `data` data where it's predecessor to be found
	 * @params: `root` root of the tree for the prevSmallerAncester function
	 *
	 * @return: in-order successor for the given data
	 */
	
	if(cur == nullptr){ throw std::runtime_error("Nullptr"); }
	else if(cur->data == data){
		if(cur->right != nullptr){ leftmost(cur->right); }
		return successor(root, data, 0);
	}
	else if(cur->data < data){return inordersuc(cur->right, data, root); }
	else{return inordersuc(cur->left, data, root); }
}

void print(TreeNode* root){
	if(root != nullptr){
		print(root->left);
		std::cout << root->data << " ";
		print(root->right);
	}
}

int main(){
	TreeNode* root = nullptr;

	Insert(root, 37);
        Insert(root, 19);
        Insert(root, 4);
        Insert(root, 22);
        Insert(root, 51);
        Insert(root, 55);
        Insert(root, 42);
        Insert(root, 20);
        Insert(root, 11);
        Insert(root, 2);
	
	/*
        Tree structure
                37
               /  \
              19  51
             / \   / \
            4  22 42 55
           /\   /
          2 11  20

        OUTPUT:
		In-order predecessor of 42 is: 37
	 */

	print(root);
	std::cout << std::endl;
	int val = 55;
	std::cout << "In-order successor " << inordersuc(root, val, root) << std::endl; 
	std::cout << "In-order pred " << inorderpred(root, val, root) << std::endl; 
}



