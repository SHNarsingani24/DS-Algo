using namespace std;

template<typename T>
class Queue;

template<typename T>
class Node{
	T data;
	Node<T> *next;

public:
	Node(T d): data(d), next(NULL){}

	~Node(){
		if(next!=NULL){
			delete next;
		}
	}

	friend class Queue<T>;
};

template<typename T>
class Queue{
	Node<T> *head;
	Node<T> *tail;

public:
	Queue(): head(NULL), tail(NULL){}

	void push(T d){
		Node<T> *n = new Node<T>(d);
		if(head == NULL){
			head = tail = n;
			return;
		}
		tail->next = n;
		tail = n; 
	}

	bool empty(){
		return head == NULL;
	}

	T front(){
		return head->data;
	}

	void pop(){
		if(!empty()){
			Node<T> *temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
		}
	}

	void print(){
		Node<T> *temp = head;
		while(temp!=NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
		return;
	}

	~Queue(){
		delete head;
	}
};