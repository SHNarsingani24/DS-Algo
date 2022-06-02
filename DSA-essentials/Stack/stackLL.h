using namespace std;

// Here, I have used Linked List to implement Stack data structure. As I used Linked List, there is no limit on the size of stack.
// also the memory allocated to each element/node is dynamic, and is not continuous.

template <typename T>
class Stack;

// template is used to make program generic.
template <typename T>
class Node{
	T data;
	Node<T> *next;

public:
	// constructor.
	Node(T d): data(d){}

	// destructor.
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}

	// making stack as friend class, so it can access private attributes of this class.
	friend class Stack<T>;
};

template <typename T>
class Stack{
	Node<T>* head;

public:
	// constructor.
	Stack(): head(NULL){}

	// pushing element on the top of the stack - O(1).
	void push(T d){
		Node<T> *n = new Node<T>(d);
		n->next = head;
		head = n;
	}

	// method to access the top element of the stack - O(1).
	T top(){
		return head->data;
	}

	// to check whether stack is empty or not.
	bool is_empty(){
		return head==NULL;
	}

	// popping the top most element of the stack - O(1).
	void pop(){
		// only if stack is not empty.
		if(!this->is_empty()){
			Node<T> *temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
		}
	}

	// method to print the whole stack.
	void print(){
		Node<T> *temp = head;
		while(temp!=NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// recursive method to insert element at the bottom of the stack.
	void insert_at_bottom(T d){
		// base case - when stack is empty i.e., we reached the bottom, we will add given element at the end.
		if(this->is_empty()){
			this->push(d);
			return;
		}

		// popping each element while moving forward.
		T temp = this->top();
		this->pop();

		// recursive call on smaller stack.
		this->insert_at_bottom(d);

		// while moving backward, we are pushing all the elements again in the same order.
		this->push(temp);

		return;
	}

	// recursive method to reverse the stack, without using any extra data structure.
	void reverse(){
		// base case - when the whole stack is empty.
		if(this->is_empty()){
			return;
		}

		// while moving forward, popping each element.
		T temp = this->top();
		this->pop();

		// recursive call on smaller stack.
		this->reverse();

		// while moving backward, we are pushing all the elements again but from the bottom.
		this->insert_at_bottom(temp);

		return;
	}

	// destructor.
	~Stack(){
		if(head!=NULL){
			delete head;
		}
	}
};