#include<iostream>
#include "heap.h"
#include<queue>
using namespace std;

// making custom comparator.
class Compare{
public:
	bool operator()(int parent, int child){
		return parent > child;		// for min heap.
		// return parent < child   -- for max heap.
	}
};

int main(){
	// ----------------------------------- Using heap.h file we coded ----------------------------------- //
	// Heap h(7); 		will create max heap
	Heap h(7, false);		// will create min heap

	int arr[] = {20, 30, 40, 100, 20, 50, 120};

	for(int node: arr){
		h.push(node);
	}

	h.print();

	h.pop();

	h.print();


	// ------------------------------------ Using in-built queue library ---------------------------- //
	// priority_queue<int> heap;		// -- will create max heap by default.

	// priority_queue<int, vector<int>, greater<int>> heap;		-- min heap using in-built comparator.

	priority_queue<int, vector<int>, Compare> heap;		// min heap using custom comparator.
	for(int node: arr){
		heap.push(node);
	}

	while(!heap.empty()){
		cout << heap.top() << " ";
		heap.pop();
	}

	return 0;
}