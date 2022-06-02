#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *right, *left;

	// constructor.
	Node(int d): data(d), right(NULL), left(NULL){}

	// destructor.
	~Node(){
		if(right){
			delete right;
		}
		if(left){
			delete left;
		}
	}
};

// inserting a new key in Binary Search Tree.
Node* insert(Node* root, int key){
	// base case -- when we reach the appropiate place to insert a node.
	if(root==NULL){
		return new Node(key);
	}

	// if key is less than root, we will insert that to the left.
	if(key < root->data){
		root->left = insert(root->left, key);
	} else {	// if key is greater than root, we will insert that to the left.
		root->right = insert(root->right, key);
	}

	return root;
}

void print_inorder(Node *root){
	// base case.
	if(root==NULL){
		return;
	}

	// Inorder -- left root right
	print_inorder(root->left);
	cout << root->data << " ";
	print_inorder(root->right);

	return;
}

// searching in Binary Search Tree.
// Time Complexity: O(H) -- H is height of tree.
// in BST, LogN <= H <= N
bool search(Node *root, int key){
	// base case -- if we reached at the end, element is not present.
	if(root==NULL){
		return false;
	}
	// base case -- if we found the element.
	if(root->data == key){
		return true;
	}

	// if element is less than root search it in left subtree.
	if(key < root->data){
		return search(root->left, key);
	} else {	// if element is greater than root, search in right subtree.
		return search(root->right, key);
	}
}

// function to find node with minimum data in given BST. --- utilized in remove function
Node* findMin(Node* root){
	while(root->left!=NULL){
		root = root->left;
	}
	return root;
}

Node* remove(Node* root, int key){
	// base case -- if there doesn't exist element with value key. 
	if(root==NULL){
		return NULL;
	}
	// Searching the key in tree.
	if(key < root->data){
		root->left = remove(root->left, key);
	} else if(key > root->data){
		root->right = remove(root->right, key);
	} else {	// found the key
		// key node has No child
		if(root->left==NULL and root->right==NULL){
			delete root;
			root = NULL;
		}

		// key node has only one child either left or right.	-- MOST TRICKY CASE
		else if(root->left==NULL){	// if only right child is there.
			Node* temp = root;
			root = temp->right;
			temp->right = temp->left = NULL;
			delete temp;
		} else if(root->right==NULL){	// if only left child is there.
			Node* temp = root;
			root = temp->left;
			temp->right = temp->left = NULL;
			delete temp;
		}

		// key node has both childs (left and right)
		else{
			Node* temp = findMin(root->right);	
			// after deleting node Inorder traversal should remain same, 
			// hence we are finding the minimum element from the right subtree to replace it with the key node.
			root->data = temp->data;
			root->right = remove(root->right, temp->data);
		}
	}

	return root;
}

// function to print nodes that has data in (lowwer, upper) range only.
void printRange(Node* root, int lwr, int upr){
	if(root==NULL){
		return;
	}

	// if root node lies in-between the range, we need to check both the sides.
	if(root->data > lwr and root->data < upr){
		printRange(root->left, lwr, upr);
		cout << root->data << " ";
		printRange(root->right, lwr, upr);
	}

	// if root node is greater than upper bound, we only need to check in left subtree.
	if(root->data > upr){
		printRange(root->left, lwr, upr);
	}

	// if root node is less than lower bound, we only need to check in right subtree.
	if(root->data < lwr){
		printRange(root->right, lwr, upr);
	}

	return;
}

// to check if given tree is BST or not.
bool isBST(Node *root){
	// base case -- when leaf node reached.
	if(root->left==NULL  and  root->right==NULL){
		return true;
	}

	// rec case -- if current node has only one child, check for only that one.
	if(root->right==NULL){
		if(root->data > root->left->data) return isBST(root->left);
	} else if(root->left==NULL){
		if(root->data < root->right->data) return isBST(root->right);
	}
	// rec case -- if node has both children checking right and left subtrees if root is in correct position
	else if(root->data > root->left->data  and  root->data < root->right->data){
		return isBST(root->left) and isBST(root->right);
	} 	

	// if root is not in correct position, returning false as it is not a BST.
	return false;

}

int main(){

	// Creating new Binary Search Tree.
	Node *root = NULL;
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	for(int key: arr){
		root = insert(root, key);
	}
	
	// Printing the BST (inorder).
	print_inorder(root);
	cout << endl;

	// Searching in Binary Search Tree.
	int ser[] = {2, 4, 5, 9, 10, 13};
	for(int key: ser){
		cout << "Search of " << key << " : " << search(root, key) << endl;
	}

	// deleting given key node from the tree.
	// int key;
	// cin>>key;
	// root = remove(root, key);
	// print_inorder(root);

	// printRange(root, 5, 12);

	cout << "BST status: " << isBST(root);
	return 0;
}