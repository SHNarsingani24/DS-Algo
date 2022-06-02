#include<iostream>
#include<unordered_set>
using namespace std;

class Node{
public:
	int key;
	Node *next;

	Node(int k){
		key = k;
		next = NULL;
	}

	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};

// finding if there is cycle in given linkedlist, using unordered_set.
// unordered_map of <Node*, bool> can be used, too.
bool isThereCycle(Node *head){
	Node *temp = head;
	unordered_set<Node*> address;
	while(temp!=NULL){
		// cout << temp->key << " ";
		if(address.find(temp)!=address.end()){
			return true;
		}
		address.insert(temp);
		temp = temp->next;
	}
	return false;
}

// Floyd’s Cycle-Finding Algorithm.
bool detect_cycle(Node* head){
	Node *fast_p = head->next;
	Node *slow_p = head;
	while(fast_p && slow_p && fast_p->next){
		if(fast_p == slow_p){
			return true;
		}
		fast_p = fast_p->next->next;
		slow_p = slow_p->next;
	}
	return false;
}


int main(){
	Node *head = new Node(10);
	head->next = new Node(12);
	head->next->next = new Node(14);
	head->next->next = head;

	cout << isThereCycle(head) << endl;
	cout << detect_cycle(head) << endl;
	return 0;
}