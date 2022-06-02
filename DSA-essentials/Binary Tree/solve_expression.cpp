#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdlib.h>
using namespace std;

// class for each node of tree.
class Node{
public:
	string data;
	Node* left;
	Node* right;

	// constructor
	Node(string d): data(d), left(NULL), right(NULL){}

	// destructor
	~Node(){
		if(left!=NULL){
			delete left;
		}
		if(right!=NULL){
			delete right;
		}
	}
};

// building tree in preorder manner.
Node* build_tree(){
	string d;
	cin >> d;

	// letter 'x' is considered as NULL while taking input.
	string null = "x";
	if(!d.compare(null)){
		return NULL;
	}

	Node* n = new Node(d);
	n->left = build_tree();
	n->right = build_tree();

	return n;
}

// solving the given expression tree.
int solve(Node* node){
	int ans;

	// performing operations according to root node
	string opt = node->data;
	if(!opt.compare("+")){
		ans = solve(node->left) + solve(node->right);
	} else if(!opt.compare("-")){
		ans = solve(node->left) - solve(node->right);
	} else if(!opt.compare("*")){
		ans = solve(node->left) * solve(node->right);
	} else if(!opt.compare("/")){
		ans = solve(node->left) / solve(node->right);
	} else {
		return stoi(node->data);
	}
	return ans;
}

// preorder traversal of tree.
void preorder_traversal(Node* root){
	if(root==NULL){
		return;
	}
	cout << root->data << " ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

int main(){
	Node* root = build_tree();
	preorder_traversal(root);
	cout << endl;
	cout << solve(root);
	return 0;
}