#include<vector>
#include<queue>
using namespace std;

// class for each node of tree.
template<typename T>
class Node{
public:
	T data;
	Node* left;
	Node* right;

	Node(T d): data(d), left(NULL), right(NULL){}

	~Node(){
		if(left!=NULL){
			delete left;
		}
		if(right!=NULL){
			delete right;
		}
	}
};

// class for whole tree.
template<typename T>
class Tree{

	// this won't be used by user directly.
	// preorder build: root -> left -> right
	Node<T>* buildTree(vector<T> keys, int &i, T null){
		
		// taking key value from user.
		T d = keys[i++];	// increasing i, as moving to next element in list.

		// reached the leaf node.
		if(d==null){	// if d is equal to null, which is user defined, we have reached leaf node.
			return NULL;
		}
	
		// making a new node.
		Node<T>* n = new Node<T>(d);	
		// first going on the left sub-tree.
		n->left = buildTree(keys, i, null);
		// then to the right sub-tree.
		n->right = buildTree(keys, i, null);
		return n;
	}

	// helper function to get height of a tree.
	int get_height(Node<T> *node){
		if(node == NULL){
			return 0;
		}
		// following post-order traversal.
		int h1 = get_height(node->left);
		int h2 = get_height(node->right);
		return max(h1, h2) + 1;
	}
public:
	// a tree will only has root node(which is linked to other nodes) and null, , which is user defined variable
	// null indicates that there is no children now, used while building tree.
	Node<T> *root;
	T null;

	// constructor.
	Tree(vector<T> keys, T end){
		null = end;
		int i = 0;
		root = buildTree(keys, i, null);	// building tree in pre-order.
	}

	// constructor_2.0.
	Tree(Node<T> *r){
		root = r;
	}

	// method for preorder traversal.
	void preorder_traversal(Node<T> *n){
		// reached at leaf.
		if(n==NULL){
			return;
		}
		// printing node.
		cout << n->data << " ";
		// moving left.
		preorder_traversal(n->left);
		// moving right.
		preorder_traversal(n->right);
	}

	// method for inorder traversal.
	void inorder_traversal(Node<T> *n){
		// reached leaf
		if(n==NULL){
			return;
		}
		// moving left.
		inorder_traversal(n->left);
		// printing node.
		cout << n->data << " ";
		// moving right.
		inorder_traversal(n->right);
	}

	// method for post-order traversal.
	void postorder_traversal(Node<T> *n){
		// if leaf node reached.
		if(n==NULL){
			return;
		}
		// moving left.
		postorder_traversal(n->left);
		// moving right.
		postorder_traversal(n->right);
		// printing node.
		cout << n->data << " ";
	}

	// also known as Breadth First Search(BFS).
	void levelorder_traversal(){
		// making a queue and pushing root node and a NULL in it.
		// NULL represents end of the level, root level can have only one node(root).
		queue<Node<T>*> q;
		q.push(root);
		q.push(NULL);
		// when queue is empty that indicates that all the nodes are traversed.
		while(!q.empty()){
			// popping the first element of the queue.
			Node<T> *temp = q.front();
			q.pop();

			// when NULL is encountered, we will print new line and if the queue is not empty we will push another NULL
			// this another NULL will appear after the nodes of next level.
			if(temp == NULL){
				if(q.empty()){
					return;
				}
				q.push(NULL);
				cout << endl;
				continue;
			}
			// printing the data of current node.
			cout << temp->data << " ";

			// if left or/and right child exists of current node than push it in the queue.
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}

	// using an exisisting tree, one can make another tree using this method.
	// we are building tree level-by-level in this method.
	Node<T>* levelorder_build(vector<T> data){
		// making a queue, and pushing a new root node in it. 
		queue<Node<T>*> q;
		Node<T>* r = new Node<T>(data[0]);
		q.push(r);
		// this integer is to track the current position in data vector.
		int i = 1;
		while(!q.empty()){
			// popping the first element.
			Node<T> *temp = q.front();
			q.pop();
			// if the data element is not null then they will be the children of current node(temp).
			// hence, after making them children of current node, they are pushed in queue.
			if(data[i]!=null){
				temp->left = new Node<T>(data[i]);
				q.push(temp->left);
			}
			if(data[i+1]!=null){
				temp->right = new Node<T>(data[i+1]);
				q.push(temp->right);
			}
			i+=2;	// each time we will take two elements from the vector.
		}
		return r;	// returning root node.
	}

	// function to get height of the tree.
	int height(){
		return get_height(root);
	}

	~Tree(){
		if(root != NULL){
			delete root;
		}
	}
};