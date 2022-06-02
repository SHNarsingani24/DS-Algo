#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d): data(d), left(NULL), right(NULL){}

	~Node(){
		if(left!=NULL){
			delete left;
		}
		if(right!=NULL){
			delete right;
		}
	}
};

// preorder build: root -> left -> right
Node* buildTree(){
	// taking key value from user.
	int d;
	cin >> d;

	// reached the leaf node.
	if(d==-1){
		return NULL;
	}

	// making a new node.
	Node* n = new Node(d);
	// first going on the left sub-tree.
	n->left = buildTree();
	// then to the right sub-tree.
	n->right = buildTree();
	return n;
}

// printing tree in preorder: root -> left -> right.
void print_preorder(Node *n){
	// if we reached leaf nodes.
	if(n==NULL){
		return;
	}
	// print root.
	cout << n->data << " ";

	// move towards left.
	print_preorder(n->left);

	// move towards right.
	print_preorder(n->right);
}

// printing tree in inorder: left -> root -> right.
void print_inorder(Node *n){
	// if we reached leaf nodes.
	if(n==NULL){
		return;
	}

	// move towards left.
	print_inorder(n->left);

	// print root.
	cout << n->data << " ";

	// move towards right.
	print_inorder(n->right);
}

// printing tree in postorder: left -> right -> root.
void print_postorder(Node *n){
	// if we reached leaf nodes.
	if(n==NULL){
		return;
	}

	// move towards left.
	print_postorder(n->left);

	// move towards right.
	print_postorder(n->right);

	// print root.
	cout << n->data << " ";
}

// also known as level-order printing.
void breadth_first_search(Node *root){
	queue<Node*> q;
	// pushing root node in queue.
	q.push(root);
	q.push(NULL); // as at root level only one node is there, it is end of root level.
	while(!q.empty()){
		// popping the elements of each level one by one.
		Node* temp = q.front();
		q.pop();

		// if NULL is encounter, it suggests the end of level hence new line can be added.
		if(temp==NULL){
			// however, if there are no elements in queue it suggests that all nodes are traversed hence returning from here.
			if(q.empty()){
				return;
			}
			// else add a new line and push NULL, it will be pushed after all the children of the next level.
			cout << endl;
			q.push(NULL);
			continue;
		}

		// printing the current node's data.
		cout << temp->data << " ";

		// we don't want to push NULLs that are at right and left of the leaf nodes hence if conditions are applied.
		// here basically before deleting the current node we will add it's children to the queue.
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}

}

// to build tree level-by-level.
Node *levelorder_build(){
	queue<Node*> q;
	int d;
	cin >> d;
	// take a queue and push root element into it.
	Node *root = new Node(d);
	q.push(root);
	while(!q.empty()){
		// pop first element of queue.
		Node* temp = q.front();
		q.pop();
		// scan two children for the current node, temp.
		int c1, c2;
		cin >> c1 >> c2;
		// if child is not null, then push it into the queue.
		if(c1!=-1){
			temp->left = new Node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right = new Node(c2);
			q.push(temp->right);
		}
	}

	return root;
}

// time complexity: O(N) -- all nodes are traversed.
int height(Node* root){
	if(root == NULL) return 0;	// when any node has NULL as children.

	int h1 = height(root->left);	// first find the height of left subtree.
	int h2 = height(root->right);	// find hight of right subtree.

	return 1 + max(h1, h2);	// work on root.
	// hence this follows post-order traversal.
}

// to get maximum diameter of the tree.
// this function will find height for each node hence the time complexity will be O(N^2), which can be reduced.
int max_diameter(Node* root){
	// for leaf nodes -- base case
	if(root==NULL){
		return 0;
	}
	// diameter can be any of these three options.
	int d1 = height(root->left) + height(root->right);	// if diameter consists root node.
	int d2 = max_diameter(root->left);	// if diameter is on left subtree.
	int d3 = max_diameter(root->right);	// if diameter is on right subtree.
	return max(max(d1, d2), d3);	// the maximum one will be chosen.
}

// ---------------------- Optimized Function to find Diameter of a tree ---------------------------------------//
// utility class for optimized function.
class hdPair{
public:
	int h, d;	// h - height, d - diameter.

	hdPair(int h, int d){
		this->h = h;
		this->d = d;
	}
};

// Time Complexity: O(N).
hdPair opt_diameter(Node* node){
	if(node == NULL){
		return hdPair(0, 0);
	}

	// PostOrder Traversal.
	hdPair left = opt_diameter(node->left);
	hdPair right = opt_diameter(node->right);

	// three options of diameter.
	int d1 = right.h + left.h;
	int d2 = left.d;
	int d3 = right.d;

	// here we are building height and diameter togather.
	int diameter = max(max(d1, d2), d3);
	int height = max(right.h, left.h)+1;
	return hdPair(height, diameter);
}

// function will print kth level of given tree.
void print_level(Node* root, int k){
	// first pushing the first level in the queue.
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int i = 1;
	// till we reach kth level, we will keep pushing levels in the queue.
	while(i < k){
		Node *temp = q.front();
		q.pop();
		if(temp==NULL){
			i++;
			if(!q.empty() and i!=k) q.push(NULL);
			continue;
		}
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}

	// corner case -- when k == 1, there is NULL in the queue, hence we should only print first (root) node.
	if(k==1){
		cout << q.front()->data << endl;
	} else {
		while(!q.empty()){
			cout << q.front()->data << " ";
			q.pop();
		}
		cout << endl;
	}
	return;
}

// function to get sum of all nodes of given tree.
int sum_of_nodes(Node* node){
	// if we reach NULL node. -- base case
	if(node==NULL){
		return 0;
	}
	// in post-order manner, first all the left nodes are summed up in ans, 
	// after that right nodes and at the end current node.
	int ans = 0;
	ans = ans + sum_of_nodes(node->left);
	ans = ans + sum_of_nodes(node->right);
	ans = ans + node->data;
	return ans;
}

int min_depth(Node* node){
	// corner case -- will run if and only if root node is NULL.
	if(node==NULL){
		return 0;
	}

	// when we reach leaf node!!!
	if(node->right==NULL and node->left==NULL){
		return 1;
	}

	// if one side is null and other has node, we need to go in which node exists.
	int right_depth = INT_MAX, left_depth = INT_MAX;
	if(node->left){
		left_depth = min_depth(node->left);
	}
	if(node->right){
		right_depth = min_depth(node->right);
	}
	
	// returning the minimum depth of the both side.
	return min(left_depth, right_depth) + 1;
}

// function to check if given tree is symmetric/mirror image with itself.
// this function is working on Top-Down approach. 
bool isSymmetric(Node* node1, Node* node2){
	// base case -- when both the nodes are NULL.
	if(node1==NULL and node2==NULL) return true;

	if((node1 and node2) and (node1->data==node2->data))
		return isSymmetric(node1->left, node2->right) and isSymmetric(node1->right, node2->left);
	
	// when any one condition fails in call stack over-all false wil be returned as we are using && operator here.
	return false;
}

// will ignore nodes with only one child.
void remove_half_nodes(Node* node){
	// if node is NULL -- base case.
	if(node==NULL){
		return;
	}

	// printing nodes in InOrder manner.
	remove_half_nodes(node->left);
	// node will be printed only if it has either 0 or 2 childs.
	if((node->right==NULL and node->left==NULL) or (node->left!=NULL and node->right!=NULL)){
		cout << node->data << " ";
	}
	remove_half_nodes(node->right);
}

// function to find paths(root to leaf) that has exact sum as target_sum.
void target_path_sum(Node* node, vector<vector<int>> &paths, int target_sum, vector<int> &temp, int cur_sum){
	if(node==NULL) return;

	if(node->left==NULL and node->right==NULL){
		if((cur_sum+node->data)==target_sum){
			temp.push_back(node->data);
			paths.push_back(temp);
			temp.pop_back();
		}
		return;
	}

	temp.push_back(node->data);
	cur_sum = cur_sum + node->data;	// taking each node in sum.
	target_path_sum(node->left, paths, target_sum, temp, cur_sum);	// moving left
	target_path_sum(node->right, paths, target_sum, temp, cur_sum);	// moving right
	temp.pop_back(); // backtracking.
	return;
}

// to make mirror tree of given tree, in which right nodes are on left and left ones are on right.
Node* make_mirror(Node *node){
	// base case -- NULL node
	if(node==NULL){
		return NULL;
	}
	// making copy of current node
	Node* n= new Node(node->data);
	// left to right and right to left
	n->left = make_mirror(node->right);
	n->right = make_mirror(node->left);
	return n;
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
	// Node *root = buildTree();
	Node *root = levelorder_build();
	// cout << "h";
	print_preorder(root);
	cout << endl;
	// cout << max_diameter(root);
	// cout << endl;
	// cout << opt_diameter(root).d << endl;
	// print_level(root, 3);
	// cout << "sum of all nodes is: " << sum_of_nodes(root) << endl;

	// cout << "min depth of this tree is: " << min_depth(root) << endl;

	// cout << "This tree is symmetric: " << isSymmetric(root, root) << endl;

	// running target_path_sum
	// vector<vector<int>> paths;
	// vector<int> v;
	// target_path_sum(root, paths, 22, v, 0);

	// for(vector<int> x: paths){
	// 	for(int i: x){
	// 		cout << i << " ";
	// 	}
	// 	cout << endl;
	// }

	Node *mirrored = make_mirror(root);
	print_inorder(root);
	cout << endl;
	print_inorder(mirrored);
	cout << endl;

	cout << "BST status: " << isBST(root);

	// remove_half_nodes(root);
	// cout << height(root);
	// print_inorder(root);
	// cout << endl;
	// print_postorder(root);
	// cout << endl;

	// breadth_first_search(root);
	return 0;
}