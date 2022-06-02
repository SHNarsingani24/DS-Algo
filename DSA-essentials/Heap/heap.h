#include<vector>
using namespace std;

class Heap{
	vector<int> v;
	bool type;		// true - max heap(default), false - min heap

	// utility function that compares two element of heap according to it's type.
	bool compare(int parent, int child){ 
		if(type){
			return parent < child;		// according to this condition elements will be swappped.
		} else {						// hence if wrong, return true so that function can make it right
			return parent > child;		// for example, if type is true it means it is max heap, in which
		}								// parent > child but if parent < child we return true and function will swap both.
	}

	void heapify(int i){	// i - index of root node of subtree, we want to heapify.
		int left = 2*i;		// index of left child in array
		int right = 2*i+1;	// index of right child in array.

		int new_root = i;
		// comparing i node with left child(if exists), if condition satisfies(based on the type of heap) 
		// we will consider left child as new root.
		if(left < v.size() and compare(v[new_root], v[left])){
			new_root = left;
		}
		// here we are comparing right child(if exists) of i with the current new root, 
		// which can be either i or the left child of i.
		if(right < v.size() and compare(v[new_root], v[right])){
			new_root = right;
		}

		// if new root is still i, it means that no swapping is needed from this point and hence we can return.
		if(new_root!=i){
			swap(v[i], v[new_root]);
			heapify(new_root);
		}

		return;
	}

public:

	Heap(int size=10, bool t=true){
		v.reserve(size+1);
		v.push_back(-1);	// we are not using index 0 and hence blocking it with -1.
		type = t;
	}

	void push(int data){
		// first normally push data into array.
		v.push_back(data);

		// i - new inserted element, p - parent of that element.
		int i = v.size()-1;
		int p = i/2;

		// for max heap
		// comparing new node with it's parent. swapping will be done till new node reaches to its correct position.
		// Time Complexity - O(Log N)
		while(i>1 and compare(v[p], v[i])){
			swap(v[p], v[i]);
			i = p;
			p = p/2;
		}
	}

	int top(){
		if(empty()) return -1;
		return v[1];
	}

	// remove the top element
	void pop(){
		if(empty()) return;
		// swap root node with right most leaf node --- from CBT point of view.
		// swap first with last element --- from array point of view.
		// Time - O(1).
		swap(v[1], v[v.size()-1]);

		// delete right most leaf node --- from CBT point of view.
		// delete last element -- from array point of view.
		// Time - O(1).
		v.pop_back();

		heapify(1);
	}

	bool empty(){
		return v.size()==1;
	}

	void print(){
		Heap temp = *this;
		while(!temp.empty()){
			cout << temp.top() << " ";
			temp.pop();
		}
		cout << endl;
	}
};