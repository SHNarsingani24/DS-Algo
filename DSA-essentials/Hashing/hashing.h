using namespace std;

template<typename T>
class Hashtable;

template<typename T>
class Node{
	string key;
	T value;
	Node *next;

public:
	// constructor.
	Node(string key, T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
 	
	// destructor.
	~Node(){
		// cout << "Deleting the node with key " << key << endl;
		if(next!=NULL){
			delete next;
		}
	}

	friend class Hashtable<T>;
};

template<typename T>
class Hashtable{
	Node<T> **table;	// table is an array of Node* (Head of linkedlist), hence one * for dynamic array and one for Node*.
	int cs, ts;		// cs - current size and ts - table size

	// hashing function.
	int hashFn(string key){
		int idx = 0;
		int base = 1;	// any prime number greater 26, here power of that prime number is 0.

		for(auto ch: key){
			idx = (idx + ch*base)%ts;
			base = (base*29)%ts;	// increasing power of prime number.
		}

		return idx;
	}

	// performing rehashing when the load_factor has passed the threshold.
	void rehash(){
		// making copy of old hash table.
		Node<T> ** oldTable = table;
		int oldTs = ts;

		// doubling size of the hashtable.
		cs = 0;
		ts = 2*ts + 1;
		table = new Node<T> *[ts];

		// each row of new table is empty, for now.
		for(int i = 0; i < ts; i++){
			table[i] = NULL;
		}

		// inserting, nodes in new table that already existed in old table.
		for(int i = 0; i < oldTs; i++){
			Node<T> *head = oldTable[i];
			while(head!=NULL){
				insert(head->key, head->value);
				head = head->next;
			}
			// deleting each row.
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}

		// deleting old table.
		delete [] oldTable;
		return;
	}

	Node<T> *delete_node(Node<T>* head){
		Node<T>* next = head->next;
		head->next = NULL;
		delete head;
		return next;
	}

public:
	Hashtable(int size=7){
		cs = 0, ts = size;
		table = new Node<T>*[ts];	// dynamic array of Node pointers of size ts.

		// initially each element will be NULL.
		for(int i = 0; i < ts; i++){
			table[i] = NULL;
		}
	}

	// average time complexity: O(1).
	void insert(string key, T val){

		int idx = hashFn(key);			// using hash function, getting index of hashtable at which val will be stored.
		Node<T> *n = new Node<T>(key, val);

		// inserting new node at head of the linkedlist, that exists at index idx.
		n->next = table[idx];
		table[idx] = n;

		cs++; 			// increasing current size.

		float load_factor = cs/float(ts);
		// if this condition is true, in that case insertion will take O(N) time.
		if(load_factor > 0.7){
			rehash();
		}
		return;
	}

	// as we don't know return type T here, we will return address.
	// so that we can return NULL, when element is not present in hashtable.
	T* search(string key){
		int idx = hashFn(key);		// finding the index at which given key should be...

		Node<T> *temp = table[idx];		// getting head of linkedlist present at idx index.

		// traversing through the linked list to find element with givrn key.
		while(temp!=NULL){
			// found..
			if(temp->key == key){
				return &temp->value;
			}
			temp = temp->next;
		}

		// key doesn't exist in linkedlist.
		return NULL;
	}

	// function to delete an element from table.
	void erase(string key){
		int idx = hashFn(key);		// finding the index at which given key should be...
		Node<T> *temp = table[idx];
		Node<T> *next = temp->next;

		// if head itself is the key element.
		if(temp->key==key){
			table[idx] = delete_node(temp);
			return;
		}

		// using temp to track previous element, and next will check for key.
		// next is element next to temp.
		while(next!=NULL){
			if(next->key==key){
				temp->next = delete_node(next);
				return;
			}
			temp = temp->next;
			next = next->next;
		}

		return;
	}

	// operator overloading.
	// user can use [] to access/update/create value of any key.
	T& operator[](string key){
		T *valAt = search(key);
		// if element with key doesn't exist.
		if(valAt==NULL){
			T val;		// uninitialized value.
			insert(key, val);	// make element with given key and uninitialized value.
			valAt = search(key);
		}

		// returning value by the refference.
		// any change on other side will be reflected in this object, too.
		return *valAt;
	}
	// to print current hash table.
	void print(){
		for(int i = 0; i < ts; i++){
			cout << "Row " << i << ": ";
			Node<T> *head = table[i];
			while(head!=NULL){
				cout << head->key << " -> ";
				head = head->next;
			}
			cout << endl;
		}
	}

};