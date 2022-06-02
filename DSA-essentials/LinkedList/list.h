using namespace std;

// forward Declration.
class List;

class Node{
	int data;
	Node* next;

	void swap(Node *x){
		int temp = x->data;
		x->data = this->data;
		this->data = temp;
		return;
	}

public:
	Node(int d): data(d), next(NULL){};

	// declaring List as friend class, so that it can access private elenents of Node class.
	friend class List;

	// This will kind of work recursively.
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};

class List{
	Node* head;
	Node* tail;

	// this function won't be called from main.
	int searching_helper(Node* start, int key){
		if(start == NULL){
			return -1;
		} else if(start->data == key){
			return 0;
		}

		int i = searching_helper(start->next, key);
		if(i == -1) return i;
		else return i + 1;
	}

	int get_length(){
		int i = 0;
		Node *temp = head;
		while(temp!=NULL){
			i++;
			temp = temp->next;
		}
		return i;
	}

public:
	List(): head(NULL), tail(NULL){};

	void push_front(int d){
		Node* n = new Node(d);
		if(head == NULL){
			head = tail = n;
		} else {
			n->next = head;
			head = n;
		}
	}

	void push_back(int d){
		Node* n = new Node(d);
		if(head == NULL){
			head = tail = n;
		} else {
			tail->next = n;
			tail = n;
		}
	}

	void print(){
		Node* n = head;
		while(n != NULL){
			cout << n->data << " ";
			n = n->next;
		}
	}

	// inserting data d, at i
	void insert(int i, int d){
		if(i == 0){
			push_front(d);
			return;
		}
		Node* temp = head;
		int j = 0;
		while(j < i-1){
			temp = temp->next;
			j++;
		}
		Node* n = new Node(d);
		n->next = temp->next;
		temp->next = n;
	}

	int linear_search(int key){
		Node* temp = head;
		int i = 0;
		while(temp!=NULL){
			if(temp->data == key){
				return i;
			}
			i++;
			temp = temp->next;
		}
		return -1;
	}

	int recursive_search(int key){
		return searching_helper(head, key);
	}

	void pop_front(){
		Node* temp = head;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}

	void pop_back(){
		// when there is only one element in linked list.
		if(head == tail and head!=NULL){
			Node* n = head;
			head = tail = NULL;
			delete n;	
			// if we delete head than it will delete the Linked List, but we want to return an empty Linked List. 
			// that's why before deleting head node, we are storing it in different node.
		}
		Node* temp = head;
		// finding element just before the tail, so that it can be made new tail.
		while(temp != NULL){
			if(temp->next == tail){
				Node* n = tail;
				temp->next = NULL;
				tail = temp;
				delete n;
				break;
			}
			temp = temp->next;
		}
	}

	void pop(int i){
		if(i==0){
			return pop_front();
		}
		int j = 0;
		Node* temp = head;
		while(j < i-1){
			if(temp==NULL || temp->next == NULL){
				return;
			}
			temp = temp->next;
		}
		Node* n = temp->next;
		temp->next = n->next;
		n->next = NULL;
		delete n;
	}

	List reverse(){
		Node* prev = NULL, *temp = NULL, *current = head;
		while(current!=NULL){
			temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		List l;
		l.head = prev;
		return l;
	}

	int get_last_kth_node(int k){
		Node *temp = head, *current; 
		while(true){
			current = temp;
			for(int i = 0; i < k; i++){
				current = current->next;
			}
			if(current == NULL) return temp->data;
			temp = temp->next;
		}
	}

	List merge_lists(List r){
		Node *h1 = head, *h2 = r.head, *current;
		List p;
		current = p.head;
		while(h1!=NULL or h2!=NULL){
			if(h1!=NULL){
				p.push_back(h1->data);
				h1 = h1->next;
			}
			if(h2!=NULL){
				p.push_back(h2->data);
				h2 = h2->next;
			}
		}
		return p;
	}

	void bubble_sort(){
		int len = this->get_length();
		for(int i = 0; i < len; i++){
			Node *x = head, *y = head->next;
			for(int j = 0; j < len-i-1; j++){
				if(x->data > y->data){
					x->swap(y);
				}
				x = x->next, y = y->next;
			}
		}
		return;
	}

	// this will call destructor of Node class, as head is instance of Node.
	~List(){
		if(head != NULL){
			delete head;
		}
	}
};