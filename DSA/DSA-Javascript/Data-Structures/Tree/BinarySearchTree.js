/* Binary Search Tree!!
 *
 * Nodes that will go on the Binary Tree.
 * They consist of the data in them, the node to the left, the node
 * to the right, and the parent from which they came from.
 *
 * A binary tree is a data structure in which an element
 * has two successors(children). The left child is usually
 * smaller than the parent, and the right child is usually
 * bigger.
 */

class Node {
  constructor (data) {
    this.data = data
    this.left = null
    this.right = null
  }
}

class BinarySearchTree {
  constructor () {
    this.root = null
  }

  insert (data) {
    // Creating a node and initialising with data
    const newNode = new Node(data)

    if (this.root === null) {
      // if root is null then node will be added to the tree and made root.
      this.root = newNode
    } else {
      // find the correct position in the tree and add the node
      this.insertNode(this.root, newNode)
    }
  }

  insertNode (node, newNode) {
    // if the data is less than the node data move left of the tree
    if (newNode.data < node.data) {
      if (node.left === null) {
        // if left is null insert node here
        node.left = newNode
      } else {
        // if left is not null recur until null is found
        this.insertNode(node.left, newNode)
      }
    } else {
      // if the data is more than the node data move right of the tree
      if (node.right === null) {
        // if right is null insert node here
        node.right = newNode
      } else {
        // if right is not null recur until null is found
        this.insertNode(node.right, newNode)
      }
    }
  }

  remove (data) {
    // root is re-initialized with root of a modified tree.
    this.root = this.removeNode(this.root, data)
  }

  removeNode (node, key) {
    if (node === null) {
      // if the root is null then tree is empty
      return null
    } else if (key < node.data) {
      // if data to be delete is less than roots data then move to left subtree
      node.left = this.removeNode(node.left, key)
      return node
    } else if (key > node.data) {
      // if data to be delete is greater than roots data then move to right subtree
      node.right = this.removeNode(node.right, key)
      return node
    } else {
      // if data is similar to the root's data then delete this node
      if (node.left === null && node.right === null) {
        // deleting node with no children
        node = null
        return node
      }

      if (node.left === null) {
        // deleting node with one children
        node = node.right
        return node
      } else if (node.right === null) {
        node = node.left
        return node
      }

      // Deleting node with two children
      // minimum node of the right subtree
      // is stored in aux
      const aux = this.findMinNode(node.right)
      node.data = aux.data

      node.right = this.removeNode(node.right, aux.data)
      return node
    }
  }

  findMinNode (node) {
    //  finds the minimum node in tree searching starts from given node
    if (node.left === null) {
      // if left of a node is null then it must be minimum node
      return node
    } else {
      return this.findMinNode(node.left)
    }
  }

  inorder (node) {
    // Performs inorder traversal of a tree
    if (node !== null) {
      this.inorder(node.left)
      console.log(node.data)
      this.inorder(node.right)
    }
  }

  preorder (node) {
    // Performs preorder traversal of a tree
    if (node !== null) {
      console.log(node.data)
      this.preorder(node.left)
      this.preorder(node.right)
    }
  }

  postorder (node) {
    // Performs postorder traversal of a tree
    if (node !== null) {
      this.postorder(node.left)
      this.postorder(node.right)
      console.log(node.data)
    }
  }

  getRootNode () {
    // returns root of the tree
    return this.root
  }

  search (node, data) {
    // search for a node with given data
    if (node === null) {
      // if trees is empty return null
      return null
    } else if (data < node.data) {
      // if data is less than node's data move left
      return this.search(node.left, data)
    } else if (data > node.data) {
      // if data is less than node's data move left
      return this.search(node.right, data)
    } else {
      // if data is equal to the node data return node
      return node
    }
  }
}

const BST = new BinarySearchTree()

// Inserting nodes to the BinarySearchTree
BST.insert(15)
BST.insert(25)
BST.insert(10)
BST.insert(7)
BST.insert(22)
BST.insert(17)
BST.insert(13)
BST.insert(5)
BST.insert(9)
BST.insert(27)

//          15
//         /  \
//        10   25
//       / \   / \
//      7  13 22  27
//     / \    /
//    5   9  17

let root = BST.getRootNode()

// prints 5 7 9 10 13 15 17 22 25 27
BST.inorder(root)

// Removing node with no children
BST.remove(5)

//          15
//         /  \
//        10   25
//       / \   / \
//      7  13 22  27
//       \    /
//        9  17

root = BST.getRootNode()

// prints 7 9 10 13 15 17 22 25 27
BST.inorder(root)

// Removing node with one child
BST.remove(7)

//          15
//         /  \
//        10   25
//       / \   / \
//      9  13 22  27
//            /
//           17

root = BST.getRootNode()

// prints 9 10 13 15 17 22 25 27
BST.inorder(root)

// Removing node with two children
BST.remove(15)

//          17
//         /  \
//        10   25
//       / \   / \
//      9  13 22  27

root = BST.getRootNode()
console.log('inorder traversal')

// prints 9 10 13 17 22 25 27
BST.inorder(root)

console.log('postorder traversal')
BST.postorder(root)
console.log('preorder traversal')
BST.preorder(root)
